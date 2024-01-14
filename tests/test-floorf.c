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

static void test_floorf_nan (void);
static void test_floorf_zero (void);
static void test_floorf_positive (void);
static void test_floorf_negative (void);
static void test_floorf_infinity (void);

int
main (void)
{
  test_floorf_nan ();
  test_floorf_zero ();
  test_floorf_positive ();
  test_floorf_negative ();
  test_floorf_infinity ();
  return 0;
}

static void
test_floorf_nan (void)
{
  /* TODO */
}

static void
test_floorf_zero (void)
{
  ASSERT (floorf (0.0f) == 0.0f);
  /* TODO: Negative zero. */
}

static void
test_floorf_positive (void)
{
  ASSERT (floorf (0.1f) == 0.0f);
  ASSERT (floorf (0.2f) == 0.0f);
  ASSERT (floorf (0.3f) == 0.0f);
  ASSERT (floorf (0.4f) == 0.0f);
  ASSERT (floorf (0.5f) == 0.0f);
  ASSERT (floorf (0.6f) == 0.0f);
  ASSERT (floorf (0.7f) == 0.0f);
  ASSERT (floorf (0.8f) == 0.0f);
  ASSERT (floorf (0.9f) == 0.0f);
  ASSERT (floorf (1.0f) == 1.0f);
}

static void
test_floorf_negative (void)
{
  ASSERT (floorf (-0.1f) == -1.0f);
  ASSERT (floorf (-0.2f) == -1.0f);
  ASSERT (floorf (-0.3f) == -1.0f);
  ASSERT (floorf (-0.4f) == -1.0f);
  ASSERT (floorf (-0.5f) == -1.0f);
  ASSERT (floorf (-0.6f) == -1.0f);
  ASSERT (floorf (-0.7f) == -1.0f);
  ASSERT (floorf (-0.8f) == -1.0f);
  ASSERT (floorf (-0.9f) == -1.0f);
  ASSERT (floorf (-1.0f) == -1.0f);
}

static void
test_floorf_infinity (void)
{
  /* TODO */
}
