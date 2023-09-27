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
#include <unistd.h>

#include "open-standard-streams.h"

int
main (void)
{
  int fd;
  char ch;

  /* Make sure stdin, stdout, stderr are open. */
  fd = creat ("test-open-standard-streams.o", 0600);
  if (fd <= STDERR_FILENO)
    abort ();

  /* This should do nothing. */
  open_standard_streams ();

  /* Doesn't fail. */
  if (write (STDOUT_FILENO, "\n", sizeof ("\n")) < 0)
    abort ();

  /* Doesn't fail. */
  if (write (STDERR_FILENO, "\n", sizeof ("\n")) < 0)
    abort ();

  /* Close stdin, stdout, stderr. */
  if (close (STDIN_FILENO) < 0 || close (STDOUT_FILENO) < 0
      || (close (STDERR_FILENO) < 0))
    abort ();

  /* Open the standard streams to /dev/null. */
  open_standard_streams ();

  /* Reads and writes fail with errno == EBADF. */
  if (read (STDIN_FILENO, &ch, sizeof (ch)) != -1 && errno != EBADF)
    abort ();
  if (write (STDOUT_FILENO, "\n", sizeof ("\n")) != -1 && errno != EBADF)
    abort ();
  if (write (STDERR_FILENO, "\n", sizeof ("\n")) != -1 && errno != EBADF)
    abort ();

  /* Cleanup the file we created. */
  if (close (fd) < 0)
    abort ();
  if (remove ("test-open-standard-streams.o") < 0)
    abort ();

  return 0;
}
