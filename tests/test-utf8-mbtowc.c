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

static void test_ascii (void);
static void test_valid_2char_range (void);
static void test_valid_3char_range1 (void);
static void test_valid_3char_range2 (void);
static void test_valid_3char_range3 (void);
static void test_valid_3char_range4 (void);
static void test_valid_4char_range1 (void);
static void test_valid_4char_range2 (void);
static void test_valid_4char_range3 (void);
static void test_invalid_2char_range (void);
static void test_invalid_3char_range1 (void);
static void test_invalid_3char_range2 (void);
static void test_invalid_3char_range3 (void);
static void test_invalid_3char_range4 (void);
static void test_invalid_4char_range1 (void);
static void test_invalid_4char_range2 (void);
static void test_invalid_4char_range3 (void);
static void test_conversion (void);

int
main (void)
{
  test_ascii ();
  test_valid_2char_range ();
  test_valid_3char_range1 ();
  test_valid_3char_range2 ();
  test_valid_3char_range3 ();
  test_valid_3char_range4 ();
  test_valid_4char_range1 ();
  test_valid_4char_range2 ();
  test_valid_4char_range3 ();
  test_invalid_2char_range ();
  test_invalid_3char_range1 ();
  test_invalid_3char_range2 ();
  test_invalid_3char_range3 ();
  test_invalid_3char_range4 ();
  test_invalid_4char_range1 ();
  test_invalid_4char_range2 ();
  test_invalid_4char_range3 ();
  test_conversion ();
  return 0;
}

/* Test the valid ASCII characters from 0x00 - 0x7f inclusive. */
static void
test_ascii (void)
{
  uint8_t input[1];
  int i, result;
  uint32_t wc;

  for (i = 0; i < 0x80; ++i)
    {
      input[0] = i;
      result = utf8_mbtowc (&wc, input, 1);
      ASSERT (result == 1);
      ASSERT (wc == (uint32_t) i);
    }
}

/* Test the valid characters made up by 2 8-bit units.
   [0xc2 - 0xdf] [0x80 - 0xbf]
 */
static void
test_valid_2char_range (void)
{
  uint8_t input[2];
  int i, result;
  uint32_t wc;

  input[0] = 0xc2;
  for (i = 0x80; i < 0xa0; ++i)
    {
      input[1] = i;
      result = utf8_mbtowc (&wc, input, 2);
      ASSERT (result == 2);
      ASSERT (wc != 0xfffd);
    }

  input[0] = 0xdf;
  for (i = 0x80; i < 0xa0; ++i)
    {
      input[1] = i;
      result = utf8_mbtowc (&wc, input, 2);
      ASSERT (result == 2);
      ASSERT (wc != 0xfffd);
    }
}

/* Test the valid characters made up by 3 8-bit units.
   [0xe0] [0xa0 - 0xbf] [0x80 - 0xbf]
 */
static void
test_valid_3char_range1 (void)
{
  uint8_t input[3];
  int i, result;
  uint32_t wc;

  input[0] = 0xe0;
  input[1] = 0xa0;
  for (i = 0x80; i < 0xa0; ++i)
    {
      input[2] = i;
      result = utf8_mbtowc (&wc, input, 3);
      ASSERT (result == 3);
      ASSERT (wc != 0xfffd);
    }

  input[1] = 0xbf;
  for (i = 0x80; i < 0xa0; ++i)
    {
      input[2] = i;
      result = utf8_mbtowc (&wc, input, 3);
      ASSERT (result == 3);
      ASSERT (wc != 0xfffd);
    }
}

/* Test the valid characters made up by 3 8-bit units.
   [0xe1 - 0xec] [0x80 - 0xbf] [0x80 - 0xbf]
 */
static void
test_valid_3char_range2 (void)
{
  uint8_t input[3];
  int i, result;
  uint32_t wc;

  input[0] = 0xe1;
  input[1] = 0x80;
  for (i = 0x80; i < 0xa0; ++i)
    {
      input[2] = i;
      result = utf8_mbtowc (&wc, input, 3);
      ASSERT (result == 3);
      ASSERT (wc != 0xfffd);
    }

  input[0] = 0xec;
  input[1] = 0xbf;
  for (i = 0x80; i < 0xa0; ++i)
    {
      input[2] = i;
      result = utf8_mbtowc (&wc, input, 3);
      ASSERT (result == 3);
      ASSERT (wc != 0xfffd);
    }
}

/* Test the valid characters made up by 3 8-bit units.
   [0xed] [0x80 - 0x9f] [0x80 - 0xbf]
 */
