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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "test-help.h"

/* Exit code for this program. */
static int exit_code = 0;

static void test_time_year2038 (void);
static void test_time (void);

int
main (void)
{
  test_time_year2038 ();
  test_time ();
  return exit_code;
}

/* Give a warning if 'time_t' is not 64-bits. Assume that it is a traditional
   implementation using a 32-bit integer and give a warning. */
static void
test_time_year2038 (void)
{
  if (sizeof (time_t) < 8)
    {
      fprintf (stderr,
               "The size of 'time_t' is less than 64-bits on your system. The "
               "'time' function will fail in the year 2038.\n");
      exit_code = 1;
    }
}

/* Perform a basic test of 'time'. */
static void
test_time (void)
{
  time_t t1 = (time_t) -1;
  time_t t2 = (time_t) -1;

  t1 = time (&t2);
  ASSERT (t1 != (time_t) -1);
  ASSERT (t1 == t2);
}
