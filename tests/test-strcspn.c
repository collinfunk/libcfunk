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

static void test_nul_byte (void);
static void test_multiple_1 (void);
static void test_multiple_2 (void);
static void test_multiple_nul (void);

int
main (void)
{
  test_nul_byte ();
  test_multiple_1 ();
  test_multiple_2 ();
  test_multiple_nul ();
  return 0;
}

/* When the second parameter is an empty string. The 'strcspn' function should
   be the same as 'strlen'. */
static void
test_nul_byte (void)
{
  const char input[] = "abcdefghijk";
  const char charset[] = "";
  size_t result;

  result = strcspn (input, charset);
  ASSERT (result == 11);
  ASSERT (input[result] == '\0');
}

/* Test 'strcspn' with 2 delimiters where the first one is in the input
   string. */
static void
test_multiple_1 (void)
{
  const char input[] = "abcdef:ghijk";
  const char charset[] = ":;";
  size_t result;

  result = strcspn (input, charset);
  ASSERT (result == 6);
  ASSERT (input[result] == ':');
}

/* Test 'strcspn' with 2 delimiters where the second one is in the input
   string. */
static void
test_multiple_2 (void)
{
  const char input[] = "abcdef;ghijk";
  const char charset[] = ":;";
  size_t result;

  result = strcspn (input, charset);
  ASSERT (result == 6);
  ASSERT (input[result] == ';');
}

/* Test that 'strcspn' respects the NUL byte when none of the other characters
   are in the input string. */
static void
test_multiple_nul (void)
{
  const char input[] = "abcdefghijk";
  const char charset[] = ":;";
  size_t result;

  result = strcspn (input, charset);
  ASSERT (result == 11);
  ASSERT (input[result] == '\0');
}
