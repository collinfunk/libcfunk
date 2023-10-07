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

#include <errno.h>
#include <unistd.h>

#if HAVE_WINDOWS_H
#  include <windows.h>
#endif

#if HAVE_WINDOWS_H

/* This function may return the incorrect value on sockets. I do not think that
   there is a way around this. :( */
/* https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfiletype */
int
isapipe (int fd)
{
  HANDLE handle;
  DWORD result;

  handle = (HANDLE) _get_osfhandle (fd);
  if (handle == INVALID_HANDLE_VALUE)
    {
      errno = EBADF;
      return -1;
    }

  result = GetFileType (handle);
  if (result == FILE_TYPE_UNKNOWN)
    {
      if (GetLastError () == NO_ERROR)
        return -1;
      else
        return 0;
    }

  return result == FILE_TYPE_PIPE;
}

#else /* !HAVE_WINDOWS_H */

/* FIXME: Try to check if FD is a FIFO or pipe. */
int
isapipe (int fd)
{
  struct stat st;

  if (fstat (fd, &st) < 0)
    return -1;

  return S_ISFIFO (st.st_mode);
}

#endif
