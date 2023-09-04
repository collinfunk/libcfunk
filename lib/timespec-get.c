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

#include <sys/time.h>
#include <time.h>

/* Fills the timespec struct pointed to by TS with the time since the epoch
   specified by base. When called with TIME_UTC the time stored in TS is
   represented in seconds and nanoseconds since the UNIX epoch. */
int
timespec_get (struct timespec *ts, int base)
{
  /* Only support TIME_UTC. */
  if (base != TIME_UTC)
    return 0;

    /* POSIX Issue 5 Realtime Extension. */
#if HAVE_CLOCK_GETTIME && defined(CLOCK_REALTIME)
  /* I don't think this can ever fail? Might be pointless to check. */
  return clock_gettime (CLOCK_REALTIME, ts) < 0 ? 0 : base;
#elif HAVE_GETTIMEOFDAY
  struct timeval tv;

  /* TODO: Don't think this can fail either. */
  if (gettimeofday (&tv, NULL) < 0)
    return 0;

  /* Convert timeval to timespec. */
  ts->tv_sec = tv.tv_sec;
  ts->tv_nsec = tv.tv_usec * 1000;

  return base;
#else
#  error "timespec_get(3) not implemented for your system."
#endif
}
