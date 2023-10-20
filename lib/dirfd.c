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

#include "attributes.h"

#if !HAVE_DIR_DD_FD && !HAVE_DIR_D_FD && !HAVE_DIR_FD

/* MinGW doesn't seem to have the ability to get a file descriptor from
   a DIRENT. Maybe dirp->dd_handle works somehow? */
int
dirfd (DIR *dirp ATTRIBUTE_UNUSED)
{
  errno = ENOSYS;
  return -1;
}

#else /* HAVE_DIR_DD_FD || HAVE_DIR_D_FD || HAVE_DIR_FD */

int
dirfd (DIR *dirp)
{
  int fd =
#  if HAVE_DIR_DD_FD
      dirp->dd_fd;
#  elif HAVE_DIR_D_FD
      dirp->d_fd;
#  elif HAVE_DIR_FD
      dirp->fd;
#  else
      -1;
#  endif

  if (fd < 0)
    {
      fd = -1;
      errno = EINVAL;
    }

  return fd;
}

#endif /* !HAVE_DIR_DD_FD && !HAVE_DIR_D_FD && !HAVE_DIR_FD */
