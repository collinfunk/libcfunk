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

#include <stdio.h>
#include <unistd.h>

int
fseeko (FILE *stream, off_t offset, int whence)
#undef fseeko
{
#if HAVE_WINDOWS_H
  {
    /* Return failures on pipes on Windows. */
    int fd = fileno (stream);
    if (fd == -1)
      return -1;
    if (lseek (fd, 0, SEEK_CUR) == -1)
      return -1;
  }
#endif

  /* Clear the end-of-file marker. Would be nice to use clearerr here but it
     would mess with other flags. */
#if HAVE_FILE__FLAGS && defined(_IOEOF)
  stream->_flags &= ~_IOEOF;
#elif HAVE_FILE__FLAG && defined(_IOEOF)
  stream->_flag &= ~_IOEOF;
#elif HAVE_FILE__FLAGS && defined(__SEOF)
  stream->_flags &= ~__SEOF;
#endif

#if HAVE_FSEEKO
  return fseeko (stream, offset, whence);
#elif HAVE__FSEEKI64
  return _fseeki64 (stream, offset, whence);
#elif HAVE_FSEEK
  return fseek (stream, (long int) offset, whence);
#else
#  error "Don't have an implementation of fseeko for your system."
  return -1;
#endif
}
