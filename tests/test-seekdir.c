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

int
main (void)
{
  DIR *dirp;
  struct dirent *curr;
  long offsets[3];
  long result;
  size_t i = 0;

  offsets[0] = offsets[1] = offsets[2] = -1;

  dirp = opendir (".");
  ASSERT (dirp != NULL);

  for (;; ++i)
    {
      if (i <= 2)
        {
          offsets[i] = telldir (dirp);
          ASSERT (offsets[i] != -1);
          ASSERT (i == 0 ? 1 : offsets[i] >= offsets[i - 1]);
          printf ("%zu (%ld): %s\n", i, offsets[i],
                  i == 0 ? "START" : curr->d_name);
        }
      curr = readdir (dirp);
      if (curr == NULL)
        break;
    }

  for (i = 0; i < ARRAY_SIZE (offsets) && offsets[i] != -1; ++i)
    {
      seekdir (dirp, offsets[i]);
      result = telldir (dirp);
      ASSERT (result == offsets[i]);
      curr = readdir (dirp);
      printf ("%zu (%ld): %s\n", i + 1, offsets[i], curr->d_name);
    }

  ASSERT (closedir (dirp) == 0);

  return 0;
}
