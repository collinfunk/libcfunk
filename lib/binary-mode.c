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
#include <stdio.h>

#include "attributes.h"
#include "binary-mode.h"

#if !defined(O_BINARY) || O_BINARY == 0
int
set_binary_mode (int fd ATTRIBUTE_UNUSED)
{
  return 0;
}

int
fset_binary_mode (FILE *fp ATTRIBUTE_UNUSED)
{
  return 0;
}
#else
int
set_binary_mode (int fd)
{
#  if HAVE__SETMODE
  return _setmode (fd, O_BINARY);
#  elif HAVE_SETMODE
  return setmode (fd, O_BINARY);
#  else /* Assume O_BINARY does nothing. */
  return 0;
#  endif
}

int
fset_binary_mode (FILE *fp)
{
  int fd =
#  if HAVE__FILENO
      _fileno (fp);
#  elif HAVE_FILENO
      fileno (fp);
#  else
      -1;
#    error "Cannot get file descriptor from a FILE *."
#  endif
  if (fd < 0)
    return -1;

  return set_binary_mode (fd);
}
#endif

#if !defined(O_TEXT) || O_TEXT == 0
int
set_text_mode (int fd ATTRIBUTE_UNUSED)
{
  return 0;
}

int
fset_text_mode (FILE *fp ATTRIBUTE_UNUSED)
{
  return 0;
}
#else
int
set_text_mode (int fd)
{
#  if HAVE__SETMODE
  return _setmode (fd, O_TEXT);
#  elif HAVE_SETMODE
  return setmode (fd, O_TEXT);
#  else /* Assume O_TEXT does nothing. */
  return 0;
#  endif
}

int
fset_text_mode (FILE *fp)
{
  int fd =
#  if HAVE__FILENO
      _fileno (fp);
#  elif HAVE_FILENO
      fileno (fp);
#  else
      -1;
#    error "Cannot get file descriptor from a FILE *."
#  endif
  if (fd < 0)
    return -1;

  return set_text_mode (fd);
}
#endif
