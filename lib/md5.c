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
  ctx->state[0] = 0x67452301UL;
  ctx->state[1] = 0xefcdab89UL;
  ctx->state[2] = 0x98badcfeUL;
  ctx->state[3] = 0x10325476UL;
  ctx->count = 0;
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

  MD5_STEP (F1, a, b, c, d, w[0] + 0xd76aa478UL, 7);
  MD5_STEP (F1, d, a, b, c, w[1] + 0xe8c7b756UL, 12);
  MD5_STEP (F1, c, d, a, b, w[2] + 0x242070dbUL, 17);
  MD5_STEP (F1, b, c, d, a, w[3] + 0xc1bdceeeUL, 22);
  MD5_STEP (F1, a, b, c, d, w[4] + 0xf57c0fafUL, 7);
  MD5_STEP (F1, d, a, b, c, w[5] + 0x4787c62aUL, 12);
  MD5_STEP (F1, c, d, a, b, w[6] + 0xa8304613UL, 17);
  MD5_STEP (F1, b, c, d, a, w[7] + 0xfd469501UL, 22);
  MD5_STEP (F1, a, b, c, d, w[8] + 0x698098d8UL, 7);
  MD5_STEP (F1, d, a, b, c, w[9] + 0x8b44f7afUL, 12);
  MD5_STEP (F1, c, d, a, b, w[10] + 0xffff5bb1UL, 17);
  MD5_STEP (F1, b, c, d, a, w[11] + 0x895cd7beUL, 22);
  MD5_STEP (F1, a, b, c, d, w[12] + 0x6b901122UL, 7);
  MD5_STEP (F1, d, a, b, c, w[13] + 0xfd987193UL, 12);
  MD5_STEP (F1, c, d, a, b, w[14] + 0xa679438eUL, 17);
  MD5_STEP (F1, b, c, d, a, w[15] + 0x49b40821UL, 22);

  MD5_STEP (F2, a, b, c, d, w[1] + 0xf61e2562UL, 5);
  MD5_STEP (F2, d, a, b, c, w[6] + 0xc040b340UL, 9);
  MD5_STEP (F2, c, d, a, b, w[11] + 0x265e5a51UL, 14);
  MD5_STEP (F2, b, c, d, a, w[0] + 0xe9b6c7aaUL, 20);
  MD5_STEP (F2, a, b, c, d, w[5] + 0xd62f105dUL, 5);
  MD5_STEP (F2, d, a, b, c, w[10] + 0x02441453UL, 9);
  MD5_STEP (F2, c, d, a, b, w[15] + 0xd8a1e681UL, 14);
  MD5_STEP (F2, b, c, d, a, w[4] + 0xe7d3fbc8UL, 20);
  MD5_STEP (F2, a, b, c, d, w[9] + 0x21e1cde6UL, 5);
  MD5_STEP (F2, d, a, b, c, w[14] + 0xc33707d6UL, 9);
  MD5_STEP (F2, c, d, a, b, w[3] + 0xf4d50d87UL, 14);
  MD5_STEP (F2, b, c, d, a, w[8] + 0x455a14edUL, 20);
  MD5_STEP (F2, a, b, c, d, w[13] + 0xa9e3e905UL, 5);
  MD5_STEP (F2, d, a, b, c, w[2] + 0xfcefa3f8UL, 9);
  MD5_STEP (F2, c, d, a, b, w[7] + 0x676f02d9UL, 14);
  MD5_STEP (F2, b, c, d, a, w[12] + 0x8d2a4c8aUL, 20);

  MD5_STEP (F3, a, b, c, d, w[5] + 0xfffa3942UL, 4);
  MD5_STEP (F3, d, a, b, c, w[8] + 0x8771f681UL, 11);
  MD5_STEP (F3, c, d, a, b, w[11] + 0x6d9d6122UL, 16);
  MD5_STEP (F3, b, c, d, a, w[14] + 0xfde5380cUL, 23);
  MD5_STEP (F3, a, b, c, d, w[1] + 0xa4beea44UL, 4);
  MD5_STEP (F3, d, a, b, c, w[4] + 0x4bdecfa9UL, 11);
  MD5_STEP (F3, c, d, a, b, w[7] + 0xf6bb4b60UL, 16);
  MD5_STEP (F3, b, c, d, a, w[10] + 0xbebfbc70UL, 23);
  MD5_STEP (F3, a, b, c, d, w[13] + 0x289b7ec6UL, 4);
  MD5_STEP (F3, d, a, b, c, w[0] + 0xeaa127faUL, 11);
  MD5_STEP (F3, c, d, a, b, w[3] + 0xd4ef3085UL, 16);
  MD5_STEP (F3, b, c, d, a, w[6] + 0x04881d05UL, 23);
  MD5_STEP (F3, a, b, c, d, w[9] + 0xd9d4d039UL, 4);
  MD5_STEP (F3, d, a, b, c, w[12] + 0xe6db99e5UL, 11);
  MD5_STEP (F3, c, d, a, b, w[15] + 0x1fa27cf8UL, 16);
  MD5_STEP (F3, b, c, d, a, w[2] + 0xc4ac5665UL, 23);

  MD5_STEP (F4, a, b, c, d, w[0] + 0xf4292244UL, 6);
  MD5_STEP (F4, d, a, b, c, w[7] + 0x432aff97UL, 10);
  MD5_STEP (F4, c, d, a, b, w[14] + 0xab9423a7UL, 15);
  MD5_STEP (F4, b, c, d, a, w[5] + 0xfc93a039UL, 21);
  MD5_STEP (F4, a, b, c, d, w[12] + 0x655b59c3UL, 6);
  MD5_STEP (F4, d, a, b, c, w[3] + 0x8f0ccc92UL, 10);
  MD5_STEP (F4, c, d, a, b, w[10] + 0xffeff47dUL, 15);
  MD5_STEP (F4, b, c, d, a, w[1] + 0x85845dd1UL, 21);
  MD5_STEP (F4, a, b, c, d, w[8] + 0x6fa87e4fUL, 6);
  MD5_STEP (F4, d, a, b, c, w[15] + 0xfe2ce6e0UL, 10);
  MD5_STEP (F4, c, d, a, b, w[6] + 0xa3014314UL, 15);
  MD5_STEP (F4, b, c, d, a, w[13] + 0x4e0811a1UL, 21);
  MD5_STEP (F4, a, b, c, d, w[4] + 0xf7537e82UL, 6);
  MD5_STEP (F4, d, a, b, c, w[11] + 0xbd3af235UL, 10);
  MD5_STEP (F4, c, d, a, b, w[2] + 0x2ad7d2bbUL, 15);
  MD5_STEP (F4, b, c, d, a, w[9] + 0xeb86d391UL, 21);

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
