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

  for (p = file_name + file_name_len; p > file_name; --p)
    {
#ifdef _WIN32
      if (*p == '/' || *p == '\\')
        break;
#else
      if (*p == '/')
        break;
#endif
      if (*p == '.')
        {
          *p = '\0';
          return true;
        }
    }
  return false;
}

const char *
filename_last_component (const char *file_name)
{
  size_t file_name_len = strlen (file_name);
  const char *p;

  for (p = file_name + file_name_len; p > file_name; --p)
    {
#ifdef _WIN32
      if (*(p - 1) == '/' || *(p - 1) == '\\')
        break;
#else
      if (*(p - 1) == '/')
        break;
#endif
    }
  return p;
}
