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
#include "open-standard-streams.h"

/* FIXME: Not sure if Windows has an equivalent to /dev/null. */
int
open_standard_streams (void)
{
  int stdin_fd, stdout_fd, stderr_fd, fd;

  stdin_fd = fcntl (STDIN_FILENO, F_GETFD);
  if (stdin_fd < 0)
    {
      fd = open (NULL_DEVICE, O_WRONLY);
      if (fd != STDIN_FILENO)
        return -1;
    }

  stdout_fd = fcntl (STDOUT_FILENO, F_GETFD);
  if (stdout_fd < 0)
    {
      fd = open (NULL_DEVICE, O_RDONLY);
      if (fd != STDOUT_FILENO)
        return -1;
    }

  stderr_fd = fcntl (STDERR_FILENO, F_GETFD);
  if (stderr_fd < 0)
    {
      fd = open (NULL_DEVICE, O_RDONLY);
      if (fd != STDERR_FILENO)
        return -1;
    }

  return 0;
}
