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

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "test-help.h"

#undef TEST_FILE_NAME
#define TEST_FILE_NAME "test-pwrite.tmp"

int
main (void)
{
  int fd;
  char buffer[64];
  size_t i;

  unlink (TEST_FILE_NAME);

  /* Open the file. */
  fd = open (TEST_FILE_NAME, O_CREAT | O_TRUNC | O_WRONLY, 0600);
  ASSERT (fd >= 0);

  /* Buffer contains 0, 1, 2, ... 63. */
  for (i = 0; i < sizeof (buffer); ++i)
    buffer[i] = (char) (i & 0xff);

  /* Write the buffer to the file.  */
  ASSERT ((size_t) write (fd, buffer, sizeof (buffer)) == sizeof (buffer));

  /* File contains 0, 1, 2, ... 31, 0, 1, 2, ... 31. */
  ASSERT (
      (size_t) pwrite (fd, buffer, sizeof (buffer) / 2, sizeof (buffer) / 2)
      == sizeof (buffer) / 2);

  ASSERT (close (fd) == 0);

  /* Open the file for reading. */
  fd = open (TEST_FILE_NAME, O_RDONLY);
  ASSERT (fd >= 0);

  /* Read the file. */
  ASSERT ((size_t) read (fd, buffer, sizeof (buffer)) == sizeof (buffer));

  /* Check the first and last byte of the repitition. */
  ASSERT (buffer[0] == 0);
  ASSERT (buffer[sizeof (buffer) / 2 - 1] == 31);
  ASSERT (buffer[sizeof (buffer) / 2] == 0);
  ASSERT (buffer[sizeof (buffer) - 1] == 31);

  /* Cleanup the file. */
  ASSERT (close (fd) == 0);
  ASSERT (unlink (TEST_FILE_NAME) == 0);

  return 0;
}
