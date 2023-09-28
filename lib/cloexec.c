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

#include <fcntl.h>
#include <unistd.h>

#include "cloexec.h"

int
cloexec_is_set (int fd)
{
  int flags = fcntl (fd, F_GETFD);

  /* fcntl failed and errno is set. */
  if (flags < 0)
    return -1;

  return !(flags & FD_CLOEXEC) ? 0 : 1;
}

int
set_cloexec (int fd)
{
  int flags = fcntl (fd, F_GETFD);
  int new_flags;

  /* fcntl failed and errno is set. */
  if (flags < 0)
    return -1;

  /* Set the FD_CLOEXEC flag if it isn't already set. */
  new_flags = flags | FD_CLOEXEC;
  if (new_flags == flags)
    return 0;
  else
    return fcntl (fd, F_SETFD, new_flags);
}

int
unset_cloexec (int fd)
{
  int flags = fcntl (fd, F_GETFD);
  int new_flags;

  /* fcntl failed and errno is set. */
  if (flags < 0)
    return -1;

  /* Remove the FD_CLOEXEC flag if it is set. */
  new_flags = flags & ~FD_CLOEXEC;
  if (new_flags == flags)
    return 0;
  else
    return fcntl (fd, F_SETFD, new_flags);
}
