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

#undef TEST_DIRECTORY_NAME
#define TEST_DIRECTORY_NAME "test-chdir.tmp"

static void test_chdir_eacces (void);
static void test_chdir_enoent (void);
static void test_chdir_enotdir (void);
static void test_chdir_works (void);

int
main (void)
{
  (void) remove (TEST_DIRECTORY_NAME);
  errno = 0;

  test_chdir_eacces ();
  test_chdir_enoent ();
  test_chdir_enotdir ();

  (void) remove (TEST_DIRECTORY_NAME);
  return 0;
}

/* Test that 'chdir' respects the given mode. This test does not apply on
   Windows systems. */
static void
test_chdir_eacces (void)
{
#if !HAVE_WINDOWS_H
  {
    ASSERT (mkdir (TEST_DIRECTORY_NAME, 0) == 0);

    errno = 0;
    ASSERT (chdir (TEST_DIRECTORY_NAME) == -1);
    ASSERT (errno == EACCES);

    ASSERT (remove (TEST_DIRECTORY_NAME) == 0);
  }
#endif
}

/* Test 'chdir' on a directory that does not exist. */
static void
test_chdir_enoent (void)
{
  errno = 0;
  ASSERT (chdir (TEST_DIRECTORY_NAME) == -1);
  ASSERT (errno == ENOENT);
}

/* Test 'chdir' on a regular file instead of a directory. */
static void
test_chdir_enotdir (void)
{
  int fd;

  /* Create a file and close the descriptor. */
  fd = creat (TEST_DIRECTORY_NAME, 0600);
  ASSERT (fd >= 0);
  ASSERT (close (fd) == 0);

  /* Try to 'chdir' into the file. */
  errno = 0;
  ASSERT (chdir (TEST_DIRECTORY_NAME) == -1);
  ASSERT (errno == ENOTDIR);

  /* Remove the file. */
  ASSERT (remove (TEST_DIRECTORY_NAME) == 0);
}

/* Test that 'chdir' works on directories. */
static void
test_chdir_works (void)
{
  ASSERT (mkdir (TEST_DIRECTORY_NAME, 0700) == 0);
  ASSERT (chdir (TEST_DIRECTORY_NAME) == 0);
  ASSERT (chdir ("../") == 0);
  ASSERT (rmdir (TEST_DIRECTORY_NAME) == 0);
}
