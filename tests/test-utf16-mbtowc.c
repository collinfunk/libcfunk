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
static void test_double_chars (void);
static void test_missing_low_surrogate (void);
static void test_invalid_low_surrogate (void);

int
main (void)
{
  test_nul_byte ();
  test_low_single_chars ();
  test_high_single_chars ();
  test_double_chars ();
  test_missing_low_surrogate ();
  test_invalid_low_surrogate ();
  return 0;
}

/* Test the behavior of 'utf16_mbtowc' on a NUL byte. */
static void
test_nul_byte (void)
{
  const uint16_t input[1] = { '\0' };
  int result;
  uint32_t wc;

  result = utf16_mbtowc (&wc, input, 1);
  ASSERT (result == 1);
  ASSERT (wc == '\0');
}

/* Test the behavior on single code units in the inclusive range
   0x0000 - 0xd7ff. */
static void
test_low_single_chars (void)
{
  uint16_t input[1];
  int result;
  uint32_t wc, i;

  for (i = 0x0; i < 0x100; ++i)
    {
      input[0] = i;
      result = utf16_mbtowc (&wc, input, 1);
      ASSERT (result == 1);
      ASSERT (wc == i);
    }

  for (i = 0xd700; i < 0xd800; ++i)
    {
      input[0] = i;
      result = utf16_mbtowc (&wc, input, 1);
      ASSERT (result == 1);
      ASSERT (wc == i);
    }
}

/* Test the behavior on single code units in the inclusive range
   0xe000 - 0xffff. */
static void
test_high_single_chars (void)
{
  uint16_t input[1];
  int result;
  uint32_t wc, i;

  for (i = 0xe000; i < 0xe100; ++i)
    {
      input[0] = i;
      result = utf16_mbtowc (&wc, input, 1);
      ASSERT (result == 1);
      ASSERT (wc == i);
    }

  for (i = 0xfeff; i < 0xffff; ++i)
    {
      input[0] = i;
      result = utf16_mbtowc (&wc, input, 1);
      ASSERT (result == 1);
      ASSERT (wc == i);
    }
}

/* Test surrogate pairs. */
static void
test_double_chars (void)
{
  uint16_t input[2];
  int result;
  uint32_t wc;

  input[0] = 0xd800;
  input[1] = 0xdc00;
  result = utf16_mbtowc (&wc, input, 2);
  ASSERT (result == 2);
  ASSERT (wc != 0xfffd);

  input[0] = 0xdbff;
  input[1] = 0xdfff;
  result = utf16_mbtowc (&wc, input, 2);
  ASSERT (result == 2);
  ASSERT (wc != 0xfffd);

  input[0] = 0xd801;
  input[1] = 0xdc37;
  result = utf16_mbtowc (&wc, input, 2);
  ASSERT (result == 2);
  ASSERT (wc == 0x10437);

  input[0] = 0xd852;
  input[1] = 0xdf62;
  result = utf16_mbtowc (&wc, input, 2);
  ASSERT (result == 2);
  ASSERT (wc == 0x24b62);
}

/* Test the behavior when missing a low surrogate after a high surrogate. */
static void
test_missing_low_surrogate (void)
{
  uint16_t input[1];
  int result;
  uint32_t wc;

  input[0] = 0xd800;
  result = utf16_mbtowc (&wc, input, 1);
  ASSERT (result == -2);
  ASSERT (wc == 0xfffd);

  input[0] = 0xdbff;
  result = utf16_mbtowc (&wc, input, 1);
  ASSERT (result == -2);
  ASSERT (wc == 0xfffd);
}

/* Test the behavior when a bad low surrogate follows a valid high
   surrogate. */
static void
test_invalid_low_surrogate (void)
{
  uint16_t input[2];
  int result;
  uint32_t wc;

  input[0] = 0xd800;
  input[1] = 0xe000;
  result = utf16_mbtowc (&wc, input, 2);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  input[0] = 0xdbff;
  input[1] = 0xdbff;
  result = utf16_mbtowc (&wc, input, 2);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);
}
