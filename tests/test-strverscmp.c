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
#include <stdlib.h>
#include <string.h>

#include "test-help.h"

struct test_case
{
  const char *str1; /* String 1. */
  const char *str2; /* String 2. */
  int expect;       /* Negative, 0, or positive */
};

static const struct test_case test_cases[]
    = { { "", "", 0 },
        { "same-string", "same-string", 0 },
        { "000", "00", -1 },
        { "00", "01", -1 },
        { "01", "010", -1 },
        { "010", "09", -1 },
        { "09", "0", -1 },
        { "0", "1", -1 },
        { "1", "9", -1 },
        { "9", "10", -1 },
        { "numbers99", "numbers100", -1 },
        { "same-prefix012", "same-prefix01", 1 },
        { "leading-zeros002", "leading-zeros02", -1 } };

static void do_test_case (const struct test_case *test);

int
main (void)
{
  size_t i;

  for (i = 0; i < ARRAY_SIZE (test_cases); ++i)
    do_test_case (&test_cases[i]);

  return 0;
}

static void
do_test_case (const struct test_case *test)
{
  int result = strverscmp (test->str1, test->str2);

  if (test->expect == 0)
    ASSERT (result == 0);
  else if (test->expect < 0)
    {
      ASSERT (result < 0);
      result = strverscmp (test->str2, test->str1);
      ASSERT (result > 0);
    }
  else /* test->expect > 0 */
    {
      ASSERT (result > 0);
      result = strverscmp (test->str2, test->str1);
      ASSERT (result < 0);
    }
}
