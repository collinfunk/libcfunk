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

#include <stddef.h>
#include <stdint.h>

#include "unicode.h"

int
utf8_mblen (const uint8_t *s, size_t n)
{
  if (s != NULL && n > 0)
    {
      if (s[0] == 0x00U)
        return 0;
      if (s[0] < 0x80U)
        return 1;
      if (s[0] >= 0xc2U)
        {
          if (s[0] < 0xe0U)
            {
              if (n >= 2 && s[1] >= 0x80U && s[1] <= 0xbfU)
                return 2;
            }
          else if (s[0] < 0xf0U)
            {
              if (n >= 3)
                {
                  if (s[0] < 0xe1U)
                    {
                      if ((s[1] >= 0xa0U && s[1] <= 0xbfU)
                          && (s[2] >= 0x80U && s[2] <= 0xbfU))
                        return 3;
                    }
                  else if (s[0] <= 0xecU)
                    {
                      if ((s[1] >= 0x80U && s[1] <= 0xbfU)
                          && (s[2] >= 0x80U && s[2] <= 0xbfU))
                        return 3;
                    }
                  else if (s[0] == 0xedU)
                    {
                      if ((s[1] >= 0x80U && s[1] <= 0x9fU)
                          && (s[2] >= 0x80U && s[2] <= 0xbfU))
                        return 3;
                    }
                  else
                    {
                      if ((s[1] >= 0x80U && s[1] <= 0xbfU)
                          && (s[2] >= 0x80U && s[2] <= 0xbfU))
                        return 3;
                    }
                }
            }
          else if (s[0] <= 0xf4U)
            {
              if (n >= 4)
                {
                  if (s[0] < 0xf1U)
                    {
                      if ((s[1] >= 0x90U && s[1] <= 0xbfU)
                          && (s[2] >= 0x80U && s[2] <= 0xbfU)
                          && (s[3] >= 0x80U && s[3] <= 0xbfU))
                        return 4;
                    }
                  else if (s[0] == 0xf4U)
                    {
                      if ((s[1] >= 0x80U && s[1] <= 0x8fU)
                          && (s[2] >= 0x80U && s[2] <= 0xbfU)
                          && (s[3] >= 0x80U && s[3] <= 0xbfU))
                        return 4;
                    }
                  else
                    {
                      if ((s[1] >= 0x80U && s[1] <= 0xbfU)
                          && (s[2] >= 0x80U && s[2] <= 0xbfU)
                          && (s[3] >= 0x80U && s[3] <= 0xbfU))
                        return 4;
                    }
                }
            }
        }
    }
  return -1;
}
