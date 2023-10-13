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

#undef DEST_FILE_NAME

#define DEST_FILE_NAME "test-copy-file-range.tmp"

int
main (int argc, char **argv)
{
  int src_fd;
  int dest_fd;

  remove (DEST_FILE_NAME);

  if (argc < 2)
    {
      src_fd = open (argv[0], O_RDONLY);
      if (src_fd < 0)
        {
          fprintf (stderr, "open () failed.\n");
          abort ();
        }
    }
  else
    {
      src_fd = open (argv[1], O_RDONLY);
      if (src_fd < 0)
        {
          fprintf (stderr, "open () failed.\n");
          abort ();
        }
    }

  dest_fd = open (DEST_FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, 0600);
  if (dest_fd < 0)
    {
      fprintf (stderr, "open () failed.\n");
      close (src_fd);
      abort ();
    }

  if (copy_file_range (src_fd, NULL, dest_fd, NULL, 512, 0) < 0)
    {
      if (errno == ENOSYS)
        fprintf (stderr, "copy_file_range not supported on your system.\n");
      else
        fprintf (stderr, "copy_file_range failed.\n");
      ASSERT (close (src_fd) == 0);
      ASSERT (close (dest_fd) == 0);
      ASSERT (remove (DEST_FILE_NAME) == 0);
      abort ();
    }

  ASSERT (close (src_fd) == 0);
  ASSERT (close (dest_fd) == 0);
  ASSERT (remove (DEST_FILE_NAME) == 0);

  return 0;
}
