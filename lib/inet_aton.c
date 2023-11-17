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

#include <sys/socket.h>

#include <arpa/inet.h>
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>

/* Convert an IPv4 dotted decimal notation string to an integer IPv4
   address. */
int
inet_aton (const char *cp, struct in_addr *addr)
#undef inet_aton
{
  uint32_t value;
  int digit_seen;
  uint8_t parts[4];
  int num_parts = 0;

  for (;; ++cp)
    {
      int base = 10;
      value = 0;
      digit_seen = 0;
      if (!(*cp >= '0' && *cp <= '9'))
        return 0;
      if (*cp == '0')
        {
          if (cp[1] == 'x' || cp[1] == 'X')
            {
              cp += 2;
              base = 16;
            }
          else
            {
              cp++;
              base = 8;
              digit_seen = 1;
            }
        }
      switch (base)
        {
        case 8:
          for (;;)
            {
              if (*cp >= '0' && *cp <= '8')
                {
                  if (value > (UINT32_MAX >> 3))
                    return 0;
                  value = value << 3;
                  if (value > (UINT32_MAX - (*cp - '0')))
                    return 0;
                  value = value + (*cp++ - '0');
                  digit_seen = 1;
                }
              else
                break;
            }
          break;
        case 10:
          for (;;)
            {
              if (*cp >= '0' && *cp <= '9')
                {
                  if (value > (UINT32_MAX / 10))
                    return 0;
                  value = value * 10;
                  if (value > (UINT32_MAX - (*cp - '0')))
                    return 0;
                  value = value + (*cp++ - '0');
                  digit_seen = 1;
                }
              else
                break;
            }
          break;
        case 16:
          for (;;)
            {
              if (*cp >= '0' && *cp <= '9')
                {
                  if (value > (UINT32_MAX >> 4))
                    return 0;
                  value = value << 4;
                  if (value > (UINT32_MAX - (*cp - '0')))
                    return 0;
                  value = value + (*cp++ - '0');
                  digit_seen = 1;
                }
              else if (*cp >= 'A' && *cp <= 'F')
                {
                  if (value > (UINT32_MAX >> 4))
                    return 0;
                  value = value << 4;
                  if (value > (UINT32_MAX - (*cp + 10 - 'A')))
                    return 0;
                  value = value + (*cp++ + 10 - 'A');
                  digit_seen = 1;
                }
              else if (*cp >= 'a' && *cp <= 'f')
                {
                  if (value > (UINT32_MAX >> 4))
                    return 0;
                  value = value << 4;
                  if (value > (UINT32_MAX - (*cp + 10 - 'a')))
                    return 0;
                  value = value + (*cp++ + 10 - 'a');
                  digit_seen = 1;
                }
              else
                break;
            }
          break;
        default:
          abort ();
        }
      if (*cp != '.')
        break;
      else
        {
          if (num_parts >= 3 || value > (uint32_t) 0xff)
            return 0;
          parts[num_parts++] = (uint8_t) value;
        }
    }

  if ((*cp != '\0'
       && (!isascii ((unsigned char) *cp) || !isspace ((unsigned char) *cp)))
      || !digit_seen)
    return 0;

  switch (num_parts)
    {
    case 0:
      break;
    case 1:
      if (value > (uint32_t) 0xffffffU)
        return 0;
      value |= (((uint32_t) parts[0]) << 24);
      break;
    case 2:
      if (value > (uint32_t) 0xffffU)
        return 0;
      value |= (((uint32_t) parts[0]) << 24) | (((uint32_t) parts[1]) << 16);
      break;
    case 3:
      if (value > (uint32_t) 0xffU)
        return 0;
      value |= (((uint32_t) parts[0]) << 24) | (((uint32_t) parts[1]) << 16)
               | (((uint32_t) parts[2]) << 8);
      break;
    default:
      abort ();
    }

  if (addr != NULL)
    addr->s_addr = htonl (value);
  return 1;
}
