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

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Returns a boolean value indicating whether GID is a part of the calling
   processes supplementary group ID's. */
int
group_member (gid_t gid)
{
  gid_t *group_list;
  int num_groups, is_group_member, i;

  /* Get the number of groups that would be returned if size wasn't 0. */
  num_groups = getgroups (0, NULL);
  if (num_groups <= 0)
    return 0;

  /* Check for the unlikely case that NUM_GROUPS is so large that
     NUM_GROUPS * sizeof (gid_t) would wrap around. */
  if ((size_t) num_groups > SIZE_MAX / sizeof (gid_t))
    return 0;

  group_list = (gid_t *) malloc (num_groups * sizeof (gid_t));
  if (group_list == NULL)
    return 0;

  /* Fill GROUP_LIST with the supplementary group IDs the calling process is a
     member of. */
  num_groups = getgroups (num_groups, group_list);

  /* Search for GID in GROUP_LIST and return true (1) if it is found. */
  is_group_member = 0;
  if (num_groups > 0)
    {
      for (i = 0; i < num_groups; ++i)
        {
          if (group_list[i] == gid)
            {
              is_group_member = 1;
              break;
            }
        }
    }

  free (group_list);
  return is_group_member;
}
