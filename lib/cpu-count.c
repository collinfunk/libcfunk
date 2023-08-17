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

#include <limits.h>
#include <unistd.h>

#include "cpu-count.h"

#if HAVE_SYS_SYSCTL_H
#  include <sys/sysctl.h>
#endif

#ifdef _WIN32
#  if HAVE_SYSINFOAPI_H
#    include <sysinfoapi.h>
#    include <windows.h>
#  else
#    error "Your system does not have <sysinfoapi.h>"
#  endif
#else
/* TODO: These are not portable. They only work on Linux and FreeBSD. Maybe
   a few others? */
#  ifndef _SC_NPROCESSORS_ONLN
#    error "cpu_count_avaliable () is unsupported."
#  endif

#  ifndef _SC_NPROCESSORS_CONF
#    error "cpu_count_total () is unsupported."
#  endif
#endif

long int
cpu_count_available (void)
{
#ifdef _WIN32
  SYSTEM_INFO system_info;

  /* FIXME: Same as total. */
  GetSystemInfo (&system_info);
  return system_info.dwNumberOfProcessors;
#elif HAVE_SYS_SYSCTL_H && defined(HW_NCPU)
  int mib[2] = { CTL_HW, CTL_NPROC };
  int cpu_count;
  size_t len;

  /* FIXME: Same as total. */
  if (sysctl (mib, 2, &cpu_count, &len, NULL, 0) < 0)
    return 1;

  return cpu_count > 0 ? cpu_count : 1;
#else
  long int cpu_count = sysconf (_SC_NPROCESSORS_ONLN);

  return cpu_count < 0 ? 1 : cpu_count;
#endif
  /* We have to have 1... */
  return 1;
}

long int
cpu_count_total (void)
{
#ifdef _WIN32
  SYSTEM_INFO system_info;

  GetSystemInfo (&system_info);
  return system_info.dwNumberOfProcessors;
#elif HAVE_SYS_SYSCTL_H && defined(HW_NCPU)
  int mib[2] = { CTL_HW, HW_NCPU };
  int cpu_count;
  size_t len;

  if (sysctl (mib, 2, &cpu_count, &len, NULL, 0) < 0)
    return 1;

  return cpu_count > 0 ? cpu_count : 1;
#else
  long int cpu_count = sysconf (_SC_NPROCESSORS_CONF);

  return cpu_count < 0 ? 1 : cpu_count;
#endif
  /* We have to have 1... */
  return 1;
}
