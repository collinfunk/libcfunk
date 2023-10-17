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
#include <unistd.h>

#include "test-help.h"

#ifndef F_DUPFD
#  define F_DUPFD 0
#endif

#undef TEST_FILE_NAME
#define TEST_FILE_NAME "test-fcntl.tmp"

int
main (void)
{
  int fd1, fd2;

  /* Cleanup file from any previous tests. */
  unlink (TEST_FILE_NAME);

  fd1 = creat (TEST_FILE_NAME, 0600);
  ASSERT (fd1 >= 0);

  fd2 = fcntl (fd1, F_DUPFD, 0);
  if (fd2 < 0)
    {
      int saved_errno = errno;
      close (fd1);
      errno = saved_errno;
      if (errno == ENOSYS)
        {
          fprintf (stderr, "fcntl (F_DUPFD) not supported.\n");
          exit (1);
        }
      else /* fcntl actually failed. */
        {
          fprintf (stderr, "fcntl (F_DUPFD) failed.\n");
          abort ();
        }
    }

  ASSERT (fd2 - 1 == fd1);
  ASSERT (close (fd1) == 0);
  ASSERT (close (fd2) == 0);
  ASSERT (unlink (TEST_FILE_NAME) == 0);

  return 0;
}
