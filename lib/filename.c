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
#include <string.h>

#include <stdio.h>

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
