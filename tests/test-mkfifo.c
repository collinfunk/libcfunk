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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "test-help.h"

#undef TEST_FILE_NAME

#define TEST_FILE_NAME "test-mkfifo.tmp"

static void test_mkfifo_supported (void);
static void test_mkfifo_empty_string (void);

/* Test that 'mkfifo' is declared and works properly. */
int
main (void)
{
  /* Make sure the test file is removed and errno is zero before testing. */
  (void) remove (TEST_FILE_NAME);
  errno = 0;

  test_mkfifo_supported ();
  test_mkfifo_empty_string ();

  /* Make sure the file is removed. */
  (void) remove (TEST_FILE_NAME);

  return 0;
}

/* Test that 'mkfifo' is supported before testing its behavior. */
static void
test_mkfifo_supported (void)
{
  int result;
  struct stat st;

  result = mkfifo (TEST_FILE_NAME, 0600);
  if (result == -1 && errno == ENOSYS)
    {
      fprintf (stderr, "mkfifo is not supported on your system.\n");
      exit (77);
    }
  ASSERT (result == 0);
  ASSERT (stat (TEST_FILE_NAME, &st) == 0);
  ASSERT (S_ISFIFO (st.st_mode));
  ASSERT (remove (TEST_FILE_NAME) == 0);
}

/* Test 'mkfifo' when given an empty string as the file name. */
static void
test_mkfifo_empty_string (void)
{
  errno = 0;
  ASSERT (mkfifo ("", 0600) == -1);
  ASSERT (errno == ENOENT);
}
