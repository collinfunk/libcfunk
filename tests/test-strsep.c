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

#include "test-help.h"

static void test_single_delimiter (void);
static void test_multiple_delimiters (void);

/* Test that 'strsep' is declared and works properly. */
int
main (void)
{
  test_single_delimiter ();
  test_multiple_delimiters ();
  return 0;
}

/* Test 'strsep' using a single delimiter character (excluding the implicit
   NUL byte in ":"). */
static void
test_single_delimiter (void)
{
  char *result;
  char *input;
  char test_string[] = "/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin";
  const char delimiters[] = ":";

  input = test_string;

  result = strsep (&input, delimiters);
  ASSERT (result == test_string);
  ASSERT (strcmp (result, "/usr/bin") == 0);

  result = strsep (&input, delimiters);
  ASSERT (result == test_string + 9);
  ASSERT (strcmp (result, "/bin") == 0);

  result = strsep (&input, delimiters);
  ASSERT (result == test_string + 14);
  ASSERT (strcmp (result, "/usr/sbin") == 0);

  result = strsep (&input, delimiters);
  ASSERT (result == test_string + 24);
  ASSERT (strcmp (result, "/sbin") == 0);

  result = strsep (&input, delimiters);
  ASSERT (result == test_string + 30);
  ASSERT (strcmp (result, "/usr/local/bin") == 0);

  result = strsep (&input, delimiters);
  ASSERT (result == NULL);
}

/* Test the 'strsep' function using multiple delimiter characters. This test
   is taken from 'test-strtok' and 'test-strtok_r'. */
static void
test_multiple_delimiters (void)
{
  char *result;
  char *input;
  char test_string[]
      = { '1', '2', ' ', '4', '5', '6', '\t', '\t', ' ', 'a', 'b', 'c', '\0' };
  const char delimiters[] = { ' ', '\t', '\0' };

  input = test_string;

  result = strsep (&input, delimiters);
  ASSERT (result == test_string);
  ASSERT (strcmp (result, "12") == 0);

  result = strsep (&input, delimiters);
  ASSERT (result == test_string + 3);
  ASSERT (strcmp (result, "456") == 0);

  result = strsep (&input, delimiters);
  ASSERT (result == test_string + 7);
  ASSERT (*result == '\0');

  result = strsep (&input, delimiters);
  ASSERT (result == test_string + 8);
  ASSERT (*result == '\0');

  result = strsep (&input, delimiters);
  ASSERT (result == test_string + 9);
  ASSERT (strcmp (result, "abc") == 0);

  result = strsep (&input, delimiters);
  ASSERT (result == NULL);
}
