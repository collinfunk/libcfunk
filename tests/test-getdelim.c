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

#include <sys/types.h>

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

static void usage (void);

int
main (int argc, char **argv)
{
  const char *filename;
  FILE *fp;
  char *buffer = NULL;
  size_t buffer_size = 0;

  if (argc != 2)
    usage ();

  filename = argv[1];

  fp = fopen (filename, "r");
  if (fp == NULL)
    {
      fprintf (stderr, "%s: Failed to open file.\n", filename);
      exit (1);
    }

  /* getline () just calls getdelim (). */
  for (;;)
    {
      ssize_t current_read = getline (&buffer, &buffer_size, fp);
      if (current_read < 0)
        break;
      ASSERT ((size_t) current_read < buffer_size);
      ASSERT (buffer[current_read] == '\0');
      printf ("%s", buffer);
    }

  free (buffer);
  return 0;
}

static void
usage (void)
{
  fprintf (stderr, "usage: test-getdelim filename\n");
  exit (1);
}
