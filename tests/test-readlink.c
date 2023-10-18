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
#undef TEST_LINK_NAME

#define TEST_FILE_NAME "test-readlink.tmp"
#define TEST_LINK_NAME "test-readlink.link.tmp"

int
main (void)
{
  int fd;
  char buffer[512];
  ssize_t result;

  /* Remove any files from previous tests. */
  unlink (TEST_FILE_NAME);
  unlink (TEST_LINK_NAME);

  /* Create a file. */
  fd = creat (TEST_FILE_NAME, 0600);
  ASSERT (fd >= 0);
  ASSERT (close (fd) == 0);

  if (symlink (TEST_FILE_NAME, TEST_LINK_NAME) < 0)
    {
      if (errno == ENOSYS)
        {
          fprintf (stderr, "symlink () unsupported on your system.\n");
          exit (1);
        }
      else /* Actual error. */
        {
          fprintf (stderr, "symlink () failed.\n");
          abort ();
        }
    }

  result = readlink (TEST_LINK_NAME, buffer, sizeof (buffer));
  ASSERT (result >= 0 && (size_t) result < sizeof (buffer));
  buffer[result] = '\0';
  ASSERT (strcmp (buffer, TEST_FILE_NAME) == 0);

  /* Cleanup files. */
  ASSERT (unlink (TEST_FILE_NAME) == 0);
  ASSERT (unlink (TEST_LINK_NAME) == 0);

  return 0;
}