static void
test_valid_3char_range3 (void)
{
  uint8_t input[3];
  int i, result;
  uint32_t wc;

  input[0] = 0xed;
  input[1] = 0x80;
  for (i = 0x80; i < 0xa0; ++i)
    {
      input[2] = i;
      result = utf8_mbtowc (&wc, input, 3);
      ASSERT (result == 3);
      ASSERT (wc != 0xfffd);
    }

  input[1] = 0x9f;
  for (i = 0x80; i < 0xa0; ++i)
    {
      input[2] = i;
      result = utf8_mbtowc (&wc, input, 3);
      ASSERT (result == 3);
      ASSERT (wc != 0xfffd);
    }
}

/* Test the valid characters made up by 3 8-bit units.
   [0xee - 0xef] [0x80 - 0xbf] [0x80 - 0xbf]
 */
static void
test_valid_3char_range4 (void)
{
  uint8_t input[3];
  int i, result;
  uint32_t wc;

  input[0] = 0xee;
  input[1] = 0x80;
  for (i = 0x80; i < 0xa0; ++i)
    {
      input[2] = i;
      result = utf8_mbtowc (&wc, input, 3);
      ASSERT (result == 3);
      ASSERT (wc != 0xfffd);
    }

  input[0] = 0xef;
  input[1] = 0xbf;
  for (i = 0x80; i < 0xa0; ++i)
    {
      input[2] = i;
      result = utf8_mbtowc (&wc, input, 3);
      ASSERT (result == 3);
      ASSERT (wc != 0xfffd);
    }
}

/* Test the valid characters made up by 4 8-bit units.
   [0xf0] [0x90 - 0xbf] [0x80 - 0xbf] [0x80 - 0xbf]
 */
static void
test_valid_4char_range1 (void)
{
  uint8_t input[4];
  int i, result;
  uint32_t wc;

  input[0] = 0xf0;
  input[1] = 0x90;
  input[2] = 0x80;
  for (i = 0x80; i < 0xa0; ++i)
    {
      input[3] = i;
      result = utf8_mbtowc (&wc, input, 4);
      ASSERT (result == 4);
      ASSERT (wc != 0xfffd);
    }

  input[1] = 0xbf;
  input[2] = 0xbf;
  for (i = 0x80; i < 0xa0; ++i)
    {
      input[3] = i;
      result = utf8_mbtowc (&wc, input, 4);
      ASSERT (result == 4);
      ASSERT (wc != 0xfffd);
    }
}

/* Test the valid characters made up by 4 8-bit units.
   [0xf1 - 0xf3] [0x80 - 0xbf] [0x80 - 0xbf] [0x80 - 0xbf]
 */
static void
test_valid_4char_range2 (void)
{
  uint8_t input[4];
  int i, result;
  uint32_t wc;

  input[0] = 0xf1;
  input[1] = 0x80;
  input[2] = 0x80;
  for (i = 0x80; i < 0xa0; ++i)
    {
      input[3] = i;
      result = utf8_mbtowc (&wc, input, 4);
      ASSERT (result == 4);
      ASSERT (wc != 0xfffd);
    }

  input[0] = 0xf3;
  input[1] = 0xbf;
  input[2] = 0xbf;
  for (i = 0x80; i < 0xa0; ++i)
    {
      input[3] = i;
      result = utf8_mbtowc (&wc, input, 4);
      ASSERT (result == 4);
      ASSERT (wc != 0xfffd);
    }
}

/* Test the valid characters made up by 4 8-bit units.
   [0xf4] [0x80 - 0x8f] [0x80 - 0xbf] [0x80 - 0xbf]
 */
static void
test_valid_4char_range3 (void)
{
  uint8_t input[4];
  int i, result;
  uint32_t wc;

  input[0] = 0xf4;
  input[1] = 0x80;
  input[2] = 0x80;
  for (i = 0x80; i < 0xbf; ++i)
    {
      input[3] = i;
      result = utf8_mbtowc (&wc, input, 4);
      ASSERT (result == 4);
      ASSERT (wc != 0xfffd);
    }

  input[1] = 0x8f;
  input[2] = 0xbf;
  for (i = 0x80; i < 0xa0; ++i)
    {
      input[3] = i;
      result = utf8_mbtowc (&wc, input, 4);
      ASSERT (result == 4);
      ASSERT (wc != 0xfffd);
    }
}

static void
test_invalid_2char_range (void)
{
  uint8_t input[2];
  int result;
  uint32_t wc;

  /* input[0] < 0xc1 */
  input[0] = 0xc1;
  input[1] = 0xe0;
  result = utf8_mbtowc (&wc, input, 2);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[1] < 0x80 */
  input[0] = 0xc2;
  input[1] = 0x79;
  result = utf8_mbtowc (&wc, input, 2);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[1] > 0xbf */
  input[0] = 0xdf;
  input[1] = 0xc0;
  result = utf8_mbtowc (&wc, input, 2);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);
}

