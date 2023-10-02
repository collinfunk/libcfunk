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
#include <string.h>
#include <unistd.h>

/* Don't call ourselves. */
#undef getcwd

/* The original system declaration. */
static char *
_system_getcwd (char *buffer, size_t size)
{
#if HAVE__GETCWD
  return _getcwd (buffer, size);
#else
  return getcwd (buffer, size);
#endif
}

char *
_libcfunk_getcwd (char *buffer, size_t size)
{
  char *return_value;
  char *ptr;
  char stack_buffer[2048];

  /* If BUFFER isn't NULL assume it points to a valid block of SIZE bytes. */
  if (buffer != NULL)
    {
      if (size > 0)
        return _system_getcwd (buffer, size);
      else /* Buffer is not NULL and size is 0. */
        {
          errno = EINVAL;
          return NULL;
        }
    }

  /* If BUFFER is NULL and SIZE isn't 0, assume that is the number of bytes the
     caller wants allocated. */
  if (size > 0)
    {
      buffer = malloc (size);
      if (buffer == NULL)
        return NULL;
      return_value = _system_getcwd (buffer, size);
      if (return_value == NULL)
        {
          free (buffer);
          buffer = NULL;
        }
      return return_value;
    }

  /* TODO: Fails on directory names over 2048 bytes long... */
  ptr = _system_getcwd (stack_buffer, sizeof (stack_buffer));
  if (ptr == NULL)
    return NULL;
  return strdup (ptr);
}
