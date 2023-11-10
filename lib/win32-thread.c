/*-
 * Copyright (c) 2023, Collin Funk
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <config.h>

#include <errno.h>
#include <process.h>
#include <stdint.h>
#include <stdlib.h>
#include <windows.h>

#include "win32-thread.h"

/* Thread local key used to access the current thread. */
static DWORD current_thread_key = TLS_OUT_OF_INDEXES;

/* clang-format off */
static unsigned int __stdcall
win32_thread_entry_point (void *ptr)
/* clang-format on */
{
  return 0;
}

/* https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/beginthread-beginthreadex?view=msvc-170 */
int win32_thread_create (struct win32_thread **thread,
                         void *(*start_routine) (void *), void *arg);

int
win32_thread_detach (struct win32_thread *thread)
{
  /* THREAD is not joinable. */
  if (thread == NULL || thread->detached)
    return EINVAL;
  thread->detached = 1;
  return 0;
}

int
win32_thread_equal (struct win32_thread *t1, struct win32_thread *t2)
{
  return t1 == t2 ? 1 : 0;
}

/* https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/endthread-endthreadex?view=msvc-170 */
void
win32_thread_exit (void *value_ptr)
{
  /* FIXME: Should return 0 on the last thread. */
  _endthreadex ((unsigned int) (uintptr_t) value_ptr);
  abort ();
}

int
win32_thread_join (struct win32_thread *thread, void **value_ptr)
{
  DWORD result;

  /* THREAD is not joinable. */
  if (thread == NULL || thread->detached)
    return EINVAL;

  /* Wait for the thread handle. */
  result = WaitForSingleObject (thread->handle, INFINITE);
  /* Not sure what GetLastError () returns. Just use EINVAL. */
  if (result == WAIT_FAILED)
    return EINVAL;

  /* TODO */
  *value_ptr = NULL;

  return 0;
}

/* If we fail to allocate memory or thread local storage just abort. The
   'pthread_equal' function never fails so it would be unexpected for this
   to also fail. */
/* https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentthread */
struct win32_thread *
win32_thread_self (void)
{
  struct win32_thread *thread;

  /* Check if we are the main thread or created by CreateThread (). */
  if (current_thread_key != TLS_OUT_OF_INDEXES)
    thread = TlsGetValue (current_thread_key);
  else
    {
      HANDLE thread_handle;

      thread = (struct win32_thread *) malloc (sizeof (struct win32_thread));
      /* Unlucky. */
      if (thread == NULL)
        abort ();
      /* Set the thread to be detached so we don't try to free it. Will cause
         memory leaks. */
      thread->detached = 1;
      thread->thread_id = GetCurrentThreadId ();
      /* Duplicate the handle so it isn't a psuedo-handle. */
      thread_handle = GetCurrentThread ();
      if (!DuplicateHandle (GetCurrentProcess (), GetCurrentThread (),
                            GetCurrentProcess (), &thread->handle, 0, FALSE,
                            DUPLICATE_SAME_ACCESS))
        abort ();
      /* Allocate the thread local storage. */
      current_thread_key = TlsAlloc ();
      if (current_thread_key == TLS_OUT_OF_INDEXES)
        abort ();
      /* Set the thread local storage to the allocated thread. */
      if (!TlsSetValue (current_thread_key, (void *) thread))
        abort ();
    }
  return thread;
}
