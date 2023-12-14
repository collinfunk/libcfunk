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

#include <sys/random.h>
#include <sys/types.h>

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#if HAVE_WINDOWS_H
#  include <bcrypt.h>
#  include <windows.h>
#endif

/* The Windows replacement for getrandom(2) uses the Windows
   "Cryptography API: Next Generation" instead of the older deprecated version.
   The function BCryptGenRandom should be avaliable on any modern version of
   Windows. Windows documentation says that BCRYPT_USE_SYSTEM_PREFERRED_RNG
   is supported on Windows Vista SP2 and later. */
#if _WIN32
ssize_t
getrandom (void *buffer, size_t length, unsigned int flags)
{
  NTSTATUS status;

  /* Check for invalid flags even thought they aren't used on the Windows
     implementation. */
  if (flags & ~(GRND_NONBLOCK | GRND_RANDOM | GRND_INSECURE))
    {
      errno = EINVAL;
      return -1;
    }

  if (flags & GRND_INSECURE)
    {
      if (flags & GRND_RANDOM)
        {
          errno = EINVAL;
          return -1;
        }
    }

  status = BCryptGenRandom (NULL, buffer, length,
                            BCRYPT_USE_SYSTEM_PREFERRED_RNG);

  /* STATUS_SUCCESS */
  return status == 0 ? (ssize_t) length : -1;
}
#else
ssize_t
getrandom (void *buffer, size_t length, unsigned int flags)
{
  int fd;
  ssize_t bytes_read;

  /* Check that flags doesn't have invalid values. */
  if (flags & ~(GRND_NONBLOCK | GRND_RANDOM | GRND_INSECURE))
    {
      errno = EINVAL;
      return -1;
    }

  /* Don't allow GRND_INSECURE to be set with GRND_RANDOM. GRND_INSECURE exists
     just for Linux API compatability. It simply acts as an alias for
     GRND_NONBLOCK. This is how FreeBSD handles their version of getrandom(2):
        https://man.freebsd.org/cgi/man.cgi?query=getrandom
   */
  if (flags & GRND_INSECURE)
    {
      if (flags & GRND_RANDOM)
        {
          errno = EINVAL;
          return -1;
        }
      flags |= GRND_NONBLOCK;
    }

  fd = open ((flags & GRND_RANDOM) ? "/dev/random" : "/dev/urandom",
             O_RDONLY | O_CLOEXEC
                 | ((flags & GRND_NONBLOCK) ? O_NONBLOCK : 0));
  if (fd < 0)
    return -1;

  bytes_read = read (fd, buffer, length);

  /* Should never happen. */
  if (close (fd) < 0)
    return -1;

  return bytes_read;
}
#endif
