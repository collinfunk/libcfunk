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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "null-device.h"
#include "test-help.h"

static void test_isatty_stdout (void);
static void test_isatty_null_device (void);

/* Test that 'isatty' is defined and working. */
int
main (void)
{
  test_isatty_stdout ();
  test_isatty_null_device ();
  return 0;
}

/* We assume this test is run from CTest or a shell script.
   Fail for STDOUT_FILENO being a tty but a print a message. */
static void
test_isatty_stdout (void)
{
  int result = isatty (STDOUT_FILENO);
  if (result)
    {
      fprintf (stderr, "This test should be run from a test driver so that "
                       "STDOUT_FILENO is not a TTY.\n");
      abort ();
    }
}

/* Test that isatty fails on the systems /dev/null (or equivalent) file. The
   Windows provided isatty returns true for character devices and may fail
   here if not replaced. */
static void
test_isatty_null_device (void)
{
  int fd;
  int result;

  fd = open (NULL_DEVICE, O_RDONLY);
  ASSERT (fd >= 0);

  result = isatty (fd);
  ASSERT (!result);

  ASSERT (close (fd) == 0);
}
