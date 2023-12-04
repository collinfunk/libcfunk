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
#include "sha512.h"

#if HAVE_OPENSSL_SHA_H

#  include <openssl/sha.h>

void
sha512_init (struct sha512_ctx *ctx)
{
  SHA512_Init (&ctx->ssl_ctx);
}

void
sha512_transform (struct sha512_ctx *ctx, const void *buffer)
{
  SHA512_Transform (&ctx->ssl_ctx, (const unsigned char *) buffer);
}

void
sha512_update (struct sha512_ctx *ctx, const void *buffer, size_t len)
{
  SHA512_Update (&ctx->ssl_ctx, buffer, len);
}

void
sha512_final (void *digest, struct sha512_ctx *ctx)
{
  SHA512_Final ((unsigned char *) digest, &ctx->ssl_ctx);
}

void
sha384_init (struct sha512_ctx *ctx)
{
  SHA384_Init (&ctx->ssl_ctx);
}

void
sha384_final (void *digest, struct sha512_ctx *ctx)
{
  SHA384_Final ((unsigned char *) digest, &ctx->ssl_ctx);
}

#else /* !HAVE_OPENSSL_SHA_H */

#  define Ch(b, c, d) (((b) & (c)) ^ ((~(b)) & (d)))
#  define Maj(b, c, d) (((b) & (c)) ^ ((b) & (d)) ^ ((c) & (d)))
#  define Sigma0(x) (rotr64 ((x), 28) ^ rotr64 ((x), 34) ^ rotr64 ((x), 39))
#  define Sigma1(x) (rotr64 ((x), 14) ^ rotr64 ((x), 18) ^ rotr64 ((x), 41))
#  define sigma0(x) (rotr64 ((x), 1) ^ rotr64 ((x), 8) ^ ((x) >> 7))
#  define sigma1(x) (rotr64 ((x), 19) ^ rotr64 ((x), 61) ^ ((x) >> 6))

