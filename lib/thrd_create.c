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
#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>
#include <threads.h>

/* A temporary structure used to store the arguments passed to
   'thrd_create'. */
struct thrd_create_args
{
  thrd_start_t func;
  void *arg;
};

/* The 'thrd_create' expects a function pointer with the type int (*) (void *)
   but 'pthread_create' expects a function pointer with the type
   void *(*) (void *). This function is passed to pthread_create along with a
   pointer to the actual start routine and it's argument. */
static void *
thrd_entry_point (void *param)
{
  struct thrd_create_args *ptr = (struct thrd_create_args *) param;
  thrd_start_t func = ptr->func;
  void *arg = ptr->arg;

  /* The allocated structure is no longer needed. Free it. */
  free (ptr);

  /* Call the function passed to 'thrd_create'. */
  return (void *) (intptr_t) func (arg);
}

int
thrd_create (thrd_t *thr, thrd_start_t func, void *arg)
{
  struct thrd_create_args *ptr;

  /* The structure used to pass information to 'thrd_entry_point' must be
     allocated using malloc. It is not defined whether the thread created
     by 'pthread_create' starts executing before the calling thread. If the
     structure were allocated on the stack and the calling thread finished
     before the new thread, the behavior would be undefined.
  */
  ptr = (struct thrd_create_args *) malloc (sizeof (struct thrd_create_args));
  if (ptr == NULL)
    return thrd_nomem;
  else
    {
      int result;

      /* Setup the arguments to 'thrd_entry_point'. */
      ptr->func = func;
      ptr->arg = arg;

      /* Create the thread. */
      result = pthread_create (thr, NULL, thrd_entry_point, ptr);
      if (result == 0)
        return thrd_success;
      else
        {
          free (ptr);
          return thrd_error;
        }
    }
}
