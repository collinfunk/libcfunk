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

static void test_timespec_get_zero (void);
static void test_timespec_get (void);

int
main (void)
{
  test_timespec_get_zero ();
  test_timespec_get ();
  return 0;
}

/* The 'timspec_get' function must support 'TIME_UTC' which is a positive
   integer. An implementation may accept any number of additional bases
   beginning with the prefix 'TIME_'. Although nearly all implementations only
   define 'TIME_UTC' to 1, there is no portable way to know a invalid positive
   value. Therefore we just perform and invalid input test with zero. */
static void
test_timespec_get_zero (void)
{
  struct timespec ts;

  ts.tv_sec = (time_t) 0;
  ts.tv_nsec = 0;
  ASSERT (timespec_get (&ts, 0) == 0);
  ASSERT (ts.tv_sec == (time_t) 0);
  ASSERT (ts.tv_nsec == 0);
}

/* Test that two subsequent calls to 'timespec_get' act as expected. */
static void
test_timespec_get (void)
{
  struct timespec ts1;
  struct timespec ts2;
  time_t t1;
  time_t t2;

  /* Store the current time in TS1 and T1. */
  ASSERT (timespec_get (&ts1, TIME_UTC) == TIME_UTC);
  t1 = time (NULL);
  ASSERT (t1 != (time_t) -1);

  /* Store the current time in TS2 and T2. */
  ASSERT (timespec_get (&ts2, TIME_UTC) == TIME_UTC);
  t2 = time (NULL);
  ASSERT (t2 != (time_t) -1);

  /* TS1 must represent a time equal to or before TS2. */
  if (!(ts1.tv_sec < ts2.tv_sec))
    ASSERT (ts1.tv_sec == ts2.tv_sec && ts1.tv_nsec <= ts2.tv_nsec);

  /* T1 must represent a time equal to or before T2. */
  ASSERT (t1 <= t2);
}
