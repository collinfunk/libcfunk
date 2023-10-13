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

#include <stddef.h>
#include <stdio.h>
#include <stdio_ext.h>

/* Return the total number of bytes in the output buffer. */
size_t
__fpending (FILE *stream)
{
#if HAVE_FILE__IO_WRITE_PTR && HAVE_FILE__IO_WRITE_BASE
  if (stream->_IO_write_ptr == NULL)
    return 0;
  else
    stream->_IO_write_ptr - stream->_IO_write_base;
#elif HAVE_FILE__P && HAVE_FILE__BF__BASE
  if (stream->_p == NULL)
    return 0;
  return stream->_p - stream->_bf._base;
#elif HAVE_FILE__BASE && HAVE_FILE__PTR
  if (stream->_ptr == NULL)
    return 0;
  else
    return stream->_ptr - stream->_base;
#else
#  error "__fpending not implemented on your system."
  return 0;
#endif
}
