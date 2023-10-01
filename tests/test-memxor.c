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

#include "memxor.h"
#include "test-help.h"

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
#  if BUFFER_SIZE % 2 != 0
#    error BUFFER_SIZE must be a even number.
#  endif
#endif

static unsigned char dest[BUFFER_SIZE];
static unsigned char src[BUFFER_SIZE];

static void test_zeros (void);
static void test_even_odd (void);

int
main (void)
{
  test_zeros ();
  test_even_odd ();
  return 0;
}

/* 0 ^ 0 == 0 */
static void
test_zeros (void)
{
  memset (dest, 0, sizeof (dest));
  memset (src, 0, sizeof (src));
  ASSERT (memcmp (memxor (dest, src, sizeof (dest)), src, sizeof (dest)) == 0);
}

/* 0xaa ^ 0x55 == 0xff */
static void
test_even_odd (void)
{
  size_t i;
  memset (dest, 0x55, sizeof (dest));
  memset (src, 0xaa, sizeof (src));
  ASSERT (memxor (dest, src, sizeof (dest) / 2) == dest);
  for (i = 0; i < sizeof (dest) / 2; ++i)
    ASSERT (dest[i] == 0xff);
  for (i = sizeof (dest) / 2; i < sizeof (dest); ++i)
    ASSERT (dest[i] == 0x55);
  ASSERT (memxor (dest + (sizeof (dest) / 2), src, sizeof (dest) / 2)
          == dest + (sizeof (dest) / 2));
  for (i = 0; i < sizeof (dest); ++i)
    ASSERT (dest[i] == 0xff);
}