static void
test_invalid_3char_range1 (void)
{
  uint8_t input[3];
  int result;
  uint32_t wc;

  /* input[1] < 0xa0 */
  input[0] = 0xe0;
  input[1] = 0x9f;
  input[2] = 0x80;
  result = utf8_mbtowc (&wc, input, 3);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[1] > 0xbf */
  input[1] = 0xc0;
  input[2] = 0xbf;
  result = utf8_mbtowc (&wc, input, 3);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[2] < 0x80 */
  input[1] = 0x80;
  input[2] = 0x79;
  result = utf8_mbtowc (&wc, input, 3);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[2] > 0xbf */
  input[1] = 0xbf;
  input[2] = 0xc0;
  result = utf8_mbtowc (&wc, input, 3);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);
}

static void
test_invalid_3char_range2 (void)
{
  uint8_t input[3];
  int result;
  uint32_t wc;

  /* input[1] < 0x80 */
  input[0] = 0xe1;
  input[1] = 0x79;
  input[2] = 0x80;
  result = utf8_mbtowc (&wc, input, 3);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[1] > 0xbf */
  input[0] = 0xec;
  input[1] = 0xc0;
  input[2] = 0xbf;
  result = utf8_mbtowc (&wc, input, 3);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[2] < 0x80 */
  input[0] = 0xe1;
  input[1] = 0x80;
  input[2] = 0x79;
  result = utf8_mbtowc (&wc, input, 3);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[2] > 0xbf */
  input[0] = 0xec;
  input[1] = 0xbf;
  input[2] = 0xc0;
  result = utf8_mbtowc (&wc, input, 3);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);
}

static void
test_invalid_3char_range3 (void)
{
  uint8_t input[3];
  int result;
  uint32_t wc;

  /* input[1] < 0x80 */
  input[0] = 0xed;
  input[1] = 0x79;
  input[2] = 0x80;
  result = utf8_mbtowc (&wc, input, 3);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[1] > 0x9f */
  input[1] = 0xa0;
  input[2] = 0xbf;
  result = utf8_mbtowc (&wc, input, 3);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[2] < 0x80 */
  input[1] = 0x80;
  input[2] = 0x79;
  result = utf8_mbtowc (&wc, input, 3);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[2] > 0xbf */
  input[1] = 0x9f;
  input[2] = 0xc0;
  result = utf8_mbtowc (&wc, input, 3);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);
}

static void
test_invalid_3char_range4 (void)
{
  uint8_t input[3];
  int result;
  uint32_t wc;

  /* input[1] < 0x80 */
  input[0] = 0xee;
  input[1] = 0x79;
  input[2] = 0x80;
  result = utf8_mbtowc (&wc, input, 3);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[1] > 0xbf */
  input[0] = 0xef;
  input[1] = 0xc0;
  input[2] = 0xbf;
  result = utf8_mbtowc (&wc, input, 3);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[2] < 0x80 */
  input[0] = 0xee;
  input[1] = 0x80;
  input[2] = 0x79;
  result = utf8_mbtowc (&wc, input, 3);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[2] > 0xbf */
  input[0] = 0xef;
  input[1] = 0xbf;
  input[2] = 0xc0;
  result = utf8_mbtowc (&wc, input, 3);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);
}

static void
test_invalid_4char_range1 (void)
{
  uint8_t input[4];
  int result;
  uint32_t wc;

  /* input[1] < 0x90 */
  input[0] = 0xf0;
  input[1] = 0x8f;
  input[2] = 0x80;
  input[3] = 0xbf;
  result = utf8_mbtowc (&wc, input, 4);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[1] > 0xbf */
  input[1] = 0xc0;
  input[2] = 0xbf;
  input[3] = 0x80;
  result = utf8_mbtowc (&wc, input, 4);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[2] < 0x80 */
  input[1] = 0x80;
  input[2] = 0x79;
  input[3] = 0x80;
  result = utf8_mbtowc (&wc, input, 4);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[2] > 0xbf */
  input[1] = 0xbf;
  input[2] = 0xc0;
  input[3] = 0xbf;
  result = utf8_mbtowc (&wc, input, 4);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[3] < 0x80 */
  input[1] = 0x80;
  input[2] = 0x80;
  input[3] = 0x79;
  result = utf8_mbtowc (&wc, input, 4);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[3] > 0xbf */
  input[1] = 0xbf;
  input[2] = 0xbf;
  input[3] = 0xc0;
  result = utf8_mbtowc (&wc, input, 4);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);
}

