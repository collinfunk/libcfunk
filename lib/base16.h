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

#ifndef BASE16_H
#define BASE16_H

#include <stddef.h>

/* The number of bytes occupied by encoding NBYTES of data.
   This does not include a null-terminator. */
#define BASE16_LENGTH(nbytes) ((nbytes) *2)

/* The number of bytes occupied by encoding NBYTES of data.
   This includes an extra byte for the null-terminator. */
#define BASE16_STRING_LENGTH(nbytes) (((nbytes) *2) + 1)

/* Base16 encode SRC_LEN bytes and store the result in the buffer
   pointed to by DEST_PTR. This function does not care about the size of
   the destination buffer and does not add a NUL byte at the end. */
void base16_encode_unsafe (const void *src_ptr, size_t src_len,
                           void *dest_ptr);

/* Base16 encode SRC_LEN bytes of the buffer pointed to by SRC_PTR. The
   result is stored in the buffer pointed to by DEST_PTR. This function
   will never encode more than DEST_LEN bytes. The result will always be
   null-terminated if possible. */
void base16_encode (const void *src_ptr, size_t src_len, void *dest_ptr,
                    size_t dest_len);

#endif /* BASE16_H */
