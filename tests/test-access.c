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
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "test-help.h"

#undef TEST_FILE_NAME

#define TEST_FILE_NAME "test-access.tmp"

static void test_access_nonexistent_file (void);
static void test_access_trailing_slash (void);

/* Test that 'access' is declared. */
int
main (void)
{
  /* Make sure the test file is removed and errno is zero before testing. */
  (void) remove (TEST_FILE_NAME);
  errno = 0;

  test_access_nonexistent_file ();
  test_access_trailing_slash ();

  /* Make sure the test file is removed. */
  (void) remove (TEST_FILE_NAME);
  return 0;
}

/* Test that 'access' function on a file that does not exist. */
static void
test_access_nonexistent_file (void)
{
  /* F_OK */
  errno = 0;
  ASSERT (access (TEST_FILE_NAME, F_OK) == -1);
  ASSERT (errno == ENOENT);

  /* R_OK */
  errno = 0;
  ASSERT (access (TEST_FILE_NAME, R_OK) == -1);
  ASSERT (errno == ENOENT);

  /* W_OK */
  errno = 0;
  ASSERT (access (TEST_FILE_NAME, W_OK) == -1);
  ASSERT (errno == ENOENT);

  /* X_OK */
  errno = 0;
  ASSERT (access (TEST_FILE_NAME, X_OK) == -1);
  ASSERT (errno == ENOENT);
}

/* Test 'access' on an existing file but with a trailing slash character. */
static void
test_access_trailing_slash (void)
{
  int fd;

  /* Create a file and close the file descriptor. */
  fd = creat (TEST_FILE_NAME, 0700);
  ASSERT (fd >= 0);
  ASSERT (close (fd) == 0);

  /* F_OK, 1 trailing slash. */
  errno = 0;
  ASSERT (access (TEST_FILE_NAME "/", F_OK) == -1);
  ASSERT (errno == ENOTDIR);

  /* R_OK, 1 trailing slash. */
  errno = 0;
  ASSERT (access (TEST_FILE_NAME "/", R_OK) == -1);
  ASSERT (errno == ENOTDIR);

  /* W_OK, 1 trailing slash. */
  errno = 0;
  ASSERT (access (TEST_FILE_NAME "/", W_OK) == -1);
  ASSERT (errno == ENOTDIR);

  /* X_OK, 1 trailing slash. */
  errno = 0;
  ASSERT (access (TEST_FILE_NAME "/", X_OK) == -1);
  ASSERT (errno == ENOTDIR);

  /* F_OK, 2 trailing slashes. */
  errno = 0;
  ASSERT (access (TEST_FILE_NAME "//", F_OK) == -1);
  ASSERT (errno == ENOTDIR);

  /* R_OK, 2 trailing slashes. */
  errno = 0;
  ASSERT (access (TEST_FILE_NAME "//", R_OK) == -1);
  ASSERT (errno == ENOTDIR);

  /* W_OK, 2 trailing slashes. */
  errno = 0;
  ASSERT (access (TEST_FILE_NAME "//", W_OK) == -1);
  ASSERT (errno == ENOTDIR);

  /* X_OK, 2 trailing slashes. */
  errno = 0;
  ASSERT (access (TEST_FILE_NAME "//", X_OK) == -1);
  ASSERT (errno == ENOTDIR);

  /* Remove the file. */
  ASSERT (remove (TEST_FILE_NAME) == 0);
}
