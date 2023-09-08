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

#include <stddef.h>
#include <string.h>

#include "test-help.h"

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
#  if BUFFER_SIZE % 2 != 0
#    error BUFFER_SIZE must be a even number.
#  endif
#endif

int
main (void)
{
  unsigned char buffer[BUFFER_SIZE];
  size_t i;

  ASSERT (memset_explicit (buffer, 0, sizeof (buffer)) == buffer);
  for (i = 0; i < sizeof (buffer); ++i)
    ASSERT (buffer[i] == 0);
  ASSERT (memset_explicit (buffer, 0xff, sizeof (buffer) / 2) == buffer);
  for (i = 0; i < sizeof (buffer) / 2; ++i)
    ASSERT (buffer[i] == 0xff);
  for (i = sizeof (buffer) / 2; i < sizeof (buffer); ++i)
    ASSERT (buffer[i] == 0);
  ASSERT (memset_explicit (buffer + (sizeof (buffer) / 2), 0x55,
                           sizeof (buffer) / 2)
          == buffer + (sizeof (buffer) / 2));
  for (i = 0; i < sizeof (buffer) / 2; ++i)
    ASSERT (buffer[i] == 0xff);
  for (i = sizeof (buffer) / 2; i < sizeof (buffer); ++i)
    ASSERT (buffer[i] == 0x55);
  ASSERT (memset_explicit (buffer, 0xaa, sizeof (buffer)) == buffer);
  for (i = 0; i < sizeof (buffer); ++i)
    ASSERT (buffer[i] == 0xaa);

  return 0;
}
