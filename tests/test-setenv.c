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

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test-help.h"

#undef TEST_ENV_VAR
#define TEST_ENV_VAR "TEST_SETENV_VALUE"

static void test_setenv_empty_envname (void);
static void test_setenv_equal_in_envname (void);
static void test_setenv_no_replace (void);
static void test_setenv_replace (void);

int
main (void)
{
  test_setenv_empty_envname ();
  test_setenv_equal_in_envname ();
  test_setenv_no_replace ();
  test_setenv_replace ();
  return 0;
}

/* Test the 'setenv' function with an empty string as the variable name. */
static void
test_setenv_empty_envname (void)
{
  errno = 0;
  ASSERT (setenv ("", "value", 0) == -1);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (setenv ("", "value", 1) == -1);
  ASSERT (errno == EINVAL);
}

/* Test the 'setenv' function with an equal sign in the variable name. */
static void
test_setenv_equal_in_envname (void)
{
  errno = 0;
  ASSERT (setenv ("=", "value", 0) == -1);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (setenv ("=", "value", 1) == -1);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (setenv ("=variable", "value", 0) == -1);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (setenv ("=variable", "value", 1) == -1);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (setenv ("variable=", "value", 0) == -1);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (setenv ("variable=", "value", 1) == -1);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (setenv ("vari=able", "value", 0) == -1);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (setenv ("vari=able", "value", 1) == -1);
  ASSERT (errno == EINVAL);
}

static void
test_setenv_no_replace (void)
{
  char *ptr;

  /* Make sure a few variables are not set. */
  (void) unsetenv (TEST_ENV_VAR "1");
  (void) unsetenv (TEST_ENV_VAR "2");
  (void) unsetenv (TEST_ENV_VAR "3");
  (void) unsetenv (TEST_ENV_VAR "4");
  ASSERT (getenv (TEST_ENV_VAR "1") == NULL);
  ASSERT (getenv (TEST_ENV_VAR "2") == NULL);
  ASSERT (getenv (TEST_ENV_VAR "3") == NULL);
  ASSERT (getenv (TEST_ENV_VAR "4") == NULL);

  /* Set the variables. */
  ASSERT (setenv (TEST_ENV_VAR "1", "a", 0) == 0);
  ASSERT (setenv (TEST_ENV_VAR "2", "aa", 0) == 0);
  ASSERT (setenv (TEST_ENV_VAR "3", "aaa", 0) == 0);
  ASSERT (setenv (TEST_ENV_VAR "4", "", 0) == 0);

  /* Ensure that 'setenv' respects the replace parameter. */
  ASSERT (setenv (TEST_ENV_VAR "1", "b", 0) == 0);
  ASSERT (setenv (TEST_ENV_VAR "2", "bb", 0) == 0);
  ASSERT (setenv (TEST_ENV_VAR "3", "bbb", 0) == 0);
  ASSERT (setenv (TEST_ENV_VAR "4", "a", 0) == 0);

  /* Test the first variable. */
  ptr = getenv (TEST_ENV_VAR "1");
  ASSERT (ptr != NULL);
  ASSERT (strcmp (ptr, "a") == 0);

  /* Test the second variable. */
  ptr = getenv (TEST_ENV_VAR "2");
  ASSERT (ptr != NULL);
  ASSERT (strcmp (ptr, "aa") == 0);

  /* Test the third variable. */
  ptr = getenv (TEST_ENV_VAR "3");
  ASSERT (ptr != NULL);
  ASSERT (strcmp (ptr, "aaa") == 0);

  /* Test the fourth variable. */
  ptr = getenv (TEST_ENV_VAR "4");
  ASSERT (ptr != NULL);
  ASSERT (strcmp (ptr, "") == 0);
}

static void
test_setenv_replace (void)
{
  char *ptr;

  /* Ensure that these are set by the previous test. */
  /* Test the first variable. */
  ptr = getenv (TEST_ENV_VAR "1");
  ASSERT (ptr != NULL);
  ASSERT (strcmp (ptr, "a") == 0);

  /* Test the second variable. */
  ptr = getenv (TEST_ENV_VAR "2");
  ASSERT (ptr != NULL);
  ASSERT (strcmp (ptr, "aa") == 0);

  /* Test the third variable. */
  ptr = getenv (TEST_ENV_VAR "3");
  ASSERT (ptr != NULL);
  ASSERT (strcmp (ptr, "aaa") == 0);

  /* Replace the variables. */
  ASSERT (setenv (TEST_ENV_VAR "1", "b", 1) == 0);
  ASSERT (setenv (TEST_ENV_VAR "2", "bb", 1) == 0);
  ASSERT (setenv (TEST_ENV_VAR "3", "bbb", 1) == 0);

  /* Test the first variable. */
  ptr = getenv (TEST_ENV_VAR "1");
  ASSERT (ptr != NULL);
  ASSERT (strcmp (ptr, "b") == 0);

  /* Test the second variable. */
  ptr = getenv (TEST_ENV_VAR "2");
  ASSERT (ptr != NULL);
  ASSERT (strcmp (ptr, "bb") == 0);

  /* Test the third variable. */
  ptr = getenv (TEST_ENV_VAR "3");
  ASSERT (ptr != NULL);
  ASSERT (strcmp (ptr, "bbb") == 0);
}
