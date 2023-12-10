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
#define TEST_FILE_NAME "test-chown.tmp"

static void test_chown_no_entry (void);
static void test_chown_trailing_slash (void);
static void test_chown_negative1 (void);

/* Check that 'chown' is declared and works properly.
     TODO: Improve checks with <grp.h> functions. Maybe just use function
     stubs for windows? */
int
main (void)
{
  /* Make sure the test file is removed and errno is zero. */
  (void) remove (TEST_FILE_NAME);
  errno = 0;

  test_chown_no_entry ();
  test_chown_trailing_slash ();
  test_chown_negative1 ();

  /* Cleanup the test file just in case. */
  (void) remove (TEST_FILE_NAME);
  return 0;
}

/* Test that 'chown' fails on files that do not exist. */
static void
test_chown_no_entry (void)
{
  errno = 0;
  ASSERT (chown (TEST_FILE_NAME, -1, -1) == -1);
  if (errno == ENOSYS)
    {
      fprintf (stderr, "chown is not supported on your system.\n");
      exit (77);
    }
  ASSERT (errno == ENOENT);
}

/* Test 'chown' on a file that exists but with a trailing slash character. */
static void
test_chown_trailing_slash (void)
{
  int fd;

  /* Create a file and close the file descriptor. */
  fd = creat (TEST_FILE_NAME, 0600);
  ASSERT (fd >= 0);
  ASSERT (close (fd) == 0);

  /* Test 'chown' on the file with a single trailing slash. */
  errno = 0;
  ASSERT (chown (TEST_FILE_NAME "/", -1, -1) == -1);
  ASSERT (errno == ENOTDIR);

  /* Test 'chown' on the file with two trailing slashes. */
  errno = 0;
  ASSERT (chown (TEST_FILE_NAME "//", -1, -1) == -1);
  ASSERT (errno == ENOTDIR);

  /* Remove the file. */
  ASSERT (remove (TEST_FILE_NAME) == 0);
}

/* Test that chown with a parameter of -1 for the uid/gid does not change the
   corresponding ID. */
static void
test_chown_negative1 (void)
{
  struct stat st1;
  struct stat st2;
  int fd;

  /* Create a file and close the file descriptor. */
  fd = creat (TEST_FILE_NAME, 0600);
  ASSERT (fd >= 0);
  ASSERT (close (fd) == 0);

  /* Get the user and group id. */
  ASSERT (stat (TEST_FILE_NAME, &st1) == 0);

  /* Check that chown with a uid of -1 does nothing. */
  ASSERT (chown (TEST_FILE_NAME, -1, st1.st_gid) == 0);
  ASSERT (stat (TEST_FILE_NAME, &st2) == 0);
  ASSERT (st1.st_uid == st2.st_uid);
  ASSERT (st1.st_gid == st2.st_gid);

  /* Check that chown with a gid of -1 does nothing. */
  ASSERT (chown (TEST_FILE_NAME, st1.st_uid, -1) == 0);
  ASSERT (stat (TEST_FILE_NAME, &st2) == 0);
  ASSERT (st1.st_uid == st2.st_uid);
  ASSERT (st1.st_gid == st2.st_gid);

  /* Check that chown with a uid of -1 and gid of -1 does nothing. */
  ASSERT (chown (TEST_FILE_NAME, -1, -1) == 0);
  ASSERT (stat (TEST_FILE_NAME, &st2) == 0);
  ASSERT (st1.st_uid == st2.st_uid);
  ASSERT (st1.st_gid == st2.st_gid);

  /* Remove the file. */
  ASSERT (remove (TEST_FILE_NAME) == 0);
}
