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
#include <stdlib.h>
#include <string.h>

#include "dirname.h"
#include "test-help.h"

struct testcase
{
  const char *file_name;
  const char *dir_name;
};

static const struct testcase test_cases[] = {
  { "", "." },
  { ".", "." },
  { "/", "/" },
  { "//", "/" },
  { "usr", "." },
  { "usr/", "." },
  { "///", "/" },
  { "/usr/", "/" },
  { "/usr/lib", "/usr" },
  { "//usr//lib//", "//usr" },
  { "/home//dwc//test", "/home//dwc" },
  { "/dir1////dir2", "/dir1" },
  { "//dir1////dir2////", "//dir1" },
  { "/dir1/dir2/dir3/file.c", "/dir1/dir2/dir3" },
};

static void try_dirname (const struct testcase *test);

int
main (void)
{
  size_t i;

  for (i = 0; i < ARRAY_SIZE (test_cases); ++i)
    try_dirname (&test_cases[i]);

  return 0;
}

static void
try_dirname (const struct testcase *test)
{
  char *result = get_dirname (test->file_name);
  if (result == NULL)
    {
      fprintf (stderr, "malloc() failed.\n");
      abort ();
    }

  printf ("%s\n", result);
  ASSERT (strcmp (result, test->dir_name) == 0);
  free (result);
}
