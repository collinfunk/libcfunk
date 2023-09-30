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

#include <stdio.h>
#include <stdlib.h>

#include "block-size.h"
#include "test-help.h"

int
main (int argc, char **argv)
{
  char *file_name = argc > 1 ? argv[1] : argv[0];
  struct stat st;

  /* Take a file or directory to stat, use the current file as a backup. */
  if (stat (file_name, &st) < 0
      || !(S_ISREG (st.st_mode) || S_ISDIR (st.st_mode)))
    {
      file_name = argv[0];
      if (stat (file_name, &st) < 0)
        {
          fprintf (stderr, "stat () failed.\n");
          abort ();
        }
    }

  /* Check DEV_BSIZE is defined and is positive. */
  ASSERT (DEV_BSIZE > 0);

  /* Check that 'ST_BLKSIZE' returns a positive block size. */
  ASSERT (ST_BLKSIZE (st) > 0);

  /* Check that 'ST_BLOCKS' is positive number of blocks. */
  ASSERT (ST_BLOCKS (st) > 0);

  printf ("DEV_BSIZE: %lld\n", (long long int) DEV_BSIZE);
  printf ("ST_BLKSIZE (st): %lld\n", (long long int) ST_BLKSIZE (st));
  printf ("DEV_BLOCKS (st): %lld\n", (long long int) ST_BLOCKS (st));

  return 0;
}
