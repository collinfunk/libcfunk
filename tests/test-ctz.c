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

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "ctz.h"
#include "test-help.h"

#ifndef CHAR_BIT
#  define CHAR_BIT 8
#endif

static void test_ctz (void);
static void test_ctzl (void);
static void test_ctzll (void);

int
main (void)
{
  test_ctz ();
  test_ctzl ();
  test_ctzll ();
  return 0;
}

static void
test_ctz (void)
{
  unsigned int value;
  int result;
  size_t i;

  for (i = 0; i < sizeof (value) * CHAR_BIT; ++i)
    {
      value = 1U << i;
      result = ctz (value);
      printf ("ctz (%08x): %d\n", value, result);
      ASSERT (result == (int) i);
    }
}

static void
test_ctzl (void)
{
  unsigned long int value;
  int result;
  size_t i;

  for (i = 0; i < sizeof (value) * CHAR_BIT; ++i)
    {
      value = 1UL << i;
      result = ctzl (value);
      printf ("ctzl (%016lx): %d\n", value, result);
      ASSERT (result == (int) i);
    }
}

static void
test_ctzll (void)
{
  unsigned long long int value;
  int result;
  size_t i;

  for (i = 0; i < sizeof (value) * CHAR_BIT; ++i)
    {
      value = 1ULL << i;
      result = ctzll (value);
      printf ("ctzll (%016llx): %d\n", value, result);
      ASSERT (result == (int) i);
    }
}
