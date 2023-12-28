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
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int
scandir (const char *dir, struct dirent ***namelist,
         int (*sel) (const struct dirent *),
         int (*compar) (const struct dirent **, const struct dirent **))
{
  DIR *dirp;
  struct dirent *curr;
  struct dirent **arr = NULL;
  size_t arr_size = 0;
  int arr_count = 0;

  dirp = opendir (dir);
  if (dirp == NULL)
    return -1;
  for (curr = readdir (dirp); curr != NULL; curr = readdir (dirp))
    {
      int valid_name;

      if (sel != NULL)
        valid_name = (*sel) (curr);
      else
        valid_name = 0;
      if (valid_name)
        {
          struct dirent *entry;
          size_t entry_size;

          if ((size_t) arr_count == arr_size)
            {
              struct dirent **new_arr = NULL;

              if (arr_size == 0)
                {
                  arr_size = 2;
                  new_arr = (struct dirent **) malloc (
                      arr_size * sizeof (struct dirent *));
                }
              else
                {
                  if (arr_size > SIZE_MAX / 2)
                    goto scandir_fail_close;
                  arr_size *= 2;
                  if (arr_size > SIZE_MAX / sizeof (struct dirent *))
                    goto scandir_fail_close;
                  new_arr = (struct dirent **) realloc (
                      arr, arr_size * sizeof (struct dirent *));
                }
              if (new_arr == NULL)
                goto scandir_fail_close;
              arr = new_arr;
            }
          entry_size
              = &curr->d_name[strlen (curr->d_name) + 1] - (char *) curr;
          entry = (struct dirent *) malloc (entry_size);
          if (entry == NULL || arr_count == INT_MAX)
            goto scandir_fail_close;
          arr[arr_count++] = memcpy (entry, curr, entry_size);
        }
    }
  if (closedir (dirp) == -1)
    goto scandir_fail;
  if (compar != NULL)
    qsort (arr, arr_count, sizeof (struct dirent *),
           (int (*) (const void *, const void *)) compar);
  *namelist = arr;
  return arr_count;
scandir_fail_close:;
  (void) closedir (dirp);
scandir_fail:;
  if (arr != NULL)
    {
      int i;

      for (i = 0; i < arr_count; ++i)
        free (arr[i]);
      free (arr);
    }
  return -1;
}
