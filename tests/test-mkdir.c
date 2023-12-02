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

#include <sys/stat.h>
#include <sys/types.h>

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "test-help.h"

#undef TEST_DIRECTORY_NAME
#define TEST_DIRECTORY_NAME "test-mkdir.tmp"

static void test_mkdir_empty_string (void);
static void test_mkdir_file (void);
static void test_mkdir_missing_parent (void);
static void test_mkdir_words (void);

int
main (void)
{
  /* Make sure the test directory is removed and errno is zero. */
  (void) remove (TEST_DIRECTORY_NAME);
  errno = 0;

  test_mkdir_empty_string ();
  test_mkdir_file ();
  test_mkdir_missing_parent ();
  test_mkdir_words ();

  /* Make sure the test directory is removed. */
  (void) remove (TEST_DIRECTORY_NAME);

  return 0;
}

/* Test 'mkdir' on an empty string. */
static void
test_mkdir_empty_string (void)
{
  errno = 0;
  ASSERT (mkdir ("", 0700) == -1);
  ASSERT (errno == ENOENT);
  errno = 0;
}

/* Test 'mkdir' on a file that exists. */
static void
test_mkdir_file (void)
{
  int fd;

  /* Create a file and close the file descriptor. */
  fd = creat (TEST_DIRECTORY_NAME, 0600);
  ASSERT (fd >= 0);
  ASSERT (close (fd) == 0);

  /* Try to create a directory with the same name as the file. */
  errno = 0;
  ASSERT (mkdir (TEST_DIRECTORY_NAME, 0700) == -1);
  ASSERT (errno == EEXIST);

  /* Same thing but with a trailing slash. */
  errno = 0;
  ASSERT (mkdir (TEST_DIRECTORY_NAME "/", 0700) == -1);
  ASSERT (errno == EEXIST || errno == ENOTDIR);

  /* Cleanup the file. */
  ASSERT (remove (TEST_DIRECTORY_NAME) == 0);
}

/* Test 'mkdir' on a path name which is missing its parent. */
static void
test_mkdir_missing_parent (void)
{
  errno = 0;
  ASSERT (mkdir (TEST_DIRECTORY_NAME "/subdirectory", 0700) == -1);
  ASSERT (errno == ENOENT);
  errno = 0;
  ASSERT (mkdir (TEST_DIRECTORY_NAME "/.", 0700) == -1);
  ASSERT (errno == ENOENT);
  errno = 0;
  ASSERT (mkdir (TEST_DIRECTORY_NAME "/./", 0700) == -1);
  ASSERT (errno == ENOENT);
  errno = 0;
  ASSERT (mkdir (TEST_DIRECTORY_NAME "/.//", 0700) == -1);
  ASSERT (errno == ENOENT);
}

/* Test that 'mkdir' can actually create directories. */
static void
test_mkdir_words (void)
{
  /* Create a directory. */
  ASSERT (mkdir (TEST_DIRECTORY_NAME, 0700) == 0);
  /* Check that it was created. */
  errno = 0;
  ASSERT (mkdir (TEST_DIRECTORY_NAME, 0700) == -1);
  ASSERT (errno == EEXIST);
  /* Same thing but with a trailing slash. */
  errno = 0;
  ASSERT (mkdir (TEST_DIRECTORY_NAME "/", 0700) == -1);
  ASSERT (errno == EEXIST);
  /* Remove the directory. */
  ASSERT (remove (TEST_DIRECTORY_NAME) == 0);
  /* Create it again but with a trailing slash. */
  ASSERT (mkdir (TEST_DIRECTORY_NAME "/", 0700) == 0);
  /* Check that it was created. */
  errno = 0;
  ASSERT (mkdir (TEST_DIRECTORY_NAME, 0700) == -1);
  ASSERT (errno == EEXIST);
  /* Same thing but with a trailing slash. */
  errno = 0;
  ASSERT (mkdir (TEST_DIRECTORY_NAME, 0700) == -1);
  ASSERT (errno == EEXIST);
  /* Remove the directory. */
  ASSERT (remove (TEST_DIRECTORY_NAME) == 0);
}
