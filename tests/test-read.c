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
#include <string.h>
#include <unistd.h>

#include "test-help.h"

#undef TEST_FILE_NAME
#define TEST_FILE_NAME "test-read.tmp"

static void test_read_invalid_fd (void);
static void test_read_works (void);

int
main (void)
{
  /* Make sure the file from previous tests is removed and errno is zero. */
  (void) remove (TEST_FILE_NAME);
  errno = 0;

  test_read_invalid_fd ();
  test_read_works ();

  /* Make sure the test file is removed. */
  (void) remove (TEST_FILE_NAME);
  return 0;
}

/* Test the 'read' function on invalid file descriptors. */
static void
test_read_invalid_fd (void)
{
  ssize_t result;
  char buffer[128];

  /* Test 'read' on a negative file descriptor. */
  errno = 0;
  result = read (-1, buffer, sizeof (buffer));
  ASSERT (result == -1);
  ASSERT (errno == EBADF);

  /* Make sure file descriptor 10 is closed and read from it. */
  (void) close (10);
  errno = 0;
  result = read (10, buffer, sizeof (buffer));
  ASSERT (result == -1);
  ASSERT (errno == EBADF);
}

/* Test that 'read' works on regular files. */
static void
test_read_works (void)
{
  int fd;
  ssize_t result;
  char buffer[128];
  const char message[] = "Test message";

  /* Create a file. */
  fd = open (TEST_FILE_NAME, O_CREAT | O_TRUNC | O_WRONLY, 0600);
  ASSERT (fd >= 0);

  /* Write to the file. */
  result = write (fd, message, sizeof (message));
  ASSERT (result == (ssize_t) sizeof (message));

  /* Close the file and open it for reading. */
  ASSERT (close (fd) == 0);
  fd = open (TEST_FILE_NAME, O_RDONLY);
  ASSERT (fd >= 0);

  /* Read from the file. */
  result = read (fd, buffer, sizeof (buffer));
  ASSERT (result == (ssize_t) sizeof (message));

  /* Check that the file is correct. */
  ASSERT (memcmp (buffer, message, sizeof (message)) == 0);

  /* Remove the file. */
  ASSERT (close (fd) == 0);
  ASSERT (remove (TEST_FILE_NAME) == 0);
}
