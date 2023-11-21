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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test-help.h"

static char src_buffer[2048];
static char dest_buffer[2048];

/* Test that 'stpcpy' is defined. */
int
main (void)
{
  size_t i;
  char *p;

  /* Make sure any changes to the buffer size don't break these conditions. */
  ASSERT (sizeof (src_buffer) == sizeof (dest_buffer));
  ASSERT ((sizeof (src_buffer) % 2) == 0);

  /* Poison the destination buffer. */
  memset (dest_buffer, 0xff, sizeof (dest_buffer));

  for (i = 0; i < sizeof (src_buffer) - 1; ++i)
    {
      src_buffer[i] = i & 0x7f;
      if (src_buffer[i] == '\0')
        src_buffer[i]++;
      src_buffer[i + 1] = '\0';
      p = stpncpy (dest_buffer, src_buffer, sizeof (dest_buffer));
      ASSERT (p != NULL);
      ASSERT (*p == '\0');
      ASSERT (p == dest_buffer + i + 1);
      ASSERT (memcmp (dest_buffer, src_buffer, i + 1) == 0);
      for (; p < dest_buffer + sizeof (dest_buffer); ++p)
        ASSERT (*p == '\0');
      memset (dest_buffer, 0xff, sizeof (dest_buffer));
    }

  return 0;
}
