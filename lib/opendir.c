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
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "dirent_internal.h"

/* https://learn.microsoft.com/en-us/windows/win32/fileio/naming-a-file */
#ifndef MAX_PATH
#  define MAX_PATH 260
#endif

/* https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfullpathnamea */
/* https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfileattributesa */
DIR *
opendir (const char *dirname)
#undef opendir
{
  DWORD result;
  /* DIRNAME, '\\', '*', '\0' */
  char buffer[MAX_PATH + 3];
  size_t buffer_len;
  DIR *dirp;

  /* If DIRNAME is an empty string return with errno ENOENT. */
  if (dirname[0] == '\0')
    {
      errno = ENOENT;
      return NULL;
    }

  /* Get the full path name. */
  result = GetFullPathName (dirname, MAX_PATH, buffer, NULL);
  if (result == 0)
    {
      errno = ENOENT;
      return NULL;
    }

  /* Check if the full file name refers to a valid directory. */
  result = GetFileAttributes (buffer);
  if (result == INVALID_FILE_ATTRIBUTES)
    {
      errno = ENOENT;
      return NULL;
    }
  if (!(result & FILE_ATTRIBUTE_DIRECTORY))
    {
      errno = ENOTDIR;
      return NULL;
    }

  /*  Append the wildcard character to the directory. Only add a slash if
      nessecary. */
  buffer_len = strlen (buffer);
  if (buffer_len > 0 && buffer[buffer_len - 1] != '/'
      && buffer[buffer_len - 1] != '\\')
    buffer[buffer_len++] = '\\';
  buffer[buffer_len++] = '*';
  buffer[buffer_len] = '\0';

  /* Allocate the directory stream. */
  dirp = (DIR *) malloc (sizeof (DIR) + buffer_len + 1);
  if (dirp == NULL)
    {
      errno = ENOMEM;
      return NULL;
    }

  /* Initialize the allocated directory stream. */
  dirp->handle = INVALID_HANDLE_VALUE;
  memcpy (dirp->dirname, buffer, buffer_len + 1);

  return dirp;
}
