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

#include <sys/resource.h>

#include <errno.h>
#include <limits.h>
#include <stdarg.h>
#include <ulimit.h>

/* Implementation of 'ulimit' which assumes a working version of 'getrlimit'
   and 'setrlimit'. */
long int
ulimit (int cmd, ...)
#undef ulimit
{
  struct rlimit rlim;

  switch (cmd)
    {
    case UL_GETFSIZE:
      if (getrlimit (RLIMIT_FSIZE, &rlim) == 0)
        return (rlim.rlim_cur == RLIM_INFINITY) ? LONG_MAX
                                                : rlim.rlim_cur / 512;
      else
        return -1L;
    case UL_SETFSIZE:
      {
        va_list ap;
        int result;
        long int new_limit;

        va_start (ap, cmd);
        new_limit = va_arg (ap, long int);
        va_end (ap);

        if ((rlim_t) new_limit > (RLIM_INFINITY / 512))
          {
            rlim.rlim_cur = RLIM_INFINITY;
            rlim.rlim_max = RLIM_INFINITY;
            new_limit = LONG_MAX;
          }
        else
          {
            rlim.rlim_cur = (rlim_t) new_limit * 512;
            rlim.rlim_max = (rlim_t) new_limit * 512;
          }

        result = setrlimit (RLIMIT_FSIZE, &rlim);
        return (result == 0) ? new_limit : -1L;
      }
    default:
      errno = EINVAL;
      return -1L;
    }
}
