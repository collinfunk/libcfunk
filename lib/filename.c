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

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "filename.h"

bool
filename_strip_extension (char *file_name)
{
  size_t file_name_len = strlen (file_name);
  char *p;

  for (p = file_name + file_name_len;
       p >= file_name && !FILENAME_IS_DIRSEP (p[0]); --p)
    {
      if (p[0] == '.')
        {
          p[0] = '\0';
          return true;
        }
    }

  return false;
}

int
filename_strip_slashes (char *file_name)
{
  size_t file_name_len = strlen (file_name);
  char *p = file_name + file_name_len;
  int slash_count = 0;

  if (p > file_name && FILENAME_IS_DIRSEP (p[-1]))
    {
      for (--p, ++slash_count; p > file_name && FILENAME_IS_DIRSEP (p[-1]);
           --p, ++slash_count)
        ;
      *p = '\0';
    }

  return slash_count;
}

const char *
filename_last_component (const char *file_name)
{
  const char *p;
  const char *lead;

  /* Skip Windows device prefixes. */
  if (FILENAME_HAS_DRIVE_PREFIX (file_name))
    p = file_name + 2;
  else
    p = file_name;

  /* Skip leading slashes in the filename. */
  for (; FILENAME_IS_DIRSEP (p[0]); ++p)
    ;

  /* Lead P to the character past the last slash. */
  for (lead = p; *lead != '\0'; ++lead)
    {
      if (FILENAME_IS_DIRSEP (lead[0]))
        {
          do
            ++lead;
          while (FILENAME_IS_DIRSEP (lead[0]));
          /* Check for the case where FILE_NAME ends with a slash. */
          if (lead[0] != '\0')
            p = lead;
          else
            break;
        }
    }

  return p;
}

char *
filename_join_extension (const char *file_name, const char *extension)
{
  char *copy;
  size_t file_name_len = strlen (file_name);

  if (extension == NULL || *extension == '\0')
    {
      copy = (char *) malloc (file_name_len + 1);
      if (copy == NULL)
        return NULL;
      else
        memcpy (copy, file_name, file_name_len + 1);
    }
  else
    {
      size_t extension_len = strlen (extension);
      copy = (char *) malloc (file_name_len + extension_len + 2);
      if (copy == NULL)
        return NULL;
      else
        {
          memcpy (copy, file_name, file_name_len);
          copy[file_name_len] = '.';
          memcpy (copy + file_name_len + 1, extension, extension_len + 1);
        }
    }

  return copy;
}

char *
filename_join_directory (const char *directory, const char *file_name)
{
  char *copy;
  size_t file_name_len = strlen (file_name);

  /* Check if directory is NULL, empty, or a pointless CWD. */
  if (directory == NULL
      || (directory[0] == '\0'
          || (directory[0] == '.' && directory[1] == '\0')))
    {
      copy = (char *) malloc (file_name_len + 1);
      if (copy == NULL)
        return NULL;
      else
        memcpy (copy, file_name, file_name_len + 1);
    }
  else
    {
      size_t directory_len = strlen (directory);
      int need_dirsep;

      /* On Windows, C: and C:/ have a different meaing. Make sure we don't
         mess up the requested filename. See header for more defails. */
      if (!FILENAME_HAS_DRIVE_PREFIX (directory))
        need_dirsep = !FILENAME_IS_DIRSEP (directory[directory_len - 1]);
      else
        {
          if (directory_len <= 2)
            need_dirsep = 0;
          else
            need_dirsep = !FILENAME_IS_DIRSEP (directory[directory_len - 1]);
        }
      copy = (char *) malloc (file_name_len + directory_len + need_dirsep + 1);
      if (copy == NULL)
        return NULL;
      else
        {
          memcpy (copy, directory, directory_len);
          if (!need_dirsep)
            memcpy (copy + directory_len, file_name, file_name_len + 1);
          else
            {
              copy[directory_len] = FILENAME_NATIVE_DIRSEP;
              memcpy (copy + directory_len + 1, file_name, file_name_len + 1);
            }
        }
    }

  return copy;
}
