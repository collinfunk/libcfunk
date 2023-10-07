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

#include "isapipe.h"
#include "test-help.h"

#undef TEST_FILE_NAME

#define TEST_FILE_NAME "test-isapipe.tmp"

/* Basic test for 'isapipe'. We ignore stdin, stdout, and stderr so that
   this program behaves when ran from a script. */
int
main (void)
{
  int fd;
  int piped_pair[2];

  fd = open (TEST_FILE_NAME, O_RDWR | O_TRUNC | O_CREAT, 0600);
  ASSERT (fd >= 0);

  /* Not a pipe. */
  ASSERT (isapipe (fd) == 0);

  /* Bad file descriptors. */
  /* FIXME: This sets off the invalid parameter handle on Windows. :( */
#if !HAVE_WINDOWS_H
  ASSERT (isapipe (-1) == -1);
  (void) close (255);
  ASSERT (isapipe (255) == -1);
#endif

  /* Test on two pipes. */
  ASSERT (pipe (piped_pair) == 0);
  ASSERT (isapipe (piped_pair[0]) == 1);
  ASSERT (isapipe (piped_pair[1]) == 1);

  /* Cleanup file descriptors. */
  ASSERT (close (fd) == 0);
  ASSERT (close (piped_pair[0]) == 0);
  ASSERT (close (piped_pair[1]) == 0);

  /* Cleanup the file. */
  ASSERT (remove (TEST_FILE_NAME) == 0);

  return 0;
}
