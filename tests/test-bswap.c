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

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bswap.h"
#include "test-help.h"

#define VAL16 ((uint16_t) 0x1234U)
#define VAL32 ((uint32_t) 0x12345678UL)
#define VAL64 ((uint64_t) 0x1234567890abcdefULL)

#define VAL16_SWAPPED ((uint16_t) 0x3412U)
#define VAL32_SWAPPED ((uint32_t) 0x78563412UL)
#define VAL64_SWAPPED ((uint64_t) 0xefcdab9078563412ULL)

static const uint8_t readbuffer[8]
    = { 0x12, 0x34, 0x56, 0x78, 0x90, 0xab, 0xcd, 0xef };

static uint8_t writebuffer16[2];
static uint8_t writebuffer32[4];
static uint8_t writebuffer64[8];

static void test_bswap (void);
static void test_buff_get_be (void);
static void test_buff_get_le (void);
static void test_buff_put_be (void);
static void test_buff_put_le (void);

int
main (void)
{
  test_bswap ();
  test_buff_get_be ();
  test_buff_get_le ();
  test_buff_put_be ();
  test_buff_put_le ();
  return 0;
}

static void
test_bswap (void)
{
  ASSERT (bswap16 (VAL16) == VAL16_SWAPPED);
  ASSERT (bswap32 (VAL32) == VAL32_SWAPPED);
  ASSERT (bswap64 (VAL64) == VAL64_SWAPPED);
  ASSERT (bswap16 (VAL16_SWAPPED) == VAL16);
  ASSERT (bswap32 (VAL32_SWAPPED) == VAL32);
  ASSERT (bswap64 (VAL64_SWAPPED) == VAL64);
}

static void
test_buff_get_be (void)
{
  ASSERT (buff_get_be16 (readbuffer) == VAL16);
  ASSERT (buff_get_be32 (readbuffer) == VAL32);
  ASSERT (buff_get_be64 (readbuffer) == VAL64);
}

static void
test_buff_get_le (void)
{
  ASSERT (buff_get_le16 (readbuffer) == VAL16_SWAPPED);
  ASSERT (buff_get_le32 (readbuffer) == VAL32_SWAPPED);
  ASSERT (buff_get_le64 (readbuffer) == VAL64_SWAPPED);
}

static void
test_buff_put_be (void)
{
  buff_put_be16 (writebuffer16, VAL16);
  buff_put_be32 (writebuffer32, VAL32);
  buff_put_be64 (writebuffer64, VAL64);
  ASSERT (memcmp (writebuffer16, readbuffer, sizeof (writebuffer16)) == 0);
  ASSERT (memcmp (writebuffer32, readbuffer, sizeof (writebuffer32)) == 0);
  ASSERT (memcmp (writebuffer64, readbuffer, sizeof (writebuffer64)) == 0);
}

static void
test_buff_put_le (void)
{
  buff_put_le16 (writebuffer16, VAL16_SWAPPED);
  buff_put_le32 (writebuffer32, VAL32_SWAPPED);
  buff_put_le64 (writebuffer64, VAL64_SWAPPED);
  ASSERT (memcmp (writebuffer16, readbuffer, sizeof (writebuffer16)) == 0);
  ASSERT (memcmp (writebuffer32, readbuffer, sizeof (writebuffer32)) == 0);
  ASSERT (memcmp (writebuffer64, readbuffer, sizeof (writebuffer64)) == 0);
}
