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

#ifndef BASE32_H
#define BASE32_H

#include <stdbool.h>
#include <stddef.h>

#define BASE32_LENGTH(nbytes) ((((nbytes) + 4) / 5) * 8)
#define BASE32_STRING_LENGTH(nbytes) (((((nbytes) + 4) / 5) * 8) + 1)

/* Base32 encode a buffer pointed to by SRC_PTR and store the result in the
   buffer pointed to by DEST_PTR. This function does not care about the size
   of the designation buffer. It also requires that SRC_LEN is divisible by 5
   without a remainder. The resulting buffer is not null-terminated. */
extern void base32_encode_unsafe (const void *src_ptr, size_t src_len,
                                  void *dest_ptr);

/* Base32 encode the buffer pointed to by SRC_PTR and store the result in
   the buffer pointed to by DEST_PTR. This function will never encode more than
   DEST_LEN bytes. If possible, the result will be null-terminated. */
extern void base32_encode (const void *src_ptr, size_t src_len, void *dest_ptr,
                           size_t dest_len);

/* Returns true if CH is a valid encoded Base32 character. This does not
   include the '=' padding character. */
extern bool isbase32 (char ch);

#endif /* BASE32_H */
