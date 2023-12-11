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

#define TEST_FILE_NAME "test-lstat.tmp"
#define TEST_LINK_NAME "test-lstat.link.tmp"

int
main (void)
{
  struct stat st;
  int fd;

  /* Remove files from any previous test. */
  unlink (TEST_FILE_NAME);
  unlink (TEST_LINK_NAME);

  /* Stat the current working directory. */
  ASSERT (lstat (".", &st) == 0);
  ASSERT (S_ISDIR (st.st_mode));

  /* Create a file. */
  fd = creat (TEST_FILE_NAME, 0600);
  ASSERT (fd >= 0);
  ASSERT (close (fd) == 0);

  /* Stat the new file. */
  ASSERT (lstat (TEST_FILE_NAME, &st) == 0);
  ASSERT (S_ISREG (st.st_mode));

  /* Create a symbolic link. */
  if (symlink (TEST_FILE_NAME, TEST_LINK_NAME) < 0)
    {
      unlink (TEST_FILE_NAME);
      if (errno == ENOSYS)
        {
          fprintf (stderr, "symlink () not supported.\n");
          exit (77);
        }
      else /* Actual error. */
        {
          fprintf (stderr, "symlink () failed.\n");
          abort ();
        }
    }

  /* Stat the symbolic link. ST should refer to the link itself. */
  ASSERT (lstat (TEST_LINK_NAME, &st) == 0);
  ASSERT (S_ISLNK (st.st_mode));

  /* Cleanup files. */
  ASSERT (unlink (TEST_FILE_NAME) == 0);
  ASSERT (unlink (TEST_LINK_NAME) == 0);

  return 0;
}
