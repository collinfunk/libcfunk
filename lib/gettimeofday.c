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

#include <errno.h>
#include <time.h>

#if HAVE_WINDOWS_H
#  include <windows.h>
#endif

/* https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getsystemtimeasfiletime */
/* https://learn.microsoft.com/en-us/windows/win32/api/minwinbase/ns-minwinbase-filetime */
int
gettimeofday (struct timeval *tp, void *tzp)
#undef gettimeofday
{
#if HAVE_WINDOWS_H
  {
    FILETIME current_time;
    unsigned long long int value;

    GetSystemTimePreciseAsFileTime (&current_time);

    /* 100-nanosecond intervals since January 1, 1601 UTC. */
    value = ((unsigned long long int) current_time.dwHighDateTime << 32)
            | ((unsigned long long int) current_time.dwLowDateTime);

    /* 134774 days between January 1, 1601 and January 1, 1970. */
    value -= 116444736000000000ULL;
    tp->tv_sec = value / 10000000ULL;
    tp->tv_usec = value % 10000000ULL;

    return 0;
  }
#elif HAVE_TIME
  {
    time_t seconds = time (NULL);
    if (seconds == (time_t) -1)
      return -1;
    else
      {
        tp->tv_sec = seconds;
        tp->tv_usec = 0;
        return 0;
      }
  }
#else
  errno = ENOSYS;
  return -1;
#endif
}
