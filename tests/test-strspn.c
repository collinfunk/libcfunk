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

static void test_none_accept (void);
static void test_all_accept (void);
static void test_some_accept (void);

int
main (void)
{
  test_none_accept ();
  test_all_accept ();
  test_some_accept ();
  return 0;
}

/* Test 'strspn' when none of the string is in the accepted character set. */
static void
test_none_accept (void)
{
  const char input[] = "abcdefghijkl";
  const char charset[] = "123456790";
  size_t result;

  result = strspn (input, charset);
  ASSERT (result == 0);
  ASSERT (input[result] == 'a');
}

/* Test 'strspn' when all of the string is in the accepted character set. */
static void
test_all_accept (void)
{
  const char input[] = "abcdefghijk";
  const char charset[] = "kjihgfedcba1234";
  size_t result;

  result = strspn (input, charset);
  ASSERT (result == 11);
  ASSERT (input[result] == '\0');
}

/* Test 'strspn' when some of the string is in the accepted character set. */
static void
test_some_accept (void)
{
  const char input[] = "abcdef123456";
  const char charset[] = "fedcba";
  size_t result;

  result = strspn (input, charset);
  ASSERT (result == 6);
  ASSERT (input[result] == '1');
}
