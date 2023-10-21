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

#include <endian.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

#define VAL16 ((uint16_t) 0x1234U)
#define VAL32 ((uint32_t) 0x12345678UL)
#define VAL64 ((uint64_t) 0x1234567890abcdefULL)

#define VAL16_SWAPPED ((uint16_t) 0x3412U)
#define VAL32_SWAPPED ((uint32_t) 0x78563412UL)
#define VAL64_SWAPPED ((uint64_t) 0xefcdab9078563412ULL)

static void print_byte_order (void);
static void test_host_to_big_endian (void);
static void test_host_to_little_endian (void);
static void test_big_endian_to_host (void);
static void test_little_endian_to_host (void);

int
main (void)
{
  print_byte_order ();
  test_host_to_big_endian ();
  test_host_to_little_endian ();
  test_big_endian_to_host ();
  test_little_endian_to_host ();
  return 0;
}

/* Test the BYTE_ORDER is defined to a valid value. */
static void
print_byte_order (void)
{
#if BYTE_ORDER == LITTLE_ENDIAN
  printf ("BYTE_ORDER == LITTLE_ENDIAN\n");
#elif BYTE_ORDER == BIG_ENDIAN
  printf ("BYTE_ORDER == BIG_ENDIAN\n");
#elif BYTE_ORDER == PDP_ENDIAN
  printf ("BYTE_ORDER == PDP_ENDIAN\n");
  fprintf (stderr, "Unsupported byte order.\n");
  abort ();
#else
  fprintf (stderr, "Unknown byte order.\n");
  abort ();
#endif
}

/* Test htobe16, htobe32, htobe64. */
static void
test_host_to_big_endian (void)
{
#if BYTE_ORDER == LITTLE_ENDIAN
  ASSERT (htobe16 (VAL16) == VAL16_SWAPPED);
  ASSERT (htobe32 (VAL32) == VAL32_SWAPPED);
  ASSERT (htobe64 (VAL64) == VAL64_SWAPPED);
  ASSERT (htobe16 (VAL16_SWAPPED) == VAL16);
  ASSERT (htobe32 (VAL32_SWAPPED) == VAL32);
  ASSERT (htobe64 (VAL64_SWAPPED) == VAL64);
#else /* BYTE_ORDER == BIG_ENDIAN */
  ASSERT (htobe16 (VAL16) == VAL16);
  ASSERT (htobe32 (VAL32) == VAL32);
  ASSERT (htobe64 (VAL64) == VAL64);
  ASSERT (htobe16 (VAL16_SWAPPED) == VAL16_SWAPPED);
  ASSERT (htobe32 (VAL32_SWAPPED) == VAL32_SWAPPED);
  ASSERT (htobe64 (VAL64_SWAPPED) == VAL64_SWAPPED);
#endif
}

/* Test htole16, htole32, htole64. */
static void
test_host_to_little_endian (void)
{
#if BYTE_ORDER == LITTLE_ENDIAN
  ASSERT (htole16 (VAL16) == VAL16);
  ASSERT (htole32 (VAL32) == VAL32);
  ASSERT (htole64 (VAL64) == VAL64);
  ASSERT (htole16 (VAL16_SWAPPED) == VAL16_SWAPPED);
  ASSERT (htole32 (VAL32_SWAPPED) == VAL32_SWAPPED);
  ASSERT (htole64 (VAL64_SWAPPED) == VAL64_SWAPPED);
#else /* BYTE_ORDER == BIG_ENDIAN */
  ASSERT (htole16 (VAL16) == VAL16_SWAPPED);
  ASSERT (htole32 (VAL32) == VAL32_SWAPPED);
  ASSERT (htole64 (VAL64) == VAL64_SWAPPED);
  ASSERT (htole16 (VAL16_SWAPPED) == VAL16);
  ASSERT (htole32 (VAL32_SWAPPED) == VAL32);
  ASSERT (htole64 (VAL64_SWAPPED) == VAL64);
#endif
}

/* Test be16toh, be32toh, be64toh. */
static void
test_big_endian_to_host (void)
{
#if BYTE_ORDER == LITTLE_ENDIAN
  ASSERT (be16toh (VAL16) == VAL16_SWAPPED);
  ASSERT (be32toh (VAL32) == VAL32_SWAPPED);
  ASSERT (be64toh (VAL64) == VAL64_SWAPPED);
  ASSERT (be16toh (VAL16_SWAPPED) == VAL16);
  ASSERT (be32toh (VAL32_SWAPPED) == VAL32);
  ASSERT (be64toh (VAL64_SWAPPED) == VAL64);
#else /* BYTE_ORDER == BIG_ENDIAN */
  ASSERT (be16toh (VAL16) == VAL16);
  ASSERT (be32toh (VAL32) == VAL32);
  ASSERT (be64toh (VAL64) == VAL64);
  ASSERT (be16toh (VAL16_SWAPPED) == VAL16_SWAPPED);
  ASSERT (be32toh (VAL32_SWAPPED) == VAL32_SWAPPED);
  ASSERT (be64toh (VAL64_SWAPPED) == VAL64_SWAPPED);
#endif
}

/* Test le16toh, le32toh, le64toh. */
static void
test_little_endian_to_host (void)
{
#if BYTE_ORDER == LITTLE_ENDIAN
  ASSERT (le16toh (VAL16) == VAL16);
  ASSERT (le32toh (VAL32) == VAL32);
  ASSERT (le64toh (VAL64) == VAL64);
  ASSERT (le16toh (VAL16_SWAPPED) == VAL16_SWAPPED);
  ASSERT (le32toh (VAL32_SWAPPED) == VAL32_SWAPPED);
  ASSERT (le64toh (VAL64_SWAPPED) == VAL64_SWAPPED);
#else /* BYTE_ORDER == BIG_ENDIAN */
  ASSERT (le16toh (VAL16) == VAL16_SWAPPED);
  ASSERT (le32toh (VAL32) == VAL32_SWAPPED);
  ASSERT (le64toh (VAL64) == VAL64_SWAPPED);
  ASSERT (le16toh (VAL16_SWAPPED) == VAL16);
  ASSERT (le32toh (VAL32_SWAPPED) == VAL32);
  ASSERT (le64toh (VAL64_SWAPPED) == VAL64);
#endif
}
