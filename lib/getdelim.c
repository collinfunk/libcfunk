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

#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* getdelim () for Windows which doesn't provide it. */
ssize_t
getdelim (char **lineptr, size_t *n, int delimiter, FILE *stream)
{
  int ch;
  size_t bytes_read = 0;

  /* POSIX doesn't say stream returns errno == EINVAL. Assume the user doesn't
     provide a NULL stream? */
  if (lineptr == NULL || n == NULL)
    {
      errno = EINVAL;
      return -1;
    }

  /* Lock the filestream. */
  flockfile (stream);

  /* Make sure LINEPTR is a pointer that can be passed to free (). */
  if (*lineptr == NULL || *n == 0)
    {
      void *new_ptr = malloc (128);
      if (new_ptr == NULL)
        {
          funlockfile (stream);
          return -1;
        }
      *lineptr = (char *) new_ptr;
      *n = 128;
    }

  do
    {
      ch = getc_unlocked (stream);

      /* If we reach the EOF, NUL terminate the string and return -1 to the
         caller so this function can be used as a loop condition. */
      if (ch == EOF)
        {
          (*lineptr)[bytes_read] = '\0';
          funlockfile (stream);
          return -1;
        }

      /* Make sure we have enough bytes for the string plus the NUL byte. */
      if (bytes_read + 1 >= *n)
        {
          void *new_ptr;
          size_t new_size;

          /* We can only read SSIZE_MAX per call don't allocate more than
             that. */
          if (*n > SSIZE_MAX / 2)
            new_size = SSIZE_MAX;
          else
            new_size = *n > 0 ? *n * 2 : 128;

          /* Check that SSIZE_MAX is enough or that N * 2 didn't cause
             size_t to wrap. */
          if (bytes_read + 1 >= new_size)
            {
              errno = EOVERFLOW;
              funlockfile (stream);
              return -1;
            }

          new_ptr = realloc (*lineptr, new_size);
          if (new_ptr == NULL)
            {
              funlockfile (stream);
              return -1;
            }

          *lineptr = (char *) new_ptr;
          *n = new_size;
        }

      (*lineptr)[bytes_read++] = (char) ch;
    }
  while (ch != delimiter);

  /* Unlock the filestream. */
  funlockfile (stream);

  /* Always NUL terminate the string. Return -1 to indicate an error if
     no bytes were read. */
  (*lineptr)[bytes_read] = '\0';
  return bytes_read > 0 ? (ssize_t) bytes_read : -1;
}
