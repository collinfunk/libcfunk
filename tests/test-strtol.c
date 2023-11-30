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

static void test_strtol_invalid_base (void);
static void test_strtol_base_2 (void);
static void test_strtol_base_10 (void);
static void test_strtol_base_16 (void);
static void test_strtol_base_2_implied (void);
static void test_strtol_base_10_implied (void);
static void test_strtol_base_16_implied (void);
static void test_strtol_bounds (void);

int
main (void)
{
  test_strtol_invalid_base ();
  test_strtol_base_2 ();
  test_strtol_base_10 ();
  test_strtol_base_16 ();
  test_strtol_base_2_implied ();
  test_strtol_base_10_implied ();
  test_strtol_base_16_implied ();
  test_strtol_bounds ();
  return 0;
}

static void
test_strtol_invalid_base (void)
{
  errno = 0;
  ASSERT (strtol ("1", NULL, -1) == 0);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (strtol ("1", NULL, 1) == 0);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (strtol ("1", NULL, 37) == 0);
  ASSERT (errno == EINVAL);
  errno = 0;
}

static void
test_strtol_base_2 (void)
{
  ASSERT (strtol ("0", NULL, 2) == 0L);
  ASSERT (strtol ("1", NULL, 2) == 1L);
  ASSERT (strtol ("10", NULL, 2) == 2L);
  ASSERT (strtol ("11", NULL, 2) == 3L);
  ASSERT (strtol ("+1", NULL, 2) == 1L);
  ASSERT (strtol ("+10", NULL, 2) == 2L);
  ASSERT (strtol ("+11", NULL, 2) == 3L);
  ASSERT (strtol ("-1", NULL, 2) == -1L);
  ASSERT (strtol ("-10", NULL, 2) == -2L);
  ASSERT (strtol ("-11", NULL, 2) == -3L);
}

static void
test_strtol_base_10 (void)
{
  ASSERT (strtol ("0", NULL, 10) == 0L);
  ASSERT (strtol ("1", NULL, 10) == 1L);
  ASSERT (strtol ("10", NULL, 10) == 10L);
  ASSERT (strtol ("11", NULL, 10) == 11L);
  ASSERT (strtol ("+1", NULL, 10) == 1L);
  ASSERT (strtol ("+10", NULL, 10) == 10L);
  ASSERT (strtol ("+11", NULL, 10) == 11L);
  ASSERT (strtol ("-1", NULL, 10) == -1L);
  ASSERT (strtol ("-10", NULL, 10) == -10L);
  ASSERT (strtol ("-11", NULL, 10) == -11L);
}

static void
test_strtol_base_16 (void)
{
  ASSERT (strtol ("0", NULL, 16) == 0L);
  ASSERT (strtol ("1", NULL, 16) == 1L);
  ASSERT (strtol ("10", NULL, 16) == 16L);
  ASSERT (strtol ("11", NULL, 16) == 17L);
  ASSERT (strtol ("+1", NULL, 16) == 1L);
  ASSERT (strtol ("+10", NULL, 16) == 16L);
  ASSERT (strtol ("+11", NULL, 16) == 17L);
  ASSERT (strtol ("-1", NULL, 16) == -1L);
  ASSERT (strtol ("-10", NULL, 16) == -16L);
  ASSERT (strtol ("-11", NULL, 16) == -17L);
}

static void
test_strtol_base_2_implied (void)
{
  ASSERT (strtol ("0b0", NULL, 0) == 0L);
  ASSERT (strtol ("0b1", NULL, 0) == 1L);
  ASSERT (strtol ("0b10", NULL, 0) == 2L);
  ASSERT (strtol ("0b11", NULL, 0) == 3L);
  ASSERT (strtol ("+0b1", NULL, 0) == 1L);
  ASSERT (strtol ("+0b10", NULL, 0) == 2L);
  ASSERT (strtol ("+0b11", NULL, 0) == 3L);
  ASSERT (strtol ("-0b1", NULL, 0) == -1L);
  ASSERT (strtol ("-0b10", NULL, 0) == -2L);
  ASSERT (strtol ("-0b11", NULL, 0) == -3L);
  ASSERT (strtol ("0B0", NULL, 0) == 0L);
  ASSERT (strtol ("0B1", NULL, 0) == 1L);
  ASSERT (strtol ("0B10", NULL, 0) == 2L);
  ASSERT (strtol ("0B11", NULL, 0) == 3L);
  ASSERT (strtol ("+0B1", NULL, 0) == 1L);
  ASSERT (strtol ("+0B10", NULL, 0) == 2L);
  ASSERT (strtol ("+0B11", NULL, 0) == 3L);
  ASSERT (strtol ("-0B1", NULL, 0) == -1L);
  ASSERT (strtol ("-0B10", NULL, 0) == -2L);
  ASSERT (strtol ("-0B11", NULL, 0) == -3L);
}

