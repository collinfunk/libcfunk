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

#undef TEST_DIRECTORY_NAME
#define TEST_DIRECTORY_NAME "test-fchdir.tmp"

static void check_fchdir_supported (void);
static void test_fchdir_ebadf (void);
static void test_fchdir_enotdir (void);
static void test_fchdir_works (void);

int
main (void)
{
  (void) remove (TEST_DIRECTORY_NAME);
  errno = 0;

  check_fchdir_supported ();
  test_fchdir_ebadf ();
  test_fchdir_enotdir ();
  test_fchdir_works ();

  (void) remove (TEST_DIRECTORY_NAME);
  return 0;
}

/* Skip this test with an error message if 'fchdir' is unsupported. */
static void
check_fchdir_supported (void)
{
  errno = 0;
  ASSERT (fchdir (-1) == -1);
  if (errno == ENOSYS)
    {
      fprintf (stderr, "fchdir () not supported on your system.\n");
      exit (77);
    }
}

/* Test 'fchdir' on an invalid file descriptor. */
static void
test_fchdir_ebadf (void)
{
  /* Negative file descriptor. */
  errno = 0;
  ASSERT (fchdir (-1) == -1);
  ASSERT (errno == EBADF);

  /* Positive but unopened file descriptor. */
  (void) close (10);
  errno = 0;
  ASSERT (fchdir (10) == -1);
  ASSERT (errno == EBADF);
}

static void
test_fchdir_enotdir (void)
{
  int fd;

  /* Create a file. */
  fd = creat (TEST_DIRECTORY_NAME, 0600);
  ASSERT (fd >= 0);

  errno = 0;
  ASSERT (fchdir (fd) == -1);
  ASSERT (errno == ENOTDIR);

  /* Close the file descriptor and remove the file. */
  ASSERT (close (fd) == 0);
  ASSERT (remove (TEST_DIRECTORY_NAME) == 0);
}

static void
test_fchdir_works (void)
{
  char *parent_directory1;
  char *parent_directory2;
  char *child_directory1;
  char *child_directory2;
  int parent_fd;
  int child_fd;

  /* Get the current working directory. */
  parent_directory1 = getcwd (NULL, 0);
  ASSERT (parent_directory1 != NULL);
  parent_fd = open (".", O_RDONLY);

  /* Create and enter a new directory. */
  ASSERT (mkdir (TEST_DIRECTORY_NAME, 0700) == 0);
  ASSERT (chdir (TEST_DIRECTORY_NAME) == 0);

  /* Get the current working directory. */
  child_directory1 = getcwd (NULL, 0);
  ASSERT (child_directory1 != NULL);
  child_fd = open (".", O_RDONLY);

  /* Use 'fchdir' to enter the parent directory. */
  ASSERT (fchdir (parent_fd) == 0);
  parent_directory2 = getcwd (NULL, 0);
  ASSERT (parent_directory2 != NULL);

  /* Use 'fchdir' to enter the child directory. */
  ASSERT (fchdir (child_fd) == 0);
  child_directory2 = getcwd (NULL, 0);
  ASSERT (child_directory2 != NULL);

  /* Return to the original directory so the test directory can be removed. */
  ASSERT (fchdir (parent_fd) == 0);

  /* Cleanup. */
  free (parent_directory1);
  free (parent_directory2);
  free (child_directory1);
  free (child_directory2);
  ASSERT (close (parent_fd) == 0);
  ASSERT (close (child_fd) == 0);
  ASSERT (remove (TEST_DIRECTORY_NAME) == 0);
}
