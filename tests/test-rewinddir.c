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

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

static size_t pass1 = 0;
static size_t pass2 = 0;

static DIR *dirp = NULL;

static size_t count_files (void);

/* Test that rewinddir is declared and working. This file assumes the current
   working directory has files and the number of files does not change during
   execution. */
int
main (void)
{
  /* Open the current directory. */
  dirp = opendir (".");
  ASSERT (dirp != NULL);

  /* Count the number of files. */
  pass1 = count_files ();
  ASSERT (pass1 > 0);

  /* Go to the start of the directory stream. */
  rewinddir (dirp);

  /* Count the number of files again. */
  pass2 = count_files ();
  ASSERT (pass2 > 0);

  ASSERT (pass1 == pass2);

  return 0;
}

static size_t
count_files (void)
{
  struct dirent *curr;
  size_t count = 0;

  for (;; ++count)
    {
      curr = readdir (dirp);
      if (curr == NULL)
        break;
      printf ("%zu: %s\n", count, curr->d_name);
    }

  return count;
}
