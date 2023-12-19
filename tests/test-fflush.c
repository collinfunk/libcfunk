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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "test-help.h"

#undef TEST_FILE_NAME
#define TEST_FILE_NAME "test-fflush.tmp"

static void test_fflush_fseeko_updates_fd (void);

int
main (void)
{
  (void) remove (TEST_FILE_NAME);
  errno = 0;

  test_fflush_fseeko_updates_fd ();

  (void) remove (TEST_FILE_NAME);
  return 0;
}

/* Test that a call to 'fflush' followed by 'fseek' or 'fseeko' updates the
   offset of open underlying file descriptors. */
static void
test_fflush_fseeko_updates_fd (void)
{
  char message[] = "test string";
  char buffer[64];
  FILE *fp;
  int fd;

  /* Create a file. */
  fp = fopen (TEST_FILE_NAME, "wb");
  ASSERT (fp != NULL);

  /* Write to the file and close it. */
  ASSERT (fwrite (message, sizeof (message) - 1, 1, fp) == 1);
  ASSERT (ferror (fp) == 0 && fclose (fp) == 0);

  /* Open the file for reading. */
  fp = fopen (TEST_FILE_NAME, "rb");
  ASSERT (fp != NULL);

  /* Get the streams file descriptor. */
  fd = fileno (fp);
  ASSERT (fd >= 0);

  /* Read 3 bytes from the file. */
  ASSERT (fread (buffer, 1, 3, fp) == 3);

  /* The rest of the file should be buffered. */
  ASSERT (ftello (fp) == 3);
  ASSERT (lseek (fd, 0, SEEK_CUR) != 3);

  /* Check that 'fflush' followed by 'fseek' or 'fseeko' updates the offset. */
  ASSERT (fflush (fp) == 0);
  ASSERT (ftello (fp) == 3);
  ASSERT (lseek (fd, 0, SEEK_CUR) == 3);
  ASSERT (ftello (fp) == 3);

  /* Get the next character. */
  ASSERT (fgetc (fp) == 't');

  /* The rest of the file should be buffered. */
  ASSERT (ftello (fp) == 4);
  ASSERT (lseek (fd, 0, SEEK_CUR) != 4);

  /* Check that 'fflush' followed by 'fseek' or 'fseeko' updates the offset. */
  ASSERT (fflush (fp) == 0);
  ASSERT (ftello (fp) == 4);
  ASSERT (lseek (fd, 0, SEEK_CUR) == 4);
  ASSERT (ftello (fp) == 4);

  /* Get the next character. */
  ASSERT (fgetc (fp) == ' ');

  /* The rest of the file should be buffered. */
  ASSERT (ftello (fp) == 5);
  ASSERT (lseek (fd, 0, SEEK_CUR) != 5);

  /* Check that 'fflush' followed by 'fseek' or 'fseeko' updates the offset. */
  ASSERT (fflush (fp) == 0);
  ASSERT (ftello (fp) == 5);
  ASSERT (lseek (fd, 0, SEEK_CUR) == 5);
  ASSERT (ftello (fp) == 5);

  /* Close and remove the file. */
  ASSERT (ferror (fp) == 0 && fclose (fp) == 0);
  ASSERT (remove (TEST_FILE_NAME) == 0);
}
