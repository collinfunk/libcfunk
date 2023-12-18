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
#include <string.h>

#include "test-help.h"

#undef TEST_FILE_NAME

#define TEST_FILE_NAME "test-rewind.tmp"

static void test_rewind (void);

int
main (void)
{
  (void) remove (TEST_FILE_NAME);
  errno = 0;

  test_rewind ();

  (void) remove (TEST_FILE_NAME);
  return 0;
}

static void
test_rewind (void)
{
  char message[] = "test string";
  char buffer[64];
  FILE *fp;

  /* Must be true for test. */
  ASSERT (sizeof (buffer) >= sizeof (message));

  /* Create a file. */
  fp = fopen (TEST_FILE_NAME, "wb");
  ASSERT (fp != NULL);

  /* Write to the file and close it. */
  ASSERT (fwrite (message, sizeof (message) - 1, 1, fp) == 1);
  ASSERT (ferror (fp) == 0 && fclose (fp) == 0);

  /* Open the file for reading. */
  fp = fopen (TEST_FILE_NAME, "rb");
  ASSERT (fp != NULL);

  /* Read and null terminated the string. */
  ASSERT (fread (buffer, 1, sizeof (buffer), fp) == sizeof (message) - 1);
  buffer[sizeof (message) - 1] = '\0';

  /* Check the buffer. */
  ASSERT (memcmp (buffer, message, sizeof (message) - 1) == 0);

  /* Check that we are at the end of the file and then rewind. */
  ASSERT (feof (fp));
  rewind (fp);
  ASSERT (!feof (fp));

  /* Read and null terminated the string. */
  ASSERT (fread (buffer, 1, sizeof (buffer), fp) == sizeof (message) - 1);
  buffer[sizeof (message) - 1] = '\0';

  /* Check the buffer. */
  ASSERT (memcmp (buffer, message, sizeof (message) - 1) == 0);

  /* Check that we are at the end of the file. */
  ASSERT (feof (fp));

  /* Close and remove the file. */
  ASSERT (ferror (fp) == 0 && fclose (fp) == 0);
  ASSERT (remove (TEST_FILE_NAME) == 0);
}
