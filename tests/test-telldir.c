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

static DIR *dirp = NULL;
static size_t count = 0;
static long *offsets = NULL;

static void count_dirs (void);
static void alloc_offsets (void);
static void fill_offsets (void);
static void verify_offsets (void);

/* Test that 'telldir' is defined and returns consistent values. This file
   assumes the current working directory contains files which do not change
   during the lifetime of the program. */
int
main (void)
{
  /* Open the current working directory. */
  dirp = opendir (".");
  ASSERT (dirp != NULL);

  /* Count the number of files. */
  count_dirs ();
  ASSERT (count > 0);

  /* Allocate an offset for each file. */
  alloc_offsets ();

  /* Reset the position. */
  rewinddir (dirp);

  /* Fill the offset table using 'telldir'. */
  fill_offsets ();

  /* Reset the position. */
  rewinddir (dirp);

  /* Verify that the results are the same. */
  verify_offsets ();

  /* Free all resources. */
  ASSERT (closedir (dirp) == 0);
  free (offsets);

  return 0;
}

static void
count_dirs (void)
{
  struct dirent *curr;
  size_t i = 0;

  for (;; ++i)
    {
      curr = readdir (dirp);
      if (curr == NULL)
        break;
      printf ("%zu: %s\n", i, curr->d_name);
    }

  count = i;
}

static void
alloc_offsets (void)
{
  offsets = (long *) calloc (count + 1, sizeof (long));
  ASSERT (offsets != NULL);
}

static void
fill_offsets (void)
{
  struct dirent *curr;
  size_t i = 0;

  for (;; ++i)
    {
      curr = readdir (dirp);
      if (curr != NULL)
        ASSERT (i < count);
      else
        {
          ASSERT (i == count);
          break;
        }
      offsets[i] = telldir (dirp);
      ASSERT (offsets[i] != -1);
      printf ("%zu (%ld): %s\n", i, offsets[i], curr->d_name);
    }
}

static void
verify_offsets (void)
{
  struct dirent *curr;
  size_t i = 0;

  for (;; ++i)
    {
      curr = readdir (dirp);
      if (curr != NULL)
        ASSERT (i < count);
      else
        {
          ASSERT (i == count);
          break;
        }
      ASSERT (offsets[i] == telldir (dirp));
      printf ("%zu (%ld): %s\n", i, offsets[i], curr->d_name);
    }
}