static const uint64_t sha512_ktable[80]
    = { UINT64_C (0x428a2f98d728ae22), UINT64_C (0x7137449123ef65cd),
        UINT64_C (0xb5c0fbcfec4d3b2f), UINT64_C (0xe9b5dba58189dbbc),
        UINT64_C (0x3956c25bf348b538), UINT64_C (0x59f111f1b605d019),
        UINT64_C (0x923f82a4af194f9b), UINT64_C (0xab1c5ed5da6d8118),
        UINT64_C (0xd807aa98a3030242), UINT64_C (0x12835b0145706fbe),
        UINT64_C (0x243185be4ee4b28c), UINT64_C (0x550c7dc3d5ffb4e2),
        UINT64_C (0x72be5d74f27b896f), UINT64_C (0x80deb1fe3b1696b1),
        UINT64_C (0x9bdc06a725c71235), UINT64_C (0xc19bf174cf692694),
        UINT64_C (0xe49b69c19ef14ad2), UINT64_C (0xefbe4786384f25e3),
        UINT64_C (0x0fc19dc68b8cd5b5), UINT64_C (0x240ca1cc77ac9c65),
        UINT64_C (0x2de92c6f592b0275), UINT64_C (0x4a7484aa6ea6e483),
        UINT64_C (0x5cb0a9dcbd41fbd4), UINT64_C (0x76f988da831153b5),
        UINT64_C (0x983e5152ee66dfab), UINT64_C (0xa831c66d2db43210),
        UINT64_C (0xb00327c898fb213f), UINT64_C (0xbf597fc7beef0ee4),
        UINT64_C (0xc6e00bf33da88fc2), UINT64_C (0xd5a79147930aa725),
        UINT64_C (0x06ca6351e003826f), UINT64_C (0x142929670a0e6e70),
        UINT64_C (0x27b70a8546d22ffc), UINT64_C (0x2e1b21385c26c926),
        UINT64_C (0x4d2c6dfc5ac42aed), UINT64_C (0x53380d139d95b3df),
        UINT64_C (0x650a73548baf63de), UINT64_C (0x766a0abb3c77b2a8),
        UINT64_C (0x81c2c92e47edaee6), UINT64_C (0x92722c851482353b),
        UINT64_C (0xa2bfe8a14cf10364), UINT64_C (0xa81a664bbc423001),
        UINT64_C (0xc24b8b70d0f89791), UINT64_C (0xc76c51a30654be30),
        UINT64_C (0xd192e819d6ef5218), UINT64_C (0xd69906245565a910),
        UINT64_C (0xf40e35855771202a), UINT64_C (0x106aa07032bbd1b8),
        UINT64_C (0x19a4c116b8d2d0c8), UINT64_C (0x1e376c085141ab53),
        UINT64_C (0x2748774cdf8eeb99), UINT64_C (0x34b0bcb5e19b48a8),
        UINT64_C (0x391c0cb3c5c95a63), UINT64_C (0x4ed8aa4ae3418acb),
        UINT64_C (0x5b9cca4f7763e373), UINT64_C (0x682e6ff3d6b2b8a3),
        UINT64_C (0x748f82ee5defb2fc), UINT64_C (0x78a5636f43172f60),
        UINT64_C (0x84c87814a1f0ab72), UINT64_C (0x8cc702081a6439ec),
        UINT64_C (0x90befffa23631e28), UINT64_C (0xa4506cebde82bde9),
        UINT64_C (0xbef9a3f7b2c67915), UINT64_C (0xc67178f2e372532b),
        UINT64_C (0xca273eceea26619c), UINT64_C (0xd186b8c721c0c207),
        UINT64_C (0xeada7dd6cde0eb1e), UINT64_C (0xf57d4f7fee6ed178),
        UINT64_C (0x06f067aa72176fba), UINT64_C (0x0a637dc5a2c898a6),
        UINT64_C (0x113f9804bef90dae), UINT64_C (0x1b710b35131c471b),
        UINT64_C (0x28db77f523047d84), UINT64_C (0x32caab7b40c72493),
        UINT64_C (0x3c9ebe0a15c9bebc), UINT64_C (0x431d67c49c100d4c),
        UINT64_C (0x4cc5d4becb3e42b6), UINT64_C (0x597f299cfc657e2a),
        UINT64_C (0x5fcb6fab3ad6faec), UINT64_C (0x6c44198c4a475817) };

/* Internal function used by sha512_final () and sha384_final (). Pads the
   final block with zero's and appends the 128-bit count. The caller will
   have the final hash value in CTX's state. */
static void
sha512_pad (struct sha512_ctx *ctx)
{
  size_t padlen = (ctx->count[0] >> 3) & 127;

  ctx->buffer[padlen++] = 0x80;

  /* Check if we have enough free space for the 128-bit count. */
  if (padlen <= 112)
    memset (&ctx->buffer[padlen], 0, 112 - padlen);
  else
    {
      /* Fill all unused bytes in the buffer with 0's and process the block. */
      memset (&ctx->buffer[padlen], 0, 128 - padlen);
      sha512_transform (ctx, ctx->buffer);
      memset (ctx->buffer, 0, 112);
    }

  /* Append the count to the end of the block and process it. */
  buff_put_be64 (ctx->buffer + 112, ctx->count[1]);
  buff_put_be64 (ctx->buffer + 120, ctx->count[0]);
  sha512_transform (ctx, ctx->buffer);
}

