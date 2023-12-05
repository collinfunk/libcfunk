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

#include <argz.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

static void test_argz_append1 (void);

int
main (void)
{
  test_argz_append1 ();
  return 0;
}

static void
test_argz_append1 (void)
{
  char *buffer;
  size_t buffer_size;
  int i;

  buffer = (char *) malloc (2);
  ASSERT (buffer != NULL);
  buffer_size = 2;
  buffer[0] = 'A';
  buffer[1] = '\0';

  for (i = 'B'; i <= 'Z'; ++i)
    {
      int result;
      char temp[2] = { (char) i, '\0' };

      result = (int) argz_append (&buffer, &buffer_size, temp, sizeof (temp));
      ASSERT (result == 0);
      ASSERT (buffer_size == (size_t) (((i - 'A') * 2) + 2));
    }

  for (i = 0; i <= 'Z' - 'A'; ++i)
    {
      ASSERT (buffer[(i * 2)] == 'A' + i);
      ASSERT (buffer[(i * 2) + 1] == '\0');
    }

  free (buffer);
}
