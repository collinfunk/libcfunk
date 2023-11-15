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

#if HAVE_WINDOWS_H
#  include <stdio.h>
#  include <windows.h>
#endif

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

#ifndef OPEN_MAX
#  define OPEN_MAX INT_MAX
#endif

int
getdtablesize (void)
#undef getdtablesize
{
#if HAVE_GETRLIMIT
  {
    struct rlimit rlim;

    /* Make sure getrlimit returns an actual limit. */
    if (getrlimit (RLIMIT_NOFILE, &rlim) == 0 && rlim.rlim_cur <= INT_MAX
        && rlim.rlim_cur != RLIM_SAVED_MAX && rlim.rlim_cur != RLIM_SAVED_CUR)
      return (int) rlim.rlim_cur;
  }
#endif

#if HAVE_SYSCONF && defined(_SC_OPEN_MAX)
  {
    long int sysconf_open_max = sysconf (_SC_OPEN_MAX);

    /* Ensure that the result fits in a signed integer. */
    if (sysconf_open_max >= 0 && sysconf_open_max <= INT_MAX)
      return (int) sysconf_open_max;
  }
#endif

  /* The page for '_setmaxstdio' states that the MSVC run-time currently
     supports 8,192 open files. By default 512 can be used for stream I/O. This
     number can be increased to the maximum supported by the OS through
     '_setmaxstdio'. The limit is a hard cap defined by the MSVC run-time
     version and cannot be modified by the user (wine-8.20 seems to only
     support 2048 for example). Therefore, we figure out the maximum number of
     open files by setting the maximum number of open streams and then caching
     the result. The following code assumes an upper limit of 8,192 and that
     any supported limit will be a power of 2. Before returning we restore the
     maximum number of streams incase the functions cause memory allocation.
     Not sure how to check through wine... */
  /* https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/setmaxstdio?view=msvc-170 */
  /* https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/getmaxstdio?view=msvc-170 */
#if HAVE_WINDOWS_H
  {
    static int cached_dtablesize = -1;
    if (cached_dtablesize == -1)
      {
        int max_stdio_floor = _getmaxstdio ();
        int max_stdio_ceiling = 8192;
        if (max_stdio_ceiling <= max_stdio_floor)
          max_stdio_ceiling = max_stdio_floor;
        else
          {
            for (;;)
              {
                int result = _setmaxstdio (max_stdio_ceiling);
                if (result != -1)
                  {
                    (void) _setmaxstdio (max_stdio_floor);
                    break;
                  }
                else
                  {
                    max_stdio_ceiling = max_stdio_ceiling / 2;
                    if (max_stdio_ceiling <= max_stdio_floor)
                      {
                        max_stdio_ceiling = max_stdio_floor;
                        break;
                      }
                  }
              }
          }
        cached_dtablesize = max_stdio_ceiling;
      }
    return cached_dtablesize;
  }
#endif

  return OPEN_MAX;
}
