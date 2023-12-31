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

#ifndef DIRENT_INTERNAL_H
#define DIRENT_INTERNAL_H

#include <config.h>

#include <dirent.h>

#if HAVE_WINDOWS_H
#  include <windows.h>
#endif

struct _libcfunk_dirstream
{
  /* The handle used for 'FindFirstFile', 'FindNextFile', and 'FindClose'. */
  HANDLE handle;

  /* Current file from the start of the directory. */
  size_t offset;

  /* State variable. -1 if 'opendir' has set the dirname field so that
     'FindFirstFile' can be called. 0 if the directory is still being read.
     1 if the stream has reached the last file of the directory. */
  int state;

  /* Current dirent struct returned by 'readdir'. */
  struct dirent current;

  /* Data used to store the result of Windows function calls. */
  WIN32_FIND_DATA find_data;

  /* The initial directory name passed to 'opendir' with wildcard characters
     appended for use with Windows functions. */
  char dirname[];
};

#endif /* DIRENT_INTERNAL_H */
