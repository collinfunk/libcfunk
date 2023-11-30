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

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

static void test_strtoll_invalid_base (void);
static void test_strtoll_base_2 (void);
static void test_strtoll_base_10 (void);
static void test_strtoll_base_16 (void);
static void test_strtoll_base_2_implied (void);
static void test_strtoll_base_10_implied (void);
static void test_strtoll_base_16_implied (void);
static void test_strtoll_bounds (void);

int
main (void)
{
  test_strtoll_invalid_base ();
  test_strtoll_base_2 ();
  test_strtoll_base_10 ();
  test_strtoll_base_16 ();
  test_strtoll_base_2_implied ();
  test_strtoll_base_10_implied ();
  test_strtoll_base_16_implied ();
  test_strtoll_bounds ();
  return 0;
}

static void
test_strtoll_invalid_base (void)
{
  errno = 0;
  ASSERT (strtoll ("1", NULL, -1) == 0);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (strtoll ("1", NULL, 1) == 0);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (strtoll ("1", NULL, 37) == 0);
  ASSERT (errno == EINVAL);
  errno = 0;
}

static void
test_strtoll_base_2 (void)
{
  ASSERT (strtoll ("0", NULL, 2) == 0LL);
  ASSERT (strtoll ("1", NULL, 2) == 1LL);
  ASSERT (strtoll ("10", NULL, 2) == 2LL);
  ASSERT (strtoll ("11", NULL, 2) == 3LL);
  ASSERT (strtoll ("+1", NULL, 2) == 1LL);
  ASSERT (strtoll ("+10", NULL, 2) == 2LL);
  ASSERT (strtoll ("+11", NULL, 2) == 3LL);
  ASSERT (strtoll ("-1", NULL, 2) == -1LL);
  ASSERT (strtoll ("-10", NULL, 2) == -2LL);
  ASSERT (strtoll ("-11", NULL, 2) == -3LL);
}

static void
test_strtoll_base_10 (void)
{
  ASSERT (strtoll ("0", NULL, 10) == 0LL);
  ASSERT (strtoll ("1", NULL, 10) == 1LL);
  ASSERT (strtoll ("10", NULL, 10) == 10LL);
  ASSERT (strtoll ("11", NULL, 10) == 11LL);
  ASSERT (strtoll ("+1", NULL, 10) == 1LL);
  ASSERT (strtoll ("+10", NULL, 10) == 10LL);
  ASSERT (strtoll ("+11", NULL, 10) == 11LL);
  ASSERT (strtoll ("-1", NULL, 10) == -1LL);
  ASSERT (strtoll ("-10", NULL, 10) == -10LL);
  ASSERT (strtoll ("-11", NULL, 10) == -11LL);
}

static void
test_strtoll_base_16 (void)
{
  ASSERT (strtoll ("0", NULL, 16) == 0LL);
  ASSERT (strtoll ("1", NULL, 16) == 1LL);
  ASSERT (strtoll ("10", NULL, 16) == 16LL);
  ASSERT (strtoll ("11", NULL, 16) == 17LL);
  ASSERT (strtoll ("+1", NULL, 16) == 1LL);
  ASSERT (strtoll ("+10", NULL, 16) == 16LL);
  ASSERT (strtoll ("+11", NULL, 16) == 17LL);
  ASSERT (strtoll ("-1", NULL, 16) == -1LL);
  ASSERT (strtoll ("-10", NULL, 16) == -16LL);
  ASSERT (strtoll ("-11", NULL, 16) == -17LL);
}

static void
test_strtoll_base_2_implied (void)
{
  ASSERT (strtoll ("0b0", NULL, 0) == 0LL);
  ASSERT (strtoll ("0b1", NULL, 0) == 1LL);
  ASSERT (strtoll ("0b10", NULL, 0) == 2LL);
  ASSERT (strtoll ("0b11", NULL, 0) == 3LL);
  ASSERT (strtoll ("+0b1", NULL, 0) == 1LL);
  ASSERT (strtoll ("+0b10", NULL, 0) == 2LL);
  ASSERT (strtoll ("+0b11", NULL, 0) == 3LL);
  ASSERT (strtoll ("-0b1", NULL, 0) == -1LL);
  ASSERT (strtoll ("-0b10", NULL, 0) == -2LL);
  ASSERT (strtoll ("-0b11", NULL, 0) == -3LL);
  ASSERT (strtoll ("0B0", NULL, 0) == 0LL);
  ASSERT (strtoll ("0B1", NULL, 0) == 1LL);
  ASSERT (strtoll ("0B10", NULL, 0) == 2LL);
  ASSERT (strtoll ("0B11", NULL, 0) == 3LL);
  ASSERT (strtoll ("+0B1", NULL, 0) == 1LL);
  ASSERT (strtoll ("+0B10", NULL, 0) == 2LL);
  ASSERT (strtoll ("+0B11", NULL, 0) == 3LL);
  ASSERT (strtoll ("-0B1", NULL, 0) == -1LL);
  ASSERT (strtoll ("-0B10", NULL, 0) == -2LL);
  ASSERT (strtoll ("-0B11", NULL, 0) == -3LL);
}

