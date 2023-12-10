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

#include <fnmatch.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

static void test_fnmatch_macros_defined (void);
static void test_fnmatch_no_flags_no_patterns (void);
static void test_fnmatch_casefold_no_patterns (void);
static void test_fnmatch_no_flags_all_question (void);
static void test_fnmatch_no_flags_end_question (void);
static void test_fnmatch_no_flags_start_question (void);
static void test_fnmatch_no_flags_split_question (void);
static void test_fnmatch_no_flags_all_asterisk (void);
static void test_fnmatch_no_flags_end_asterisk (void);
static void test_fnmatch_no_flags_start_asterisk (void);
static void test_fnmatch_no_flags_split_asterisk (void);
static void test_fnmatch_no_flags_char_class_alnum (void);
static void test_fnmatch_no_flags_char_class_alpha (void);
static void test_fnmatch_no_flags_char_class_blank (void);
static void test_fnmatch_no_flags_char_class_cntrl (void);
static void test_fnmatch_no_flags_char_class_digit (void);
static void test_fnmatch_no_flags_char_class_graph (void);
static void test_fnmatch_no_flags_char_class_lower (void);
static void test_fnmatch_no_flags_char_class_print (void);
static void test_fnmatch_no_flags_char_class_punct (void);
static void test_fnmatch_no_flags_char_class_space (void);
static void test_fnmatch_no_flags_char_class_upper (void);
static void test_fnmatch_no_flags_char_class_xdigit (void);

/* Test that 'fnmatch.h' can be included. */
int
main (void)
{
  test_fnmatch_macros_defined ();
  test_fnmatch_no_flags_no_patterns ();
  test_fnmatch_casefold_no_patterns ();
  test_fnmatch_no_flags_all_question ();
  test_fnmatch_no_flags_end_question ();
  test_fnmatch_no_flags_start_question ();
  test_fnmatch_no_flags_split_question ();
  test_fnmatch_no_flags_all_asterisk ();
  test_fnmatch_no_flags_end_asterisk ();
  test_fnmatch_no_flags_start_asterisk ();
  test_fnmatch_no_flags_split_asterisk ();
  test_fnmatch_no_flags_char_class_alnum ();
  test_fnmatch_no_flags_char_class_alpha ();
  test_fnmatch_no_flags_char_class_blank ();
  test_fnmatch_no_flags_char_class_cntrl ();
  test_fnmatch_no_flags_char_class_digit ();
  test_fnmatch_no_flags_char_class_graph ();
  test_fnmatch_no_flags_char_class_lower ();
  test_fnmatch_no_flags_char_class_print ();
  test_fnmatch_no_flags_char_class_punct ();
  test_fnmatch_no_flags_char_class_space ();
  test_fnmatch_no_flags_char_class_upper ();
  test_fnmatch_no_flags_char_class_xdigit ();
  return 0;
}

/* Test that macros are defined properly in 'fnmatch.h'. */
static void
test_fnmatch_macros_defined (void)
{
  /* GNU libc uses 'FNM_FILE_NAME' as an alias for 'FNM_PATHNAME'. */
  ASSERT (FNM_FILE_NAME == FNM_PATHNAME);
  /* The value of 'FNM_NOMATCH' must be any value other than zero. */
  ASSERT (FNM_NOMATCH != 0);
  /* Check that the flag bits for 'fnmatch' are unique. */
  switch (0)
    {
    case FNM_PATHNAME:
      break;
    case FNM_PERIOD:
      break;
    case FNM_NOESCAPE:
      break;
    case FNM_LEADING_DIR:
      break;
    case FNM_CASEFOLD:
      break;
    default:
      break;
    }
}

