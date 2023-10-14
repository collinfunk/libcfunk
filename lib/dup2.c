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
#include <fcntl.h>
#include <unistd.h>

#if HAVE__DUP2

int
dup2 (int fd1, int fd2)
{
  return _dup2 (fd1, fd2);
}

#else

/* Closing and duplicating the file descriptor is not done atomically.
   This is susceptible to race conditions. */
int
dup2 (int fd1, int fd2)
{
  int saved_errno;

  if (fd2 < 0)
    {
      errno = EBADF;
      return -1;
    }

  /* Check that FD1 refers to an open file. */
  if (fcntl (fd1, F_GETFL) < 0)
    return -1;

  /* If FD1 and FD2 are the same, return FD2 without closing it. */
  if (fd1 == fd2)
    return fd2;

  /* Close FD2 while preserving the current value of errno. */
  saved_errno = errno;
  close (fd2);
  errno = saved_errno;

  return fcntl (fd1, F_DUPFD, fd2);
}

#endif
