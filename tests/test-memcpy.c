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
#include <string.h>

#include "test-help.h"

static unsigned char buffer1[2048];
static unsigned char buffer2[2048];

/* Test that 'memcpy' is declared. */
int
main (void)
{
  size_t i;

  ASSERT (sizeof (buffer1) == sizeof (buffer2));
  ASSERT ((sizeof (buffer1) % 2) == 0);

  for (i = 0; i < sizeof (buffer1); ++i)
    buffer1[i] = i & 0xff;

  ASSERT (memcpy (buffer2, buffer1, sizeof (buffer1) / 2) == buffer2);
  ASSERT (memcpy (buffer2 + (sizeof (buffer2) / 2),
                  buffer1 + (sizeof (buffer2) / 2), sizeof (buffer2) / 2)
          == buffer2 + (sizeof (buffer2) / 2));
  ASSERT (memcmp (buffer2, buffer1, sizeof (buffer2)) == 0);

  return 0;
}
