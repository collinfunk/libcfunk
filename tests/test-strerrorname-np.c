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

#include <errno.h>
#include <string.h>

#include "test-help.h"

struct test_error_number
{
  int number;      /* Numerical value. */
  const char *str; /* String. */
};

/* Test the error numbers required by C99. */
static const struct test_error_number test_cases[] = {
#ifdef EDOM
  { EDOM, "EDOM" },
#endif
#ifdef EILSEQ
  { EILSEQ, "EILSEQ" },
#endif
#ifdef ERANGE
  { ERANGE, "ERANGE" }
#endif
};

int
main (void)
{
  size_t i;

  for (i = 0; i < ARRAY_SIZE (test_cases); ++i)
    {
      int number = test_cases[i].number;
      const char *str = test_cases[i].str;
      const char *result = strerrorname_np (number);
      ASSERT (result != 0);
      ASSERT (strcmp (result, str) == 0);
    }

  return 0;
}
