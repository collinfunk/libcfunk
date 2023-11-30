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
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

static void test_strtoimax_invalid_base (void);
static void test_strtoimax_base_2 (void);
static void test_strtoimax_base_10 (void);
static void test_strtoimax_base_16 (void);
static void test_strtoimax_base_2_implied (void);
static void test_strtoimax_base_10_implied (void);
static void test_strtoimax_base_16_implied (void);
static void test_strtoimax_bounds (void);

int
main (void)
{
  test_strtoimax_invalid_base ();
  test_strtoimax_base_2 ();
  test_strtoimax_base_10 ();
  test_strtoimax_base_16 ();
  test_strtoimax_base_2_implied ();
  test_strtoimax_base_10_implied ();
  test_strtoimax_base_16_implied ();
  test_strtoimax_bounds ();
  return 0;
}

static void
test_strtoimax_invalid_base (void)
{
  errno = 0;
  ASSERT (strtoimax ("1", NULL, -1) == 0);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (strtoimax ("1", NULL, 1) == 0);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (strtoimax ("1", NULL, 37) == 0);
  ASSERT (errno == EINVAL);
  errno = 0;
}

static void
test_strtoimax_base_2 (void)
{
  ASSERT (strtoimax ("0", NULL, 2) == INTMAX_C (0));
  ASSERT (strtoimax ("1", NULL, 2) == INTMAX_C (1));
  ASSERT (strtoimax ("10", NULL, 2) == INTMAX_C (2));
  ASSERT (strtoimax ("11", NULL, 2) == INTMAX_C (3));
  ASSERT (strtoimax ("+1", NULL, 2) == INTMAX_C (1));
  ASSERT (strtoimax ("+10", NULL, 2) == INTMAX_C (2));
  ASSERT (strtoimax ("+11", NULL, 2) == INTMAX_C (3));
  ASSERT (strtoimax ("-1", NULL, 2) == INTMAX_C (-1));
  ASSERT (strtoimax ("-10", NULL, 2) == INTMAX_C (-2));
  ASSERT (strtoimax ("-11", NULL, 2) == INTMAX_C (-3));
}

static void
test_strtoimax_base_10 (void)
{
  ASSERT (strtoimax ("0", NULL, 10) == INTMAX_C (0));
  ASSERT (strtoimax ("1", NULL, 10) == INTMAX_C (1));
  ASSERT (strtoimax ("10", NULL, 10) == INTMAX_C (10));
  ASSERT (strtoimax ("11", NULL, 10) == INTMAX_C (11));
  ASSERT (strtoimax ("+1", NULL, 10) == INTMAX_C (1));
  ASSERT (strtoimax ("+10", NULL, 10) == INTMAX_C (10));
  ASSERT (strtoimax ("+11", NULL, 10) == INTMAX_C (11));
  ASSERT (strtoimax ("-1", NULL, 10) == INTMAX_C (-1));
  ASSERT (strtoimax ("-10", NULL, 10) == INTMAX_C (-10));
  ASSERT (strtoimax ("-11", NULL, 10) == INTMAX_C (-11));
}

static void
test_strtoimax_base_16 (void)
{
  ASSERT (strtoimax ("0", NULL, 16) == INTMAX_C (0));
  ASSERT (strtoimax ("1", NULL, 16) == INTMAX_C (1));
  ASSERT (strtoimax ("10", NULL, 16) == INTMAX_C (16));
  ASSERT (strtoimax ("11", NULL, 16) == INTMAX_C (17));
  ASSERT (strtoimax ("+1", NULL, 16) == INTMAX_C (1));
  ASSERT (strtoimax ("+10", NULL, 16) == INTMAX_C (16));
  ASSERT (strtoimax ("+11", NULL, 16) == INTMAX_C (17));
  ASSERT (strtoimax ("-1", NULL, 16) == INTMAX_C (-1));
  ASSERT (strtoimax ("-10", NULL, 16) == INTMAX_C (-16));
  ASSERT (strtoimax ("-11", NULL, 16) == INTMAX_C (-17));
}

static void
test_strtoimax_base_2_implied (void)
{
  ASSERT (strtoimax ("0b0", NULL, 0) == INTMAX_C (0));
  ASSERT (strtoimax ("0b1", NULL, 0) == INTMAX_C (1));
  ASSERT (strtoimax ("0b10", NULL, 0) == INTMAX_C (2));
  ASSERT (strtoimax ("0b11", NULL, 0) == INTMAX_C (3));
  ASSERT (strtoimax ("+0b1", NULL, 0) == INTMAX_C (1));
  ASSERT (strtoimax ("+0b10", NULL, 0) == INTMAX_C (2));
  ASSERT (strtoimax ("+0b11", NULL, 0) == INTMAX_C (3));
  ASSERT (strtoimax ("-0b1", NULL, 0) == INTMAX_C (-1));
  ASSERT (strtoimax ("-0b10", NULL, 0) == INTMAX_C (-2));
  ASSERT (strtoimax ("-0b11", NULL, 0) == INTMAX_C (-3));
  ASSERT (strtoimax ("0B0", NULL, 0) == INTMAX_C (0));
  ASSERT (strtoimax ("0B1", NULL, 0) == INTMAX_C (1));
  ASSERT (strtoimax ("0B10", NULL, 0) == INTMAX_C (2));
  ASSERT (strtoimax ("0B11", NULL, 0) == INTMAX_C (3));
  ASSERT (strtoimax ("+0B1", NULL, 0) == INTMAX_C (1));
  ASSERT (strtoimax ("+0B10", NULL, 0) == INTMAX_C (2));
  ASSERT (strtoimax ("+0B11", NULL, 0) == INTMAX_C (3));
  ASSERT (strtoimax ("-0B1", NULL, 0) == INTMAX_C (-1));
  ASSERT (strtoimax ("-0B10", NULL, 0) == INTMAX_C (-2));
  ASSERT (strtoimax ("-0B11", NULL, 0) == INTMAX_C (-3));
}

