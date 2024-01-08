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
  const char *directory; /* The directory to add as a prefix. */
  const char *file_name; /* The filename to use. */
  const char *expect;    /* The expected result. */
};

static const struct test_case test_cases[]
    = { { NULL, "strdup", "strdup" },
        { "", "strdup", "strdup" },
        { ".", "strdup", "strdup" },
#ifdef _WIN32
        { "..", "file", "..\\file" },
        { "../", "file", "../file" },
        { "..\\", "file", "..\\file" },
        { "c:", "", "c:" },
        { "c:/", "", "c:/" },
        { "c:\\", "", "c:\\" },
        { "c:", "file", "c:file" },
        { "c:/", "file", "c:/file" },
        { "c:\\", "file", "c:\\file" },
        { "c:", "dir\\file", "c:dir\\file" },
        { "c:/", "dir\\file/", "c:/dir\\file/" },
        { "c:\\", "dir\\file\\", "c:\\dir\\file\\" },
        { "bin", "sh", "bin\\sh" },
        { "bin/", "sh", "bin/sh" },
        { "/bin/", "sh", "/bin/sh" },
        { "/usr/bin", "cc", "/usr/bin\\cc" }
#else
        { "..", "file", "../file" },
        { "../", "file", "../file" },
        { "..\\", "file", "..\\/file" },
        { "c:", "", "c:/" },
        { "c:/", "", "c:/" },
        { "c:\\", "", "c:\\/" },
        { "c:", "file", "c:/file" },
        { "c:/", "file", "c:/file" },
        { "c:\\", "file", "c:\\/file" },
        { "c:", "dir\\file", "c:/dir\\file" },
        { "c:/", "dir\\file/", "c:/dir\\file/" },
        { "c:\\", "dir\\file\\", "c:\\/dir\\file\\" },
        { "bin", "sh", "bin/sh" },
        { "bin/", "sh", "bin/sh" },
        { "/bin/", "sh", "/bin/sh" },
        { "/usr/bin", "cc", "/usr/bin/cc" }
#endif
      };

static void do_test (const struct test_case *test);

int
main (void)
{
  size_t i;

  for (i = 0; i < ARRAY_SIZE (test_cases); ++i)
    do_test (&test_cases[i]);

  return 0;
}

static void
do_test (const struct test_case *test)
{
  const char *directory = test->directory;
  const char *file_name = test->file_name;
  const char *expect = test->expect;
  char *result = filename_join_directory (directory, file_name);

  /* Out of memory. */
  if (result == NULL)
    {
      fprintf (stderr, "filename_join_directory (): Out of memory.\n");
      abort ();
    }

  printf ("%s\n", result);
  ASSERT (strcmp (result, expect) == 0);

  free (result);
}
