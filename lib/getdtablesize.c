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
#include <stdio.h>
#include <unistd.h>

#if HAVE_SYS_RESOURCE_H
#  include <sys/resource.h>
/* Make sure these are defined. These are often RLIM_INFINITY anyways. */
#  ifndef RLIM_SAVED_MAX
#    define RLIM_SAVED_MAX RLIM_INFINITY
#  endif
#  ifndef RLIM_SAVED_CUR
#    define RLIM_SAVED_CUR RLIM_INFINITY
#  endif
#endif

int
getdtablesize (void)
{
#if HAVE_GETRLIMIT
  struct rlimit rlim;

  /* Make sure getrlimit returns an actual limit. */
  if (getrlimit (RLIMIT_NOFILE, &rlim) == 0 && rlim.rlim_cur <= INT_MAX
      && rlim.rlim_cur != RLIM_SAVED_MAX && rlim.rlim_cur != RLIM_SAVED_CUR)
    return rlim.rlim_cur;
#endif

#if HAVE_SYSCONF && defined(_SC_OPEN_MAX)
  long int sysconf_open_max = sysconf (_SC_OPEN_MAX);

  /* Ensure that the result fits in a signed integer. */
  if (sysconf_open_max >= 0 && sysconf_open_max <= INT_MAX)
    return sysconf_open_max;
#endif

#if HAVE__GETMAXSTDIO
  int max_stdio = _getmaxstdio ();
  if (max_stdio >= 0)
    return max_stdio;
#endif

  return INT_MAX;
}
