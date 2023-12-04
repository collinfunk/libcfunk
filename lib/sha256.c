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
#include "sha256.h"

#if HAVE_OPENSSL_SHA_H

#  include <openssl/sha.h>

void
sha256_init (struct sha256_ctx *ctx)
{
  SHA256_Init (&ctx->ssl_ctx);
}

void
sha256_transform (struct sha256_ctx *ctx, const void *buffer)
{
  SHA256_Transform (&ctx->ssl_ctx, (const unsigned char *) buffer);
}

void
sha256_update (struct sha256_ctx *ctx, const void *buffer, size_t len)
{
  SHA256_Update (&ctx->ssl_ctx, buffer, len);
}

void
sha256_final (void *digest, struct sha256_ctx *ctx)
{
  SHA256_Final ((unsigned char *) digest, &ctx->ssl_ctx);
}

void
sha224_init (struct sha256_ctx *ctx)
{
  SHA224_Init (&ctx->ssl_ctx);
}

void
sha224_final (void *digest, struct sha256_ctx *ctx)
{
  SHA224_Final ((unsigned char *) digest, &ctx->ssl_ctx);
}

#else /* !HAVE_OPENSSL_SHA_H */

#  define Ch(b, c, d) (((b) & (c)) ^ ((~(b)) & (d)))
#  define Maj(b, c, d) (((b) & (c)) ^ ((b) & (d)) ^ ((c) & (d)))
#  define Sigma0(x) (rotr32 ((x), 2) ^ rotr32 ((x), 13) ^ rotr32 ((x), 22))
#  define Sigma1(x) (rotr32 ((x), 6) ^ rotr32 ((x), 11) ^ rotr32 ((x), 25))
#  define sigma0(x) (rotr32 ((x), 7) ^ rotr32 ((x), 18) ^ ((x) >> 3))
#  define sigma1(x) (rotr32 ((x), 17) ^ rotr32 ((x), 19) ^ ((x) >> 10))

static const uint32_t sha256_ktable[64]
    = { UINT32_C (0x428a2f98), UINT32_C (0x71374491), UINT32_C (0xb5c0fbcf),
        UINT32_C (0xe9b5dba5), UINT32_C (0x3956c25b), UINT32_C (0x59f111f1),
        UINT32_C (0x923f82a4), UINT32_C (0xab1c5ed5), UINT32_C (0xd807aa98),
        UINT32_C (0x12835b01), UINT32_C (0x243185be), UINT32_C (0x550c7dc3),
        UINT32_C (0x72be5d74), UINT32_C (0x80deb1fe), UINT32_C (0x9bdc06a7),
        UINT32_C (0xc19bf174), UINT32_C (0xe49b69c1), UINT32_C (0xefbe4786),
        UINT32_C (0x0fc19dc6), UINT32_C (0x240ca1cc), UINT32_C (0x2de92c6f),
        UINT32_C (0x4a7484aa), UINT32_C (0x5cb0a9dc), UINT32_C (0x76f988da),
        UINT32_C (0x983e5152), UINT32_C (0xa831c66d), UINT32_C (0xb00327c8),
        UINT32_C (0xbf597fc7), UINT32_C (0xc6e00bf3), UINT32_C (0xd5a79147),
        UINT32_C (0x06ca6351), UINT32_C (0x14292967), UINT32_C (0x27b70a85),
        UINT32_C (0x2e1b2138), UINT32_C (0x4d2c6dfc), UINT32_C (0x53380d13),
        UINT32_C (0x650a7354), UINT32_C (0x766a0abb), UINT32_C (0x81c2c92e),
        UINT32_C (0x92722c85), UINT32_C (0xa2bfe8a1), UINT32_C (0xa81a664b),
        UINT32_C (0xc24b8b70), UINT32_C (0xc76c51a3), UINT32_C (0xd192e819),
        UINT32_C (0xd6990624), UINT32_C (0xf40e3585), UINT32_C (0x106aa070),
        UINT32_C (0x19a4c116), UINT32_C (0x1e376c08), UINT32_C (0x2748774c),
        UINT32_C (0x34b0bcb5), UINT32_C (0x391c0cb3), UINT32_C (0x4ed8aa4a),
        UINT32_C (0x5b9cca4f), UINT32_C (0x682e6ff3), UINT32_C (0x748f82ee),
        UINT32_C (0x78a5636f), UINT32_C (0x84c87814), UINT32_C (0x8cc70208),
        UINT32_C (0x90befffa), UINT32_C (0xa4506ceb), UINT32_C (0xbef9a3f7),
        UINT32_C (0xc67178f2) };

