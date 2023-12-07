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
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int
setenv (const char *envname, const char *envval, int overwrite)
#undef setenv
{
  char **envp;
  size_t envname_len;
  size_t envval_len;
  size_t var_count;
  static int allocated = 0;

  if (envname == NULL || *envname == '\0' || strchr (envname, '=') != NULL)
    {
      errno = EINVAL;
      return -1;
    }

  envp = environ;
  envname_len = strlen (envname);
  envval_len = (envval != NULL) ? strlen (envval) : 0;
  var_count = 0;
  if (envp != NULL)
    {
      for (; *envp != NULL; ++envp)
        {
          if (strncmp (*envp, envname, envname_len) == 0
              && (*envp)[envname_len] == '=')
            break;
          else
            var_count++;
        }
    }
  if (envp == NULL || *envp == NULL)
    {
      char **new_environ;

      if ((var_count > (SIZE_MAX - 2))
          || ((var_count + 2) > (SIZE_MAX / sizeof (char *))))
        {
          errno = EINVAL;
          return -1;
        }
      if (!allocated)
        new_environ = (char **) malloc ((var_count + 2) * sizeof (char *));
      else
        new_environ = (char **) realloc ((char *) environ,
                                         (var_count + 2) * sizeof (char *));
      if (new_environ == NULL)
        {
          errno = ENOMEM;
          return -1;
        }
      new_environ[var_count]
          = (char *) malloc (envname_len + 1 + envval_len + 1);
      if (new_environ[var_count] == NULL)
        {
          errno = ENOMEM;
          return -1;
        }
      memcpy (new_environ[var_count], envname, envname_len);
      new_environ[var_count][envname_len] = '=';
      if (envname_len == 0)
        new_environ[var_count][envname_len + 1] = '\0';
      else
        memcpy (&new_environ[var_count][envname_len + 1], envval,
                envval_len + 1);
      if (!allocated)
        {
          memcpy ((char *) new_environ, (char *) environ,
                  var_count * sizeof (char *));
          allocated = 1;
        }
      new_environ[var_count + 1] = NULL;
      environ = new_environ;
    }
  else if (overwrite)
    {
      char *ptr;

      ptr = (char *) malloc (envname_len + 1 + envval_len + 1);
      if (ptr == NULL)
        {
          errno = ENOMEM;
          return -1;
        }
      memcpy (ptr, envname, envname_len);
      ptr[envname_len] = '=';
      if (envname_len == 0)
        ptr[envname_len + 1] = '\0';
      else
        memcpy (&ptr[envname_len + 1], envval, envval_len + 1);
      *envp = ptr;
    }

  return 0;
}
