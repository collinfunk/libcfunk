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

#include "base64.h"

/* RFC 4648 */
static const char base64_alphabet[64]
    = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

/* Base64 without any bounds checking or padding. This function requires that
   SRC_LEN is divisible by 3 without a remainder. It also requires that the
   buffer pointed to by DEST_PTR has a size >= ((SRC_LEN / 3) * 4). The
   result is not null-terminated.
 */
void
base64_encode_unsafe (const void *src_ptr, size_t src_len, void *dest_ptr)
{
  const unsigned char *src = (const unsigned char *) src_ptr;
  char *dest = (char *) dest_ptr;
  while (src_len)
    {
      *dest++ = base64_alphabet[(src[0] >> 2) & 63];
      *dest++ = base64_alphabet[((src[0] << 4) + (src[1] >> 4)) & 63];
      *dest++ = base64_alphabet[((src[1] << 2) + (src[2] >> 6)) & 63];
      *dest++ = base64_alphabet[src[2] & 63];
      src += 3;
      src_len -= 3;
    }
}

#if 0
int
main (void)
{
  char str[30];
  char buffer[30];

  memset (str, 0, sizeof (str));
  memset (buffer, 0, sizeof (buffer));
  strcpy (str, "Hello ");

  base64_encode_unsafe (str, strlen (str), buffer);

  printf ("%s\n", buffer);

  return 0;
}
#endif
