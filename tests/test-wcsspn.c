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
#include <wchar.h>

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

/* Test 'wcsspn' when none of the string is in the accepted character set. */
static void
test_none_accept (void)
{
  const wchar_t input[] = L"abcdefghijkl";
  const wchar_t charset[] = L"123456790";
  size_t result;

  result = wcsspn (input, charset);
  ASSERT (result == 0);
  ASSERT (input[result] == L'a');
}

/* Test 'wcsspn' when all of the string is in the accepted character set. */
static void
test_all_accept (void)
{
  const wchar_t input[] = L"abcdefghijk";
  const wchar_t charset[] = L"kjihgfedcba1234";
  size_t result;

  result = wcsspn (input, charset);
  ASSERT (result == 11);
  ASSERT (input[result] == L'\0');
}

/* Test 'wcsspn' when some of the string is in the accepted character set. */
static void
test_some_accept (void)
{
  const wchar_t input[] = L"abcdef123456";
  const wchar_t charset[] = L"fedcba";
  size_t result;

  result = wcsspn (input, charset);
  ASSERT (result == 6);
  ASSERT (input[result] == L'1');
}
