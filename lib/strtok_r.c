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
strtok_r (char *restrict s, const char *restrict sep, char **restrict state)
#undef strtok_r
{
  char *end;

  /* If S is NULL, a previous call set the STATE parameter. */
  if (s == NULL)
    s = *state;

  /* Check for the easy case where a previous call reached the end of
     the string. */
  if (*s == '\0')
    {
      *state = s;
      return NULL;
    }

  /* Skip any leading delimiters in S. */
  s += strspn (s, sep);
  if (*s == '\0')
    {
      *state = s;
      return NULL;
    }

  /* Find the end of the current token or string, whichever is first. */
  end = s + strcspn (s, sep);
  if (*end == '\0')
    {
      *state = end;
      return s;
    }

  /* Set the delimiter at the end of the token to NUL and update STATE for
     the next call. */
  *end = '\0';
  *state = end + 1;

  return s;
}
