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

#include <stddef.h>
#include <stdint.h>

#include "unicode.h"

/* See Unicode Chapter 3 Table 3-6 and Table 3-7. */
int
utf8_mbtowc (uint32_t *pwc, const uint8_t *s, size_t n)
{
  if (s[0] < 0x80)
    {
      *pwc = s[0];
      return 1;
    }
  else if (s[0] > 0xc1)
    {
      if (s[0] < 0xe0)
        {
          if (n > 1)
            {
              if ((s[1] ^ 0x80) < 0x40)
                {
                  *pwc = ((uint32_t) (s[0] & 0x1f) << 6)
                         | ((uint32_t) (s[1] ^ 0x80));
                  return 2;
                }
            }
          else
            {
              *pwc = 0xfffd;
              return -2;
            }
        }
      else if (s[0] < 0xf0)
        {
          if (n > 1)
            {
              if ((s[1] ^ 0x80) < 0x40 && (s[0] > 0xe0 || s[1] > 0x9f)
                  && (s[0] != 0xed || s[1] < 0xa0))
                {
                  if (n > 2)
                    {
                      if ((s[2] ^ 0x80) < 0x40)
                        {
                          *pwc = ((uint32_t) (s[0] & 0x0f) << 12)
                                 | ((uint32_t) (s[1] ^ 0x80) << 6)
                                 | ((uint32_t) (s[2] ^ 0x80));
                          return 3;
                        }
                    }
                  else
                    {
                      *pwc = 0xfffd;
                      return -2;
                    }
                }
            }
          else
            {
              *pwc = 0xfffd;
              return -2;
            }
        }
      else if (s[0] < 0xf5)
        {
          if (n > 1)
            {
              if ((s[1] ^ 0x80) < 0x40 && (s[0] > 0xf0 || s[1] > 0x8f)
                  && (s[0] < 0xf4 || s[1] < 0x90))
                {
                  if (n > 2)
                    {
                      if ((s[2] ^ 0x80) < 0x40)
                        {
                          if (n > 3)
                            {
                              if ((s[3] ^ 0x80) < 0x40)
                                {
                                  *pwc = ((uint32_t) (s[0] & 0x07) << 18)
                                         | ((uint32_t) (s[1] ^ 0x80) << 12)
                                         | ((uint32_t) (s[2] ^ 0x80) << 6)
                                         | ((uint32_t) (s[3] ^ 0x80));
                                  return 4;
                                }
                            }
                          else
                            {
                              *pwc = 0xfffd;
                              return -2;
                            }
                        }
                    }
                  else
                    {
                      *pwc = 0xfffd;
                      return -2;
                    }
                }
            }
          else
            {
              *pwc = 0xfffd;
              return -2;
            }
        }
    }
  *pwc = 0xfffd;
  return -1;
}
