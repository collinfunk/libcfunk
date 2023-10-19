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
    = { 0x428a2f98UL, 0x71374491UL, 0xb5c0fbcfUL, 0xe9b5dba5UL, 0x3956c25bUL,
        0x59f111f1UL, 0x923f82a4UL, 0xab1c5ed5UL, 0xd807aa98UL, 0x12835b01UL,
        0x243185beUL, 0x550c7dc3UL, 0x72be5d74UL, 0x80deb1feUL, 0x9bdc06a7UL,
        0xc19bf174UL, 0xe49b69c1UL, 0xefbe4786UL, 0x0fc19dc6UL, 0x240ca1ccUL,
        0x2de92c6fUL, 0x4a7484aaUL, 0x5cb0a9dcUL, 0x76f988daUL, 0x983e5152UL,
        0xa831c66dUL, 0xb00327c8UL, 0xbf597fc7UL, 0xc6e00bf3UL, 0xd5a79147UL,
        0x06ca6351UL, 0x14292967UL, 0x27b70a85UL, 0x2e1b2138UL, 0x4d2c6dfcUL,
        0x53380d13UL, 0x650a7354UL, 0x766a0abbUL, 0x81c2c92eUL, 0x92722c85UL,
        0xa2bfe8a1UL, 0xa81a664bUL, 0xc24b8b70UL, 0xc76c51a3UL, 0xd192e819UL,
        0xd6990624UL, 0xf40e3585UL, 0x106aa070UL, 0x19a4c116UL, 0x1e376c08UL,
        0x2748774cUL, 0x34b0bcb5UL, 0x391c0cb3UL, 0x4ed8aa4aUL, 0x5b9cca4fUL,
        0x682e6ff3UL, 0x748f82eeUL, 0x78a5636fUL, 0x84c87814UL, 0x8cc70208UL,
        0x90befffaUL, 0xa4506cebUL, 0xbef9a3f7UL, 0xc67178f2UL };

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
  ctx->state[0] = 0x6a09e667UL;
  ctx->state[1] = 0xbb67ae85UL;
  ctx->state[2] = 0x3c6ef372UL;
  ctx->state[3] = 0xa54ff53aUL;
  ctx->state[4] = 0x510e527fUL;
  ctx->state[5] = 0x9b05688cUL;
  ctx->state[6] = 0x1f83d9abUL;
  ctx->state[7] = 0x5be0cd19UL;
  ctx->count = 0;
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
  ctx->state[0] = 0xc1059ed8UL;
  ctx->state[1] = 0x367cd507UL;
  ctx->state[2] = 0x3070dd17UL;
  ctx->state[3] = 0xf70e5939UL;
  ctx->state[4] = 0xffc00b31UL;
  ctx->state[5] = 0x68581511UL;
  ctx->state[6] = 0x64f98fa7UL;
  ctx->state[7] = 0xbefa4fa4UL;
  ctx->count = 0;
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
