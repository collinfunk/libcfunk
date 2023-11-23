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

#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

#undef TEST_FILE_NAME
#define TEST_FILE_NAME "test-ftell.tmp"

static void test_ftell (void);

int
main (void)
{
  test_ftell ();
  return 0;
}

static void
test_ftell (void)
{
  FILE *fp;
  char buffer[] = "test";

  /* Open a file for reading and writing. Use binary mode since Windows
     'ftell' is inconsistent on text mode streams. */
  fp = fopen (TEST_FILE_NAME, "w+b");
  ASSERT (fp != NULL);

  /* Write some data to the file. */
  ASSERT (fwrite (buffer, 1, sizeof (buffer), fp) == sizeof (buffer));

  /* Check that we are at the end of the file. */
  ASSERT ((size_t) ftell (fp) == sizeof (buffer));

  /* Seek to the start of the file. */
  ASSERT (fseeko (fp, 0, SEEK_SET) == 0);

  /* Check the result of 'ftell'. */
  ASSERT ((size_t) ftell (fp) == 0);

  /* Close the stream and cleanup the file. */
  ASSERT (fclose (fp) == 0);
  ASSERT (unlink (TEST_FILE_NAME) == 0);
}
