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

#include "test-help.h"
#include "unicode.h"

struct test_case
{
  uint8_t str[4];
  int expect;
};

static struct test_case test_cases[] = {
  { { 0x00, 0x00, 0x00, 0x00 }, 0 },  /* Empty string. */
  { { 0x01, 0x00, 0x00, 0x00 }, 1 },  /* Ascii character. */
  { { 0x79, 0x00, 0x00, 0x00 }, 1 },  /* Ascii character. */
  { { 0x80, 0x00, 0x00, 0x00 }, -1 }, /* Invalid s[0] > 0x80. */
  { { 0xc1, 0xa1, 0x00, 0x00 }, -1 }, /* Invalid s[0] < 0xc2. */
  { { 0xc2, 0x79, 0x00, 0x00 }, -1 }, /* Invalid s[1] < 0x80. */
  { { 0xc2, 0x80, 0x00, 0x00 }, 2 },  /* 2 byte character. */
  { { 0xc2, 0xbf, 0x00, 0x00 }, 2 },  /* 2 byte character. */
  { { 0xc2, 0xc0, 0x00, 0x00 }, -1 }, /* Invalid s[1] > 0xbf. */
  { { 0xc2, 0xbf, 0x00, 0x00 }, 2 },  /* 2 byte character. */
  { { 0xdf, 0x79, 0x00, 0x00 }, -1 }, /* Invalid s[1] < 0x80. */
  { { 0xdf, 0x80, 0x00, 0x00 }, 2 },  /* 2 byte character. */
  { { 0xdf, 0xbf, 0x00, 0x00 }, 2 },  /* 2 byte character. */
  { { 0xdf, 0xc0, 0x00, 0x00 }, -1 }, /* Invalid s[1] > 0xbf. */
  { { 0xdf, 0xbf, 0x00, 0x00 }, 2 },  /* 2 byte character. */
  { { 0xe0, 0x9f, 0x80, 0x00 }, -1 }, /* Invalid s[1] < 0xa0. */
  { { 0xe0, 0xa0, 0x80, 0x00 }, 3 },  /* Valid 3 byte character. */
  { { 0xe0, 0xbf, 0x80, 0x00 }, 3 },  /* Valid 3 byte character. */
  { { 0xe0, 0xa0, 0x79, 0x00 }, -1 }, /* Invalid s[2] < 0x80. */
  { { 0xe0, 0xa0, 0xbf, 0x00 }, 3 },  /* Valid 3 byte character. */
  { { 0xe0, 0xa0, 0xc0, 0x00 }, -1 }, /* Invalid s[2] > 0xbf. */
  { { 0xe1, 0x79, 0x80, 0x00 }, -1 }, /* Invalid s[1] < 0x79. */
  { { 0xe1, 0x80, 0x79, 0x00 }, -1 }, /* Invalid s[2] < 0x79. */
  { { 0xe1, 0xc0, 0x80, 0x00 }, -1 }, /* Invalid s[1] > 0xbf. */
  { { 0xe1, 0x80, 0xc0, 0x00 }, -1 }, /* Invalid s[2] > 0xbf. */
  { { 0xe1, 0x80, 0x80, 0x00 }, 3 },  /* Valid 3 byte character. */
  { { 0xec, 0xbf, 0xbf, 0x00 }, 3 },  /* Valid 3 byte character. */
  { { 0xed, 0x79, 0x80, 0x00 }, -1 }, /* Invalid s[1] < 0x80. */
  { { 0xed, 0xa0, 0xbf, 0x00 }, -1 }, /* Invalid s[1] > 0x9f. */
  { { 0xed, 0x80, 0x79, 0x00 }, -1 }, /* Invalid s[2] < 0x80. */
  { { 0xed, 0x9f, 0xc0, 0x00 }, -1 }, /* Invalid s[2] > 0xbf. */
  { { 0xed, 0x80, 0x80, 0x00 }, 3 },  /* Valid 3 byte character. */
  { { 0xed, 0x9f, 0xbf, 0x00 }, 3 },  /* Valid 3 byte character. */
  { { 0xee, 0x79, 0xbf, 0x00 }, -1 }, /* Invalid s[1] < 0x80. */
  { { 0xef, 0xc0, 0x80, 0x00 }, -1 }, /* Invalid s[1] > 0xbf. */
  { { 0xee, 0xbf, 0x79, 0x00 }, -1 }, /* Invalid s[2] < 0x80. */
  { { 0xef, 0x80, 0xc0, 0x00 }, -1 }, /* Invalid s[2] > 0xbf. */
  { { 0xee, 0x80, 0xbf, 0x00 }, 3 },  /* Valid 3 byte character. */
  { { 0xef, 0xbf, 0x80, 0x00 }, 3 },  /* Valid 3 byte character. */
  { { 0xee, 0xbf, 0x80, 0x00 }, 3 },  /* Valid 3 byte character. */
  { { 0xef, 0x80, 0xbf, 0x00 }, 3 },  /* Valid 3 byte character. */
  { { 0xf0, 0x8f, 0x80, 0xbf }, -1 }, /* Invalid s[1] < 0x90. */
  { { 0xf0, 0xc0, 0xbf, 0x80 }, -1 }, /* Invalid s[1] > 0xbf. */
  { { 0xf0, 0x90, 0x79, 0x80 }, -1 }, /* Invalid s[2] < 0x80. */
  { { 0xf0, 0xbf, 0xc0, 0xbf }, -1 }, /* Invalid s[2] > 0xbf. */
  { { 0xf0, 0x90, 0x80, 0xc0 }, -1 }, /* Invalid s[3] > 0xbf. */
  { { 0xf0, 0xbf, 0xbf, 0x79 }, -1 }, /* Invalid s[3] < 0x80. */
  { { 0xf0, 0x90, 0x80, 0x80 }, 4 },  /* Valid 4 byte character. */
  { { 0xf0, 0xbf, 0xbf, 0xbf }, 4 },  /* Valid 4 byte character. */
  { { 0xf0, 0xbf, 0xbf, 0x80 }, 4 },  /* Valid 4 byte character. */
  { { 0xf0, 0x90, 0x80, 0xbf }, 4 },  /* Valid 4 byte character. */
  { { 0xf0, 0xbf, 0xbf, 0xbf }, 4 },  /* Valid 4 byte character. */
  { { 0xf0, 0x90, 0x80, 0x80 }, 4 },  /* Valid 4 byte character. */
  { { 0xf1, 0x79, 0x80, 0xbf }, -1 }, /* Invalid s[1] < 0x80. */
  { { 0xf3, 0xc0, 0xbf, 0x80 }, -1 }, /* Invalid s[1] > 0xbf. */
  { { 0xf1, 0x90, 0x79, 0x80 }, -1 }, /* Invalid s[2] < 0x80. */
  { { 0xf3, 0xbf, 0xc0, 0xbf }, -1 }, /* Invalid s[2] > 0xbf. */
  { { 0xf1, 0x90, 0x80, 0xc0 }, -1 }, /* Invalid s[3] > 0xbf. */
  { { 0xf3, 0xbf, 0xbf, 0x79 }, -1 }, /* Invalid s[3] < 0x80. */
  { { 0xf1, 0x80, 0x80, 0x80 }, 4 },  /* Valid 4 byte character. */
  { { 0xf3, 0xbf, 0xbf, 0xbf }, 4 },  /* Valid 4 byte character. */
  { { 0xf1, 0xbf, 0xbf, 0x80 }, 4 },  /* Valid 4 byte character. */
  { { 0xf3, 0x80, 0x80, 0xbf }, 4 },  /* Valid 4 byte character. */
  { { 0xf1, 0xbf, 0xbf, 0xbf }, 4 },  /* Valid 4 byte character. */
  { { 0xf3, 0x80, 0x80, 0x80 }, 4 },  /* Valid 4 byte character. */
  { { 0xf4, 0x79, 0x80, 0xbf }, -1 }, /* Invalid s[1] < 0x80. */
  { { 0xf4, 0x90, 0xbf, 0x80 }, -1 }, /* Invalid s[1] > 0x8f. */
  { { 0xf4, 0x90, 0x79, 0x80 }, -1 }, /* Invalid s[2] < 0x80. */
  { { 0xf4, 0x80, 0xc0, 0xbf }, -1 }, /* Invalid s[2] > 0xbf. */
  { { 0xf4, 0x90, 0x80, 0xc0 }, -1 }, /* Invalid s[3] > 0xbf. */
  { { 0xf4, 0x80, 0xbf, 0x79 }, -1 }, /* Invalid s[3] < 0x80. */
  { { 0xf4, 0x80, 0x80, 0x80 }, 4 },  /* Valid 4 byte character. */
  { { 0xf4, 0x8f, 0xbf, 0xbf }, 4 },  /* Valid 4 byte character. */
  { { 0xf4, 0x8f, 0xbf, 0x80 }, 4 },  /* Valid 4 byte character. */
  { { 0xf4, 0x80, 0x80, 0xbf }, 4 },  /* Valid 4 byte character. */
  { { 0xf4, 0x8f, 0xbf, 0xbf }, 4 },  /* Valid 4 byte character. */
  { { 0xf4, 0x80, 0x80, 0x80 }, 4 },  /* Valid 4 byte character. */
};

static void run_test_case (const struct test_case *test);

int
main (void)
{
  size_t i;

  for (i = 0; i < ARRAY_SIZE (test_cases); ++i)
    run_test_case (&test_cases[i]);

  return 0;
}

static void
run_test_case (const struct test_case *test)
{
  int result = utf8_mblen (test->str, 4);
  if (result != test->expect)
    {
      fprintf (stderr, "ERROR: utf8_mblen returned %d, expected %d.\n", result,
               test->expect);
      fprintf (stderr, "{ 0x%02x, 0x%02x, 0x%02x, 0x%02x },\n", test->str[0],
               test->str[1], test->str[2], test->str[3]);
      abort ();
    }
}
