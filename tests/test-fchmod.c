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
#define TEST_FILE_NAME "test-fchmod.tmp"

static void test_fchmod_ebadf (void);
static void test_fchmod_works (void);

int
main (void)
{
  /* Make sure the test file is removed and errno is zero. */
  (void) remove (TEST_FILE_NAME);
  errno = 0;

  test_fchmod_ebadf ();
  test_fchmod_works ();

  /* Make sure the test file is removed. */
  (void) remove (TEST_FILE_NAME);
  return 0;
}

/* Test 'fchmod' with invalid file descriptors. */
static void
test_fchmod_ebadf (void)
{
  /* Negative file descriptor. */
  errno = 0;
  ASSERT (fchmod (-1, 0777) == -1);
  ASSERT (errno == EBADF);

  /* Positive but unopened file descriptor. */
  (void) close (10);
  errno = 0;
  ASSERT (fchmod (10, 0777) == -1);
  ASSERT (errno == EBADF);
}

static void
test_fchmod_works (void)
{
  int fd;
  struct stat st;
  size_t i;
  mode_t modes[] = { 0100, 0200, 0300, 0400, 0500, 0600, 0700 };

  fd = creat (TEST_FILE_NAME, 0600);
  ASSERT (fd >= 0);

  for (i = 0; i < ARRAY_SIZE (modes); ++i)
    {
      ASSERT (fchmod (fd, modes[i]) == 0);
      ASSERT (stat (TEST_FILE_NAME, &st) == 0);
      ASSERT ((st.st_mode & 0700) == modes[i]);
    }

  ASSERT (close (fd) == 0);
  ASSERT (remove (TEST_FILE_NAME) == 0);
}
