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

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "test-help.h"

#ifndef CHAR_BIT
#  define CHAR_BIT 8
#endif

#define TYPE_WIDTH(type) (CHAR_BIT * sizeof (type))

/* Windows doesn't define these in <limits.h> :( */
#ifndef INT_WIDTH
#  define INT_WIDTH TYPE_WIDTH (int)
#endif

#ifndef LONG_WIDTH
#  define LONG_WIDTH TYPE_WIDTH (long int)
#endif

#ifndef LLONG_WIDTH
#  define LLONG_WIDTH TYPE_WIDTH (long long int)
#endif

static void test_ffs (void);
static void test_ffsl (void);
static void test_ffsll (void);

int
main (void)
{
  test_ffs ();
  test_ffsl ();
  test_ffsll ();
  return 0;
}

static void
test_ffs (void)
{
  int value;
  int result;
  size_t i;

  for (i = 0; i < INT_WIDTH - 1; ++i)
    {
      value = 1 << i;
      result = ffs (value);
      ASSERT ((size_t) result - 1 == i);
      printf ("ffs (0x%x) == %d\n", value, result);
    }
}

static void
test_ffsl (void)
{
  long int value;
  int result;
  size_t i;

  for (i = 0; i < LONG_WIDTH - 1; ++i)
    {
      value = 1L << i;
      result = ffsl (value);
      ASSERT ((size_t) result - 1 == i);
      printf ("ffsl (0x%lx) == %d\n", value, result);
    }
}

static void
test_ffsll (void)
{
  long long int value;
  int result;
  size_t i;

  for (i = 0; i < LLONG_WIDTH - 1; ++i)
    {
      value = 1LL << i;
      result = ffsll (value);
      ASSERT ((size_t) result - 1 == i);
      printf ("ffsll (0x%llx) == %d\n", value, result);
    }
}
