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

#include <sys/types.h>

#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#ifndef __error_t_defined
#  define __error_t_defined 1
#  ifndef _ERRNO_T_DEFINED
#    define _ERRNO_T_DEFINED
typedef int error_t;
#  endif /* _ERRNO_T_DEFINED */
#endif   /* __error_t_defined */

error_t
argz_create (char *const argv[], char **argz, size_t *argz_len)
{
  int i, argc;
  size_t len;
  size_t total_len = 0;
  char *p;

  for (argc = 0; argv[argc] != NULL; ++argc)
    total_len += strlen (argv[argc]) + 1;

  if (total_len == 0)
    {
      *argz = NULL;
      *argz_len = 0;
    }
  else
    {
      *argz = (char *) malloc (total_len);
      if (*argz == NULL)
        return ENOMEM;

      for (i = 0, p = *argz; i < argc; ++i, p += len)
        memcpy (p, argv[i], (len = strlen (argv[i]) + 1));
      *argz_len = total_len;
    }
  return 0;
}

size_t
argz_count (const char *argz, size_t len)
{
  size_t i;
  size_t count = 0;

  for (i = 0; i < len; ++i)
    {
      if (argz[i] == '\0')
        ++count;
    }
  return count;
}

void
argz_stringify (char *argz, size_t len, int sep)
{
  size_t i;

  if (len > 1)
    {
      for (i = 0; i < len - 1; ++i)
        {
          if (argz[i] == '\0')
            argz[i] = (char) sep;
        }
    }
}

char *
argz_next (const char *argz, size_t len, const char *entry)
{
  if (entry == NULL)
    return len > 0 ? (char *) argz : NULL;
  else
    {
      if (entry < argz + len)
        entry = strchr (entry, '\0') + 1;

      return entry < argz + len ? (char *) entry : NULL;
    }
}
