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

/* Set by CTest. */
#undef TEST_ENV_VAR
#define TEST_ENV_VAR "TEST_UNSETENV_VALUE"

static void test_unsetenv_empty_name (void);
static void test_unsetenv_equal_name (void);
static void test_unsetenv_works (void);

int
main (void)
{
  test_unsetenv_empty_name ();
  test_unsetenv_equal_name ();
  test_unsetenv_works ();
  return 0;
}

/* Test that calling 'unsetenv' with an empty string returns failure with
   EINVAL. */
static void
test_unsetenv_empty_name (void)
{
  errno = 0;
  ASSERT (unsetenv ("") == -1);
  ASSERT (errno == EINVAL);
  errno = 0;
}

/* Test that calling 'unsetenv' with a string containing '=' returns failure
   with EINVAL. */
static void
test_unsetenv_equal_name (void)
{
  errno = 0;
  ASSERT (unsetenv (TEST_ENV_VAR "=") == -1);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (unsetenv (TEST_ENV_VAR "=value") == -1);
  ASSERT (errno == EINVAL);
  errno = 0;
}

/* Test that 'unsetenv' properly clears an environment variable. */
static void
test_unsetenv_works (void)
{
  char *ptr = getenv (TEST_ENV_VAR);

  /* Print a message incase this was run manually and the variable is not
     set. */
  if (ptr == NULL)
    {
      fprintf (stderr,
               "This test expects to be run from CTest or a shell which sets "
               "the environment variable 'TEST_UNSETENV_VALUE=ok'.\n");
      exit (1);
    }

  /* Unset the environment variable. */
  ASSERT (unsetenv (TEST_ENV_VAR) == 0);

  /* Make sure it was removed. */
  ptr = getenv (TEST_ENV_VAR);
  ASSERT (ptr == NULL);
}
