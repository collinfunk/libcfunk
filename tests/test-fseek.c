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
#include <unistd.h>

#include "test-help.h"

#undef TEST_FILE_NAME
#define TEST_FILE_NAME "test-fseek.tmp"

static void test_fseek_clears_eof (void);
static void test_fseek_undo_ungetc (void);

int
main (void)
{
  test_fseek_clears_eof ();
  test_fseek_undo_ungetc ();
  return 0;
}

/* Test that the 'fseek' function resets the end-of-file indicator on the
   stream. */
static void
test_fseek_clears_eof (void)
{
  FILE *fp;
  char buffer[] = "test";

  /* Open a file for reading and writing. */
  fp = fopen (TEST_FILE_NAME, "w+");
  ASSERT (fp != NULL);

  /* Write some data to the file. */
  ASSERT (fwrite (buffer, 1, sizeof (buffer), fp) == sizeof (buffer));

  /* Make sure we are at the end of file. */
  while (fgetc (fp) != EOF)
    ;

  /* Check that fseek resets the end-of-file indicator for the stream. */
  ASSERT (feof (fp));
  ASSERT (fseek (fp, 0, SEEK_END) == 0);
  ASSERT (!feof (fp));

  /* Close the stream and cleanup the file. */
  ASSERT (fclose (fp) == 0);
  ASSERT (unlink (TEST_FILE_NAME) == 0);
}

/* Tests that 'fseek' discards the effect of 'ungetc' on the same stream. */
static void
test_fseek_undo_ungetc (void)
{
  FILE *fp;
  char buffer[] = "test";
  int ch;

  /* Open a file for reading and writing. */
  fp = fopen (TEST_FILE_NAME, "w+");
  ASSERT (fp != NULL);

  /* Write some data to the file. */
  ASSERT (fwrite (buffer, 1, sizeof (buffer), fp) == sizeof (buffer));

  /* Seek to the start of the file. */
  ASSERT (fseek (fp, 0, SEEK_SET) == 0);

  /* Get a character. */
  ch = fgetc (fp);
  ASSERT (ch == 't');

  /* Unget the character and then seek to the following character. */
  ASSERT (ungetc (ch, fp) == ch);
  ASSERT (fseek (fp, 1, SEEK_SET) == 0);

  /* Make sure that the 'ungetc' character was discarded. */
  ch = fgetc (fp);
  ASSERT (ch == 'e');

  /* Close the stream and cleanup the file. */
  ASSERT (fclose (fp) == 0);
  ASSERT (unlink (TEST_FILE_NAME) == 0);
}
