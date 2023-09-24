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

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int
main (void)
{
  gid_t *group_list;
  int group_count, i;

  group_count = getgroups (0, NULL);

  /* Expect failure with ENOSYS on Windows. */
  if (group_count < 0)
    {
      if (errno == ENOSYS)
        return 0;
      else
        abort ();
    }

  /* Make sure size_t doesn't wrap. */
  if (group_count > SIZE_MAX / sizeof (gid_t))
    abort ();

  group_list = (gid_t *) malloc (group_count * sizeof (gid_t));
  if (group_list == NULL)
    abort ();

  /* Make sure we get the same number of groups. */
  if (group_count != getgroups (group_count, group_list))
    {
      fprintf (stderr, "getgroups (): %s.\n", strerror (errno));
      free (group_list);
      abort ();
    }

  printf ("Supplementary group IDs:\n");
  for (i = 0; i < group_count; ++i)
    printf ("%2d. %d\n", i, (int) group_list[i]);

  free (group_list);
  return 0;
}
