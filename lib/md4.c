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
#include "md4.h"

#if HAVE_OPENSSL_MD4_H

#  include <openssl/md4.h>

void
md4_init (struct md4_ctx *ctx)
{
  MD4_Init (&ctx->ssl_ctx);
}

void
md4_transform (struct md4_ctx *ctx, const void *buffer)
{
  MD4_Transform (&ctx->ssl_ctx, (const unsigned char *) buffer);
}

void
md4_update (struct md4_ctx *ctx, const void *buffer, size_t len)
{
  MD4_Update (&ctx->ssl_ctx, buffer, len);
}

void
md4_final (void *digest, struct md4_ctx *ctx)
{
  MD4_Final ((unsigned char *) digest, &ctx->ssl_ctx);
}

#else /* !HAVE_OPENSSL_MD4_H */

#  define F1(b, c, d) (((b) & (c)) | ((~(b)) & (d)))
#  define F2(b, c, d) (((b) & (c)) | ((b) & (d)) | ((c) & (d)))
#  define F3(b, c, d) ((b) ^ (c) ^ (d))

#  define MD4_STEP(fx, a, b, c, d, x, s)                                      \
    do                                                                        \
      {                                                                       \
        (a) += fx ((b), (c), (d)) + (x);                                      \
        (a) = rotl32 ((a), (s));                                              \
      }                                                                       \
    while (0)

void
md4_init (struct md4_ctx *ctx)
{
  ctx->state[0] = UINT32_C (0x67452301);
  ctx->state[1] = UINT32_C (0xefcdab89);
  ctx->state[2] = UINT32_C (0x98badcfe);
  ctx->state[3] = UINT32_C (0x10325476);
  ctx->count = UINT64_C (0);
}

