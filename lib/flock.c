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

#include <sys/file.h>

#include <errno.h>
#include <string.h>

#if HAVE_FCNTL_H
#  include <fcntl.h>
#endif

#if HAVE_UNISTD_H
#  include <unistd.h>
#endif

#if HAVE_WINDOWS_H
#  include <windows.h>
#  ifndef LOCKFILE_FAIL_IMMEDIATELY
#    define LOCKFILE_FAIL_IMMEDIATELY 1
#  endif
#  ifndef LOCKFILE_EXCLUSIVE_LOCK
#    define LOCKFILE_EXCLUSIVE_LOCK 2
#  endif
#endif

#if HAVE_STRUCT_FLOCK && HAVE_STRUCT_FLOCK_L_LEN && HAVE_STRUCT_FLOCK_L_START \
    && HAVE_STRUCT_FLOCK_L_TYPE && HAVE_STRUCT_FLOCK_L_WHENCE                 \
    && defined(F_RDLCK) && defined(F_WRLCK) && defined(F_UNLCK)               \
    && defined(F_SETLK) && defined(F_SETLKW)

int
flock (int fd, int operation)
#  undef flock
{
  struct flock file_lock;

  /* Get the command for fcntl. */
  switch (operation & ~LOCK_NB)
    {
    case LOCK_SH:
      file_lock.l_type = F_RDLCK;
      break;
    case LOCK_EX:
      file_lock.l_type = F_WRLCK;
      break;
    case LOCK_UN:
      file_lock.l_type = F_UNLCK;
      break;
    default:
      errno = EINVAL;
      return -1;
    }

  /* Lock the entire file. */
  file_lock.l_whence = SEEK_SET;
  file_lock.l_start = file_lock.l_len = 0;

  /* FIXME: Trust the errno for fcntl or change it? */
  return fcntl (fd, (operation & LOCK_NB) ? F_SETLK : F_SETLKW, &file_lock);
}

#else /* HAVE_WINDOWS_H */

/* Windows does not document the return value for 'GetLastError ()'. The error
   numbers returned by these functions is probably incorrect. If any Windows
   fileapi function fails, we just set errno to 'EBADF'. */
static int win32_flock_lock (int fd, int nonblocking, int exclusive);
static int win32_flock_unlock (int fd);

int
flock (int fd, int operation)
#  undef flock
{
  /* Get the command ignoring the nonblocking flag. */
  switch (operation & ~LOCK_NB)
    {
    case LOCK_SH:
      return win32_flock_lock (fd, (operation & LOCK_NB), 0);
    case LOCK_EX:
      return win32_flock_lock (fd, (operation & LOCK_NB), 1);
    case LOCK_UN:
      return win32_flock_unlock (fd);
    default:
      errno = EINVAL;
      return -1;
    }
}

static int
win32_flock_lock (int fd, int nonblocking, int exclusive)
{
  HANDLE fd_handle;
  LARGE_INTEGER file_size;
  OVERLAPPED overlapped;
  BOOL result;
  DWORD flags = 0;

  fd_handle = (HANDLE) _get_osfhandle (fd);
  if (fd_handle == INVALID_HANDLE_VALUE)
    {
      errno = EBADF;
      return -1;
    }
  result = GetFileSizeEx (fd_handle, &file_size);
  if (!result)
    {
      errno = EBADF;
      return -1;
    }
  memset (&overlapped, '\0', sizeof (OVERLAPPED));
  if (nonblocking)
    flags |= LOCKFILE_FAIL_IMMEDIATELY;
  if (exclusive)
    flags |= LOCKFILE_EXCLUSIVE_LOCK;
  result = LockFileEx (fd_handle, flags, 0, file_size.LowPart,
                       file_size.HighPart, &overlapped);
  if (!result)
    {
      errno = EBADF;
      return -1;
    }
  return 0;
}

static int
win32_flock_unlock (int fd)
{
  HANDLE fd_handle;
  LARGE_INTEGER file_size;
  OVERLAPPED overlapped;
  BOOL result;

  fd_handle = (HANDLE) _get_osfhandle (fd);
  if (fd_handle == INVALID_HANDLE_VALUE)
    {
      errno = EBADF;
      return -1;
    }
  result = GetFileSizeEx (fd_handle, &file_size);
  if (!result)
    {
      errno = EBADF;
      return -1;
    }
  memset (&overlapped, '\0', sizeof (OVERLAPPED));
  result = UnlockFileEx (fd_handle, 0, file_size.LowPart, file_size.HighPart,
                         &overlapped);
  if (!result)
    {
      errno = EBADF;
      return -1;
    }
  return 0;
}

#endif
