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
#include <stdckdint.h>

#include "test-help.h"

static void test_ckd_add (void);
static void test_ckd_sub (void);
static void test_ckd_mul (void);

int
main (void)
{
  test_ckd_add ();
  test_ckd_sub ();
  test_ckd_mul ();
  return 0;
}

static void
test_ckd_add (void)
{
  unsigned int uresult;
  int sresult;

  /* No overflow. */
  ASSERT (!ckd_add (&sresult, INT_MIN, 0));
  ASSERT (sresult == INT_MIN);
  ASSERT (!ckd_add (&sresult, INT_MAX, 0));
  ASSERT (sresult == INT_MAX);
  ASSERT (!ckd_add (&sresult, INT_MIN, 1));
  ASSERT (sresult == INT_MIN + 1);
  ASSERT (!ckd_add (&sresult, INT_MAX, -1));
  ASSERT (sresult == INT_MAX - 1);

  /* a + b == b + a */
  ASSERT (!ckd_add (&sresult, 0, INT_MIN));
  ASSERT (!ckd_add (&sresult, 0, INT_MAX));
  ASSERT (!ckd_add (&sresult, 1, INT_MIN));
  ASSERT (!ckd_add (&sresult, -1, INT_MAX));

  /* Overflow. */
  ASSERT (ckd_add (&sresult, -1, INT_MIN));
  ASSERT (ckd_add (&sresult, 1, INT_MAX));
  ASSERT (ckd_add (&sresult, -2, INT_MIN));
  ASSERT (ckd_add (&sresult, 2, INT_MAX));

  /* a + b == b + a */
  ASSERT (ckd_add (&sresult, INT_MIN, -1));
  ASSERT (ckd_add (&sresult, INT_MAX, 1));
  ASSERT (ckd_add (&sresult, INT_MIN, -2));
  ASSERT (ckd_add (&sresult, INT_MAX, 2));

  /* No overflow. */
  ASSERT (!ckd_add (&uresult, 0U, 0U));
  ASSERT (uresult == 0U);
  ASSERT (!ckd_add (&uresult, 0U, UINT_MAX));
  ASSERT (uresult == UINT_MAX);
  ASSERT (!ckd_add (&uresult, 0U, 1U));
  ASSERT (uresult == 1U);
  ASSERT (!ckd_add (&uresult, UINT_MAX, -1));
  ASSERT (uresult == UINT_MAX - 1U);

  /* a + b == b + a */
  ASSERT (!ckd_add (&uresult, 0U, 0U));
  ASSERT (uresult == 0U);
  ASSERT (!ckd_add (&uresult, UINT_MAX, 0U));
  ASSERT (uresult == UINT_MAX);
  ASSERT (!ckd_add (&uresult, 1U, 0U));
  ASSERT (uresult == 1U);
  ASSERT (!ckd_add (&uresult, -1, UINT_MAX));
  ASSERT (uresult == UINT_MAX - 1U);

  /* Overflow. */
  ASSERT (ckd_add (&uresult, 0U, -1));
  ASSERT (ckd_add (&uresult, UINT_MAX, 1U));
  ASSERT (ckd_add (&uresult, 0U, -2));
  ASSERT (ckd_add (&uresult, UINT_MAX, 2U));

  /* a + b == b + a */
  ASSERT (ckd_add (&uresult, -1, 0U));
  ASSERT (ckd_add (&uresult, 1U, UINT_MAX));
  ASSERT (ckd_add (&uresult, -2, 0U));
  ASSERT (ckd_add (&uresult, 2U, UINT_MAX));
}

static void
test_ckd_sub (void)
{
  unsigned int uresult;
  int sresult;

  /* No overflow. */
  ASSERT (!ckd_sub (&sresult, INT_MIN, 0));
  ASSERT (sresult == INT_MIN);
  ASSERT (!ckd_sub (&sresult, INT_MAX, 0));
  ASSERT (sresult == INT_MAX);
  ASSERT (!ckd_sub (&sresult, INT_MIN, -1));
  ASSERT (sresult == INT_MIN + 1);
  ASSERT (!ckd_sub (&sresult, INT_MAX, 1));
  ASSERT (sresult == INT_MAX - 1);

  /* Overflow. */
  ASSERT (ckd_sub (&sresult, INT_MIN, 1));
  ASSERT (ckd_sub (&sresult, INT_MAX, -1));
  ASSERT (ckd_sub (&sresult, INT_MIN, 2));
  ASSERT (ckd_sub (&sresult, INT_MAX, -2));

  /* No overflow. */
  ASSERT (!ckd_sub (&uresult, 0U, 0));
  ASSERT (uresult == 0U);
  ASSERT (!ckd_sub (&uresult, UINT_MAX, 0));
  ASSERT (uresult == UINT_MAX);
  ASSERT (!ckd_sub (&uresult, 0U, -1));
  ASSERT (uresult == 1U);
  ASSERT (!ckd_sub (&uresult, UINT_MAX, 1U));
  ASSERT (uresult == UINT_MAX - 1U);

  /* Overflow. */
  ASSERT (ckd_sub (&uresult, 0U, 1));
  ASSERT (ckd_sub (&uresult, UINT_MAX, -1));
  ASSERT (ckd_sub (&uresult, 0U, 2));
  ASSERT (ckd_sub (&uresult, UINT_MAX, -2));
}

