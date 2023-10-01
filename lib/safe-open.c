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

#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>

#include "safe-dup.h"
#include "safe-open.h"

int
safe_open (const char *path, int flags, ...)
{
  int fd;
  mode_t mode;

  if (!(flags & O_CREAT))
    mode = 0;
  else /* Requires a mode argument. */
    {
      va_list args;
      va_start (args, flags);
      mode = va_arg (args, mode_t);
      va_end (args);
    }

  fd = open (path, flags, mode);

  if (fd >= STDIN_FILENO && fd <= STDERR_FILENO)
    {
      int new_fd = safe_dup (fd);
      close (fd);
      fd = new_fd;
    }

  return fd;
}

int
safe_open_cloexec (const char *path, int flags, ...)
{
  int fd;
  mode_t mode;

  if (!(flags & O_CREAT))
    mode = 0;
  else /* Requires a mode argument. */
    {
      va_list args;
      va_start (args, flags);
      mode = va_arg (args, mode_t);
      va_end (args);
    }

  /* Make sure that the O_CLOEXEC flag is set. */
  if (!(flags & O_CLOEXEC))
    flags |= O_CLOEXEC;

  fd = open (path, flags, mode);

  if (fd >= STDIN_FILENO && fd <= STDERR_FILENO)
    {
      int new_fd = safe_dup_cloexec (fd);
      close (fd);
      fd = new_fd;
    }

  return fd;
}
