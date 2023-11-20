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

#include <string.h>

char *
strsep (char **restrict stringp, const char *restrict delim)
#undef strsep
{
  char *str = *stringp;
  char *end;

  /* If the string pointed to by STRINGP is NULL, return NULL. */
  if (str == NULL)
    return NULL;

  /* If DELIM is an empty string, the entire string pointed to by STRINGP is
     a single token. */
  if (*delim == '\0')
    {
      *stringp = NULL;
      return str;
    }

  /* If DELIM only contains one delimiter we can call strchr and perform less
     comparisons. */
  end = (delim[1] == '\0') ? strchr (str, delim[0]) : strpbrk (str, delim);
  if (end == NULL)
    {
      *stringp = NULL;
      return str;
    }

  /* Set the delimiter at the end of the token to NUL and update STRINGP for
     the next call. */
  *end = '\0';
  *stringp = end + 1;

  return str;
}
