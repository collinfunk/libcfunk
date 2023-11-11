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
#include <string.h>
#include <unistd.h>

#include "attributes.h"

#if HAVE_WINDOWS_H
int
ttyname_r (int fd ATTRIBUTE_UNUSED, char *buffer ATTRIBUTE_UNUSED,
           size_t buffer_len ATTRIBUTE_UNUSED)
{
  /* I don't think Windows has tty's. Python's os.ttyname() isn't aviable on
     Windows for example. */
  return ENOTTY;
}

#else /* Not Windows. */

/* Substite function for ttyname_r for systems that don't have it.
   Note that this uses ttyname(3) so it is not reentrant or thread-safe. */
int
ttyname_r (int fd, char *buffer, size_t buffer_len)
{
#  if HAVE_TTYNAME
  char *name;
  size_t name_len;

  name = ttyname (fd);
  if (name == NULL)
    return errno;
  name_len = strlen (name) + 1;
  if (buffer_len < name_len)
    return ERANGE;
  memcpy (buffer, name, name_len);
  return 0;
#  else
#    error "ttyname_r not implemented for your system."
#  endif
}
#endif
