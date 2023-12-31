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

#include <ctype.h>
#include <stddef.h>
#include <string.h>

/* Compare two strings while ignoring case. Compares until the NUL
   byte or until SIZE bytes are compared. */
int
strncasecmp (const char *str1, const char *str2, size_t size)
{
  const unsigned char *p1 = (const unsigned char *) str1;
  const unsigned char *p2 = (const unsigned char *) str2;
  unsigned char c1, c2;

  /* If size is 0, protect against undefined behavior caused by c1 and c2 being
     uninitialized. */
  if (size == 0)
    return 0;

  /* We know size >= 1. Don't check it here. */
  for (;; ++p1, ++p2)
    {
      c1 = tolower (*p1);
      c2 = tolower (*p2);

      /* Prefix decrement will never wrap since size >= 1. */
      if (--size == 0)
        break;
      if (c1 == '\0')
        break;
      if (c1 != c2)
        break;
    }

  return c1 - c2;
}
