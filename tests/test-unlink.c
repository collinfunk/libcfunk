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
#define TEST_FILE_NAME "test-unlink.tmp"

static void test_unlink_bad_filename (void);
static void test_unlink_filename_slash (void);

int
main (void)
{

  /* Remove the file from previous tests. Hope unlink works... */
  (void) unlink (TEST_FILE_NAME);
  errno = 0;

  test_unlink_bad_filename ();
  test_unlink_filename_slash ();

  /* Make sure to cleanup any files. */
  (void) unlink (TEST_FILE_NAME);

  return 0;
}

/* Test the 'unlink' function on a file that does not exist. */
static void
test_unlink_bad_filename (void)
{
  errno = 0;
  ASSERT (unlink (TEST_FILE_NAME) == -1);
  ASSERT (errno == ENOENT);
  errno = 0;
}

/* Test the 'unlink' function on a valid filename but with a '/' character
   appended. */
static void
test_unlink_filename_slash (void)
{
  int fd;

  /* Create a file and cleanup the file descriptor. */
  fd = creat (TEST_FILE_NAME, 0600);
  ASSERT (fd >= 0);
  ASSERT (close (fd) == 0);

  /* Make sure 'unlink' works correctly with '/' appended to the file name. */
  errno = 0;
  ASSERT (unlink (TEST_FILE_NAME "/") == -1);
  ASSERT (errno = ENOTDIR);
  errno = 0;
  ASSERT (unlink (TEST_FILE_NAME "//") == -1);
  ASSERT (errno = ENOTDIR);
  errno = 0;

  /* Cleanup the file. */
  ASSERT (unlink (TEST_FILE_NAME) == 0);
}
