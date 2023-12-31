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

#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

static const char *inet_ntop4 (const void *restrict src, char *restrict dst,
                               socklen_t size);

/* Convert a numeric address to a text string representation. */
const char *
inet_ntop (int af, const void *restrict src, char *restrict dst,
           socklen_t size)
{
  switch (af)
    {
    case AF_INET:
      return inet_ntop4 (src, dst, size);
      /* case AF_INET6: TODO */
    default:
      errno = EAFNOSUPPORT;
      return NULL;
    }
}

static const char *
inet_ntop4 (const void *restrict src, char *restrict dst, socklen_t size)
{
  char temp[sizeof ("255.255.255.255")];
  int result;
  const unsigned char *ptr = (const unsigned char *) src;

  result = snprintf (temp, sizeof (temp), "%u.%u.%u.%u", ptr[0], ptr[1],
                     ptr[2], ptr[3]);
  if (result < 0)
    return NULL;

  /* Ignore '-Wsign-compare', we know result >= 0. */
  if ((socklen_t) result > size)
    {
      errno = ENOSPC;
      return NULL;
    }

  return memcpy (dst, temp, result + 1);
}