static void
test_ckd_mul (void)
{
  unsigned int uresult;
  int sresult;

  /* No overflow. */
  ASSERT (!ckd_mul (&sresult, INT_MIN, 0));
  ASSERT (sresult == 0);
  ASSERT (!ckd_mul (&sresult, INT_MAX, 0));
  ASSERT (sresult == 0);
  ASSERT (!ckd_mul (&sresult, INT_MIN, 1));
  ASSERT (sresult == INT_MIN);
  ASSERT (!ckd_mul (&sresult, INT_MAX, 1));
  ASSERT (sresult == INT_MAX);
  ASSERT (!ckd_mul (&sresult, INT_MIN + 1, -1));
  ASSERT (sresult == (INT_MIN + 1) * -1);
  ASSERT (!ckd_mul (&sresult, INT_MAX, -1));
  ASSERT (sresult == INT_MAX * -1);

  /* a * b == b * a */
  ASSERT (!ckd_mul (&sresult, 0, INT_MIN));
  ASSERT (sresult == 0);
  ASSERT (!ckd_mul (&sresult, 0, INT_MAX));
  ASSERT (sresult == 0);
  ASSERT (!ckd_mul (&sresult, 1, INT_MIN));
  ASSERT (sresult == INT_MIN);
  ASSERT (!ckd_mul (&sresult, 1, INT_MAX));
  ASSERT (sresult == INT_MAX);
  ASSERT (!ckd_mul (&sresult, -1, INT_MIN + 1));
  ASSERT (sresult == (INT_MIN + 1) * -1);
  ASSERT (!ckd_mul (&sresult, -1, INT_MAX));
  ASSERT (sresult == INT_MAX * -1);

  /* Overflow. */
  ASSERT (ckd_mul (&sresult, INT_MIN, 2));
  ASSERT (ckd_mul (&sresult, INT_MAX, 2));
  ASSERT (ckd_mul (&sresult, INT_MIN, 3));
  ASSERT (ckd_mul (&sresult, INT_MAX, 3));
  ASSERT (ckd_mul (&sresult, INT_MIN, -1));
  ASSERT (ckd_mul (&sresult, INT_MAX, -2));

  /* a * b == b * a */
  ASSERT (ckd_mul (&sresult, 2, INT_MIN));
  ASSERT (ckd_mul (&sresult, 2, INT_MAX));
  ASSERT (ckd_mul (&sresult, 3, INT_MIN));
  ASSERT (ckd_mul (&sresult, 3, INT_MAX));
  ASSERT (ckd_mul (&sresult, -1, INT_MIN));
  ASSERT (ckd_mul (&sresult, -2, INT_MAX));

  /* No overflow. */
  ASSERT (!ckd_mul (&uresult, 0U, 0U));
  ASSERT (uresult == 0U);
  ASSERT (!ckd_mul (&uresult, UINT_MAX, 0U));
  ASSERT (uresult == 0U);
  ASSERT (!ckd_mul (&uresult, 0U, 1U));
  ASSERT (uresult == 0U);
  ASSERT (!ckd_mul (&uresult, UINT_MAX, 1U));
  ASSERT (uresult == UINT_MAX);
  ASSERT (!ckd_mul (&uresult, 0U, 2U));
  ASSERT (uresult == 0U);
  ASSERT (!ckd_mul (&uresult, 0U, 3U));
  ASSERT (uresult == 0U);

  /* a * b == b * a */
  ASSERT (!ckd_mul (&uresult, 0U, 0U));
  ASSERT (uresult == 0U);
  ASSERT (!ckd_mul (&uresult, 0U, UINT_MAX));
  ASSERT (uresult == 0U);
  ASSERT (!ckd_mul (&uresult, 1U, 0U));
  ASSERT (uresult == 0U);
  ASSERT (!ckd_mul (&uresult, 1U, UINT_MAX));
  ASSERT (uresult == UINT_MAX);
  ASSERT (!ckd_mul (&uresult, 2U, 0U));
  ASSERT (uresult == 0U);
  ASSERT (!ckd_mul (&uresult, 3U, 0U));
  ASSERT (uresult == 0U);

  /* Overflow. */
  ASSERT (ckd_mul (&uresult, UINT_MAX, 2U));
  ASSERT (ckd_mul (&uresult, UINT_MAX, 3U));
  ASSERT (ckd_mul (&uresult, UINT_MAX, -1));
  ASSERT (ckd_mul (&uresult, UINT_MAX, -2));
  ASSERT (ckd_mul (&uresult, UINT_MAX, -3));

  /* a * b == b * a */
  ASSERT (ckd_mul (&uresult, 2U, UINT_MAX));
  ASSERT (ckd_mul (&uresult, 3U, UINT_MAX));
  ASSERT (ckd_mul (&uresult, -1, UINT_MAX));
  ASSERT (ckd_mul (&uresult, -2, UINT_MAX));
  ASSERT (ckd_mul (&uresult, -3, UINT_MAX));
}
