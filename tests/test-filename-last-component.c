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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filename.h"
#include "test-help.h"

struct test_case
{
  const char *file_name;
  const char *expect;
};

static const struct test_case test_cases[] = {
  { "", "" },
  { "/", "" },
  { "//", "" },
  { "///", "" },
  { "/file", "file" },
  { "///file", "file" },
  { "///file/", "file/" },
  { "///dir1/dir2", "dir2" },
  { "///dir1//dir2", "dir2" },
  { "///dir1/dir2/", "dir2/" },
  { "///dir1//dir2/", "dir2/" },
  { "///dir1//dir2//", "dir2//" },
  { "/aaa/bbb/ccc", "ccc" },
  { "///aaa///bbb///ccc", "ccc" },
  { "///aaa///bbb///ccc///", "ccc///" },
#if defined(_WIN32)
  { "c:/", "" },
  { "c:\\", "" },
  { "C://", "" },
  { "a:///", "" },
  { "A:/file", "file" },
  { "a:\\file", "file" },
  { "a:\\file\\", "file\\" },
  { "b:\\dir1\\dir2", "dir2" },
  { "B:\\\\dir1\\dir2", "dir2" },
  { "c:\\\\dir1\\\\dir2\\", "dir2\\" },
  { "C:\\\\dir1\\dir2\\", "dir2\\" },
  { "D:///dir1//dir2//", "dir2//" },
  { "D:/aaa\\bbb\\ccc", "ccc" },
  { "E:///aaa\\\\\\bbb\\\\\\ccc", "ccc" },
  { "E:\\\\\\aaa\\\\\\bbb///ccc///", "ccc///" },
#else
  { "c:/", "c:/" },
  { "c:\\", "c:\\" },
  { "C://", "C://" },
  { "a:///", "a:///" },
  { "A:/file", "file" },
  { "a:\\file", "a:\\file" },
  { "a:\\file\\", "a:\\file\\" },
  { "b:\\dir1\\dir2", "b:\\dir1\\dir2" },
  { "B:\\\\dir1\\dir2", "B:\\\\dir1\\dir2" },
  { "c:\\\\dir1\\\\dir2\\", "c:\\\\dir1\\\\dir2\\" },
  { "C:\\\\dir1\\dir2\\", "C:\\\\dir1\\dir2\\" },
  { "D:///dir1//dir2//", "dir2//" },
  { "D:/aaa\\bbb\\ccc", "aaa\\bbb\\ccc" },
  { "E:///aaa\\\\\\bbb\\\\\\ccc", "aaa\\\\\\bbb\\\\\\ccc" },
  { "E:\\\\\\aaa\\\\\\bbb///ccc///", "ccc///" },
#endif
};

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
  const char *file_name = test->file_name;
  const char *expect = test->expect;
  const char *result = filename_last_component (test->file_name);

  if (strcmp (result, test->expect) != 0)
    {
      fprintf (stderr, "filename_last_component failed with path %s.\n",
               file_name);
      fprintf (stderr, "Got %s, expected %s.\n", result, expect);
      abort ();
    }
}