void
md4_transform (struct md4_ctx *ctx, const void *buffer)
{
  uint32_t a, b, c, d, w[16];
  int i;

  for (i = 0; i < 16; ++i)
    w[i] = buff_get_le32 ((char *) buffer + i * 4);

  a = ctx->state[0];
  b = ctx->state[1];
  c = ctx->state[2];
  d = ctx->state[3];

  MD4_STEP (F1, a, b, c, d, w[0], 3);
  MD4_STEP (F1, d, a, b, c, w[1], 7);
  MD4_STEP (F1, c, d, a, b, w[2], 11);
  MD4_STEP (F1, b, c, d, a, w[3], 19);
  MD4_STEP (F1, a, b, c, d, w[4], 3);
  MD4_STEP (F1, d, a, b, c, w[5], 7);
  MD4_STEP (F1, c, d, a, b, w[6], 11);
  MD4_STEP (F1, b, c, d, a, w[7], 19);
  MD4_STEP (F1, a, b, c, d, w[8], 3);
  MD4_STEP (F1, d, a, b, c, w[9], 7);
  MD4_STEP (F1, c, d, a, b, w[10], 11);
  MD4_STEP (F1, b, c, d, a, w[11], 19);
  MD4_STEP (F1, a, b, c, d, w[12], 3);
  MD4_STEP (F1, d, a, b, c, w[13], 7);
  MD4_STEP (F1, c, d, a, b, w[14], 11);
  MD4_STEP (F1, b, c, d, a, w[15], 19);

  MD4_STEP (F2, a, b, c, d, w[0] + UINT32_C (0x5a827999), 3);
  MD4_STEP (F2, d, a, b, c, w[4] + UINT32_C (0x5a827999), 5);
  MD4_STEP (F2, c, d, a, b, w[8] + UINT32_C (0x5a827999), 9);
  MD4_STEP (F2, b, c, d, a, w[12] + UINT32_C (0x5a827999), 13);
  MD4_STEP (F2, a, b, c, d, w[1] + UINT32_C (0x5a827999), 3);
  MD4_STEP (F2, d, a, b, c, w[5] + UINT32_C (0x5a827999), 5);
  MD4_STEP (F2, c, d, a, b, w[9] + UINT32_C (0x5a827999), 9);
  MD4_STEP (F2, b, c, d, a, w[13] + UINT32_C (0x5a827999), 13);
  MD4_STEP (F2, a, b, c, d, w[2] + UINT32_C (0x5a827999), 3);
  MD4_STEP (F2, d, a, b, c, w[6] + UINT32_C (0x5a827999), 5);
  MD4_STEP (F2, c, d, a, b, w[10] + UINT32_C (0x5a827999), 9);
  MD4_STEP (F2, b, c, d, a, w[14] + UINT32_C (0x5a827999), 13);
  MD4_STEP (F2, a, b, c, d, w[3] + UINT32_C (0x5a827999), 3);
  MD4_STEP (F2, d, a, b, c, w[7] + UINT32_C (0x5a827999), 5);
  MD4_STEP (F2, c, d, a, b, w[11] + UINT32_C (0x5a827999), 9);
  MD4_STEP (F2, b, c, d, a, w[15] + UINT32_C (0x5a827999), 13);

  MD4_STEP (F3, a, b, c, d, w[0] + UINT32_C (0x6ed9eba1), 3);
  MD4_STEP (F3, d, a, b, c, w[8] + UINT32_C (0x6ed9eba1), 9);
  MD4_STEP (F3, c, d, a, b, w[4] + UINT32_C (0x6ed9eba1), 11);
  MD4_STEP (F3, b, c, d, a, w[12] + UINT32_C (0x6ed9eba1), 15);
  MD4_STEP (F3, a, b, c, d, w[2] + UINT32_C (0x6ed9eba1), 3);
  MD4_STEP (F3, d, a, b, c, w[10] + UINT32_C (0x6ed9eba1), 9);
  MD4_STEP (F3, c, d, a, b, w[6] + UINT32_C (0x6ed9eba1), 11);
  MD4_STEP (F3, b, c, d, a, w[14] + UINT32_C (0x6ed9eba1), 15);
  MD4_STEP (F3, a, b, c, d, w[1] + UINT32_C (0x6ed9eba1), 3);
  MD4_STEP (F3, d, a, b, c, w[9] + UINT32_C (0x6ed9eba1), 9);
  MD4_STEP (F3, c, d, a, b, w[5] + UINT32_C (0x6ed9eba1), 11);
  MD4_STEP (F3, b, c, d, a, w[13] + UINT32_C (0x6ed9eba1), 15);
  MD4_STEP (F3, a, b, c, d, w[3] + UINT32_C (0x6ed9eba1), 3);
  MD4_STEP (F3, d, a, b, c, w[11] + UINT32_C (0x6ed9eba1), 9);
  MD4_STEP (F3, c, d, a, b, w[7] + UINT32_C (0x6ed9eba1), 11);
  MD4_STEP (F3, b, c, d, a, w[15] + UINT32_C (0x6ed9eba1), 15);

  ctx->state[0] += a;
  ctx->state[1] += b;
  ctx->state[2] += c;
  ctx->state[3] += d;
}

void
md4_update (struct md4_ctx *ctx, const void *buffer, size_t len)
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
          md4_transform (ctx, ctx->buffer);
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
      md4_transform (ctx, buffer);
      len -= 64;
      buffer = (char *) buffer + 64;
    }

  /* Save any remaining bytes. */
  if (len > 0)
    memcpy (ctx->buffer, buffer, len);
}

void
md4_final (void *digest, struct md4_ctx *ctx)
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
      md4_transform (ctx, ctx->buffer);
      memset (ctx->buffer, 0, 56);
    }

  /* Append the count to the end of the block and process it. */
  buff_put_le64 (ctx->buffer + 56, ctx->count);
  md4_transform (ctx, ctx->buffer);

  for (i = 0; i < 4; ++i)
    buff_put_le32 ((char *) digest + i * 4, ctx->state[i]);
  explicit_bzero (ctx, sizeof (struct md4_ctx));
}

#endif /* HAVE_OPENSSL_MD4_H */