static void
test_strtoimax_base_10_implied (void)
{
  ASSERT (strtoimax ("1", NULL, 0) == INTMAX_C (1));
  ASSERT (strtoimax ("10", NULL, 0) == INTMAX_C (10));
  ASSERT (strtoimax ("11", NULL, 0) == INTMAX_C (11));
  ASSERT (strtoimax ("+1", NULL, 0) == INTMAX_C (1));
  ASSERT (strtoimax ("+10", NULL, 0) == INTMAX_C (10));
  ASSERT (strtoimax ("+11", NULL, 0) == INTMAX_C (11));
  ASSERT (strtoimax ("-1", NULL, 0) == INTMAX_C (-1));
  ASSERT (strtoimax ("-10", NULL, 0) == INTMAX_C (-10));
  ASSERT (strtoimax ("-11", NULL, 0) == INTMAX_C (-11));
}

static void
test_strtoimax_base_16_implied (void)
{
  ASSERT (strtoimax ("0x0", NULL, 0) == INTMAX_C (0));
  ASSERT (strtoimax ("0x1", NULL, 0) == INTMAX_C (1));
  ASSERT (strtoimax ("0x10", NULL, 0) == INTMAX_C (16));
  ASSERT (strtoimax ("0x11", NULL, 0) == INTMAX_C (17));
  ASSERT (strtoimax ("+0x1", NULL, 0) == INTMAX_C (1));
  ASSERT (strtoimax ("+0x10", NULL, 0) == INTMAX_C (16));
  ASSERT (strtoimax ("+0x11", NULL, 0) == INTMAX_C (17));
  ASSERT (strtoimax ("-0x1", NULL, 0) == INTMAX_C (-1));
  ASSERT (strtoimax ("-0x10", NULL, 0) == INTMAX_C (-16));
  ASSERT (strtoimax ("-0x11", NULL, 0) == INTMAX_C (-17));
  ASSERT (strtoimax ("0X0", NULL, 0) == INTMAX_C (0));
  ASSERT (strtoimax ("0X1", NULL, 0) == INTMAX_C (1));
  ASSERT (strtoimax ("0X10", NULL, 0) == INTMAX_C (16));
  ASSERT (strtoimax ("0X11", NULL, 0) == INTMAX_C (17));
  ASSERT (strtoimax ("+0X1", NULL, 0) == INTMAX_C (1));
  ASSERT (strtoimax ("+0X10", NULL, 0) == INTMAX_C (16));
  ASSERT (strtoimax ("+0X11", NULL, 0) == INTMAX_C (17));
  ASSERT (strtoimax ("-0X1", NULL, 0) == INTMAX_C (-1));
  ASSERT (strtoimax ("-0X10", NULL, 0) == INTMAX_C (-16));
  ASSERT (strtoimax ("-0X11", NULL, 0) == INTMAX_C (-17));
}

static void
test_strtoimax_bounds (void)
{
#if INTMAX_MAX == INTMAX_C(127)
  errno = 0;
  ASSERT (strtoimax ("127", NULL, 0) == INTMAX_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoimax ("-128", NULL, 0) == INTMAX_MIN);
  ASSERT (errno == 0);
  ASSERT (strtoimax ("128", NULL, 0) == INTMAX_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
  ASSERT (strtoimax ("-129", NULL, 0) == INTMAX_MIN);
  ASSERT (errno == ERANGE);
  errno = 0;
#elif INTMAX_MAX == INTMAX_C(32767)
  errno = 0;
  ASSERT (strtoimax ("32767", NULL, 0) == INTMAX_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoimax ("-32768", NULL, 0) == INTMAX_MIN);
  ASSERT (errno == 0);
  ASSERT (strtoimax ("32768", NULL, 0) == INTMAX_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
  ASSERT (strtoimax ("-32769", NULL, 0) == INTMAX_MIN);
  ASSERT (errno == ERANGE);
  errno = 0;
#elif INTMAX_MAX == INTMAX_C(2147483647)
  errno = 0;
  ASSERT (strtoimax ("2147483647", NULL, 0) == INTMAX_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoimax ("-2147483648", NULL, 0) == INTMAX_MIN);
  ASSERT (errno == 0);
  ASSERT (strtoimax ("2147483648", NULL, 0) == INTMAX_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
  ASSERT (strtoimax ("-2147483649", NULL, 0) == INTMAX_MIN);
  ASSERT (errno == ERANGE);
  errno = 0;
#elif INTMAX_MAX == INTMAX_C(9223372036854775807)
  errno = 0;
  ASSERT (strtoimax ("9223372036854775807", NULL, 0) == INTMAX_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoimax ("-9223372036854775808", NULL, 0) == INTMAX_MIN);
  ASSERT (errno == 0);
  ASSERT (strtoimax ("9223372036854775808", NULL, 0) == INTMAX_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
  ASSERT (strtoimax ("-9223372036854775809", NULL, 0) == INTMAX_MIN);
  ASSERT (errno == ERANGE);
  errno = 0;
#endif
}
