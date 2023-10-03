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
#include <stdlib.h>
#include <unistd.h>

#include "null-device.h"

/* 4.4BSD-like daemon(3) function. */

int
daemon (int nochdir, int noclose)
{
  int fd;

  switch (fork ())
    {
    case -1: /* Error. */
      return -1;
    case 0: /* Child. */
      break;
    default: /* Parent. */
      /* Don't call any functions registered with atexit(3). */
      _Exit (0);
    }

  /* Create a new session seperate from the parent. */
  if (setsid () < 0)
    return -1;

  /* Change the current working directory to the root directory unless
     NOCHDIR is set. */
  if (!nochdir && chdir ("/") < 0)
    return -1;

  /* Try to redirect the standard I/O streams to /dev/null unless
     NOCLOSE is set. */
  if (!noclose)
    {
      fd = open (NULL_DEVICE, O_RDWR);
      if (fd < 0)
        return -1;
      else
        {
          if (dup2 (fd, STDIN_FILENO) < 0)
            return -1;
          if (dup2 (fd, STDOUT_FILENO) < 0)
            return -1;
          if (dup2 (fd, STDERR_FILENO) < 0)
            return -1;
          /* Close FD if it isn't stdin, stdout, or stderr. */
          if (fd > STDERR_FILENO)
            close (fd);
        }
    }

  return 0;
}
