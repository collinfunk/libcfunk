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
#include <string.h>

#include "bswap.h"
#include "circular-shift.h"
#include "sha1.h"

#if HAVE_OPENSSL_SHA_H

#  include <openssl/sha.h>

void
sha1_init (struct sha1_ctx *ctx)
{
  SHA1_Init (&ctx->ssl_ctx);
}

void
sha1_transform (struct sha1_ctx *ctx, const void *buffer)
{
  SHA1_Transform (&ctx->ssl_ctx, (const unsigned char *) buffer);
}

void
sha1_update (struct sha1_ctx *ctx, const void *buffer, size_t len)
{
  SHA1_Update (&ctx->ssl_ctx, buffer, len);
}

void
sha1_final (void *digest, struct sha1_ctx *ctx)
{
  SHA1_Final ((unsigned char *) digest, &ctx->ssl_ctx);
}

#else /* !HAVE_OPENSSL_SHA_H */

#  define F1(b, c, d) (((b) & (c)) | ((~(b)) & (d)))
#  define F2(b, c, d) ((b) ^ (c) ^ (d))
#  define F3(b, c, d) (((b) & (c)) | ((b) & (d)) | ((c) & (d)))
#  define F4(b, c, d) ((b) ^ (c) ^ (d))

#  define K1 0x5a827999UL
#  define K2 0x6ed9eba1UL
#  define K3 0x8f1bbcdcUL
#  define K4 0xca62c1d6UL

void
sha1_init (struct sha1_ctx *ctx)
{
  ctx->state[0] = 0x67452301UL;
  ctx->state[1] = 0xefcdab89UL;
  ctx->state[2] = 0x98badcfeUL;
  ctx->state[3] = 0x10325476UL;
  ctx->state[4] = 0xc3d2e1f0UL;
  ctx->count = 0;
}

void
sha1_transform (struct sha1_ctx *ctx, const void *buffer)
{
  uint32_t a, b, c, d, e, t, w[80];
  int i;

  for (i = 0; i < 16; ++i)
    w[i] = buff_get_be32 ((char *) buffer + i * 4);
  for (i = 16; i < 80; ++i)
    w[i] = rotl32 (w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);

  a = ctx->state[0];
  b = ctx->state[1];
  c = ctx->state[2];
  d = ctx->state[3];
  e = ctx->state[4];

  for (i = 0; i < 20; ++i)
    {
      t = rotl32 (a, 5) + F1 (b, c, d) + e + w[i] + K1;
      e = d;
      d = c;
      c = rotl32 (b, 30);
      b = a;
      a = t;
    }
  for (i = 20; i < 40; ++i)
    {
      t = rotl32 (a, 5) + F2 (b, c, d) + e + w[i] + K2;
      e = d;
      d = c;
      c = rotl32 (b, 30);
      b = a;
      a = t;
    }
  for (i = 40; i < 60; ++i)
    {
      t = rotl32 (a, 5) + F3 (b, c, d) + e + w[i] + K3;
      e = d;
      d = c;
      c = rotl32 (b, 30);
      b = a;
      a = t;
    }
  for (i = 60; i < 80; ++i)
    {
      t = rotl32 (a, 5) + F4 (b, c, d) + e + w[i] + K4;
      e = d;
      d = c;
      c = rotl32 (b, 30);
      b = a;
      a = t;
    }

  ctx->state[0] += a;
  ctx->state[1] += b;
  ctx->state[2] += c;
  ctx->state[3] += d;
  ctx->state[4] += e;
}

void
sha1_update (struct sha1_ctx *ctx, const void *buffer, size_t len)
{
  size_t have;

  /* No input. */
  if (len == 0)
    return;

  /* (Bit count / 8) mod blocksize */
  have = (ctx->count >> 3) & 63;

  /* Update the bit count. */
  ctx->count += (uint64_t) len << 3;

  /* Check if we have any bytes in the buffer. */
  if (have > 0)
    {
      size_t need = 64 - have;

      if (len >= need)
        {
          /* Process the bytes we have in the buffer first. */
          memcpy (&ctx->buffer[have], buffer, need);
          sha1_transform (ctx, ctx->buffer);
          len -= need;
          buffer = (char *) buffer + need;
        }
      else
        {
          /* We don't have enough input to fill a block so just save it. */
          memcpy (&ctx->buffer[have], buffer, len);
          return;
        }
    }

  /* Process as many blocks as possible. */
  while (len >= 64)
    {
      sha1_transform (ctx, buffer);
      len -= 64;
      buffer = (char *) buffer + 64;
    }

  /* Save any remaining bytes. */
  if (len > 0)
    memcpy (ctx->buffer, buffer, len);
}

void
sha1_final (void *digest, struct sha1_ctx *ctx)
{
  size_t padlen = (ctx->count >> 3) & 63;
  int i;

  ctx->buffer[padlen++] = 0x80;

  /* Check if we have enough free space for the 64-bit count. */
  if (padlen <= 56)
    memset (&ctx->buffer[padlen], 0, 56 - padlen);
  else
    {
      /* Fill all unused bytes in the buffer with 0's and process the block. */
      memset (&ctx->buffer[padlen], 0, 64 - padlen);
      sha1_transform (ctx, ctx->buffer);
      memset (ctx->buffer, 0, 56);
    }

  /* Append the count to the end of the block and process it. */
  buff_put_be64 (ctx->buffer + 56, ctx->count);
  sha1_transform (ctx, ctx->buffer);

  for (i = 0; i < 5; ++i)
    buff_put_be32 ((char *) digest + i * 4, ctx->state[i]);
  explicit_bzero (ctx, sizeof (struct sha1_ctx));
}

#endif /* HAVE_OPENSSL_SHA_H */
