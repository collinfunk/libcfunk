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

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "dirname.h"

char *
get_dirname (const char *file_name)
{
  const char *p;
  const char *end;
  size_t len;
  char *dir;

  /* Skip leading slashes in FILE_NAME. */
  for (p = file_name; *p == '/'; ++p)
    ;

  /* Lead P to the last '/' that isn't the end of the string. */
  for (end = p; *end != '\0'; ++end)
    {
      /* Skip consecutive slashes. */
      if (*end == '/')
        {
          do
            ++end;
          while (*end == '/');
          if (*end != '\0')
            p = end;
          else
            break;
        }
    }

  /* Move P to the last character that isn't '/' or the basename. */
  for (len = p - file_name; len > 1 && p[-1] == '/'; --len)
    --p;

  /* DIR is an actual filename. */
  if (len > 0)
    {
      dir = malloc (len + 1);
      if (dir == NULL)
        return NULL;
      memcpy (dir, file_name, len);
      dir[len] = '\0';
    }
  else /* Root or current working directory. */
    {
      dir = malloc (2);
      if (dir == NULL)
        return NULL;
      dir[0] = *file_name == '/' ? '/' : '.';
      dir[1] = '\0';
    }

  return dir;
}
