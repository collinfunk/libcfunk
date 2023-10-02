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
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "test-help.h"

static char buffer[2048];

/* Length of the current directory. */
static size_t cwd_len;

int
main (void)
{
  char *ptr = NULL;

  /* Make sure that passing a non-NULL pointer doesn't allocate memory. */
  ASSERT (getcwd (buffer, sizeof (buffer)) != NULL);
  cwd_len = strlen (buffer);

  /* Allocate enough bytes for the CWD + NUL byte. */
  ptr = getcwd (NULL, cwd_len + 1);
  ASSERT (ptr != NULL);
  ASSERT (strcmp (ptr, buffer) == 0);

  /* Cleanup the memory. */
  free (ptr);
  ptr = NULL;

  /* Test that memory is allocated when passing a NULL pointer and 0 size. */
  ptr = getcwd (NULL, 0);
  ASSERT (ptr != NULL);
  ASSERT (strcmp (ptr, buffer) == 0);

  /* Cleanup the memory. */
  free (ptr);

  return 0;
}
