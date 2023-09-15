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
  char file_name[128];
  int trailing_slashes;
};

static struct test_case test_cases[] = {
  { "", 0 },          { "a", 0 },           { "ab", 0 },     { "abc", 0 },
  { "/", 1 },         { "//", 2 },          { "///", 3 },    { "a/", 1 },
  { "a//", 2 },       { "a///", 3 },        { "a/b", 0 },    { "a/b/", 1 },
  { "a/b//", 2 },     { "a/b///", 3 },      { "a/b/c", 0 },  { "a/b/c/", 1 },
  { "a/b/c//", 2 },   { "a/b/c///", 3 },
#if defined(_WIN32)
  { "", 0 },          { "a", 0 },           { "ab", 0 },     { "abc", 0 },
  { "\\", 1 },        { "\\\\", 2 },        { "\\\\\\", 3 }, { "a\\", 1 },
  { "a\\\\", 2 },     { "a\\\\\\", 3 },     { "a/b", 0 },    { "a/b\\", 1 },
  { "a/b\\\\", 2 },   { "a/b\\\\\\", 3 },   { "a/b/c", 0 },  { "a/b/c\\", 1 },
  { "a/b/c\\\\", 2 }, { "a/b/c\\\\\\", 3 },
#else
  { "", 0 },          { "a", 0 },           { "ab", 0 },     { "abc", 0 },
  { "\\", 0 },        { "\\\\", 0 },        { "\\\\\\", 0 }, { "a\\", 0 },
  { "a\\\\", 0 },     { "a\\\\\\", 0 },     { "a/b", 0 },    { "a/b\\", 0 },
  { "a/b\\\\", 0 },   { "a/b\\\\\\", 0 },   { "a/b/c", 0 },  { "a/b/c\\", 0 },
  { "a/b/c\\\\", 0 }, { "a/b/c\\\\\\", 0 },
#endif
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
  char *str = test->file_name;
  size_t len = strlen (str);
  int trailing_slashes = test->trailing_slashes;
  int result = filename_strip_slashes (str);
  char *end = str + len - result;

  ASSERT (result == trailing_slashes);
  ASSERT (end[0] == '\0');
  printf ("%s\n", str);
}
