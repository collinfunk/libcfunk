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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filename.h"
#include "test-help.h"

struct test_case
{
  char file_name[128]; /* File names must be null-terminated.
                          Change size if needed. */
  const char *expect;  /* String without extension. */
  bool has_extension;
};

static struct test_case test_cases[] = {
  { "", "", false },
  { "/", "/", false },
  { ".", "", true },
  { "..", ".", true },
  { "...", "..", true },
  { "....", "...", true },
  { "/.", "/", true },
  { "test.txt", "test", true },
  { "dir/file.c", "dir/file", true },
  { "dirwith.dot/file", "dirwith.dot/file", false },
  { "dirwith.dot/file.c", "dirwith.dot/file", true },
};

static void do_test_case (struct test_case *test);

int
main (void)
{
  size_t i;

  for (i = 0; i < ARRAY_SIZE (test_cases); ++i)
    do_test_case (&test_cases[i]);

  return 0;
}

static void
do_test_case (struct test_case *test)
{
  char *file_name = test->file_name;
  bool has_extension = test->has_extension;
  bool result = filename_strip_extension (file_name);

  if (result != has_extension || strcmp (file_name, test->expect) != 0)
    {
      /* Filename is modified, hopefully this is enough to guess. :) */
      fprintf (stderr, "filename_strip_extension failed with path %s.\n",
               file_name);
      fprintf (stderr, "Expected path %s.\n", test->expect);
      fprintf (stderr, "Got %s, got %s.\n", result ? "TRUE" : "FALSE",
               has_extension ? "TRUE" : "FALSE");
      abort ();
    }
}
