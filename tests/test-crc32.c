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
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "crc32.h"
#include "test-help.h"

struct crc32_testcase
{
  const char *str;
  const uint32_t crc;
};

static const struct crc32_testcase testcases[] = {
  { "", 0x00000000UL },
  { "a", 0xe8b7be43UL },
  { "abc", 0x352441c2UL },
  { "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq", 0x171a3f5fUL },
  { "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmn", 0x40e1b159UL },
  { "hijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu", 0xf4aa1538UL },
  { "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopj"
    "klmnopqklmnopqrlmnopqrsmnopqrstnopqrstu",
    0x191f3349UL },
  { "01234567012345670123456701234567", 0x8053b40UL },
  { "0123456701234567012345670123456701234567012345670123456701234567",
    0x93bac4e4UL },
};

static void do_crc32_testcase (const struct crc32_testcase *test);

int
main (void)
{
  size_t i;

  for (i = 0; i < ARRAY_SIZE (testcases); ++i)
    do_crc32_testcase (&testcases[i]);

  return 0;
}

static void
do_crc32_testcase (const struct crc32_testcase *test)
{
  uint32_t crc;

  crc = crc32 (test->str, strlen (test->str));
  printf ("0x%08x\n", crc);

  ASSERT (crc == test->crc);
}
