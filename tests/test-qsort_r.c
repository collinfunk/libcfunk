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

#include <sys/random.h>

#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

static int compare_ints (const void *a_ptr, const void *b_ptr, void *arg);
static void test_qsort_r (void);

int
main (void)
{
  test_qsort_r ();
  return 0;
}

static int
compare_ints (const void *a_ptr, const void *b_ptr, void *arg)
{
  const int a = *(const int *) a_ptr;
  const int b = *(const int *) b_ptr;
  const int order = *(const int *) arg;

  if (a == b)
    return 0;
  else if (a < b)
    return order < 0 ? 1 : -1;
  else /* a > b */
    return order < 0 ? -1 : 1;
}

static void
test_qsort_r (void)
{
  int values[255];
  size_t i;
  int arg;

  ASSERT (ARRAY_SIZE (values) > 1);
  ASSERT (getrandom (values, sizeof (values), 0) == (ssize_t) sizeof (values));

  /* Ascending. */
  arg = 1;
  qsort_r (values, ARRAY_SIZE (values), sizeof (int), compare_ints, &arg);

  for (i = 0; i < ARRAY_SIZE (values) - 1; ++i)
    ASSERT (values[i] <= values[i + 1]);

  /* Descending. */
  arg = -1;
  qsort_r (values, ARRAY_SIZE (values), sizeof (int), compare_ints, &arg);

  for (i = 0; i < ARRAY_SIZE (values) - 1; ++i)
    ASSERT (values[i] >= values[i + 1]);
}
