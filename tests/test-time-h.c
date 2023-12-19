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

#include <time.h>

#include "attributes.h"

static void test_clock_t_defined (void);
static void test_size_t_defined (void);
static void test_time_t_defined (void);
static void test_pid_t_defined (void);
static void test_struct_tm_defined (void);
static void test_struct_timespec_defined (void);
static void test_struct_itimerspec_defined (void);
static void test_NULL_defined (void);

static_assert (TIME_UTC > 0);

/* Test that 'time.h' can be included. */
int
main (void)
{
  test_clock_t_defined ();
  test_size_t_defined ();
  test_time_t_defined ();
  test_pid_t_defined ();
  test_struct_tm_defined ();
  test_struct_timespec_defined ();
  test_struct_itimerspec_defined ();
  test_NULL_defined ();
  return 0;
}

static void
test_clock_t_defined (void)
{
  clock_t value ATTRIBUTE_UNUSED;
}

static void
test_size_t_defined (void)
{
  size_t value ATTRIBUTE_UNUSED;
}

static void
test_time_t_defined (void)
{
  time_t value ATTRIBUTE_UNUSED;
}

static void
test_pid_t_defined (void)
{
  pid_t value ATTRIBUTE_UNUSED;
}

static void
test_struct_tm_defined (void)
{
  struct tm value ATTRIBUTE_UNUSED;
}

static void
test_struct_timespec_defined (void)
{
  struct timespec value ATTRIBUTE_UNUSED;
}

static void
test_struct_itimerspec_defined (void)
{
  struct itimerspec value ATTRIBUTE_UNUSED;
}

static void
test_NULL_defined (void)
{
  char *ptr ATTRIBUTE_UNUSED;

  ptr = NULL;
}
