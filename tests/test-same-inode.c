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

#include <sys/stat.h>
#include <sys/types.h>

#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include "same-inode.h"
#include "test-help.h"

/* Use a static buffer for getcwd(3). Many implementations will allocate memory
   for the path if the pointer is NULL, but POSIX states the behavior with a
   NULL argument is "unspecified". */
static char buffer[4096];

/* Checks that getcwd and "." have the same inode. */
int
main (void)
{
  struct stat cwd_stat;
  struct stat dot_stat;

  if (getcwd (buffer, sizeof (buffer)) == NULL)
    {
      fprintf (stderr, "test-same-inode failed with error: %s.\n",
               strerror (errno));
      /* Should never happen but print a message just in case. */
      fprintf (stderr, "test-same-inode must be run in a path under 4096 "
                       "characters in length.\n");
      abort ();
    }

  if (stat (buffer, &cwd_stat) < 0)
    {
      fprintf (stderr, "Failed to stat `%s'. Failed with error: %s.\n", buffer,
               strerror (errno));
      abort ();
    }

  if (stat (".", &dot_stat) < 0)
    {
      fprintf (stderr, "Failed to stat `.'. Failed with error: %s.\n",
               strerror (errno));
      abort ();
    }

    /* see same-inode.h */
#ifdef _WIN32
  ASSERT (!SAME_INODE (cwd_stat, dot_stat));
#else
  ASSERT (SAME_INODE (cwd_stat, dot_stat));
#endif
  return 0;
}
