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
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"
#include "unicode.h"

struct test_case
{
  uint32_t str[1];
  int expect;
};

static struct test_case test_cases[] = {
  { { 0x00000000U }, 0 },  /* Empty string. */
  { { 0x00000001U }, 1 },  /* Valid 1 word character. */
  { { 0x0010ffffU }, 1 },  /* Valid 1 word character. */
  { { 0x0010fffeU }, 1 },  /* Valid 1 word character. */
  { { 0x00110000U }, -1 }, /* Invalid s[0] > 0x10ffff. */
  { { 0x00110001U }, -1 }, /* Invalid s[0] > 0x10ffff. */
  { { 0xffffffffU }, -1 }, /* Invalid s[0] > 0x10ffff. */
  { { 0x0000d7ffU }, 1 },  /* Valid 1 word character. */
  { { 0x0000e000U }, 1 },  /* Valid 1 word character. */
  { { 0x0000d800U }, -1 }, /* Invalid, in surrogate range. */
  { { 0x0000d801U }, -1 }, /* Invalid, in surrogate range. */
  { { 0x0000dffeU }, -1 }, /* Invalid, in surrogate range. */
  { { 0x0000dfffU }, -1 }, /* Invalid, in surrogate range. */
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
  int result = utf32_mblen (test->str, 1);
  if (result != test->expect)
    {
      fprintf (stderr, "ERROR: utf32_mblen returned %d, expected %d.\n",
               result, test->expect);
      fprintf (stderr, "{ 0x%08x },\n", test->str[0]);
      abort ();
    }
}
