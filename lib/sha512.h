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

#ifndef SHA512_H
#define SHA512_H

#include <config.h>

#include <stddef.h>
#include <stdint.h>

#if HAVE_OPENSSL_SHA_H
#  include <openssl/sha.h>
#endif

#ifndef SHA512_BLOCK_SIZE
#  define SHA512_BLOCK_SIZE 128
#endif

#ifndef SHA512_DIGEST_SIZE
#  define SHA512_DIGEST_SIZE 64
#endif

#ifndef SHA384_BLOCK_SIZE
#  define SHA384_BLOCK_SIZE 128
#endif

#ifndef SHA384_DIGEST_SIZE
#  define SHA384_DIGEST_SIZE 48
#endif

#if HAVE_OPENSSL_SHA_H

struct sha512_ctx
{
  SHA512_CTX ssl_ctx;
};

#else /* !HAVE_OPENSSL_SHA_H */

struct sha512_ctx
{
  uint64_t state[8];
  uint64_t count[2];
  uint8_t buffer[128];
};

#endif /* HAVE_OPENSSL_SHA_H */

extern void sha512_init (struct sha512_ctx *ctx);
extern void sha512_transform (struct sha512_ctx *ctx, const void *buffer);
extern void sha512_update (struct sha512_ctx *ctx, const void *buffer,
                           size_t len);
extern void sha512_final (void *digest, struct sha512_ctx *ctx);

extern void sha384_init (struct sha512_ctx *ctx);
extern void sha384_final (void *digest, struct sha512_ctx *ctx);

#endif /* SHA512_H */
