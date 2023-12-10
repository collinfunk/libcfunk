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

#undef TEST_FILE_NAME
#undef TEST_LINK_NAME

#define TEST_FILE_NAME "test-symlink.tmp"
#define TEST_LINK_NAME "test-symlink.link.tmp"

static void test_symlink_nonexistent_file (void);
static void test_symlink_empty_string (void);
static void test_symlink_existing_link (void);

int
main (void)
{
  /* Make sure any files from previous tests are removed. */
  (void) remove (TEST_FILE_NAME);
  (void) remove (TEST_LINK_NAME);
  errno = 0;

  test_symlink_nonexistent_file ();
  test_symlink_empty_string ();
  test_symlink_existing_link ();

  /* Make sure any files are removed. */
  (void) remove (TEST_FILE_NAME);
  (void) remove (TEST_LINK_NAME);
  return 0;
}

/* Test that a symbolic link can be created even if the original file does not
   exist. */
static void
test_symlink_nonexistent_file (void)
{
  int result;

  result = symlink (TEST_FILE_NAME, TEST_LINK_NAME);
  if (result != 0 && errno == ENOSYS)
    {
      fprintf (stderr, "Symbolic links not supported on your system.\n");
      exit (77);
    }
  ASSERT (result == 0);
  ASSERT (remove (TEST_LINK_NAME) == 0);
}

/* Test that 'symlink' fails when the link is an empty string. */
static void
test_symlink_empty_string (void)
{
  errno = 0;
  ASSERT (symlink (TEST_FILE_NAME, "") == -1);
  ASSERT (errno == ENOENT);
}

/* Test that 'symlink' fails when the link is an existing symbolic link. */
static void
test_symlink_existing_link (void)
{
  /* Create a symbolic link. */
  ASSERT (symlink (TEST_FILE_NAME, TEST_LINK_NAME) == 0);

  /* Try to create the symbolic link again. */
  errno = 0;
  ASSERT (symlink (TEST_FILE_NAME, TEST_LINK_NAME) == -1);
  ASSERT (errno == EEXIST);

  /* Remove the link. */
  ASSERT (remove (TEST_LINK_NAME) == 0);
}
