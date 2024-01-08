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
#include <sys/types.h>

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "read-full.h"
#include "read-nointr.h"
#include "write-full.h"
#include "write-nointr.h"

/* Windows */
#ifndef O_CLOEXEC
#  ifdef O_NOINHERIT
#    define O_CLOEXEC O_NOINHERIT
#  else
#    define O_CLOEXEC 0
#  endif
#endif

static void usage (void);
static bool do_test (const char *filename);

int
main (int argc, char **argv)
{
  if (argc != 2)
    usage ();

  if (!do_test (argv[1]))
    exit (1);

  return 0;
}

static void
usage (void)
{
  fprintf (stderr, "usage: test-read-write-full filename\n");
  exit (1);
}

/* Reads a file in full to memory and then writes it in stdout. This file is
   only used for testing so the file size is not validated to fit in memory
   before calling malloc (). */
static bool
do_test (const char *filename)
{
  struct stat st;
  int fd;
  char *buffer;
  size_t bytes_read, bytes_written;

  if (stat (filename, &st) < 0 || !S_ISREG (st.st_mode))
    {
      fprintf (stderr, "%s: Not a regular file.\n", filename);
      goto fail;
    }

  if (st.st_size <= 0)
    {
      fprintf (stderr, "%s: File is empty.\n", filename);
      goto fail;
    }

  fd = open (filename, O_RDONLY | O_CLOEXEC);
  if (fd < 0)
    {
      fprintf (stderr, "%s: Failed to open file.\n", filename);
      goto fail;
    }

  buffer = malloc ((size_t) st.st_size);
  if (buffer == NULL)
    {
      fprintf (stderr, "malloc (): Out of memory.\n");
      goto fail_close;
    }

  bytes_read = read_full (fd, buffer, (size_t) st.st_size);
  if (bytes_read != (size_t) st.st_size)
    {
      fprintf (stderr, "%s: Could only read %zu/%zu bytes.\n", filename,
               bytes_read, (size_t) st.st_size);
      goto fail_close_free;
    }

  bytes_written = write_full (STDOUT_FILENO, buffer, bytes_read);
  if (bytes_written != bytes_read)
    {
      fprintf (stderr, "%s: Could only write %zu/%zu bytes.\n", filename,
               bytes_written, bytes_read);
      goto fail_close_free;
    }

  free (buffer);
  if (close (fd) < 0)
    {
      fprintf (stderr, "%s: Failed to close file descriptor.\n", filename);
      goto fail;
    }

  return true;
fail_close_free:
  free (buffer);
fail_close:
  close (fd);
fail:
  return false;
}
