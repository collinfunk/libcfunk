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
#define TEST_FILE_NAME "test-fread.tmp"

static void test_fread (void);

int
main (void)
{
  (void) remove (TEST_FILE_NAME);
  errno = 0;

  test_fread ();

  (void) remove (TEST_FILE_NAME);
  return 0;
}

static void
test_fread (void)
{
  char message[] = "test string";
  char buffer[64];
  size_t result;
  FILE *fp;
  int fd;

  /* Must be valid for test. */
  ASSERT (sizeof (buffer) >= sizeof (message));

  /* Create a file. */
  fd = creat (TEST_FILE_NAME, 0600);
  ASSERT (fd >= 0);

  /* Write the message to the file and close the descriptor. */
  result = (size_t) write (fd, message, sizeof (message) - 1);
  ASSERT (result == sizeof (message) - 1);
  ASSERT (close (fd) == 0);

  /* Open the file for reading. */
  fp = fopen (TEST_FILE_NAME, "rb");
  ASSERT (fp != NULL);

  /* Read from the file. */
  result = fread (buffer, 1, sizeof (buffer), fp);
  ASSERT (result == sizeof (message) - 1);

  /* Null terminated and check the string. */
  buffer[sizeof (message) - 1] = '\0';
  ASSERT (memcmp (buffer, message, sizeof (message)) == 0);

  /* Close the stream and remove the file. */
  ASSERT (ferror (fp) == 0 && fclose (fp) == 0);
  ASSERT (remove (TEST_FILE_NAME) == 0);
}
