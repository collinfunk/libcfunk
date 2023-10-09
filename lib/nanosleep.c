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

/* #include <config.h> */

#define HAVE_WINDOWS_H 1

#include <errno.h>
#include <time.h>

#if HAVE_WINDOWS_H
#  include <windows.h>
#else
#  error "No implementation of nanosleep for your system."
#endif

/* FIXME: Support high resolution timers and check for overflows.
   SetWaitableTimerEx, QueryPerformanceFrequency, or some other function
   might work. */
int
nanosleep (const struct timespec *rqtp, struct timespec *rmtp)
{
  /* If requested nanoseconds is less than 0 or greater than or equal to
     1000 million nanoseconds. */
  if (rqtp->tv_nsec < 0 || rqtp->tv_nsec >= 1000000000)
    {
      errno = EINVAL;
      return -1;
    }

  /* Convert to milliseconds. */
  Sleep (rqtp->tv_sec * 1000 + rqtp->tv_nsec / 1000000);

  if (rmtp != NULL)
    {
      rmtp->tv_sec = 0;
      rmtp->tv_nsec = 0;
    }
  return 0;
}
