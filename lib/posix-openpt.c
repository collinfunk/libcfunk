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
#include <stdlib.h>
#include <unistd.h>

#if HAVE_SYS_IOCTL_H
#  include <sys/ioctl.h>
#endif

#if HAVE_SYS_TTY_H
#  include <sys/tty.h>
#endif

int
posix_openpt (int flags)
{
#if HAVE_DEV_PTMX
  return open ("/dev/ptmx", flags);
#elif HAVE_DEV_PTC
  return open ("/dev/ptc", flags);
#elif HAVE_DEV_PTM && HAVE_SYS_IOCTL_H && HAVE_SYS_TTY_H && HAVE_IOCTL        \
    && HAVE_STRUCT_PTMGET
  struct ptmget ptm;
  int master_fd, fd;

  fd = open ("/dev/ptm", O_RDWR);
  if (fd < 0)
    master_fd = -1;
  else
    {
      if (ioctl (fd, PTMGET, &ptm) != -1)
        {
          master_fd = ptm.cfd;
          close (ptm.sfd);
          close (fd);
        }
      else /* ioctl failed, cleanup but perserve errno. */
        {
          int saved_errno = errno;
          master_fd = -1;
          close (fd);
          errno = saved_errno;
        }
    }

  return master_fd;
#else
#  error "No implementation of posix_openpt for your system."
  return -1;
#endif
}
