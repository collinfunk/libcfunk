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

#include <sys/times.h>

#include <time.h>

#if HAVE_WINDOWS_H
#  include <windows.h>
#else
#  error "No implementation of 'times' for your system."
#endif

#ifndef CLOCKS_PER_SEC
#  ifdef CLK_TCK
#    define CLOCKS_PER_SEC CLK_TCK
#  else
#    define CLOCKS_PER_SEC 1000
#  endif
#endif

/* https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getprocesstimes */
clock_t
times (struct tms *buffer)
{
  FILETIME creation_time, exit_time, kernel_time, user_time;

  /* Not sure how frequently this will fail... */
  if (!GetProcessTimes (GetCurrentProcess (), &creation_time, &exit_time,
                        &kernel_time, &user_time))
    return (clock_t) -1;

  /* Time spent executing user instructions. */
  buffer->tms_utime = (unsigned long long int) user_time.dwHighDateTime << 32;
  buffer->tms_utime += (unsigned long long int) user_time.dwLowDateTime;
  buffer->tms_utime = buffer->tms_utime * CLOCKS_PER_SEC / 10000000;

  /* Time spent executing by the system on behalf of the current process. */
  buffer->tms_stime = (unsigned long long int) kernel_time.dwHighDateTime
                      << 32;
  buffer->tms_stime += (unsigned long long int) kernel_time.dwLowDateTime;
  buffer->tms_stime = buffer->tms_stime * CLOCKS_PER_SEC / 10000000;

  /* Child process times. */
  buffer->tms_cutime = 0;
  buffer->tms_cstime = 0;

  return clock ();
}
