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

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "filename.h"

/* TODO: Fix this ugly thing. */

int
execvpe (const char *file, char *const argv[], char *const envp[])
{
  char *path;
  char *path_ptr;
  char *p;
  char *end;
  size_t path_len;

  path_ptr = getenv ("PATH");
  if (path_ptr == NULL || *path_ptr == '\0')
    return -1;

  path_len = strlen (path_ptr);
  path = (char *) malloc (path_len + 1);
  if (path == NULL)
    return -1;
  memcpy (path, path_ptr, path_len + 1);

  for (p = path;; p = end + 1)
    {
      bool end_of_list;
      char *full_program_name;
      char *dir_name;
      struct stat st;

      /* Find the end of this directory. */
      for (end = p; *end != '\0' && !FILENAME_IS_LISTSEP (*end); ++end)
        ;

      /* Check if we are at the last element in PATH. */
      if (*end == '\0')
        end_of_list = true;
      else
        {
          *end = '\0';
          end_of_list = false;
        }

      /* Two ':' characters in a row means CWD. */
      if (p != end)
        dir_name = p;
      else
        dir_name = ".";

      /* Join the file path. */
      full_program_name = filename_join_directory (dir_name, file);
      if (full_program_name == NULL)
        goto fail_nomem;

      /* Check that the program exists and that it can be executed. */
      if (stat (full_program_name, &st) >= 0
          && euidaccess (full_program_name, X_OK) == 0)
        {
          int save_errno;
          free (path);
          execve (full_program_name, argv, envp);
          save_errno = errno;
          free (full_program_name);
          errno = save_errno;
          return -1;
        }

      if (end_of_list)
        goto fail_noent;
    }

  return -1;
fail_nomem:
  errno = ENOMEM;
  free (path);
  return -1;
fail_noent:
  errno = ENOENT;
  free (path);
  return -1;
}
