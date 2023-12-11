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
#define TEST_FILE_NAME "test-creat.tmp"

static void test_creat_missing_parent (void);
static void test_creat_parent_is_file (void);
static void test_creat_trailing_slash (void);
static void test_creat_regular_file (void);
static void test_creat_executable_file (void);

int
main (void)
{
  /* Make sure the test file is removed from previous tests. */
  (void) remove (TEST_FILE_NAME);

  test_creat_missing_parent ();
  test_creat_parent_is_file ();
  test_creat_trailing_slash ();
  test_creat_regular_file ();
  test_creat_executable_file ();

  /* Make sure the test file is removed. */
  (void) remove (TEST_FILE_NAME);
  return 0;
}

/* Test 'creat' fails when the path contains a missing parent directory. */
static void
test_creat_missing_parent (void)
{
  int fd;

  errno = 0;
  fd = creat (TEST_FILE_NAME "/file", 0600);
  ASSERT (fd == -1);
  ASSERT (errno == ENOENT);
}

/* Test that 'creat' fails when the file name contains a parent directory which
   refers to a regular file. */
static void
test_creat_parent_is_file (void)
{
  int fd;

  /* Create a file and close the descriptor. */
  fd = creat (TEST_FILE_NAME, 0600);
  ASSERT (fd >= 0);
  ASSERT (close (fd) == 0);

  /* Try to use the file as a directory. */
  errno = 0;
  fd = creat (TEST_FILE_NAME "/file", 0600);
  ASSERT (fd == -1);
  ASSERT (errno == ENOTDIR);

  /* Remove the file. */
  ASSERT (remove (TEST_FILE_NAME) == 0);
}

/* Test that 'creat' fails when the file name has trailing slashes. */
static void
test_creat_trailing_slash (void)
{
  int fd;

  /* Single trailing slash. */
  errno = 0;
  fd = creat (TEST_FILE_NAME "/", 0600);
  ASSERT (fd == -1);
  ASSERT (errno == ENOTDIR || errno == ENOENT || errno == EISDIR);

  /* Two trailing slashes. */
  errno = 0;
  fd = creat (TEST_FILE_NAME "//", 0600);
  ASSERT (fd == -1);
  ASSERT (errno == ENOTDIR || errno == ENOENT || errno == EISDIR);
}

/* Test that 'creat' can create regular files. */
static void
test_creat_regular_file (void)
{
  int fd;

  /* Create a file and close the descriptor. */
  fd = creat (TEST_FILE_NAME, 0000);
  ASSERT (fd >= 0);
  ASSERT (close (fd) == 0);

  /* Remove the file. */
  ASSERT (remove (TEST_FILE_NAME) == 0);
}

/* Test that 'creat' can create executable files. */
static void
test_creat_executable_file (void)
{
  int fd;

  /* Create an executable file and close the descriptor. */
  fd = creat (TEST_FILE_NAME, 0700);
  ASSERT (fd >= 0);
  ASSERT (close (fd) == 0);

  /* Remove the file. */
  ASSERT (remove (TEST_FILE_NAME) == 0);
}
