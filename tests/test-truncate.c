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
#include <sys/types.h>

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "test-help.h"

#undef TEST_FILE_NAME
#define TEST_FILE_NAME "test-truncate.tmp"

int
main (void)
{
  int fd;
  char buffer[4096];
  struct stat st;
  size_t i;

  /* Cleanup file from previous tests. */
  unlink (TEST_FILE_NAME);

  /* Fill the buffer to avoid uninitialized undefined behavior. */
  for (i = 0; i < sizeof (buffer); ++i)
    buffer[i] = (char) (i & 0xff);

  fd = open (TEST_FILE_NAME, O_RDWR | O_CREAT | O_TRUNC, 0600);
  ASSERT (fd >= 0);

  /* Write some data to the file. */
  ASSERT ((size_t) write (fd, buffer, sizeof (buffer)) == sizeof (buffer));

  /* Truncate it to half the size. */
  ASSERT (truncate (TEST_FILE_NAME, sizeof (buffer) / 2) == 0);
  ASSERT (fstat (fd, &st) == 0);
  ASSERT (st.st_size == sizeof (buffer) / 2);

  /* Truncate it to an empty size. */
  ASSERT (truncate (TEST_FILE_NAME, 0) == 0);
  ASSERT (fstat (fd, &st) == 0);
  ASSERT (st.st_size == 0);

  ASSERT (close (fd) == 0);
  ASSERT (unlink (TEST_FILE_NAME) == 0);

  return 0;
}