void
sha512_init (struct sha512_ctx *ctx)
{
  ctx->state[0] = UINT64_C (0x6a09e667f3bcc908);
  ctx->state[1] = UINT64_C (0xbb67ae8584caa73b);
  ctx->state[2] = UINT64_C (0x3c6ef372fe94f82b);
  ctx->state[3] = UINT64_C (0xa54ff53a5f1d36f1);
  ctx->state[4] = UINT64_C (0x510e527fade682d1);
  ctx->state[5] = UINT64_C (0x9b05688c2b3e6c1f);
  ctx->state[6] = UINT64_C (0x1f83d9abfb41bd6b);
  ctx->state[7] = UINT64_C (0x5be0cd19137e2179);
  ctx->count[0] = UINT64_C (0);
  ctx->count[1] = UINT64_C (0);
}

void
sha512_transform (struct sha512_ctx *ctx, const void *buffer)
{
  uint64_t a, b, c, d, e, f, g, h, t1, t2, w[80];
  int i;

  for (i = 0; i < 16; ++i)
    w[i] = buff_get_be64 ((char *) buffer + i * 8);
  for (i = 16; i < 80; ++i)
    w[i] = sigma1 (w[i - 2]) + w[i - 7] + sigma0 (w[i - 15]) + w[i - 16];

  a = ctx->state[0];
  b = ctx->state[1];
  c = ctx->state[2];
  d = ctx->state[3];
  e = ctx->state[4];
  f = ctx->state[5];
  g = ctx->state[6];
  h = ctx->state[7];

  for (i = 0; i < 80; ++i)
    {
      t1 = h + Sigma1 (e) + Ch (e, f, g) + sha512_ktable[i] + w[i];
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
sha512_update (struct sha512_ctx *ctx, const void *buffer, size_t len)
{
  size_t have;
  uint64_t increment = (uint64_t) len << 3;

  /* No input. */
  if (len == 0)
    return;

  /* (Bit count / 8) mod blocksize */
  have = (ctx->count[0] >> 3) & 127;

  /* Update the bit count. */
  ctx->count[0] += increment;
  /* Check for overflow. */
  if (ctx->count[0] < increment)
    ++ctx->count[1];

  /* Check if we have any bytes in the buffer. */
  if (have > 0)
    {
      size_t need = 128 - have;

      if (len >= need)
        {
          /* Process the bytes we have in the buffer first. */
          memcpy (&ctx->buffer[have], buffer, need);
          sha512_transform (ctx, ctx->buffer);
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
  while (len >= 128)
    {
      sha512_transform (ctx, buffer);
      len -= 128;
      buffer = (char *) buffer + 128;
    }

  /* Save any remaining bytes. */
  if (len > 0)
    memcpy (ctx->buffer, buffer, len);
}

void
sha512_final (void *digest, struct sha512_ctx *ctx)
{
  int i;

  sha512_pad (ctx);

  for (i = 0; i < 8; ++i)
    buff_put_be64 ((char *) digest + i * 8, ctx->state[i]);
  explicit_bzero (ctx, sizeof (struct sha512_ctx));
}

void
sha384_init (struct sha512_ctx *ctx)
{
  ctx->state[0] = UINT64_C (0xcbbb9d5dc1059ed8);
  ctx->state[1] = UINT64_C (0x629a292a367cd507);
  ctx->state[2] = UINT64_C (0x9159015a3070dd17);
  ctx->state[3] = UINT64_C (0x152fecd8f70e5939);
  ctx->state[4] = UINT64_C (0x67332667ffc00b31);
  ctx->state[5] = UINT64_C (0x8eb44a8768581511);
  ctx->state[6] = UINT64_C (0xdb0c2e0d64f98fa7);
  ctx->state[7] = UINT64_C (0x47b5481dbefa4fa4);
  ctx->count[0] = UINT64_C (0);
  ctx->count[1] = UINT64_C (0);
}

void
sha384_final (void *digest, struct sha512_ctx *ctx)
{
  int i;

  sha512_pad (ctx);

  for (i = 0; i < 6; ++i)
    buff_put_be64 ((char *) digest + i * 8, ctx->state[i]);
  explicit_bzero (ctx, sizeof (struct sha512_ctx));
}

#endif /* HAVE_OPENSSL_SHA_H */