static void
test_invalid_4char_range2 (void)
{
  uint8_t input[4];
  int result;
  uint32_t wc;

  /* input[1] < 0x80 */
  input[0] = 0xf1;
  input[1] = 0x79;
  input[2] = 0x80;
  input[3] = 0xbf;
  result = utf8_mbtowc (&wc, input, 4);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[1] > 0xbf */
  input[0] = 0xf3;
  input[1] = 0xc0;
  input[2] = 0xbf;
  input[3] = 0x80;
  result = utf8_mbtowc (&wc, input, 4);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[2] < 0x80 */
  input[0] = 0xf1;
  input[1] = 0x80;
  input[2] = 0x79;
  input[3] = 0x80;
  result = utf8_mbtowc (&wc, input, 4);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[2] > 0xbf */
  input[0] = 0xf3;
  input[1] = 0xbf;
  input[2] = 0xc0;
  input[3] = 0xbf;
  result = utf8_mbtowc (&wc, input, 4);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[3] < 0x80 */
  input[0] = 0xf1;
  input[1] = 0x80;
  input[2] = 0x80;
  input[3] = 0x79;
  result = utf8_mbtowc (&wc, input, 4);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[3] > 0xbf */
  input[0] = 0xf3;
  input[1] = 0xbf;
  input[2] = 0xbf;
  input[3] = 0xc0;
  result = utf8_mbtowc (&wc, input, 4);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);
}

static void
test_invalid_4char_range3 (void)
{
  uint8_t input[4];
  int result;
  uint32_t wc;

  /* input[1] < 0x80 */
  input[0] = 0xf4;
  input[1] = 0x79;
  input[2] = 0x80;
  input[3] = 0xbf;
  result = utf8_mbtowc (&wc, input, 4);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[1] > 0x8f */
  input[1] = 0x90;
  input[2] = 0xbf;
  input[3] = 0x80;
  result = utf8_mbtowc (&wc, input, 4);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[2] < 0x80 */
  input[1] = 0x80;
  input[2] = 0x79;
  input[3] = 0x80;
  result = utf8_mbtowc (&wc, input, 4);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[2] > 0xbf */
  input[1] = 0xbf;
  input[2] = 0xc0;
  input[3] = 0xbf;
  result = utf8_mbtowc (&wc, input, 4);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[3] < 0x80 */
  input[1] = 0x80;
  input[2] = 0x80;
  input[3] = 0x79;
  result = utf8_mbtowc (&wc, input, 4);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);

  /* input[3] > 0xbf */
  input[1] = 0xbf;
  input[2] = 0xbf;
  input[3] = 0xc0;
  result = utf8_mbtowc (&wc, input, 4);
  ASSERT (result == -1);
  ASSERT (wc == 0xfffd);
}

static void
test_conversion (void)
{
  const uint8_t valid1[1] = { 0x79 };
  const uint8_t valid2[2] = { 0xd0, 0x98 };
  const uint8_t valid3[3] = { 0xe2, 0x82, 0xac };
  const uint8_t valid4[4] = { 0xf0, 0x90, 0x8d, 0x88 };
  uint32_t wc;
  int result;
  size_t i;

  /* LATIN SMALL LETTER Y */
  result = utf8_mbtowc (&wc, valid1, 1);
  ASSERT (result == 1);
  ASSERT (wc == 0x79);

  /* CYRILLIC CAPITAL LETTER I */
  result = utf8_mbtowc (&wc, valid2, 2);
  ASSERT (result == 2);
  ASSERT (wc == 0x0418);

  /* EURO SIGN */
  result = utf8_mbtowc (&wc, valid3, 3);
  ASSERT (result == 3);
  ASSERT (wc == 0x20ac);

  /* GOTHIC LETTER HWAIR */
  result = utf8_mbtowc (&wc, valid4, 4);
  ASSERT (result == 4);
  ASSERT (wc == 0x10348);

  /* Test that 'utf8_mblen' respects buffer size when > 0. */
  for (i = 1; i < ARRAY_SIZE (valid2); ++i)
    {
      result = utf8_mbtowc (&wc, valid2, i);
      ASSERT (result == -2);
      ASSERT (wc == 0xfffd);
    }

  for (i = 1; i < ARRAY_SIZE (valid3); ++i)
    {
      result = utf8_mbtowc (&wc, valid3, i);
      ASSERT (result == -2);
      ASSERT (wc == 0xfffd);
    }

  for (i = 0; i < ARRAY_SIZE (valid4); ++i)
    {
      result = utf8_mbtowc (&wc, valid4, i);
      ASSERT (result == -2);
      ASSERT (wc == 0xfffd);
    }
}
