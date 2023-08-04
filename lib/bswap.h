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

#ifndef BSWAP_H
#define BSWAP_H

#include <stdint.h>

#define bswap16(x)                                                            \
  ((uint16_t) ((((uint16_t) (x) &0x00ffU) << 8)                               \
               | (((uint16_t) (x) &0xff00U) >> 8)))

#define bswap32(x)                                                            \
  ((uint32_t) ((((uint32_t) (x) &0x000000ffUL) << 24)                         \
               | (((uint32_t) (x) &0x0000ff00UL) << 8)                        \
               | (((uint32_t) (x) &0x00ff0000UL) >> 8)                        \
               | (((uint32_t) (x) &0xff000000UL) >> 24)))

#define bswap64(x)                                                            \
  ((uint64_t) ((((uint64_t) (x) &0x00000000000000ffULL) << 56)                \
               | (((uint64_t) (x) &0x000000000000ff00ULL) << 40)              \
               | (((uint64_t) (x) &0x0000000000ff0000ULL) << 24)              \
               | (((uint64_t) (x) &0x00000000ff000000ULL) << 8)               \
               | (((uint64_t) (x) &0x000000ff00000000ULL) >> 8)               \
               | (((uint64_t) (x) &0x0000ff0000000000ULL) >> 24)              \
               | (((uint64_t) (x) &0x00ff000000000000ULL) >> 40)              \
               | (((uint64_t) (x) &0xff00000000000000ULL) >> 56)))

static inline uint16_t
buff_get_be16 (const void *bufferptr)
{
  const uint8_t *buffer = (const uint8_t *) bufferptr;

  return ((uint16_t) buffer[0] << 8) | ((uint16_t) buffer[1]);
}

static inline uint32_t
buff_get_be32 (const void *bufferptr)
{
  const uint8_t *buffer = (const uint8_t *) bufferptr;

  return ((uint32_t) buffer[0] << 24) | ((uint32_t) buffer[1] << 16)
         | ((uint32_t) buffer[2] << 8) | ((uint32_t) buffer[3]);
}

static inline uint64_t
buff_get_be64 (const void *bufferptr)
{
  const uint8_t *buffer = (const uint8_t *) bufferptr;

  return ((uint64_t) buffer[0] << 56) | ((uint64_t) buffer[1] << 48)
         | ((uint64_t) buffer[2] << 40) | ((uint64_t) buffer[3] << 32)
         | ((uint64_t) buffer[4] << 24) | ((uint64_t) buffer[5] << 16)
         | ((uint64_t) buffer[6] << 8) | ((uint64_t) buffer[7]);
}

static inline uint16_t
buff_get_le16 (const void *bufferptr)
{
  const uint8_t *buffer = (const uint8_t *) bufferptr;

  return ((uint16_t) buffer[1] << 8) | ((uint16_t) buffer[0]);
}

static inline uint32_t
buff_get_le32 (const void *bufferptr)
{
  const uint8_t *buffer = (const uint8_t *) bufferptr;

  return ((uint32_t) buffer[3] << 24) | ((uint32_t) buffer[2] << 16)
         | ((uint32_t) buffer[1] << 8) | ((uint32_t) buffer[0]);
}

static inline uint64_t
buff_get_le64 (const void *bufferptr)
{
  const uint8_t *buffer = (const uint8_t *) bufferptr;

  return ((uint64_t) buffer[7] << 56) | ((uint64_t) buffer[6] << 48)
         | ((uint64_t) buffer[5] << 40) | ((uint64_t) buffer[4] << 32)
         | ((uint64_t) buffer[3] << 24) | ((uint64_t) buffer[2] << 16)
         | ((uint64_t) buffer[1] << 8) | ((uint64_t) buffer[0]);
}

static inline void
buff_put_be16 (void *bufferptr, uint16_t value)
{
  uint8_t *buffer = (uint8_t *) bufferptr;

  buffer[0] = (value >> 8) & 0xff;
  buffer[1] = value & 0xff;
}

static inline void
buff_put_be32 (void *bufferptr, uint32_t value)
{
  uint8_t *buffer = (uint8_t *) bufferptr;

  buffer[0] = (value >> 24) & 0xff;
  buffer[1] = (value >> 16) & 0xff;
  buffer[2] = (value >> 8) & 0xff;
  buffer[3] = value & 0xff;
}

static inline void
buff_put_be64 (void *bufferptr, uint64_t value)
{
  uint8_t *buffer = (uint8_t *) bufferptr;

  buffer[0] = (value >> 56) & 0xff;
  buffer[1] = (value >> 48) & 0xff;
  buffer[2] = (value >> 40) & 0xff;
  buffer[3] = (value >> 32) & 0xff;
  buffer[4] = (value >> 24) & 0xff;
  buffer[5] = (value >> 16) & 0xff;
  buffer[6] = (value >> 8) & 0xff;
  buffer[7] = value & 0xff;
}

static inline void
buff_put_le16 (void *bufferptr, uint16_t value)
{
  uint8_t *buffer = (uint8_t *) bufferptr;

  buffer[0] = value & 0xff;
  buffer[1] = (value >> 8) & 0xff;
}

static inline void
buff_put_le32 (void *bufferptr, uint32_t value)
{
  uint8_t *buffer = (uint8_t *) bufferptr;

  buffer[0] = value & 0xff;
  buffer[1] = (value >> 8) & 0xff;
  buffer[2] = (value >> 16) & 0xff;
  buffer[3] = (value >> 24) & 0xff;
}

static inline void
buff_put_le64 (void *bufferptr, uint64_t value)
{
  uint8_t *buffer = (uint8_t *) bufferptr;

  buffer[0] = value & 0xff;
  buffer[1] = (value >> 8) & 0xff;
  buffer[2] = (value >> 16) & 0xff;
  buffer[3] = (value >> 24) & 0xff;
  buffer[4] = (value >> 32) & 0xff;
  buffer[5] = (value >> 40) & 0xff;
  buffer[6] = (value >> 48) & 0xff;
  buffer[7] = (value >> 56) & 0xff;
}

#endif /* BSWAP_H */
