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
#include "md5.h"

#if HAVE_OPENSSL_MD5_H

#  include <openssl/md5.h>

void
md5_init (struct md5_ctx *ctx)
{
  MD5_Init (&ctx->ssl_ctx);
}

void
md5_transform (struct md5_ctx *ctx, const void *buffer)
{
  MD5_Transform (&ctx->ssl_ctx, (const unsigned char *) buffer);
}

void
md5_update (struct md5_ctx *ctx, const void *buffer, size_t len)
{
  MD5_Update (&ctx->ssl_ctx, buffer, len);
}

void
md5_final (void *digest, struct md5_ctx *ctx)
{
  MD5_Final ((unsigned char *) digest, &ctx->ssl_ctx);
}

#else /* !HAVE_OPENSSL_MD5_H */

#  define F1(b, c, d) (((b) & (c)) | ((~(b)) & (d)))
#  define F2(b, c, d) (((b) & (d)) | ((~(d)) & (c)))
#  define F3(b, c, d) ((b) ^ (c) ^ (d))
#  define F4(b, c, d) ((c) ^ ((b) | (~(d))))

#  define MD5_STEP(fx, a, b, c, d, x, s)                                      \
    do                                                                        \
      {                                                                       \
        (a) += fx ((b), (c), (d)) + (x);                                      \
        (a) = rotl32 ((a), (s));                                              \
        (a) += (b);                                                           \
      }                                                                       \
    while (0)

void
md5_init (struct md5_ctx *ctx)
{
  ctx->state[0] = UINT32_C (0x67452301);
  ctx->state[1] = UINT32_C (0xefcdab89);
  ctx->state[2] = UINT32_C (0x98badcfe);
  ctx->state[3] = UINT32_C (0x10325476);
  ctx->count = UINT64_C (0);
}

