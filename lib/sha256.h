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

#ifndef SHA256_H
#define SHA256_H

#include <config.h>

#include <stddef.h>
#include <stdint.h>

#if HAVE_OPENSSL_SHA_H
#  include <openssl/sha.h>
#endif

#ifndef SHA256_BLOCK_SIZE
#  define SHA256_BLOCK_SIZE 64
#endif

#ifndef SHA256_DIGEST_SIZE
#  define SHA256_DIGEST_SIZE 32
#endif

#ifndef SHA224_BLOCK_SIZE
#  define SHA224_BLOCK_SIZE 64
#endif

#ifndef SHA224_DIGEST_SIZE
#  define SHA224_DIGEST_SIZE 28
#endif

#if HAVE_OPENSSL_SHA_H

struct sha256_ctx
{
  SHA256_CTX ssl_ctx;
};

#else /* !HAVE_OPENSSL_SHA_H */

struct sha256_ctx
{
  uint32_t state[8];
  uint64_t count;
  uint8_t buffer[64];
};

#endif /* HAVE_OPENSSL_SHA_H */

extern void sha256_init (struct sha256_ctx *ctx);
extern void sha256_transform (struct sha256_ctx *ctx, const void *buffer);
extern void sha256_update (struct sha256_ctx *ctx, const void *buffer,
                           size_t len);
extern void sha256_final (void *digest, struct sha256_ctx *ctx);

extern void sha224_init (struct sha256_ctx *ctx);
extern void sha224_final (void *digest, struct sha256_ctx *ctx);

#endif /* SHA256_H */
