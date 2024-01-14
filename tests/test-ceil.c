/*-
 * Copyright (c) 2024, Collin Funk
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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

static void test_ceil_nan (void);
static void test_ceil_zero (void);
static void test_ceil_positive (void);
static void test_ceil_negative (void);
static void test_ceil_infinity (void);

int
main (void)
{
  test_ceil_nan ();
  test_ceil_zero ();
  test_ceil_positive ();
  test_ceil_negative ();
  test_ceil_infinity ();
  return 0;
}

static void
test_ceil_nan (void)
{
  /* TODO */
}

static void
test_ceil_zero (void)
{
  ASSERT (ceil (0.0) == 0.0);
  /* TODO: Negative zero. */
}

static void
test_ceil_positive (void)
{
  ASSERT (ceil (0.1) == 1.0);
  ASSERT (ceil (0.2) == 1.0);
  ASSERT (ceil (0.3) == 1.0);
  ASSERT (ceil (0.4) == 1.0);
  ASSERT (ceil (0.5) == 1.0);
  ASSERT (ceil (0.6) == 1.0);
  ASSERT (ceil (0.7) == 1.0);
  ASSERT (ceil (0.8) == 1.0);
  ASSERT (ceil (0.9) == 1.0);
  ASSERT (ceil (1.0) == 1.0);
}

static void
test_ceil_negative (void)
{
  ASSERT (ceil (-0.1) == 0.0);
  ASSERT (ceil (-0.2) == 0.0);
  ASSERT (ceil (-0.3) == 0.0);
  ASSERT (ceil (-0.4) == 0.0);
  ASSERT (ceil (-0.5) == 0.0);
  ASSERT (ceil (-0.6) == 0.0);
  ASSERT (ceil (-0.7) == 0.0);
  ASSERT (ceil (-0.8) == 0.0);
  ASSERT (ceil (-0.9) == 0.0);
  ASSERT (ceil (-1.0) == -1.0);
}

static void
test_ceil_infinity (void)
{
  /* TODO */
}
