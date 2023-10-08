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
#include <string.h>
#include <unistd.h>

#include "test-help.h"

#undef TEST_FILE_NAME

#define TEST_FILE_NAME "test-mknod.tmp"

/* Test that 'mknod' works on systems that support it. On Windows, make sure
   that it fails with errno == ENOSYS. */
int
main (void)
{
  int result;
  struct stat st;

  /* Remove the file existing because of a failed test. */
  remove (TEST_FILE_NAME);

  /* POSIX states that "The only portable use of mknod() is to create a
     FIFO-special file. If mode is not S_IFIFO or dev is not 0, the behavior
     of mknod() is unspecified." Therefore we only test creating a FIFO. */
  result = mknod (TEST_FILE_NAME, S_IFIFO | 0600, 0);
  if (result != 0)
    {
      if (errno == ENOSYS)
        {
          fprintf (stderr, "mknod is unsupported by your system.\n");
          exit (1);
        }
      else
        {
          fprintf (stderr, "mknod failed: %s\n", strerror (errno));
          abort ();
        }
    }

  /* Check S_ISFIFO. */
  ASSERT (stat (TEST_FILE_NAME, &st) == 0);
  ASSERT (S_ISFIFO (st.st_mode));

  /* Cleanup the file. */
  ASSERT (remove (TEST_FILE_NAME) == 0);

  return 0;
}
