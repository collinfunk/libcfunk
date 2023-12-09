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
#include <unistd.h>

#include "test-help.h"

/* Set by 'test_getcwd_null_0' and used for later tests. */
static size_t current_directory_length = 0;

static void test_getcwd_nonnull_0 (void);
static void test_getcwd_small_buffer (void);
static void test_getcwd_null_0 (void);
static void test_getcwd_null_size (void);
static void test_getcwd_buffer (void);

int
main (void)
{
  test_getcwd_nonnull_0 ();
  test_getcwd_small_buffer ();
  test_getcwd_null_0 ();
  test_getcwd_null_size ();
  test_getcwd_buffer ();
  return 0;
}

/* Test that 'getcwd' fails when given a valid buffer but a size of zero. */
static void
test_getcwd_nonnull_0 (void)
{
  char buffer[2];
  char *ptr;

  errno = 0;
  ptr = getcwd (buffer, 0);
  ASSERT (ptr == NULL);
  ASSERT (errno == EINVAL);
}

/* Test that 'getcwd' fails with ERANGE when given a buffer which is too small
   for the current working directory. This test uses a one byte buffer since
   the shortest directory, the root directory, occupies two bytes. */
static void
test_getcwd_small_buffer (void)
{
  char buffer[1];
  char *ptr;

  errno = 0;
  ptr = getcwd (buffer, sizeof (buffer));
  ASSERT (ptr == NULL);
  ASSERT (errno == ERANGE);
}

/* Test that 'getcwd' allocates memory if given a null pointer and a size
   of zero. */
static void
test_getcwd_null_0 (void)
{
  char *ptr;
  size_t len;

  /* Get the current working directory. */
  ptr = getcwd (NULL, 0);
  ASSERT (ptr != NULL);

  /* Get the length of the current working directory. */
  len = strlen (ptr);
  ASSERT (len > 1);

  /* Cleanup memory. */
  free (ptr);

  /* Set the global variable. */
  current_directory_length = len;
}

/* Test that 'getcwd' allocates memory while respecting the size parameter. */
static void
test_getcwd_null_size (void)
{
  char *ptr;

  /* Missing space for the NUL byte. */
  errno = 0;
  ptr = getcwd (NULL, current_directory_length);
  ASSERT (ptr == NULL);
  ASSERT (errno == ERANGE);

  /* Test that 'getcwd' works. */
  ptr = getcwd (NULL, current_directory_length + 1);
  ASSERT (ptr != NULL);
  ASSERT (strlen (ptr) == current_directory_length);

  /* Cleanup memory. */
  free (ptr);
}

/* Test 'getcwd' with a buffer we allocate. */
static void
test_getcwd_buffer (void)
{
  char *ptr;
  char *result;

  /* Allocate a buffer with enough space for the current directory. */
  ptr = (char *) malloc (current_directory_length + 1);
  ASSERT (ptr != NULL);

  /* Make sure 'getcwd' fails if the path cannot be null terminated. */
  errno = 0;
  result = getcwd (ptr, current_directory_length);
  ASSERT (result == NULL);
  ASSERT (errno == ERANGE);

  /* Test that 'getcwd' works. */
  result = getcwd (ptr, current_directory_length + 1);
  ASSERT (result == ptr);
  ASSERT (strlen (ptr) == current_directory_length);

  /* Cleanup memory. */
  free (ptr);
}
