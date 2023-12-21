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

#include <glob.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

static void test_glob_pattern_p_none_no_quote (void);
static void test_glob_pattern_p_question_no_quote (void);
static void test_glob_pattern_p_asterisk_no_quote (void);
static void test_glob_pattern_p_open_bracket_no_quote (void);
static void test_glob_pattern_p_close_bracket_no_quote (void);
static void test_glob_pattern_p_special_bracket_no_quote (void);
static void test_glob_pattern_p_trailing_backslash (void);
static void test_glob_pattern_p_question_quote (void);
static void test_glob_pattern_p_asterisk_quote (void);
static void test_glob_pattern_p_open_bracket_quote (void);
static void test_glob_pattern_p_close_bracket_quote (void);
static void test_glob_pattern_p_special_bracket_quote (void);

int
main (void)
{
  test_glob_pattern_p_none_no_quote ();
  test_glob_pattern_p_question_no_quote ();
  test_glob_pattern_p_asterisk_no_quote ();
  test_glob_pattern_p_open_bracket_no_quote ();
  test_glob_pattern_p_close_bracket_no_quote ();
  test_glob_pattern_p_special_bracket_no_quote ();
  test_glob_pattern_p_trailing_backslash ();
  test_glob_pattern_p_question_quote ();
  test_glob_pattern_p_asterisk_quote ();
  test_glob_pattern_p_open_bracket_quote ();
  test_glob_pattern_p_close_bracket_quote ();
  test_glob_pattern_p_special_bracket_quote ();
  return 0;
}

static void
test_glob_pattern_p_none_no_quote (void)
{
  ASSERT (glob_pattern_p ("", 0) == 0);
  ASSERT (glob_pattern_p ("a", 0) == 0);
  ASSERT (glob_pattern_p ("ab", 0) == 0);
  ASSERT (glob_pattern_p ("abc", 0) == 0);
}

static void
test_glob_pattern_p_question_no_quote (void)
{
  ASSERT (glob_pattern_p ("?", 0) == 1);
  ASSERT (glob_pattern_p ("?a", 0) == 1);
  ASSERT (glob_pattern_p ("a?", 0) == 1);
  ASSERT (glob_pattern_p ("?ab", 0) == 1);
  ASSERT (glob_pattern_p ("a?b", 0) == 1);
  ASSERT (glob_pattern_p ("ab?", 0) == 1);
}

static void
test_glob_pattern_p_asterisk_no_quote (void)
{
  ASSERT (glob_pattern_p ("*", 0) == 1);
  ASSERT (glob_pattern_p ("*a", 0) == 1);
  ASSERT (glob_pattern_p ("a*", 0) == 1);
  ASSERT (glob_pattern_p ("*ab", 0) == 1);
  ASSERT (glob_pattern_p ("a*b", 0) == 1);
  ASSERT (glob_pattern_p ("ab*", 0) == 1);
}

static void
test_glob_pattern_p_open_bracket_no_quote (void)
{
  ASSERT (glob_pattern_p ("[", 0) == 0);
  ASSERT (glob_pattern_p ("[[", 0) == 0);
  ASSERT (glob_pattern_p ("[[[", 0) == 0);
}

static void
test_glob_pattern_p_close_bracket_no_quote (void)
{
  ASSERT (glob_pattern_p ("]", 0) == 0);
  ASSERT (glob_pattern_p ("]]", 0) == 0);
  ASSERT (glob_pattern_p ("]]]", 0) == 0);
}

static void
test_glob_pattern_p_special_bracket_no_quote (void)
{
  ASSERT (glob_pattern_p ("[]", 0) == 1);
  ASSERT (glob_pattern_p ("[[]]", 0) == 1);
  ASSERT (glob_pattern_p ("[[[]]]", 0) == 1);
  ASSERT (glob_pattern_p ("[][]", 0) == 1);
  ASSERT (glob_pattern_p ("[][][]", 0) == 1);
}

static void
test_glob_pattern_p_trailing_backslash (void)
{
  ASSERT (glob_pattern_p ("\\", 0) == 0);
  ASSERT (glob_pattern_p ("\\", 1) == 0);
  ASSERT (glob_pattern_p ("a\\", 0) == 0);
  ASSERT (glob_pattern_p ("a\\", 1) == 0);
  ASSERT (glob_pattern_p ("ab\\", 0) == 0);
  ASSERT (glob_pattern_p ("ab\\", 1) == 0);
  ASSERT (glob_pattern_p ("abc\\", 0) == 0);
  ASSERT (glob_pattern_p ("abc\\", 1) == 0);
}

static void
test_glob_pattern_p_question_quote (void)
{
  ASSERT (glob_pattern_p ("\\?", 1) == 0);
  ASSERT (glob_pattern_p ("\\?a\\?", 1) == 0);
  ASSERT (glob_pattern_p ("\\?a\\?b\\?", 1) == 0);
}

static void
test_glob_pattern_p_asterisk_quote (void)
{
  ASSERT (glob_pattern_p ("\\*", 1) == 0);
  ASSERT (glob_pattern_p ("\\*a\\*", 1) == 0);
  ASSERT (glob_pattern_p ("\\*a\\*b\\*", 1) == 0);
}

static void
test_glob_pattern_p_open_bracket_quote (void)
{
  ASSERT (glob_pattern_p ("\\[", 1) == 0);
  ASSERT (glob_pattern_p ("\\[\\[", 1) == 0);
  ASSERT (glob_pattern_p ("\\[\\[\\[", 1) == 0);
}

static void
test_glob_pattern_p_close_bracket_quote (void)
{
  ASSERT (glob_pattern_p ("\\]", 1) == 0);
  ASSERT (glob_pattern_p ("\\]\\]", 1) == 0);
  ASSERT (glob_pattern_p ("\\]\\]\\]", 1) == 0);
}

static void
test_glob_pattern_p_special_bracket_quote (void)
{
  ASSERT (glob_pattern_p ("\\[\\]", 1) == 0);
  ASSERT (glob_pattern_p ("\\[\\[\\]\\]", 1) == 0);
  ASSERT (glob_pattern_p ("\\[\\[\\[\\]\\]\\]", 1) == 0);
  ASSERT (glob_pattern_p ("\\[\\]\\[\\]", 1) == 0);
  ASSERT (glob_pattern_p ("\\[\\]\\[\\]\\[\\]", 1) == 0);
}
