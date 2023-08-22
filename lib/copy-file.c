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

#include <sys/stat.h>
#include <sys/types.h>

#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "copy-file.h"
#include "read-nointr.h"
#include "write-full.h"

#ifndef O_CLOEXEC
#  ifdef O_NOINHERIT
#    define O_CLOEXEC O_NOINHERIT
#  else
#    define O_CLOEXEC 0
#  endif
#endif

bool
copy_file (const char *src, const char *dest)
{
  int src_fd, dest_fd;
  struct stat st;
  unsigned char buffer[4096];

  /* Check that SRC exists and is a non-empty file. */
  if (stat (src, &st) < 0 || !S_ISREG (st.st_mode) || st.st_size <= 0)
    return false;

  /* Open SRC for reading. */
  src_fd = open (src, O_RDONLY | O_CLOEXEC);
  if (src_fd < 0)
    return false;

  /* Open DEST and copy the permissions from SRC. If DEST already exists then
     it is overwritten. */
  dest_fd = open (dest, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC,
                  st.st_mode & 07777);
  if (dest_fd < 0)
    {
      close (src_fd);
      return false;
    }

  /* Copy until EOF. */
  for (;;)
    {
      size_t current_read = read_nointr (src_fd, buffer, sizeof (buffer));

      /* EOF. */
      if (current_read == 0)
        break;

      /* Error. */
      if (current_read < 0)
        {
          close (src_fd);
          close (dest_fd);
          return false;
        }

      /* Write to the copy. */
      if (write_full (dest_fd, buffer, current_read) != current_read)
        {
          close (src_fd);
          close (dest_fd);
          return false;
        }
    }

  /* Shouldn't ever happen. */
  if (close (src_fd) < 0)
    {
      close (dest_fd);
      return false;
    }
  if (close (dest_fd) < 0)
    return false;

  return true;
}
