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

#include "safe-dup.h"

/* Simple test program. Can't really print error messages since it closes
   stderr... */
int
main (void)
{
  int standard_descriptor;
  int trash_file;
  int fd;

  /* Just pick a name that won't litter version control. */
  trash_file = creat ("safe-dup-trash.o", 0600);

  /* We need this file descriptor for testing, and we assume all standard
     standard streams are open like normal. */
  if (trash_file <= STDERR_FILENO)
    {
      /* Make sure we are actually writing to standard error. */
      if (trash_file != STDERR_FILENO)
        fprintf (stderr, "Failed to create safe-dup-trash.log for testing.\n");
      exit (1);
    }

  /* Close each file descriptor and make sure that safe_dup doesn't take it. */
  for (standard_descriptor = STDIN_FILENO;
       standard_descriptor <= STDERR_FILENO; ++standard_descriptor)
    {
      /* Close the standard descriptor. */
      if (close (standard_descriptor) < 0)
        abort ();

      /* Abort if safe_dup fails or if the file descriptor is one of the
         standard streams. */
      fd = safe_dup (trash_file);
      if (fd <= STDERR_FILENO)
        abort ();

      /* Clean up the file descriptor. */
      if (close (fd) < 0)
        abort ();

      /* Test safe_dup_cloexec. */
      fd = safe_dup_cloexec (trash_file);
      if (fd <= STDERR_FILENO)
        abort ();

      /* Cleanup. */
      if (close (fd) < 0)
        abort ();
    }

  /* Close the file descriptor we used for safe_dup. */
  if (close (trash_file) < 0)
    abort ();

  /* Delete the file. */
  if (remove ("safe-dup-trash.o") < 0)
    abort ();

  return 0;
}
