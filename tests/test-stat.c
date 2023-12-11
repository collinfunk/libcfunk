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

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "test-help.h"

#undef TEST_FILE_NAME
#define TEST_FILE_NAME "test-stat.tmp"

static void test_stat_nonexistent_file (void);
static void test_stat_empty_string (void);
static void test_stat_regular_file (void);
static void test_stat_directory (void);
static void test_stat_trailing_slash (void);

int
main (void)
{
  /* Make sure the test file is removed and errno is zero before testing. */
  (void) remove (TEST_FILE_NAME);
  errno = 0;

  test_stat_nonexistent_file ();
  test_stat_empty_string ();
  test_stat_regular_file ();
  test_stat_directory ();
  test_stat_trailing_slash ();

  /* Make sure the file is removed. */
  (void) remove (TEST_FILE_NAME);
  return 0;
}

/* Test the 'stat' function on a file that does not exist. */
static void
test_stat_nonexistent_file (void)
{
  struct stat st;

  errno = 0;
  ASSERT (stat (TEST_FILE_NAME, &st) == -1);
  ASSERT (errno == ENOENT);
}

/* Test the 'stat' function on an empty string. */
static void
test_stat_empty_string (void)
{
  struct stat st;

  errno = 0;
  ASSERT (stat ("", &st) == -1);
  ASSERT (errno == ENOENT);
}

/* Test the 'stat' function on a regular file. */
static void
test_stat_regular_file (void)
{
  int fd;
  struct stat st;

  /* Create a file and close the file descriptor. */
  fd = creat (TEST_FILE_NAME, 0600);
  ASSERT (fd >= 0);
  ASSERT (close (fd) == 0);

  /* Stat the file. */
  ASSERT (stat (TEST_FILE_NAME, &st) == 0);

  /* Test some stat macros. */
  ASSERT (S_ISREG (st.st_mode));
  ASSERT (!S_ISDIR (st.st_mode));

  /* Remove the file. */
  ASSERT (remove (TEST_FILE_NAME) == 0);
}

/* Test the 'stat' function on a directory. */
static void
test_stat_directory (void)
{
  struct stat st;

  /* Create a directory. */
  ASSERT (mkdir (TEST_FILE_NAME, 0700) == 0);

  /* Stat the directory. */
  ASSERT (stat (TEST_FILE_NAME, &st) == 0);

  /* Test some stat macros. */
  ASSERT (S_ISDIR (st.st_mode));
  ASSERT (!S_ISREG (st.st_mode));

  /* Remove the directory. */
  ASSERT (remove (TEST_FILE_NAME) == 0);
}

/* Test the 'stat' function on a regular file with trailing slashes. */
static void
test_stat_trailing_slash (void)
{
  int fd;
  struct stat st;

  /* Create a file and close the file descriptor. */
  fd = creat (TEST_FILE_NAME, 0600);
  ASSERT (fd >= 0);
  ASSERT (close (fd) == 0);

  /* Stat the file with a trailing slash. */
  errno = 0;
  ASSERT (stat (TEST_FILE_NAME "/", &st) == -1);
  ASSERT (errno == ENOTDIR);

  /* Stat the file with 2 trailing slashes. */
  errno = 0;
  ASSERT (stat (TEST_FILE_NAME "//", &st) == -1);
  ASSERT (errno == ENOTDIR);

  /* Remove the file. */
  ASSERT (remove (TEST_FILE_NAME) == 0);
}
