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

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"
#include "unicode.h"

static void test_nul_byte (void);
static void test_low_single_chars (void);
static void test_high_single_chars (void);
static void test_invalid_low_single_chars (void);
static void test_invalid_high_single_chars (void);

int
main (void)
{
  test_nul_byte ();
  test_low_single_chars ();
  test_high_single_chars ();
  test_invalid_low_single_chars ();
  test_invalid_high_single_chars ();
  return 0;
}

/* Test the behavior of 'utf32_mbtowc' on a NUL byte. */
static void
test_nul_byte (void)
{
  const uint32_t input[1] = { '\0' };
  int result;
  uint32_t wc;

  result = utf32_mbtowc (&wc, input, 1);
  ASSERT (result == 1);
  ASSERT (wc == '\0');
}

/* Test the valid code points in the inclusive range 0x0000 - 0xd7ff. */
static void
test_low_single_chars (void)
{
  uint32_t input[1];
  int result;
  uint32_t wc, i;

  for (i = 0; i < 80; ++i)
    {
      input[0] = i;
      result = utf32_mbtowc (&wc, input, 1);
      ASSERT (result == 1);
      ASSERT (wc == i);
    }

  for (i = 0xd700; i < 0xd800; ++i)
    {
      input[0] = i;
      result = utf32_mbtowc (&wc, input, 1);
      ASSERT (result == 1);
      ASSERT (wc == i);
    }
}

/* Test the valid code points in the inclusive range 0xe000 - 0x10ffff. */
static void
test_high_single_chars (void)
{
  uint32_t input[1];
  int result;
  uint32_t wc, i;

  for (i = 0xe000; i < 0xe100; ++i)
    {
      input[0] = i;
      result = utf32_mbtowc (&wc, input, 1);
      ASSERT (result == 1);
      ASSERT (wc == i);
    }

  for (i = 0x10ff00; i < 0x110000; ++i)
    {
      input[0] = i;
      result = utf32_mbtowc (&wc, input, 1);
      ASSERT (result == 1);
      ASSERT (wc == i);
    }
}

/* Test the invalid characters in the inclusive range 0xd800 - 0xdfff. */
static void
test_invalid_low_single_chars (void)
{
  uint32_t input[1];
  int result;
  uint32_t wc, i;

  for (i = 0xd800; i < 0xd900; ++i)
    {
      input[0] = i;
      result = utf32_mbtowc (&wc, input, 1);
      ASSERT (result == -1);
      ASSERT (wc == 0xfffd);
    }

  for (i = 0xdeff; i < 0xe000; ++i)
    {
      input[0] = i;
      result = utf32_mbtowc (&wc, input, 1);
      ASSERT (result == -1);
      ASSERT (wc == 0xfffd);
    }
}

/* Test the invalid characters greater than or equal to 0x110000. */
static void
test_invalid_high_single_chars (void)
{
  uint32_t input[1];
  int result;
  uint32_t wc, i;

  for (i = 0x110000; i < 0x110100; ++i)
    {
      input[0] = i;
      result = utf32_mbtowc (&wc, input, 1);
      ASSERT (result == -1);
      ASSERT (wc == 0xfffd);
    }
}
