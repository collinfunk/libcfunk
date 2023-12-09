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
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *
getcwd (char *buf, size_t size)
#undef getcwd
#if HAVE_WINDOWS_H && HAVE__GETCWD
#  define getcwd _getcwd
#endif
{
  if (size == 0)
    {
      if (buf != NULL)
        {
          errno = EINVAL;
          return NULL;
        }
    }
  else if (size == 1)
    {
      errno = ERANGE;
      return NULL;
    }
  else if (buf != NULL)
    return getcwd (buf, size);
  else /* buf == NULL && size > 1 */
    {
      buf = (char *) malloc (size);
      if (buf == NULL)
        {
          errno = ENOMEM;
          return NULL;
        }
      else
        {
          char *result = getcwd (buf, size);
          if (result == NULL)
            free (buf);
          return result;
        }
    }
  /* BUF is a null pointer and SIZE is zero. */
  {
    char stack_buf[2048];
    char *ptr;
    char *result;

    ptr = getcwd (stack_buf, sizeof (stack_buf));
    if (ptr == NULL)
      {
        if (errno != ERANGE)
          return NULL;
      }
    else
      {
        result = strdup (stack_buf);
        if (result == NULL)
          errno = ENOMEM;
        return result;
      }
    /* Path is longer than 2048 bytes. */
    size = sizeof (stack_buf) * 2;
    buf = (char *) malloc (size);
    if (buf == NULL)
      {
        errno = ENOMEM;
        return NULL;
      }
    /* Increase the size of BUF until it is large enough. */
    for (;;)
      {
        result = getcwd (buf, size);
        if (result != NULL)
          break;
        else if (errno != ERANGE || (size > (SIZE_MAX / 2)))
          {
            free (buf);
            return NULL;
          }
        size *= 2;
        ptr = (char *) realloc (buf, size);
        if (ptr == NULL)
          {
            free (buf);
            errno = ENOMEM;
            return NULL;
          }
        buf = ptr;
      }
    return result;
  }
}
