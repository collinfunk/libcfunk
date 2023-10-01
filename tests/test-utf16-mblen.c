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
  uint16_t str[2];
  int expect;
};

static struct test_case test_cases[] = {
  { { 0x0000, 0x0000 }, 0 },  /* Empty string. */
  { { 0x0001, 0x0000 }, 1 },  /* Valid 1 word character. */
  { { 0x0079, 0x0000 }, 1 },  /* Valid 1 word character. */
  { { 0xd7ff, 0x0000 }, 1 },  /* Valid 1 word character. */
  { { 0xe000, 0x0000 }, 1 },  /* Valid 1 word character. */
  { { 0xffff, 0x0000 }, 1 },  /* Valid 1 word character. */
  { { 0xd800, 0x0000 }, -1 }, /* Missing low surrogate. */
  { { 0xdbff, 0x0000 }, -1 }, /* Missing low surrogate. */
  { { 0xdc00, 0x0000 }, -1 }, /* Single high surrogate. */
  { { 0xdfff, 0x0000 }, -1 }, /* Single high surrogate. */
  { { 0xd800, 0xdc00 }, 2 },  /* Valid 2 word character. */
  { { 0xdbff, 0xdfff }, 2 },  /* Valid 2 word character. */
  { { 0xd800, 0xdbff }, -1 }, /* 2 high surrogates. */
  { { 0xdbff, 0xd800 }, -1 }, /* 2 high surrogates. */
  { { 0xd800, 0xe000 }, -1 }, /* Single high surrogate. */
  { { 0xdbff, 0xffff }, -1 }, /* Single high surrogate. */
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
  int result = utf16_mblen (test->str, 2);
  if (result != test->expect)
    {
      fprintf (stderr, "ERROR: utf16_mblen returned %d, expected %d.\n",
               result, test->expect);
      fprintf (stderr, "{ 0x%04x, 0x%04x },\n", test->str[0], test->str[1]);
      abort ();
    }
}
