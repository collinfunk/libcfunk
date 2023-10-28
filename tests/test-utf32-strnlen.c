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

#include "test-help.h"
#include "unicode.h"

int
main (void)
{
  uint32_t buffer[4096 / sizeof (uint32_t)];
  size_t i;

  /* Fill the buffer and make sure 'utf32_strnlen' respects the NUL
     character. */
  memset (buffer, '\0', sizeof (buffer));
  for (i = 0; i < ARRAY_SIZE (buffer) - 1; ++i)
    {
      buffer[i] = 'a';
      ASSERT (utf32_strnlen (buffer, i + 1) == i + 1);
    }

  /* Test that 'utf32_strnlen' respects the size. */
  for (i = 0; i < ARRAY_SIZE (buffer) - 1; ++i)
    ASSERT (utf32_strnlen (buffer, i + 1) == i + 1);

  /* Test that 'utf32_strnlen' respects the NUL byte over size. */
  for (i = 0; i < ARRAY_SIZE (buffer) - 1; ++i)
    ASSERT (utf32_strnlen (buffer, ARRAY_SIZE (buffer) + i + 1)
            == ARRAY_SIZE (buffer) - 1);

  return 0;
}