static void
test_fnmatch_no_flags_no_patterns (void)
{
  /* Match. */
  ASSERT (fnmatch ("", "", 0) == 0);
  ASSERT (fnmatch ("a", "a", 0) == 0);
  ASSERT (fnmatch ("ab", "ab", 0) == 0);
  ASSERT (fnmatch ("abc", "abc", 0) == 0);

  /* No match. Bad case. */
  ASSERT (fnmatch ("a", "A", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("ab", "Ab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("ab", "aB", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("ab", "AB", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("abc", "Abc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("abc", "aBc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("abc", "abC", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("A", "a", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("Ab", "ab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("aB", "ab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("AB", "ab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("Abc", "abc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("aBc", "abc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("abC", "abc", 0) == FNM_NOMATCH);
}

static void
test_fnmatch_casefold_no_patterns (void)
{
  /* Match. */
  ASSERT (fnmatch ("a", "a", FNM_CASEFOLD) == 0);
  ASSERT (fnmatch ("ab", "ab", FNM_CASEFOLD) == 0);
  ASSERT (fnmatch ("abc", "abc", FNM_CASEFOLD) == 0);
  ASSERT (fnmatch ("a", "A", FNM_CASEFOLD) == 0);
  ASSERT (fnmatch ("ab", "Ab", FNM_CASEFOLD) == 0);
  ASSERT (fnmatch ("ab", "aB", FNM_CASEFOLD) == 0);
  ASSERT (fnmatch ("ab", "AB", FNM_CASEFOLD) == 0);
  ASSERT (fnmatch ("abc", "Abc", FNM_CASEFOLD) == 0);
  ASSERT (fnmatch ("abc", "aBc", FNM_CASEFOLD) == 0);
  ASSERT (fnmatch ("abc", "abC", FNM_CASEFOLD) == 0);
  ASSERT (fnmatch ("A", "a", FNM_CASEFOLD) == 0);
  ASSERT (fnmatch ("Ab", "ab", FNM_CASEFOLD) == 0);
  ASSERT (fnmatch ("aB", "ab", FNM_CASEFOLD) == 0);
  ASSERT (fnmatch ("AB", "ab", FNM_CASEFOLD) == 0);
  ASSERT (fnmatch ("Abc", "abc", FNM_CASEFOLD) == 0);
  ASSERT (fnmatch ("aBc", "abc", FNM_CASEFOLD) == 0);
  ASSERT (fnmatch ("abC", "abc", FNM_CASEFOLD) == 0);
}

static void
test_fnmatch_no_flags_all_question (void)
{
  /* Match. */
  ASSERT (fnmatch ("?", "a", 0) == 0);
  ASSERT (fnmatch ("?", "b", 0) == 0);
  ASSERT (fnmatch ("?", "c", 0) == 0);
  ASSERT (fnmatch ("??", "ab", 0) == 0);
  ASSERT (fnmatch ("??", "bc", 0) == 0);
  ASSERT (fnmatch ("??", "ca", 0) == 0);
  ASSERT (fnmatch ("???", "abc", 0) == 0);
  ASSERT (fnmatch ("???", "bca", 0) == 0);
  ASSERT (fnmatch ("???", "cab", 0) == 0);

  /* No match. String is short. */
  ASSERT (fnmatch ("?", "", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("??", "", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("??", "a", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("??", "b", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("??", "c", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("???", "", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("???", "a", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("???", "b", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("???", "c", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("???", "ab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("???", "bc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("???", "ca", 0) == FNM_NOMATCH);

  /* No match. String is long. */
  ASSERT (fnmatch ("?", "ab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("?", "bc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("?", "ca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("?", "abc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("?", "bca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("?", "cab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("??", "abc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("??", "bca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("??", "cab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("???", "abc1", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("???", "bc1a", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("???", "c1ab", 0) == FNM_NOMATCH);
}

static void
test_fnmatch_no_flags_end_question (void)
{
  /* Match. */
  ASSERT (fnmatch ("a?", "ab", 0) == 0);
  ASSERT (fnmatch ("b?", "bc", 0) == 0);
  ASSERT (fnmatch ("c?", "ca", 0) == 0);
  ASSERT (fnmatch ("a??", "abc", 0) == 0);
  ASSERT (fnmatch ("b??", "bca", 0) == 0);
  ASSERT (fnmatch ("c??", "cab", 0) == 0);
  ASSERT (fnmatch ("ab?", "abc", 0) == 0);
  ASSERT (fnmatch ("bc?", "bca", 0) == 0);
  ASSERT (fnmatch ("ca?", "cab", 0) == 0);
  ASSERT (fnmatch ("ab??", "abca", 0) == 0);
  ASSERT (fnmatch ("bc??", "bcab", 0) == 0);
  ASSERT (fnmatch ("ca??", "cabc", 0) == 0);

  /* No match. String is short. */
  ASSERT (fnmatch ("a?", "a", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("b?", "b", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("c?", "c", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("a??", "ab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("b??", "bc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("c??", "ca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("ab?", "ab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("bc?", "bc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("ca?", "ca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("ab??", "abc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("bc??", "bca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("ca??", "cab", 0) == FNM_NOMATCH);

  /* No match. String is long. */
  ASSERT (fnmatch ("a?", "abc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("b?", "bca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("c?", "cab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("a??", "abca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("b??", "bcab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("c??", "cabc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("ab?", "abca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("bc?", "bcab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("ca?", "cabc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("ab??", "abcab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("bc??", "bcabc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("ca??", "cabca", 0) == FNM_NOMATCH);
}

static void
test_fnmatch_no_flags_start_question (void)
{
  /* Match. */
  ASSERT (fnmatch ("?b", "ab", 0) == 0);
  ASSERT (fnmatch ("?c", "bc", 0) == 0);
  ASSERT (fnmatch ("?a", "ca", 0) == 0);
  ASSERT (fnmatch ("??c", "abc", 0) == 0);
  ASSERT (fnmatch ("??a", "bca", 0) == 0);
  ASSERT (fnmatch ("??b", "cab", 0) == 0);
  ASSERT (fnmatch ("?bc", "abc", 0) == 0);
  ASSERT (fnmatch ("?ca", "bca", 0) == 0);
  ASSERT (fnmatch ("?ab", "cab", 0) == 0);
  ASSERT (fnmatch ("??ca", "abca", 0) == 0);
  ASSERT (fnmatch ("??ab", "bcab", 0) == 0);
  ASSERT (fnmatch ("??bc", "cabc", 0) == 0);

  /* No match. String is short. */
  ASSERT (fnmatch ("?b", "b", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("?c", "c", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("?a", "a", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("??c", "bc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("??a", "ca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("??b", "ab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("?bc", "bc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("?ca", "ca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("?ab", "ab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("??ca", "bca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("??ab", "cab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("??bc", "abc", 0) == FNM_NOMATCH);

  /* No match. String is long. */
  ASSERT (fnmatch ("?b", "cab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("?c", "abc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("?a", "bca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("??c", "cabc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("??a", "abca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("??b", "bcab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("?bc", "cabc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("?ca", "abca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("?ab", "bcab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("??ca", "babca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("??ab", "cbcab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("??bc", "acabc", 0) == FNM_NOMATCH);
}

static void
test_fnmatch_no_flags_split_question (void)
{
  /* Match. */
  ASSERT (fnmatch ("a?c", "abc", 0) == 0);
  ASSERT (fnmatch ("b?a", "bca", 0) == 0);
  ASSERT (fnmatch ("c?b", "cab", 0) == 0);
  ASSERT (fnmatch ("a??c", "ab1c", 0) == 0);
  ASSERT (fnmatch ("b??a", "bc1a", 0) == 0);
  ASSERT (fnmatch ("c??b", "ca1b", 0) == 0);

  /* No match. Missing end character. */
  ASSERT (fnmatch ("a?c", "ab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("b?a", "bc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("c?b", "ca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("a??c", "ab1", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("b??a", "bc1", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("c??b", "ca1", 0) == FNM_NOMATCH);

  /* No match. Missing start character. */
  ASSERT (fnmatch ("a?c", "bc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("b?a", "ca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("c?b", "ab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("a??c", "b1c", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("b??a", "c1a", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("c??b", "a1b", 0) == FNM_NOMATCH);

  /* No match. Missing middle character. */
  ASSERT (fnmatch ("a?c", "ac", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("b?a", "ba", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("c?b", "cb", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("a??c", "abc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("b??a", "bca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("c??b", "cab", 0) == FNM_NOMATCH);
}

static void
test_fnmatch_no_flags_all_asterisk (void)
{
  /* Match. */
  ASSERT (fnmatch ("*", "", 0) == 0);
  ASSERT (fnmatch ("**", "", 0) == 0);
  ASSERT (fnmatch ("***", "", 0) == 0);
  ASSERT (fnmatch ("*", "a", 0) == 0);
  ASSERT (fnmatch ("**", "a", 0) == 0);
  ASSERT (fnmatch ("***", "a", 0) == 0);
  ASSERT (fnmatch ("*", "ab", 0) == 0);
  ASSERT (fnmatch ("**", "ab", 0) == 0);
  ASSERT (fnmatch ("***", "ab", 0) == 0);
  ASSERT (fnmatch ("*", "abc", 0) == 0);
  ASSERT (fnmatch ("**", "abc", 0) == 0);
  ASSERT (fnmatch ("***", "abc", 0) == 0);
}

static void
test_fnmatch_no_flags_end_asterisk (void)
{
  /* Match. */
  ASSERT (fnmatch ("a*", "a", 0) == 0);
  ASSERT (fnmatch ("b*", "b", 0) == 0);
  ASSERT (fnmatch ("c*", "c", 0) == 0);
  ASSERT (fnmatch ("a*", "ab", 0) == 0);
  ASSERT (fnmatch ("b*", "bc", 0) == 0);
  ASSERT (fnmatch ("c*", "ca", 0) == 0);
  ASSERT (fnmatch ("a*", "abc", 0) == 0);
  ASSERT (fnmatch ("b*", "bca", 0) == 0);
  ASSERT (fnmatch ("c*", "cab", 0) == 0);
  ASSERT (fnmatch ("a**", "a", 0) == 0);
  ASSERT (fnmatch ("b**", "b", 0) == 0);
  ASSERT (fnmatch ("c**", "c", 0) == 0);
  ASSERT (fnmatch ("a**", "ab", 0) == 0);
  ASSERT (fnmatch ("b**", "bc", 0) == 0);
  ASSERT (fnmatch ("c**", "ca", 0) == 0);
  ASSERT (fnmatch ("a**", "abc", 0) == 0);
  ASSERT (fnmatch ("b**", "bca", 0) == 0);
  ASSERT (fnmatch ("c**", "cab", 0) == 0);

  /* No match. */
  ASSERT (fnmatch ("a*", "b", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("b*", "c", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("c*", "a", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("a*", "bc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("b*", "ca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("c*", "ab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("a*", "bca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("b*", "cab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("c*", "abc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("a**", "b", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("b**", "c", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("c**", "a", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("a**", "bc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("b**", "ca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("c**", "ab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("a**", "bca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("b**", "cab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("c**", "abc", 0) == FNM_NOMATCH);
}

static void
test_fnmatch_no_flags_start_asterisk (void)
{
  /* Match. */
  ASSERT (fnmatch ("*a", "a", 0) == 0);
  ASSERT (fnmatch ("*b", "b", 0) == 0);
  ASSERT (fnmatch ("*c", "c", 0) == 0);
  ASSERT (fnmatch ("*a", "ba", 0) == 0);
  ASSERT (fnmatch ("*b", "ab", 0) == 0);
  ASSERT (fnmatch ("*c", "bc", 0) == 0);
  ASSERT (fnmatch ("*a", "bca", 0) == 0);
  ASSERT (fnmatch ("*b", "cab", 0) == 0);
  ASSERT (fnmatch ("*c", "abc", 0) == 0);
  ASSERT (fnmatch ("**a", "a", 0) == 0);
  ASSERT (fnmatch ("**b", "b", 0) == 0);
  ASSERT (fnmatch ("**c", "c", 0) == 0);
  ASSERT (fnmatch ("**a", "ba", 0) == 0);
  ASSERT (fnmatch ("**b", "ab", 0) == 0);
  ASSERT (fnmatch ("**c", "bc", 0) == 0);
  ASSERT (fnmatch ("**a", "bca", 0) == 0);
  ASSERT (fnmatch ("**b", "cab", 0) == 0);
  ASSERT (fnmatch ("**c", "abc", 0) == 0);

  /* No match. */
  ASSERT (fnmatch ("*a", "b", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("*b", "c", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("*c", "a", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("*a", "ab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("*b", "bc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("*c", "ca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("*a", "cab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("*b", "abc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("*c", "bca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("**a", "b", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("**b", "c", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("**c", "a", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("**a", "ab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("**b", "bc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("**c", "ca", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("**a", "cab", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("**b", "abc", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("**c", "bca", 0) == FNM_NOMATCH);
}

static void
test_fnmatch_no_flags_split_asterisk (void)
{
  /* Match. */
  ASSERT (fnmatch ("a*b", "ab", 0) == 0);
  ASSERT (fnmatch ("a*b", "abb", 0) == 0);
  ASSERT (fnmatch ("a*b", "abbb", 0) == 0);
  ASSERT (fnmatch ("a**b", "ab", 0) == 0);
  ASSERT (fnmatch ("a**b", "abb", 0) == 0);
  ASSERT (fnmatch ("a**b", "abbb", 0) == 0);

  /* No match. Missing end character */
  ASSERT (fnmatch ("a**b", "a", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("a**b", "a", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("a**b", "a", 0) == FNM_NOMATCH);

  /* No match. Missing start character */
  ASSERT (fnmatch ("a**b", "b", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("a**b", "b", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("a**b", "b", 0) == FNM_NOMATCH);
}

static void
test_fnmatch_no_flags_char_class_alnum (void)
{
  /* Match. */
  ASSERT (fnmatch ("[[:alnum:]]", "a", 0) == 0);
  ASSERT (fnmatch ("[[:alnum:]]", "b", 0) == 0);
  ASSERT (fnmatch ("[[:alnum:]]", "c", 0) == 0);
  ASSERT (fnmatch ("[[:alnum:]]", "A", 0) == 0);
  ASSERT (fnmatch ("[[:alnum:]]", "B", 0) == 0);
  ASSERT (fnmatch ("[[:alnum:]]", "C", 0) == 0);
  ASSERT (fnmatch ("[[:alnum:]]", "1", 0) == 0);
  ASSERT (fnmatch ("[[:alnum:]]", "2", 0) == 0);
  ASSERT (fnmatch ("[[:alnum:]]", "3", 0) == 0);
}

static void
test_fnmatch_no_flags_char_class_alpha (void)
{
  /* Match. */
  ASSERT (fnmatch ("[[:alpha:]]", "a", 0) == 0);
  ASSERT (fnmatch ("[[:alpha:]]", "b", 0) == 0);
  ASSERT (fnmatch ("[[:alpha:]]", "c", 0) == 0);
  ASSERT (fnmatch ("[[:alpha:]]", "A", 0) == 0);
  ASSERT (fnmatch ("[[:alpha:]]", "B", 0) == 0);
  ASSERT (fnmatch ("[[:alpha:]]", "C", 0) == 0);

  /* No match. */
  ASSERT (fnmatch ("[[:alpha:]]", "1", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("[[:alpha:]]", "2", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("[[:alpha:]]", "3", 0) == FNM_NOMATCH);
}

static void
test_fnmatch_no_flags_char_class_blank (void)
{
}

static void
test_fnmatch_no_flags_char_class_cntrl (void)
{
}

static void
test_fnmatch_no_flags_char_class_digit (void)
{
}

static void
test_fnmatch_no_flags_char_class_graph (void)
{
}

static void
test_fnmatch_no_flags_char_class_lower (void)
{
  /* Match. */
  ASSERT (fnmatch ("[[:lower:]]", "a", 0) == 0);
  ASSERT (fnmatch ("[[:lower:]]", "b", 0) == 0);
  ASSERT (fnmatch ("[[:lower:]]", "c", 0) == 0);

  /* No match. */
  ASSERT (fnmatch ("[[:lower:]]", "A", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("[[:lower:]]", "B", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("[[:lower:]]", "C", 0) == FNM_NOMATCH);
}

static void
test_fnmatch_no_flags_char_class_print (void)
{
}

static void
test_fnmatch_no_flags_char_class_punct (void)
{
}

static void
test_fnmatch_no_flags_char_class_space (void)
{
}

static void
test_fnmatch_no_flags_char_class_upper (void)
{
  /* Match. */
  ASSERT (fnmatch ("[[:upper:]]", "A", 0) == 0);
  ASSERT (fnmatch ("[[:upper:]]", "B", 0) == 0);
  ASSERT (fnmatch ("[[:upper:]]", "C", 0) == 0);

  /* No match. */
  ASSERT (fnmatch ("[[:upper:]]", "a", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("[[:upper:]]", "b", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("[[:upper:]]", "c", 0) == FNM_NOMATCH);
}

static void
test_fnmatch_no_flags_char_class_xdigit (void)
{
  /* Match. */
  ASSERT (fnmatch ("[[:xdigit:]]", "0", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "1", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "2", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "3", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "4", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "5", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "6", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "7", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "8", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "9", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "a", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "b", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "c", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "d", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "e", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "f", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "A", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "B", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "C", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "D", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "E", 0) == 0);
  ASSERT (fnmatch ("[[:xdigit:]]", "F", 0) == 0);

  /* No match. */
  ASSERT (fnmatch ("[[:xdigit:]]", "g", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("[[:xdigit:]]", "h", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("[[:xdigit:]]", "i", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("[[:xdigit:]]", "G", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("[[:xdigit:]]", "H", 0) == FNM_NOMATCH);
  ASSERT (fnmatch ("[[:xdigit:]]", "I", 0) == FNM_NOMATCH);
}
