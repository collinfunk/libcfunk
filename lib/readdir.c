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

#include <dirent.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "dirent_internal.h"

struct dirent *
readdir (DIR *dirp)
#undef readdir
{
  switch (dirp->state)
    {
    case -1: /* DIRP has had a filename initialized by opendir. */
      dirp->handle = FindFirstFile (dirp->dirname, &dirp->find_data);
      if (dirp->handle != INVALID_HANDLE_VALUE)
        dirp->state = 0;
      else
        {
          errno = EBADF;
          return NULL;
        }
      dirp->offset = 1;
      break;
    case 0: /* DIRP has a open HANDLE object. */
      if (FindNextFile (dirp->handle, &dirp->find_data))
        {
          if (dirp->offset < SIZE_MAX)
            ++dirp->offset;
          else /* Overflow. */
            {
              errno = EOVERFLOW;
              return NULL;
            }
        }
      else /* Error or end of directory. */
        {
          switch (GetLastError ())
            {
            case ERROR_NO_MORE_FILES:
              dirp->state = 1;
              return NULL;
            default:
              errno = EBADF;
              return NULL;
            }
        }
      break;
    case 1: /* DIRP has finished reading the directory. */
      return NULL;
    default: /* DIRP is uninitialized. */
      errno = EBADF;
      return NULL;
    }

  dirp->current.d_ino = 0;
  /* Both buffers are the same size. */
  strcpy (dirp->current.d_name, dirp->find_data.cFileName);

  return &dirp->current;
}
