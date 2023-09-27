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
#include <limits.h>
#include <stddef.h>
#include <string.h>

/* Don't call ourselves. */
#undef strerror_r

/* Use the POSIX compatible strerror_r provided by glibc. */
#if HAVE___XPG_STRERROR_R
extern int __xpg_strerror_r (int errnum, char *buffer, size_t buffer_len);
#endif

int
_libcfunk_strerror_r (int errnum, char *buffer, size_t buffer_len)
{
#if HAVE___XPG_STRERROR_R
  int return_value = __xpg_strerror_r (errnum, buffer, buffer_len);
  if (return_value == 0)
    return 0;
  else
    return errno;
#elif HAVE_STRERROR_S
  int return_val;

  /* strerror_s takes an int, not size_t. */
  if (buffer_len > INT_MAX)
    return ERANGE;

  return_val = strerror_s (buffer, buffer_len, errnum);
  if (return_val == 0)
    return 0;
  else
    return errno;
#else
#  error "No thread-safe implementation of strerror_r for your system."
#endif
}
