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
#include <threads.h>

int
mtx_init (mtx_t *mtx, int type)
{
  if (type != mtx_plain && type != mtx_timed
      && type != (mtx_plain | mtx_recursive)
      && type != (mtx_timed | mtx_recursive))
    return thrd_error;

  if (!(type & mtx_recursive))
    {
      int result = pthread_mutex_init (mtx, NULL);
      if (result != 0)
        {
          if (result == ENOMEM)
            return thrd_nomem;
          else
            return thrd_error;
        }
    }
  else
    {
      pthread_mutexattr_t attr;
      int result;

      result = pthread_mutexattr_init (&attr);
      if (result != 0)
        {
          if (result == ENOMEM)
            return thrd_nomem;
          else
            return thrd_error;
        }

      result = pthread_mutexattr_settype (&attr, PTHREAD_MUTEX_RECURSIVE);
      if (result != 0)
        {
          (void) pthread_mutexattr_destroy (&attr);
          return thrd_error;
        }

      result = pthread_mutex_init (mtx, &attr);
      if (result != 0)
        {
          (void) pthread_mutexattr_destroy (&attr);
          if (result == ENOMEM)
            return thrd_nomem;
          else
            return thrd_error;
        }

      result = pthread_mutexattr_destroy (&attr);
      if (result != 0)
        return thrd_error;
    }

  return thrd_success;
}
