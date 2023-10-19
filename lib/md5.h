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

#ifndef MD5_H
#define MD5_H

#include <config.h>

#include <stddef.h>
#include <stdint.h>

#if HAVE_OPENSSL_MD5_H
#  include <openssl/md5.h>
#endif

#ifndef MD5_DIGEST_SIZE
#  define MD5_DIGEST_SIZE 16
#endif

#ifndef MD5_BLOCK_SIZE
#  define MD5_BLOCK_SIZE 64
#endif

#if HAVE_OPENSSL_MD5_H

struct md5_ctx
{
  MD5_CTX ssl_ctx;
};

#else /* !HAVE_OPENSSL_MD5_H */

struct md5_ctx
{
  uint32_t state[4];
  uint64_t count;
  uint8_t buffer[64];
};

#endif /* HAVE_OPENSSL_MD5_H */

extern void md5_init (struct md5_ctx *ctx);
extern void md5_transform (struct md5_ctx *ctx, const void *buffer);
extern void md5_update (struct md5_ctx *ctx, const void *buffer, size_t len);
extern void md5_final (void *digest, struct md5_ctx *ctx);

#endif /* MD5_H */
