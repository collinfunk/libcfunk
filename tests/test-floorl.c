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

static void test_floorl_nan (void);
static void test_floorl_zero (void);
static void test_floorl_positive (void);
static void test_floorl_negative (void);
static void test_floorl_infinity (void);

int
main (void)
{
  test_floorl_nan ();
  test_floorl_zero ();
  test_floorl_positive ();
  test_floorl_negative ();
  test_floorl_infinity ();
  return 0;
}

static void
test_floorl_nan (void)
{
  /* TODO */
}

static void
test_floorl_zero (void)
{
  ASSERT (floorl (0.0L) == 0.0L);
  /* TODO: Negative zero. */
}

static void
test_floorl_positive (void)
{
  ASSERT (floorl (0.1L) == 0.0L);
  ASSERT (floorl (0.2L) == 0.0L);
  ASSERT (floorl (0.3L) == 0.0L);
  ASSERT (floorl (0.4L) == 0.0L);
  ASSERT (floorl (0.5L) == 0.0L);
  ASSERT (floorl (0.6L) == 0.0L);
  ASSERT (floorl (0.7L) == 0.0L);
  ASSERT (floorl (0.8L) == 0.0L);
  ASSERT (floorl (0.9L) == 0.0L);
  ASSERT (floorl (1.0L) == 1.0L);
}

static void
test_floorl_negative (void)
{
  ASSERT (floorl (-0.1L) == -1.0L);
  ASSERT (floorl (-0.2L) == -1.0L);
  ASSERT (floorl (-0.3L) == -1.0L);
  ASSERT (floorl (-0.4L) == -1.0L);
  ASSERT (floorl (-0.5L) == -1.0L);
  ASSERT (floorl (-0.6L) == -1.0L);
  ASSERT (floorl (-0.7L) == -1.0L);
  ASSERT (floorl (-0.8L) == -1.0L);
  ASSERT (floorl (-0.9L) == -1.0L);
  ASSERT (floorl (-1.0L) == -1.0L);
}

static void
test_floorl_infinity (void)
{
  /* TODO */
}
