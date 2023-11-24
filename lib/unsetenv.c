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

int
unsetenv (const char *name)
#undef unsetenv
{
  if (name == NULL || *name == '\0' || strchr (name, '=') != NULL)
    {
      errno = EINVAL;
      return -1;
    }
#if HAVE_UNSETENV
  {
    int result = 0;

    /* Remove all occurrences of NAME in the environment. */
    for (;;)
      {
        /* Check if NAME is in the current environment. */
        if (getenv (name) == NULL)
          break;
          /* Keep track of the return value if 'unsetenv' is declared
           correctly. */
#  if UNSETENV_HAS_POSIX_PROTOTYPE
        result = unsetenv (name);
#  else /* !UNSETENV_HAS_POSIX_PROTOTYPE */
        unsetenv (name);
#  endif
      }
    return result;
  }
#else /* !HAVE_UNSETENV */
  {
    char **envp;
    size_t name_len;

    name_len = strlen (name);
    for (envp = environ; *envp != NULL; ++envp)
      {
        /* Check if the current variable is NAME terminated by a '='. */
        if (strncmp (*envp, name, name_len) == 0 && (*envp)[name_len] == '=')
          {
            char **temp_ptr = envp;

            /* Move all subsequent variables back one place. */
            for (;;)
              {
                *temp_ptr = temp_ptr[1];
                if (*temp_ptr++ == NULL)
                  break;
              }
          }
      }
    return 0;
  }
#endif
}
