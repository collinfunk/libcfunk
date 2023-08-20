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

int
isalnum (int c)
{
  return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
         || (c >= 'a' && c <= 'z');
}

int
isalpha (int c)
{
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int
isascii (int c)
{
  return c >= 0 && c < 128;
}

int
isblank (int c)
{
  return c == ' ' || c == '\t';
}

int
iscntrl (int c)
{
  return c < 32 || c == 127;
}

int
isdigit (int c)
{
  return c >= '0' && c <= '9';
}

int
isgraph (int c)
{
  return c >= 33 && c <= 126;
}

int
islower (int c)
{
  return c >= 'a' && c <= 'z';
}

int
isprint (int c)
{
  return c >= 32 && c <= 126;
}

int
ispunct (int c)
{
  return (c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96)
         || (c >= 123 && c <= 126);
}

int
isspace (int c)
{
  return c == ' ' || (c >= 9 && c <= 13);
}

int
isupper (int c)
{
  return c >= 'A' && c <= 'Z';
}

int
isxdigit (int c)
{
  return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')
         || (c >= 'A' && c <= 'F');
}

int
toascii (int c)
{
  return c & 127;
}

int
tolower (int c)
{
  return c >= 'A' && c <= 'Z' ? c + 32 : c;
}

int
toupper (int c)
{
  return c >= 'a' && c <= 'z' ? c - 32 : c;
}

/* POSIX requires that these are defined as macros. They are required
   to check C is a lowercase character before converting (or vice versa).
   This is already required in the non prefixed functions according to C99. */
#ifndef _toupper
#  define _toupper(c) toupper (c)
#endif

#ifndef _tolower
#  define _tolower(c) tolower ((c))
#endif
