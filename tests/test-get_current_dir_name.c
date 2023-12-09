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
#include <unistd.h>

#include "test-help.h"

/* Current directory initialized by 'getcwd'. */
static char *current_directory = NULL;

static void test_get_current_dir_name_PWD_set (void);
static void test_get_current_dir_name_PWD_unset (void);

int
main (void)
{
  /* Initialize 'current_directory' to use for tests. */
  current_directory = getcwd (NULL, 0);
  ASSERT (current_directory != NULL);

  test_get_current_dir_name_PWD_set ();
  test_get_current_dir_name_PWD_unset ();

  /* Cleanup memory. */
  free (current_directory);
  return 0;
}

/* Test 'get_current_dir_name' with the $PWD environment variable set. We
   assume this is set by the users shell. */
static void
test_get_current_dir_name_PWD_set (void)
{
  char *ptr;

  /* Make sure 'current_directory' is set. */
  ASSERT (current_directory != NULL);

  /* Get the current working directory. */
  ptr = get_current_dir_name ();
  ASSERT (ptr != NULL);

  /* Check the result. */
  ASSERT (strcmp (ptr, current_directory) == 0);

  /* Cleanup memory. */
  free (ptr);
}

/* Test 'get_current_dir_name' with the $PWD environment variable unset. */
static void
test_get_current_dir_name_PWD_unset (void)
{
  char *ptr;

  /* Make sure 'current_directory' is set. */
  ASSERT (current_directory != NULL);

  /* Unset the $PWD environment variable. */
  ASSERT (unsetenv ("PWD") == 0);

  /* Get the current working directory. */
  ptr = get_current_dir_name ();
  ASSERT (ptr != NULL);

  /* Check the result. */
  ASSERT (strcmp (ptr, current_directory) == 0);

  /* Cleanup memory. */
  free (ptr);
}