/* Internal function used by sha256_final () and sha224_final (). Pads the
   final block with zero's and appends the 64-bit count. The caller will
   have the final hash value in CTX's state. */
static void
sha256_pad (struct sha256_ctx *ctx)
{
  size_t padlen = (ctx->count >> 3) & 63;

  ctx->buffer[padlen++] = 0x80;

  /* Check if we have enough free space for the 64-bit count. */
  if (padlen <= 56)
    memset (&ctx->buffer[padlen], 0, 56 - padlen);
  else
    {
      /* Fill all unused bytes in the buffer with 0's and process the block. */
      memset (&ctx->buffer[padlen], 0, 64 - padlen);
      sha256_transform (ctx, ctx->buffer);
      memset (ctx->buffer, 0, 56);
    }

  /* Append the count to the end of the block and process it. */
  buff_put_be64 (ctx->buffer + 56, ctx->count);
  sha256_transform (ctx, ctx->buffer);
}

void
sha256_init (struct sha256_ctx *ctx)
{
  ctx->state[0] = UINT32_C (0x6a09e667);
  ctx->state[1] = UINT32_C (0xbb67ae85);
  ctx->state[2] = UINT32_C (0x3c6ef372);
  ctx->state[3] = UINT32_C (0xa54ff53a);
  ctx->state[4] = UINT32_C (0x510e527f);
  ctx->state[5] = UINT32_C (0x9b05688c);
  ctx->state[6] = UINT32_C (0x1f83d9ab);
  ctx->state[7] = UINT32_C (0x5be0cd19);
  ctx->count = UINT64_C (0);
}

void
sha256_transform (struct sha256_ctx *ctx, const void *buffer)
{
  uint32_t a, b, c, d, e, f, g, h, t1, t2, w[64];
  int i;

  for (i = 0; i < 16; ++i)
    w[i] = buff_get_be32 ((char *) buffer + i * 4);
  for (i = 16; i < 64; ++i)
    w[i] = sigma1 (w[i - 2]) + w[i - 7] + sigma0 (w[i - 15]) + w[i - 16];

  a = ctx->state[0];
  b = ctx->state[1];
  c = ctx->state[2];
  d = ctx->state[3];
  e = ctx->state[4];
  f = ctx->state[5];
  g = ctx->state[6];
  h = ctx->state[7];

  for (i = 0; i < 64; ++i)
    {
      t1 = h + Sigma1 (e) + Ch (e, f, g) + sha256_ktable[i] + w[i];
      t2 = Sigma0 (a) + Maj (a, b, c);
      h = g;
      g = f;
      f = e;
      e = d + t1;
      d = c;
      c = b;
      b = a;
      a = t1 + t2;
    }

  ctx->state[0] += a;
  ctx->state[1] += b;
  ctx->state[2] += c;
  ctx->state[3] += d;
  ctx->state[4] += e;
  ctx->state[5] += f;
  ctx->state[6] += g;
  ctx->state[7] += h;
}

void
sha256_update (struct sha256_ctx *ctx, const void *buffer, size_t len)
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
          sha256_transform (ctx, ctx->buffer);
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
      sha256_transform (ctx, buffer);
      len -= 64;
      buffer = (char *) buffer + 64;
    }

  /* Save any remaining bytes. */
  if (len > 0)
    memcpy (ctx->buffer, buffer, len);
}

void
sha256_final (void *digest, struct sha256_ctx *ctx)
{
  int i;

  sha256_pad (ctx);

  for (i = 0; i < 8; ++i)
    buff_put_be32 ((char *) digest + i * 4, ctx->state[i]);
  explicit_bzero (ctx, sizeof (struct sha256_ctx));
}

void
sha224_init (struct sha256_ctx *ctx)
{
  ctx->state[0] = UINT32_C (0xc1059ed8);
  ctx->state[1] = UINT32_C (0x367cd507);
  ctx->state[2] = UINT32_C (0x3070dd17);
  ctx->state[3] = UINT32_C (0xf70e5939);
  ctx->state[4] = UINT32_C (0xffc00b31);
  ctx->state[5] = UINT32_C (0x68581511);
  ctx->state[6] = UINT32_C (0x64f98fa7);
  ctx->state[7] = UINT32_C (0xbefa4fa4);
  ctx->count = UINT64_C (0);
}

void
sha224_final (void *digest, struct sha256_ctx *ctx)
{
  int i;

  sha256_pad (ctx);

  for (i = 0; i < 7; ++i)
    buff_put_be32 ((char *) digest + i * 4, ctx->state[i]);
  explicit_bzero (ctx, sizeof (struct sha256_ctx));
}

#endif /* HAVE_OPENSSL_SHA_H */
