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

#undef TEST_DIRECTORY_NAME
#define TEST_DIRECTORY_NAME "test-rmdir.tmp"

static void test_rmdir_bad_dirname (void);
static void test_rmdir_dirname_is_filename (void);
static void test_rmdir_nonempty_directory (void);
static void test_rmdir_single_dot (void);
static void test_rmdir_double_dot (void);

int
main (void)
{
  /* Try to remove any leftovers from previous tests. Hope rmdir works... */
  (void) rmdir (TEST_DIRECTORY_NAME);
  errno = 0;

  test_rmdir_bad_dirname ();
  test_rmdir_dirname_is_filename ();
  test_rmdir_nonempty_directory ();
  test_rmdir_single_dot ();
  test_rmdir_double_dot ();

  /* Make sure to cleanup the directory. */
  (void) rmdir (TEST_DIRECTORY_NAME);

  return 0;
}

/* Test that 'rmdir' works as expected on a directory that does not exist. */
static void
test_rmdir_bad_dirname (void)
{
  errno = 0;
  ASSERT (rmdir (TEST_DIRECTORY_NAME) == -1);
  ASSERT (errno == ENOENT);
  errno = 0;
}

/* Test that 'rmdir' works as expected on names of files. */
static void
test_rmdir_dirname_is_filename (void)
{
  int fd;

  /* Create a file and close the file descriptor. */
  fd = creat (TEST_DIRECTORY_NAME, 0600);
  ASSERT (fd >= 0);
  ASSERT (close (fd) == 0);

  /* Test calling 'rmdir' on the file. */
  errno = 0;
  ASSERT (rmdir (TEST_DIRECTORY_NAME "/") == -1);
  ASSERT (errno == ENOTDIR);
  errno = 0;
  ASSERT (rmdir (TEST_DIRECTORY_NAME) == -1);
  ASSERT (errno == ENOTDIR);
  errno = 0;

  /* Remove the file. */
  ASSERT (unlink (TEST_DIRECTORY_NAME) == 0);
}

/* Test that 'rmdir' works as expected on non-empty directories. */
static void
test_rmdir_nonempty_directory (void)
{
  int fd;

  /* Create a directory. */
  ASSERT (mkdir (TEST_DIRECTORY_NAME, 0700) == 0);

  /* Create a file inside the directory and close the descriptor. */
  fd = creat (TEST_DIRECTORY_NAME "/file.tmp", 0600);
  ASSERT (fd >= 0);
  ASSERT (close (fd) == 0);

  /* Test 'rmdir' on the non-empty directory. */
  errno = 0;
  ASSERT (rmdir (TEST_DIRECTORY_NAME) == -1);
  ASSERT (errno == EEXIST || errno == ENOTEMPTY);
  errno = 0;

  /* Remove the file and then the directory. */
  ASSERT (unlink (TEST_DIRECTORY_NAME "/file.tmp") == 0);
  ASSERT (rmdir (TEST_DIRECTORY_NAME) == 0);
}

/* Test that 'rmdir' works as expected when the last path component is a single
   dot. */
static void
test_rmdir_single_dot (void)
{
  errno = 0;
  ASSERT (rmdir (".") == -1);
  /* Could fail with any of these depending on order the system checks. */
  ASSERT (errno == EINVAL || errno == EBUSY || errno == EEXIST
          || errno == ENOTEMPTY);

  /* Create a directory. */
  ASSERT (mkdir (TEST_DIRECTORY_NAME, 0700) == 0);

  /* Do tests with '.' as the last path component. Test it with various numbers
     of trailing slashes. */
  errno = 0;
  ASSERT (rmdir (TEST_DIRECTORY_NAME "/.") == -1);
  ASSERT (errno == EINVAL || errno == EBUSY || errno == EEXIST
          || errno == ENOTEMPTY);
  errno = 0;
  ASSERT (rmdir (TEST_DIRECTORY_NAME "/./") == -1);
  ASSERT (errno == EINVAL || errno == EBUSY || errno == EEXIST
          || errno == ENOTEMPTY);
  errno = 0;
  ASSERT (rmdir (TEST_DIRECTORY_NAME "/.//") == -1);
  ASSERT (errno == EINVAL || errno == EBUSY || errno == EEXIST
          || errno == ENOTEMPTY);
  errno = 0;

  /* Remove the directory. */
  ASSERT (rmdir (TEST_DIRECTORY_NAME) == 0);
}

/* Test that 'rmdir' fails when the last path component is two '.' characters.
   Don't check errno since it is too varied depending on the system. */
static void
test_rmdir_double_dot (void)
{
  /* Test rmdir with ".." as the path name. */
  ASSERT (rmdir ("..") == -1);

  /* Create a directory. */
  ASSERT (mkdir (TEST_DIRECTORY_NAME, 0700) == 0);

  /* Do tests with ".." as the last path component. Test it with various
     numbers of trailing slashes. */
  ASSERT (rmdir (TEST_DIRECTORY_NAME "/..") == -1);
  ASSERT (rmdir (TEST_DIRECTORY_NAME "/../") == -1);
  ASSERT (rmdir (TEST_DIRECTORY_NAME "/..//") == -1);

  /* Remove the directory. */
  ASSERT (rmdir (TEST_DIRECTORY_NAME) == 0);
}