static void
test_strtoll_base_10_implied (void)
{
  ASSERT (strtoll ("1", NULL, 0) == 1LL);
  ASSERT (strtoll ("10", NULL, 0) == 10LL);
  ASSERT (strtoll ("11", NULL, 0) == 11LL);
  ASSERT (strtoll ("+1", NULL, 0) == 1LL);
  ASSERT (strtoll ("+10", NULL, 0) == 10LL);
  ASSERT (strtoll ("+11", NULL, 0) == 11LL);
  ASSERT (strtoll ("-1", NULL, 0) == -1LL);
  ASSERT (strtoll ("-10", NULL, 0) == -10LL);
  ASSERT (strtoll ("-11", NULL, 0) == -11LL);
}

static void
test_strtoll_base_16_implied (void)
{
  ASSERT (strtoll ("0x0", NULL, 0) == 0LL);
  ASSERT (strtoll ("0x1", NULL, 0) == 1LL);
  ASSERT (strtoll ("0x10", NULL, 0) == 16LL);
  ASSERT (strtoll ("0x11", NULL, 0) == 17LL);
  ASSERT (strtoll ("+0x1", NULL, 0) == 1LL);
  ASSERT (strtoll ("+0x10", NULL, 0) == 16LL);
  ASSERT (strtoll ("+0x11", NULL, 0) == 17LL);
  ASSERT (strtoll ("-0x1", NULL, 0) == -1LL);
  ASSERT (strtoll ("-0x10", NULL, 0) == -16LL);
  ASSERT (strtoll ("-0x11", NULL, 0) == -17LL);
  ASSERT (strtoll ("0X0", NULL, 0) == 0LL);
  ASSERT (strtoll ("0X1", NULL, 0) == 1LL);
  ASSERT (strtoll ("0X10", NULL, 0) == 16LL);
  ASSERT (strtoll ("0X11", NULL, 0) == 17LL);
  ASSERT (strtoll ("+0X1", NULL, 0) == 1LL);
  ASSERT (strtoll ("+0X10", NULL, 0) == 16LL);
  ASSERT (strtoll ("+0X11", NULL, 0) == 17LL);
  ASSERT (strtoll ("-0X1", NULL, 0) == -1LL);
  ASSERT (strtoll ("-0X10", NULL, 0) == -16LL);
  ASSERT (strtoll ("-0X11", NULL, 0) == -17LL);
}

static void
test_strtoll_bounds (void)
{
#if LLONG_MAX == 127LL
  errno = 0;
  ASSERT (strtoll ("127", NULL, 0) == LLONG_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoll ("-128", NULL, 0) == LLONG_MIN);
  ASSERT (errno == 0);
  ASSERT (strtoll ("128", NULL, 0) == LLONG_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
  ASSERT (strtoll ("-129", NULL, 0) == LLONG_MIN);
  ASSERT (errno == ERANGE);
  errno = 0;
#elif LLONG_MAX == 32767LL
  errno = 0;
  ASSERT (strtoll ("32767", NULL, 0) == LLONG_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoll ("-32768", NULL, 0) == LLONG_MIN);
  ASSERT (errno == 0);
  ASSERT (strtoll ("32768", NULL, 0) == LLONG_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
  ASSERT (strtoll ("-32769", NULL, 0) == LLONG_MIN);
  ASSERT (errno == ERANGE);
  errno = 0;
#elif LLONG_MAX == 2147483647LL
  errno = 0;
  ASSERT (strtoll ("2147483647", NULL, 0) == LLONG_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoll ("-2147483648", NULL, 0) == LLONG_MIN);
  ASSERT (errno == 0);
  ASSERT (strtoll ("2147483648", NULL, 0) == LLONG_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
  ASSERT (strtoll ("-2147483649", NULL, 0) == LLONG_MIN);
  ASSERT (errno == ERANGE);
  errno = 0;
#elif LLONG_MAX == 9223372036854775807LL
  errno = 0;
  ASSERT (strtoll ("9223372036854775807", NULL, 0) == LLONG_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoll ("-9223372036854775808", NULL, 0) == LLONG_MIN);
  ASSERT (errno == 0);
  ASSERT (strtoll ("9223372036854775808", NULL, 0) == LLONG_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
  ASSERT (strtoll ("-9223372036854775809", NULL, 0) == LLONG_MIN);
  ASSERT (errno == ERANGE);
  errno = 0;
#endif
}
