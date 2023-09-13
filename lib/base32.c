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

#include <stdbool.h>
#include <stddef.h>

#include "base32.h"

/* RFC 4648 */
static const char base32_alphabet[32] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";

/* Don't assume that char is signed. */
static const signed char base32_decode_table[256]
    = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 26, 27, 28, 29,
        30, 31, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  1,  2,  3,  4,  5,  6,
        7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
        25, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1 };

/* Base32 without any bounds checking or padding. This function requires that
   SRC_LEN is divisible by 5 without a remainder. It also requires that the
   buffer pointed to by DEST_PTR has a size >= ((SRC_LEN / 5) * 8). The
   result is not null-terminated.
 */
void
base32_encode_unsafe (const void *src_ptr, size_t src_len, void *dest_ptr)
{
  const unsigned char *src = (const unsigned char *) src_ptr;
  char *dest = (char *) dest_ptr;
  while (src_len)
    {
      *dest++ = base32_alphabet[(src[0] >> 3) & 31];
      *dest++ = base32_alphabet[((src[0] << 2) + (src[1] >> 6)) & 31];
      *dest++ = base32_alphabet[(src[1] >> 1) & 31];
      *dest++ = base32_alphabet[((src[1] << 4) + (src[2] >> 4)) & 31];
      *dest++ = base32_alphabet[((src[2] << 1) + (src[3] >> 7)) & 31];
      *dest++ = base32_alphabet[(src[3] >> 2) & 31];
      *dest++ = base32_alphabet[((src[3] << 3) + (src[4] >> 5)) & 31];
      *dest++ = base32_alphabet[src[4] & 31];
      src += 5;
      src_len -= 5;
    }
}

void
base32_encode (const void *src_ptr, size_t src_len, void *dest_ptr,
               size_t dest_len)
{
  const unsigned char *src = (const unsigned char *) src_ptr;
  char *dest = (char *) dest_ptr;

  while (src_len && dest_len)
    {
      *dest++ = base32_alphabet[(src[0] >> 3) & 31];
      if (!--dest_len)
        return;
      if (--src_len)
        *dest++ = base32_alphabet[((src[0] << 2) + (src[1] >> 6)) & 31];
      else
        {
          *dest++ = base32_alphabet[(src[0] << 2) & 31];
          if (!--dest_len)
            return;
          *dest++ = '=';
          if (!--dest_len)
            return;
          *dest++ = '=';
          if (!--dest_len)
            return;
          *dest++ = '=';
          if (!--dest_len)
            return;
          *dest++ = '=';
          if (!--dest_len)
            return;
          *dest++ = '=';
          if (!--dest_len)
            return;
          *dest++ = '=';
          if (!--dest_len)
            return;
          break;
        }
      if (!--dest_len)
        return;
      *dest++ = base32_alphabet[(src[1] >> 1) & 31];
      if (!--dest_len)
        return;
      if (--src_len)
        *dest++ = base32_alphabet[((src[1] << 4) + (src[2] >> 4)) & 31];
      else
        {
          *dest++ = base32_alphabet[(src[1] << 4) & 31];
          if (!--dest_len)
            return;
          *dest++ = '=';
          if (!--dest_len)
            return;
          *dest++ = '=';
          if (!--dest_len)
            return;
          *dest++ = '=';
          if (!--dest_len)
            return;
          *dest++ = '=';
          if (!--dest_len)
            return;
          break;
        }
      if (!--dest_len)
        return;
      if (--src_len)
        *dest++ = base32_alphabet[((src[2] << 1) + (src[3] >> 7)) & 31];
      else
        {
          *dest++ = base32_alphabet[(src[2] << 1) & 31];
          if (!--dest_len)
            return;
          *dest++ = '=';
          if (!--dest_len)
            return;
          *dest++ = '=';
          if (!--dest_len)
            return;
          *dest++ = '=';
          if (!--dest_len)
            return;
          break;
        }
      if (!--dest_len)
        break;
      *dest++ = base32_alphabet[(src[3] >> 2) & 31];
      if (!--dest_len)
        return;
      if (--src_len)
        *dest++ = base32_alphabet[((src[3] << 3) + (src[4] >> 5)) & 31];
      else
        {
          *dest++ = base32_alphabet[(src[3] << 3) & 31];
          if (!--dest_len)
            return;
          *dest++ = '=';
          if (!--dest_len)
            return;
          break;
        }
      if (!--dest_len)
        return;
      *dest++ = base32_alphabet[src[4] & 31];
      if (!--dest_len)
        return;
      if (src_len)
        --src_len;
      if (src_len)
        src += 5;
    }

  if (dest_len)
    *dest = '\0';
}

bool
isbase32 (char ch)
{
  unsigned char idx = (unsigned char) ch;

  return base32_decode_table[idx] >= 0;
}

#if 0
int
main (void)
{
  char str[30];
  char buffer[30];

  memset (str, 0, sizeof (str));
  memset (buffer, 0, sizeof (buffer));
  strcpy (str, "Hello   asdasfa");

  base32_encode_unsafe (str, strlen (str), buffer);

  printf ("%s\n", buffer);

  return 0;
}
#endif
