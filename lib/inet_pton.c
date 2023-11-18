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
#include <stdint.h>
#include <string.h>

static int inet_pton4 (const char *restrict src, void *restrict dst);

/* Convert a test string adress into its numeric binary representation. */
int
inet_pton (int af, const char *restrict src, void *restrict dst)
#undef inet_pton
{
  switch (af)
    {
    case AF_INET:
      return inet_pton4 (src, dst);
      /* case AF_INET6: TODO */
    default:
      errno = EAFNOSUPPORT;
      return -1;
    }
}

static int
inet_pton4 (const char *restrict src, void *restrict dst)
{
  uint8_t parts[4];
  int num_parts = 0;

  for (;; ++src)
    {
      if (*src >= '0' && *src <= '9')
        {
          uint8_t value = 0;
          do
            {
              if (value > (UINT8_MAX / 10))
                return 0;
              value = value * 10;
              if (value > (UINT8_MAX - (*src - '0')))
                return 0;
              value = value + (*src++ - '0');
            }
          while (*src >= '0' && *src <= '9');
          if (*src == '.')
            {
              if (num_parts < 3)
                parts[num_parts++] = value;
              else
                return 0;
            }
          else if (*src == '\0')
            {
              if (num_parts == 3)
                {
                  parts[num_parts++] = value;
                  memcpy (dst, parts, num_parts);
                  return 1;
                }
              else
                return 0;
            }
          else
            return 0;
        }
      else
        return 0;
    }
}
