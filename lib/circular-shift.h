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

#ifndef CIRCULAR_SHIFT_H
#define CIRCULAR_SHIFT_H

/* Circular shift/bit rotation functions.
   All shifts are done modulo the bit-length of the value. This prevents
   undefined behavior caused by shifting greater than or equal to the
   bit-length of an unsigned integer. */

static inline uint8_t
rotl8 (uint8_t value, unsigned shift)
{
  return (value << (shift & 7)) | (value >> ((-shift) & 7));
}

static inline uint16_t
rotl16 (uint16_t value, unsigned shift)
{
  return (value << (shift & 15)) | (value >> ((-shift) & 15));
}

static inline uint32_t
rotl32 (uint32_t value, unsigned shift)
{
  return (value << (shift & 31)) | (value >> ((-shift) & 31));
}

static inline uint64_t
rotl64 (uint64_t value, unsigned shift)
{
  return (value << (shift & 63)) | (value >> ((-shift) & 63));
}

static inline uint8_t
rotr8 (uint8_t value, unsigned shift)
{
  return (value >> (shift & 7)) | (value << ((-shift) & 7));
}

static inline uint16_t
rotr16 (uint16_t value, unsigned shift)
{
  return (value >> (shift & 15)) | (value << ((-shift) & 15));
}

static inline uint32_t
rotr32 (uint32_t value, unsigned shift)
{
  return (value >> (shift & 31)) | (value << ((-shift) & 31));
}

static inline uint64_t
rotr64 (uint64_t value, unsigned shift)
{
  return (value >> (shift & 63)) | (value << ((-shift) & 63));
}

#endif /* CIRCULAR_SHIFT_H */
