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
#include <utime.h>

#include "test-help.h"

#undef TEST_FILE_NAME
#define TEST_FILE_NAME "test-utime.tmp"

static void test_utime_no_file (void);
static void test_utime_trailing_slash (void);

int
main (void)
{
  (void) remove (TEST_FILE_NAME);
  errno = 0;

  test_utime_no_file ();
  test_utime_trailing_slash ();

  (void) remove (TEST_FILE_NAME);

  return 0;
}

/* Test 'utime' on a file that does not exist. */
static void
test_utime_no_file (void)
{
  errno = 0;
  ASSERT (utime (TEST_FILE_NAME, NULL) == -1);
  ASSERT (errno == ENOENT);
}

/* Test 'utime' on a file that exists but with a trailing slash character. */
static void
test_utime_trailing_slash (void)
{
  int fd;

  /* Create a file and close the file descriptor. */
  fd = creat (TEST_FILE_NAME, 0600);
  ASSERT (fd >= 0);
  ASSERT (close (fd) == 0);

  /* 1 trailing slash. */
  errno = 0;
  ASSERT (utime (TEST_FILE_NAME "/", NULL) == -1);
  ASSERT (errno == ENOTDIR);

  /* 2 trailing slashes. */
  errno = 0;
  ASSERT (utime (TEST_FILE_NAME "//", NULL) == -1);
  ASSERT (errno == ENOTDIR);

  ASSERT (remove (TEST_FILE_NAME) == 0);
}
