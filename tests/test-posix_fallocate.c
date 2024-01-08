/*-
 * Copyright (c) 2024, Collin Funk
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
#define TEST_FILE_NAME "test-posix_fallocate.tmp"

static void test_posix_fallocate_ebadf (void);
static void test_posix_fallocate_einval (void);
static void test_posix_fallocate_espipe (void);

int
main (void)
{
  (void) remove (TEST_FILE_NAME);

  test_posix_fallocate_ebadf ();
  test_posix_fallocate_einval ();
  test_posix_fallocate_espipe ();

  (void) remove (TEST_FILE_NAME);
  return 0;
}

static void
test_posix_fallocate_ebadf (void)
{
  int result;

  /* Negative file descriptor. */
  result = posix_fallocate (-1, 0, 0);
  ASSERT (result != 0);
  ASSERT (result == EBADF);

  /* Closed but positive file descriptor. */
  (void) close (10);
  result = posix_fallocate (10, 0, 0);
  ASSERT (result != 0);
  ASSERT (result == EBADF);
}

static void
test_posix_fallocate_einval (void)
{
  int fd;
  int result;

  /* Create a file. */
  fd = creat (TEST_FILE_NAME, 0600);
  ASSERT (fd >= 0);

  /* Length argument is zero. */
  result = posix_fallocate (fd, 0, 0);
  ASSERT (result != 0);
  ASSERT (result == EINVAL);

  /* Offset argument is less than zero. */
  result = posix_fallocate (fd, -1, 1);
  ASSERT (result != 0);
  ASSERT (result == EINVAL);

  /* Cleanup the file descriptor and file. */
  ASSERT (close (fd) == 0);
  ASSERT (remove (TEST_FILE_NAME) == 0);
}

/* Linux debian 6.1.0-17-amd64 glibc fails with EBADF */
static void
test_posix_fallocate_espipe (void)
{
  int fds[2];
  int result;

  ASSERT (pipe (fds) == 0);

  result = posix_fallocate (fds[0], 0, 1);
  ASSERT (result != 0);
  ASSERT (result == ESPIPE || result == EBADF);

  result = posix_fallocate (fds[1], 0, 1);
  ASSERT (result != 0);
  ASSERT (result == ESPIPE || result == EBADF);

  ASSERT (close (fds[0]) == 0);
  ASSERT (close (fds[1]) == 0);
}
