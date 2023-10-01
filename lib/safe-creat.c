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
#include <unistd.h>

#include "safe-creat.h"
#include "safe-dup.h"

int
safe_creat (const char *path, mode_t mode)
{
  int fd = creat (path, mode);

  if (fd >= STDIN_FILENO && fd <= STDERR_FILENO)
    {
      int new_fd = safe_dup (fd);
      close (fd);
      fd = new_fd;
    }

  return fd;
}

int
safe_creat_cloexec (const char *path, mode_t mode)
{
  int fd;

  /* Call open with the normal flags for creat and the close-on-exec flag. */
  fd = open (path, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, mode);

  if (fd >= STDIN_FILENO && fd <= STDERR_FILENO)
    {
      int new_fd = safe_dup_cloexec (fd);
      close (fd);
      fd = new_fd;
    }

  return fd;
}
