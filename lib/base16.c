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

#include "base16.h"

/* RFC 4648 */
static const char base16_alphabet[16] = "0123456789ABCDEF";

/* Base16 without any bounds checking. The buffer pointed to by DEST_PTR should
   be atleast (SRC_LEN * 2) bytes. The result is not null-terminated. */
void
base16_encode_unsafe (const void *src_ptr, size_t src_len, void *dest_ptr)
{
  const unsigned char *src = (const unsigned char *) src_ptr;
  char *dest = (char *) dest_ptr;
  while (src_len)
    {
      *dest++ = base16_alphabet[(src[0] / 16) & 15];
      *dest++ = base16_alphabet[(src[0] & 15)];
      --src_len;
      ++src;
    }
}

void
base16_encode (const void *src_ptr, size_t src_len, void *dest_ptr,
               size_t dest_len)
{
  const unsigned char *src = (const unsigned char *) src_ptr;
  char *dest = (char *) dest_ptr;

  while (src_len > 0 && dest_len > 0)
    {
      *dest++ = base16_alphabet[(src[0] / 16) & 15];
      if (!--dest_len)
        break;
      *dest++ = base16_alphabet[(src[0] & 15)];
      if (!--dest_len)
        break;
      --src_len;
      ++src;
    }

  if (dest_len > 0)
    *dest = '\0';
}

#if 0
int
main (void)
{
  char str[30];
  char buffer[30];

  memset (str, 0, sizeof (str));
  memset (buffer, 0, sizeof (buffer));
  strcpy (str, "Hello ghi xyz");

  base16_encode (str, strlen (str), buffer, sizeof (buffer));

  printf ("%s\n", buffer);

  return 0;
}
#endif
