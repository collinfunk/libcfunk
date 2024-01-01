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
#undef TEST_LINK_NAME

#define TEST_FILE_NAME "test-link1.tmp"
#define TEST_LINK_NAME "test-link2.tmp"

static void test_link_empty_string (void);
static void test_link_eexist (void);

int
main (void)
{
  /* Make sure the test files are removed and errno is zero. */
  (void) remove (TEST_FILE_NAME);
  (void) remove (TEST_LINK_NAME);
  errno = 0;

  test_link_empty_string ();
  test_link_eexist ();

  /* Cleanup the file system. */
  (void) remove (TEST_FILE_NAME);
  (void) remove (TEST_LINK_NAME);
  return 0;
}

/* Test 'link' with empty strings. */
static void
test_link_empty_string (void)
{
  errno = 0;
  ASSERT (link ("abc", "") == -1);
  ASSERT (errno == ENOENT);

  errno = 0;
  ASSERT (link ("", "abc") == -1);
  ASSERT (errno == ENOENT);

  errno = 0;
  ASSERT (link ("", "") == -1);
  ASSERT (errno == ENOENT);
}

static void
test_link_eexist (void)
{
  int fd;

  /* Create a file and close the descriptor. */
  fd = creat (TEST_FILE_NAME, 0600);
  ASSERT (close (fd) == 0);

  /* Create another file and close the descriptor. */
  fd = creat (TEST_LINK_NAME, 0600);
  ASSERT (close (fd) == 0);

  /* Try to create a link. */
  errno = 0;
  ASSERT (link (TEST_FILE_NAME, TEST_LINK_NAME) == -1);
  ASSERT (errno == EEXIST);

  /* Remove the file and create a directory. */
  ASSERT (remove (TEST_LINK_NAME) == 0);
  ASSERT (mkdir (TEST_LINK_NAME, 0700) == 0);

  /* Try to create a link. */
  errno = 0;
  ASSERT (link (TEST_FILE_NAME, TEST_LINK_NAME) == -1);
  ASSERT (errno == EEXIST);

  /* Remove the files. */
  ASSERT (remove (TEST_FILE_NAME) == 0);
  ASSERT (remove (TEST_LINK_NAME) == 0);
}