void
md5_transform (struct md5_ctx *ctx, const void *buffer)
{
  uint32_t a, b, c, d, w[16];
  int i;

  for (i = 0; i < 16; ++i)
    w[i] = buff_get_le32 ((char *) buffer + i * 4);

  a = ctx->state[0];
  b = ctx->state[1];
  c = ctx->state[2];
  d = ctx->state[3];

  MD5_STEP (F1, a, b, c, d, w[0] + UINT32_C (0xd76aa478), 7);
  MD5_STEP (F1, d, a, b, c, w[1] + UINT32_C (0xe8c7b756), 12);
  MD5_STEP (F1, c, d, a, b, w[2] + UINT32_C (0x242070db), 17);
  MD5_STEP (F1, b, c, d, a, w[3] + UINT32_C (0xc1bdceee), 22);
  MD5_STEP (F1, a, b, c, d, w[4] + UINT32_C (0xf57c0faf), 7);
  MD5_STEP (F1, d, a, b, c, w[5] + UINT32_C (0x4787c62a), 12);
  MD5_STEP (F1, c, d, a, b, w[6] + UINT32_C (0xa8304613), 17);
  MD5_STEP (F1, b, c, d, a, w[7] + UINT32_C (0xfd469501), 22);
  MD5_STEP (F1, a, b, c, d, w[8] + UINT32_C (0x698098d8), 7);
  MD5_STEP (F1, d, a, b, c, w[9] + UINT32_C (0x8b44f7af), 12);
  MD5_STEP (F1, c, d, a, b, w[10] + UINT32_C (0xffff5bb1), 17);
  MD5_STEP (F1, b, c, d, a, w[11] + UINT32_C (0x895cd7be), 22);
  MD5_STEP (F1, a, b, c, d, w[12] + UINT32_C (0x6b901122), 7);
  MD5_STEP (F1, d, a, b, c, w[13] + UINT32_C (0xfd987193), 12);
  MD5_STEP (F1, c, d, a, b, w[14] + UINT32_C (0xa679438e), 17);
  MD5_STEP (F1, b, c, d, a, w[15] + UINT32_C (0x49b40821), 22);

  MD5_STEP (F2, a, b, c, d, w[1] + UINT32_C (0xf61e2562), 5);
  MD5_STEP (F2, d, a, b, c, w[6] + UINT32_C (0xc040b340), 9);
  MD5_STEP (F2, c, d, a, b, w[11] + UINT32_C (0x265e5a51), 14);
  MD5_STEP (F2, b, c, d, a, w[0] + UINT32_C (0xe9b6c7aa), 20);
  MD5_STEP (F2, a, b, c, d, w[5] + UINT32_C (0xd62f105d), 5);
  MD5_STEP (F2, d, a, b, c, w[10] + UINT32_C (0x02441453), 9);
  MD5_STEP (F2, c, d, a, b, w[15] + UINT32_C (0xd8a1e681), 14);
  MD5_STEP (F2, b, c, d, a, w[4] + UINT32_C (0xe7d3fbc8), 20);
  MD5_STEP (F2, a, b, c, d, w[9] + UINT32_C (0x21e1cde6), 5);
  MD5_STEP (F2, d, a, b, c, w[14] + UINT32_C (0xc33707d6), 9);
  MD5_STEP (F2, c, d, a, b, w[3] + UINT32_C (0xf4d50d87), 14);
  MD5_STEP (F2, b, c, d, a, w[8] + UINT32_C (0x455a14ed), 20);
  MD5_STEP (F2, a, b, c, d, w[13] + UINT32_C (0xa9e3e905), 5);
  MD5_STEP (F2, d, a, b, c, w[2] + UINT32_C (0xfcefa3f8), 9);
  MD5_STEP (F2, c, d, a, b, w[7] + UINT32_C (0x676f02d9), 14);
  MD5_STEP (F2, b, c, d, a, w[12] + UINT32_C (0x8d2a4c8a), 20);

  MD5_STEP (F3, a, b, c, d, w[5] + UINT32_C (0xfffa3942), 4);
  MD5_STEP (F3, d, a, b, c, w[8] + UINT32_C (0x8771f681), 11);
  MD5_STEP (F3, c, d, a, b, w[11] + UINT32_C (0x6d9d6122), 16);
  MD5_STEP (F3, b, c, d, a, w[14] + UINT32_C (0xfde5380c), 23);
  MD5_STEP (F3, a, b, c, d, w[1] + UINT32_C (0xa4beea44), 4);
  MD5_STEP (F3, d, a, b, c, w[4] + UINT32_C (0x4bdecfa9), 11);
  MD5_STEP (F3, c, d, a, b, w[7] + UINT32_C (0xf6bb4b60), 16);
  MD5_STEP (F3, b, c, d, a, w[10] + UINT32_C (0xbebfbc70), 23);
  MD5_STEP (F3, a, b, c, d, w[13] + UINT32_C (0x289b7ec6), 4);
  MD5_STEP (F3, d, a, b, c, w[0] + UINT32_C (0xeaa127fa), 11);
  MD5_STEP (F3, c, d, a, b, w[3] + UINT32_C (0xd4ef3085), 16);
  MD5_STEP (F3, b, c, d, a, w[6] + UINT32_C (0x04881d05), 23);
  MD5_STEP (F3, a, b, c, d, w[9] + UINT32_C (0xd9d4d039), 4);
  MD5_STEP (F3, d, a, b, c, w[12] + UINT32_C (0xe6db99e5), 11);
  MD5_STEP (F3, c, d, a, b, w[15] + UINT32_C (0x1fa27cf8), 16);
  MD5_STEP (F3, b, c, d, a, w[2] + UINT32_C (0xc4ac5665), 23);

  MD5_STEP (F4, a, b, c, d, w[0] + UINT32_C (0xf4292244), 6);
  MD5_STEP (F4, d, a, b, c, w[7] + UINT32_C (0x432aff97), 10);
  MD5_STEP (F4, c, d, a, b, w[14] + UINT32_C (0xab9423a7), 15);
  MD5_STEP (F4, b, c, d, a, w[5] + UINT32_C (0xfc93a039), 21);
  MD5_STEP (F4, a, b, c, d, w[12] + UINT32_C (0x655b59c3), 6);
  MD5_STEP (F4, d, a, b, c, w[3] + UINT32_C (0x8f0ccc92), 10);
  MD5_STEP (F4, c, d, a, b, w[10] + UINT32_C (0xffeff47d), 15);
  MD5_STEP (F4, b, c, d, a, w[1] + UINT32_C (0x85845dd1), 21);
  MD5_STEP (F4, a, b, c, d, w[8] + UINT32_C (0x6fa87e4f), 6);
  MD5_STEP (F4, d, a, b, c, w[15] + UINT32_C (0xfe2ce6e0), 10);
  MD5_STEP (F4, c, d, a, b, w[6] + UINT32_C (0xa3014314), 15);
  MD5_STEP (F4, b, c, d, a, w[13] + UINT32_C (0x4e0811a1), 21);
  MD5_STEP (F4, a, b, c, d, w[4] + UINT32_C (0xf7537e82), 6);
  MD5_STEP (F4, d, a, b, c, w[11] + UINT32_C (0xbd3af235), 10);
  MD5_STEP (F4, c, d, a, b, w[2] + UINT32_C (0x2ad7d2bb), 15);
  MD5_STEP (F4, b, c, d, a, w[9] + UINT32_C (0xeb86d391), 21);

  ctx->state[0] += a;
  ctx->state[1] += b;
  ctx->state[2] += c;
  ctx->state[3] += d;
}

void
md5_update (struct md5_ctx *ctx, const void *buffer, size_t len)
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
          md5_transform (ctx, ctx->buffer);
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
      md5_transform (ctx, buffer);
      len -= 64;
      buffer = (char *) buffer + 64;
    }

  /* Save any remaining bytes. */
  if (len > 0)
    memcpy (ctx->buffer, buffer, len);
}

void
md5_final (void *digest, struct md5_ctx *ctx)
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
      md5_transform (ctx, ctx->buffer);
      memset (ctx->buffer, 0, 56);
    }

  /* Append the count to the end of the block and process it. */
  buff_put_le64 (ctx->buffer + 56, ctx->count);
  md5_transform (ctx, ctx->buffer);

  for (i = 0; i < 4; ++i)
    buff_put_le32 ((char *) digest + i * 4, ctx->state[i]);
  explicit_bzero (ctx, sizeof (struct md5_ctx));
}

#endif /* HAVE_OPENSSL_MD5_H */
