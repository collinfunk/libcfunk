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

#include <errno.h>
#include <unistd.h>

#if HAVE_WINDOWS_H
#  include <lmcons.h>
#  include <windows.h>
#else
#  error "This file should only be built on Windows."
#endif

/* Should be defined in <lmcons.h>. */
#ifndef UNLEN
#  define UNLEN 256
#endif

/* getlogin(3) may be overwritten by subsequent calls. */
static char getlogin_buffer[UNLEN];

/* https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getusernamea */
char *
getlogin (void)
{
  DWORD name_len = sizeof (getlogin_buffer);
  if (!GetUserName (getlogin_buffer, &name_len))
    {
      /* This should never happen with a buffer size of UNLEN. */
      if (GetLastError () == ERROR_INSUFFICIENT_BUFFER)
        errno = ENOMEM;
      return NULL;
    }
  return (char *) getlogin_buffer;
}
