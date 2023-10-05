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
#include <stdlib.h>
#include <sys/ioctl.h>

int
unlockpt (int fd)
{
#ifdef TIOCSPTLCK
  int unlock = 0;
  int result = ioctl (fd, TIOCSPTLCK, &unlock);
  /* ioctl sets errno to ENOTTY if FD is invalid. POSIX requires unlockpt to
     set errrno to EINVAL in this case. */
  if (result != 0)
    {
      if (errno == ENOTTY)
        errno = EINVAL;
    }
  return result;
#elif HAVE_PTSNAME && HAVE_REVOKE
  char *name = ptsname (fd);
  if (name == NULL)
    {
      if (errno == ENOTTY)
        errno = EINVAL;
      return -1;
    }
  return revoke (name);
#else /* Just fail and assume TTY's aren't supported. */
  errno = ENOSYS;
  return -1;
#endif
}
