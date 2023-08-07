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
#ifndef UINT_WIDTH
#  define UINT_WIDTH TYPE_WIDTH (unsigned int)
#endif

#ifndef ULONG_WIDTH
#  define ULONG_WIDTH TYPE_WIDTH (unsigned long int)
#endif

#ifndef ULLONG_WIDTH
#  define ULLONG_WIDTH TYPE_WIDTH (unsigned long long int)
#endif

static void test_popcount (void);
static void test_popcountl (void);
static void test_popcountll (void);

int
main (void)
{
  test_popcount ();
  test_popcountl ();
  test_popcountll ();
  return 0;
}

static void
test_popcount (void)
{
  unsigned int forward;
  unsigned int backward;
  unsigned int forward_result;
  unsigned int backward_result;
  size_t i;

  forward = 0;
  backward = 0;

  for (i = 0; i < UINT_WIDTH; ++i)
    {
      forward |= (1U << i);
      backward |= (1U << (UINT_WIDTH - i - 1));
      forward_result = popcount (forward);
      backward_result = popcount (backward);
      ASSERT ((size_t) forward_result == i + 1);
      ASSERT (forward_result == backward_result);
    }
}

static void
test_popcountl (void)
{
  unsigned long int forward;
  unsigned long int backward;
  unsigned int forward_result;
  unsigned int backward_result;
  size_t i;

  forward = 0;
  backward = 0;

  for (i = 0; i < ULONG_WIDTH; ++i)
    {
      forward |= (1UL << i);
      backward |= (1UL << (ULONG_WIDTH - i - 1));
      forward_result = popcountl (forward);
      backward_result = popcountl (backward);
      ASSERT ((size_t) forward_result == i + 1);
      ASSERT (forward_result == backward_result);
    }
}

static void
test_popcountll (void)
{
  unsigned long long int forward;
  unsigned long long int backward;
  unsigned int forward_result;
  unsigned int backward_result;
  size_t i;

  forward = 0;
  backward = 0;

  for (i = 0; i < ULLONG_WIDTH; ++i)
    {
      forward |= (1ULL << i);
      backward |= (1ULL << (ULLONG_WIDTH - i - 1));
      forward_result = popcountll (forward);
      backward_result = popcountll (backward);
      ASSERT ((size_t) forward_result == i + 1);
      ASSERT (forward_result == backward_result);
    }
}
