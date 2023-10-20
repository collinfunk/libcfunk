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

#ifndef ARC4_H
#define ARC4_H

#include <config.h>

#include <stddef.h>
#include <stdint.h>

#if HAVE_OPENSSL_RC4_H
#  include <openssl/rc4.h>
#endif

#if HAVE_OPENSSL_RC4_H

struct arc4_ctx
{
  RC4_KEY ssl_ctx;
};

#else /* !HAVE_OPENSSL_RC4_H */

struct arc4_ctx
{
  uint8_t data[256];
  uint8_t x;
  uint8_t y;
};

#endif /* HAVE_OPENSSL_RC4_H */

extern void arc4_set_key (struct arc4_ctx *ctx, const void *key_ptr,
                          size_t key_len);
extern void arc4_crypt (struct arc4_ctx *ctx, size_t len,
                        const void *input_ptr, void *output_ptr);

#endif /* ARC4_H */
