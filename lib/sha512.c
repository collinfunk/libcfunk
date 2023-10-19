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
    = { 0x428a2f98d728ae22ULL, 0x7137449123ef65cdULL, 0xb5c0fbcfec4d3b2fULL,
        0xe9b5dba58189dbbcULL, 0x3956c25bf348b538ULL, 0x59f111f1b605d019ULL,
        0x923f82a4af194f9bULL, 0xab1c5ed5da6d8118ULL, 0xd807aa98a3030242ULL,
        0x12835b0145706fbeULL, 0x243185be4ee4b28cULL, 0x550c7dc3d5ffb4e2ULL,
        0x72be5d74f27b896fULL, 0x80deb1fe3b1696b1ULL, 0x9bdc06a725c71235ULL,
        0xc19bf174cf692694ULL, 0xe49b69c19ef14ad2ULL, 0xefbe4786384f25e3ULL,
        0x0fc19dc68b8cd5b5ULL, 0x240ca1cc77ac9c65ULL, 0x2de92c6f592b0275ULL,
        0x4a7484aa6ea6e483ULL, 0x5cb0a9dcbd41fbd4ULL, 0x76f988da831153b5ULL,
        0x983e5152ee66dfabULL, 0xa831c66d2db43210ULL, 0xb00327c898fb213fULL,
        0xbf597fc7beef0ee4ULL, 0xc6e00bf33da88fc2ULL, 0xd5a79147930aa725ULL,
        0x06ca6351e003826fULL, 0x142929670a0e6e70ULL, 0x27b70a8546d22ffcULL,
        0x2e1b21385c26c926ULL, 0x4d2c6dfc5ac42aedULL, 0x53380d139d95b3dfULL,
        0x650a73548baf63deULL, 0x766a0abb3c77b2a8ULL, 0x81c2c92e47edaee6ULL,
        0x92722c851482353bULL, 0xa2bfe8a14cf10364ULL, 0xa81a664bbc423001ULL,
        0xc24b8b70d0f89791ULL, 0xc76c51a30654be30ULL, 0xd192e819d6ef5218ULL,
        0xd69906245565a910ULL, 0xf40e35855771202aULL, 0x106aa07032bbd1b8ULL,
        0x19a4c116b8d2d0c8ULL, 0x1e376c085141ab53ULL, 0x2748774cdf8eeb99ULL,
        0x34b0bcb5e19b48a8ULL, 0x391c0cb3c5c95a63ULL, 0x4ed8aa4ae3418acbULL,
        0x5b9cca4f7763e373ULL, 0x682e6ff3d6b2b8a3ULL, 0x748f82ee5defb2fcULL,
        0x78a5636f43172f60ULL, 0x84c87814a1f0ab72ULL, 0x8cc702081a6439ecULL,
        0x90befffa23631e28ULL, 0xa4506cebde82bde9ULL, 0xbef9a3f7b2c67915ULL,
        0xc67178f2e372532bULL, 0xca273eceea26619cULL, 0xd186b8c721c0c207ULL,
        0xeada7dd6cde0eb1eULL, 0xf57d4f7fee6ed178ULL, 0x06f067aa72176fbaULL,
        0x0a637dc5a2c898a6ULL, 0x113f9804bef90daeULL, 0x1b710b35131c471bULL,
        0x28db77f523047d84ULL, 0x32caab7b40c72493ULL, 0x3c9ebe0a15c9bebcULL,
        0x431d67c49c100d4cULL, 0x4cc5d4becb3e42b6ULL, 0x597f299cfc657e2aULL,
        0x5fcb6fab3ad6faecULL, 0x6c44198c4a475817ULL };

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
  ctx->state[0] = 0x6a09e667f3bcc908ULL;
  ctx->state[1] = 0xbb67ae8584caa73bULL;
  ctx->state[2] = 0x3c6ef372fe94f82bULL;
  ctx->state[3] = 0xa54ff53a5f1d36f1ULL;
  ctx->state[4] = 0x510e527fade682d1ULL;
  ctx->state[5] = 0x9b05688c2b3e6c1fULL;
  ctx->state[6] = 0x1f83d9abfb41bd6bULL;
  ctx->state[7] = 0x5be0cd19137e2179ULL;
  ctx->count[0] = 0;
  ctx->count[1] = 0;
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
  ctx->state[0] = 0xcbbb9d5dc1059ed8ULL;
  ctx->state[1] = 0x629a292a367cd507ULL;
  ctx->state[2] = 0x9159015a3070dd17ULL;
  ctx->state[3] = 0x152fecd8f70e5939ULL;
  ctx->state[4] = 0x67332667ffc00b31ULL;
  ctx->state[5] = 0x8eb44a8768581511ULL;
  ctx->state[6] = 0xdb0c2e0d64f98fa7ULL;
  ctx->state[7] = 0x47b5481dbefa4fa4ULL;
  ctx->count[0] = 0;
  ctx->count[1] = 0;
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