static void
test_strtol_base_10_implied (void)
{
  ASSERT (strtol ("1", NULL, 0) == 1L);
  ASSERT (strtol ("10", NULL, 0) == 10L);
  ASSERT (strtol ("11", NULL, 0) == 11L);
  ASSERT (strtol ("+1", NULL, 0) == 1L);
  ASSERT (strtol ("+10", NULL, 0) == 10L);
  ASSERT (strtol ("+11", NULL, 0) == 11L);
  ASSERT (strtol ("-1", NULL, 0) == -1L);
  ASSERT (strtol ("-10", NULL, 0) == -10L);
  ASSERT (strtol ("-11", NULL, 0) == -11L);
}

static void
test_strtol_base_16_implied (void)
{
  ASSERT (strtol ("0x0", NULL, 0) == 0L);
  ASSERT (strtol ("0x1", NULL, 0) == 1L);
  ASSERT (strtol ("0x10", NULL, 0) == 16L);
  ASSERT (strtol ("0x11", NULL, 0) == 17L);
  ASSERT (strtol ("+0x1", NULL, 0) == 1L);
  ASSERT (strtol ("+0x10", NULL, 0) == 16L);
  ASSERT (strtol ("+0x11", NULL, 0) == 17L);
  ASSERT (strtol ("-0x1", NULL, 0) == -1L);
  ASSERT (strtol ("-0x10", NULL, 0) == -16L);
  ASSERT (strtol ("-0x11", NULL, 0) == -17L);
  ASSERT (strtol ("0X0", NULL, 0) == 0L);
  ASSERT (strtol ("0X1", NULL, 0) == 1L);
  ASSERT (strtol ("0X10", NULL, 0) == 16L);
  ASSERT (strtol ("0X11", NULL, 0) == 17L);
  ASSERT (strtol ("+0X1", NULL, 0) == 1L);
  ASSERT (strtol ("+0X10", NULL, 0) == 16L);
  ASSERT (strtol ("+0X11", NULL, 0) == 17L);
  ASSERT (strtol ("-0X1", NULL, 0) == -1L);
  ASSERT (strtol ("-0X10", NULL, 0) == -16L);
  ASSERT (strtol ("-0X11", NULL, 0) == -17L);
}

static void
test_strtol_bounds (void)
{
#if LONG_MAX == 127L
  errno = 0;
  ASSERT (strtol ("127", NULL, 0) == LONG_MAX);
  ASSERT (errno == 0);
  ASSERT (strtol ("-128", NULL, 0) == LONG_MIN);
  ASSERT (errno == 0);
  ASSERT (strtol ("128", NULL, 0) == LONG_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
  ASSERT (strtol ("-129", NULL, 0) == LONG_MIN);
  ASSERT (errno == ERANGE);
  errno = 0;
#elif LONG_MAX == 32767L
  errno = 0;
  ASSERT (strtol ("32767", NULL, 0) == LONG_MAX);
  ASSERT (errno == 0);
  ASSERT (strtol ("-32768", NULL, 0) == LONG_MIN);
  ASSERT (errno == 0);
  ASSERT (strtol ("32768", NULL, 0) == LONG_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
  ASSERT (strtol ("-32769", NULL, 0) == LONG_MIN);
  ASSERT (errno == ERANGE);
  errno = 0;
#elif LONG_MAX == 2147483647L
  errno = 0;
  ASSERT (strtol ("2147483647", NULL, 0) == LONG_MAX);
  ASSERT (errno == 0);
  ASSERT (strtol ("-2147483648", NULL, 0) == LONG_MIN);
  ASSERT (errno == 0);
  ASSERT (strtol ("2147483648", NULL, 0) == LONG_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
  ASSERT (strtol ("-2147483649", NULL, 0) == LONG_MIN);
  ASSERT (errno == ERANGE);
  errno = 0;
#elif LONG_MAX == 9223372036854775807L
  errno = 0;
  ASSERT (strtol ("9223372036854775807", NULL, 0) == LONG_MAX);
  ASSERT (errno == 0);
  ASSERT (strtol ("-9223372036854775808", NULL, 0) == LONG_MIN);
  ASSERT (errno == 0);
  ASSERT (strtol ("9223372036854775808", NULL, 0) == LONG_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
  ASSERT (strtol ("-9223372036854775809", NULL, 0) == LONG_MIN);
  ASSERT (errno == ERANGE);
  errno = 0;
#endif
}
