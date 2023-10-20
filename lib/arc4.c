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

#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "arc4.h"

#if HAVE_OPENSSL_RC4_H
#  include <openssl/rc4.h>

void
arc4_set_key (struct arc4_ctx *ctx, const void *key_ptr, size_t key_len)
{
  if (key_len > INT_MAX)
    abort ();
  RC4_set_key (&ctx->ssl_ctx, (int) key_len, (const unsigned char *) key_ptr);
}

void
arc4_crypt (struct arc4_ctx *ctx, size_t len, const void *input_ptr,
            void *output_ptr)
{
  if (len > ULONG_MAX)
    abort ();
  RC4 (&ctx->ssl_ctx, (unsigned long int) len,
       (const unsigned char *) input_ptr, (unsigned char *) output_ptr);
}

#else /* !HAVE_OPENSSL_RC4_H */

void
arc4_set_key (struct arc4_ctx *ctx, const void *key_ptr, size_t key_len)
{
  size_t i, j, k;
  const uint8_t *key = (const uint8_t *) key_ptr;

  for (i = 0; i < 256; ++i)
    ctx->data[i] = i;
  for (i = j = k = 0; i < 256; ++i)
    {
      uint8_t temp;
      j = (j + ctx->data[i] + key[k]) & 0xff;
      temp = ctx->data[i];
      ctx->data[i] = ctx->data[j];
      ctx->data[j] = temp;
      if (++k >= key_len)
        k = 0;
    }
  ctx->x = ctx->y = 0;
}

void
arc4_crypt (struct arc4_ctx *ctx, size_t len, const void *input_ptr,
            void *output_ptr)
{
  size_t i;
  uint8_t *output = (uint8_t *) output_ptr;
  const uint8_t *input = (const uint8_t *) input_ptr;

  for (i = 0; i < len; ++i)
    {
      uint8_t temp;
      ctx->x = (ctx->x + 1) & 0xff;
      ctx->y = (ctx->y + ctx->data[ctx->x]) & 0xff;
      temp = ctx->data[ctx->x];
      ctx->data[ctx->x] = ctx->data[ctx->y];
      ctx->data[ctx->y] = temp;
      output[i] = input[i]
                  ^ ctx->data[(ctx->data[ctx->x] + ctx->data[ctx->y]) & 0xff];
    }
}

#endif /* HAVE_OPENSSL_RC4_H */
