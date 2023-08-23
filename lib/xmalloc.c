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

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xmalloc.h"

void *
xmalloc (size_t size)
{
  void *ptr = malloc (size);
  if (ptr == NULL)
    {
      fprintf (stderr, "malloc (): Out of memory.\n");
      abort ();
    }
  return ptr;
}

void *
xcalloc (size_t nelem, size_t elsize)
{
  void *ptr = calloc (nelem, elsize);
  if (ptr == NULL)
    {
      fprintf (stderr, "calloc (): Out of memory.\n");
      abort ();
    }
  return ptr;
}

void *
xrealloc (void *ptr, size_t size)
{
  void *new_ptr = realloc (ptr, size);
  if (new_ptr == NULL)
    {
      fprintf (stderr, "realloc (): Out of memory.\n");
      abort ();
    }
  return new_ptr;
}

void *
xreallocarray (void *ptr, size_t nelem, size_t elsize)
{
  void *new_ptr = reallocarray (ptr, nelem, elsize);
  if (new_ptr == NULL)
    {
      fprintf (stderr, "reallocarray (): Out of memory.\n");
      abort ();
    }
  return new_ptr;
}

void *
xmemdup (const char *ptr, size_t n)
{
  void *copy = malloc (n);
  if (copy == NULL)
    {
      fprintf (stderr, "xmemdup (): Out of memory.\n");
      abort ();
    }
  return memcpy (copy, ptr, n);
}

char *
xstrdup (const char *s)
{
  return (char *) xmemdup (s, strlen (s) + 1);
}

char *
xstrndup (const char *s, size_t size)
{
  size_t slen = strnlen (s, size);
  char *copy = (char *) xmemdup (s, slen + 1);
  copy[slen] = '\0';
  return copy;
}
