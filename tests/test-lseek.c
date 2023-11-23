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
#include <stdlib.h>
#include <unistd.h>

#include "test-help.h"

#undef TEST_FILE_NAME
#define TEST_FILE_NAME "test-lseek.tmp"

static void test_lseek_bad_fd (void);
static void test_lseek_regular_file (void);
static void test_lseek_pipe (void);

int
main (void)
{
  /* Remove any previous files and clear errno. */
  unlink (TEST_FILE_NAME);
  errno = 0;

  /* Perform tests. */
  test_lseek_bad_fd ();
  test_lseek_regular_file ();
  test_lseek_pipe ();

  /* Cleanup any created files. */
  unlink (TEST_FILE_NAME);

  return 0;
}

static void
test_lseek_bad_fd (void)
{
  /* Test seeking on a negative invalid file descriptor. */
  errno = 0;
  ASSERT (lseek (-1, (off_t) 0, SEEK_CUR) == (off_t) -1);
  ASSERT (errno == EBADF);

  /* Test seeking on a positive but closed file descriptor. */
  close (4);
  errno = 0;
  ASSERT (lseek (4, (off_t) 0, SEEK_CUR) == (off_t) -1);
  ASSERT (errno == EBADF);
}

static void
test_lseek_regular_file (void)
{
  int fd;
  char buffer[] = "test";

  /* Create a test file. */
  fd = open (TEST_FILE_NAME, O_CREAT | O_TRUNC | O_RDWR, 0600);
  ASSERT (fd >= 0);

  /* Get the current offset of an empty file. */
  errno = 0;
  ASSERT (lseek (fd, (off_t) 0, SEEK_CUR) == (off_t) 0);
  ASSERT (errno == 0);

  /* Write some data to the file. */
  ASSERT ((size_t) write (fd, buffer, sizeof (buffer)) == sizeof (buffer));

  /* Seek to the end of the file. */
  errno = 0;
  ASSERT (lseek (fd, sizeof (buffer), SEEK_SET) == (off_t) sizeof (buffer));
  ASSERT (errno == 0);

  /* Test rewinding to the start of the file. */
  errno = 0;
  ASSERT (lseek (fd, (off_t) 0, SEEK_SET) == (off_t) 0);
  ASSERT (errno == 0);

  /* Cleanup the file. */
  ASSERT (close (fd) == 0);
  ASSERT (unlink (TEST_FILE_NAME) == 0);
}

static void
test_lseek_pipe (void)
{
  int fds[2];

  /* Poison both file descriptors. */
  fds[0] = -1;
  fds[1] = -1;

  /* Create a pipe. */
  ASSERT (pipe (fds) == 0);

  /* Validate the file descriptors. */
  ASSERT (fds[0] >= 0);
  ASSERT (fds[1] >= 0);

  /* Test that seeking on the pipes fails with ESPIPE. */
  errno = 0;
  ASSERT (lseek (fds[0], (off_t) 0, SEEK_CUR) == -1);
  ASSERT (errno == ESPIPE);
  errno = 0;
  ASSERT (lseek (fds[1], (off_t) 0, SEEK_CUR) == -1);
  ASSERT (errno == ESPIPE);

  /* Cleanup the file descriptors. */
  ASSERT (close (fds[0]) == 0);
  ASSERT (close (fds[1]) == 0);
}
