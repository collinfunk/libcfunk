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

static void test_strtoumax_invalid_base (void);
static void test_strtoumax_base_2 (void);
static void test_strtoumax_base_10 (void);
static void test_strtoumax_base_16 (void);
static void test_strtoumax_base_2_implied (void);
static void test_strtoumax_base_10_implied (void);
static void test_strtoumax_base_16_implied (void);
static void test_strtoumax_bounds (void);

int
main (void)
{
  test_strtoumax_invalid_base ();
  test_strtoumax_base_2 ();
  test_strtoumax_base_10 ();
  test_strtoumax_base_16 ();
  test_strtoumax_base_2_implied ();
  test_strtoumax_base_10_implied ();
  test_strtoumax_base_16_implied ();
  test_strtoumax_bounds ();
  return 0;
}

static void
test_strtoumax_invalid_base (void)
{
  errno = 0;
  ASSERT (strtoumax ("1", NULL, -1) == 0);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (strtoumax ("1", NULL, 1) == 0);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (strtoumax ("1", NULL, 37) == 0);
  ASSERT (errno == EINVAL);
  errno = 0;
}

static void
test_strtoumax_base_2 (void)
{
  ASSERT (strtoumax ("0", NULL, 2) == UINTMAX_C (0));
  ASSERT (strtoumax ("1", NULL, 2) == UINTMAX_C (1));
  ASSERT (strtoumax ("10", NULL, 2) == UINTMAX_C (2));
  ASSERT (strtoumax ("11", NULL, 2) == UINTMAX_C (3));
  ASSERT (strtoumax ("+1", NULL, 2) == UINTMAX_C (1));
  ASSERT (strtoumax ("+10", NULL, 2) == UINTMAX_C (2));
  ASSERT (strtoumax ("+11", NULL, 2) == UINTMAX_C (3));
}

static void
test_strtoumax_base_10 (void)
{
  ASSERT (strtoumax ("0", NULL, 10) == UINTMAX_C (0));
  ASSERT (strtoumax ("1", NULL, 10) == UINTMAX_C (1));
  ASSERT (strtoumax ("10", NULL, 10) == UINTMAX_C (10));
  ASSERT (strtoumax ("11", NULL, 10) == UINTMAX_C (11));
  ASSERT (strtoumax ("+1", NULL, 10) == UINTMAX_C (1));
  ASSERT (strtoumax ("+10", NULL, 10) == UINTMAX_C (10));
  ASSERT (strtoumax ("+11", NULL, 10) == UINTMAX_C (11));
}

static void
test_strtoumax_base_16 (void)
{
  ASSERT (strtoumax ("0", NULL, 16) == UINTMAX_C (0));
  ASSERT (strtoumax ("1", NULL, 16) == UINTMAX_C (1));
  ASSERT (strtoumax ("10", NULL, 16) == UINTMAX_C (16));
  ASSERT (strtoumax ("11", NULL, 16) == UINTMAX_C (17));
  ASSERT (strtoumax ("+1", NULL, 16) == UINTMAX_C (1));
  ASSERT (strtoumax ("+10", NULL, 16) == UINTMAX_C (16));
  ASSERT (strtoumax ("+11", NULL, 16) == UINTMAX_C (17));
}

static void
test_strtoumax_base_2_implied (void)
{
  ASSERT (strtoumax ("0b0", NULL, 0) == UINTMAX_C (0));
  ASSERT (strtoumax ("0b1", NULL, 0) == UINTMAX_C (1));
  ASSERT (strtoumax ("0b10", NULL, 0) == UINTMAX_C (2));
  ASSERT (strtoumax ("0b11", NULL, 0) == UINTMAX_C (3));
  ASSERT (strtoumax ("+0b1", NULL, 0) == UINTMAX_C (1));
  ASSERT (strtoumax ("+0b10", NULL, 0) == UINTMAX_C (2));
  ASSERT (strtoumax ("+0b11", NULL, 0) == UINTMAX_C (3));
  ASSERT (strtoumax ("0B0", NULL, 0) == UINTMAX_C (0));
  ASSERT (strtoumax ("0B1", NULL, 0) == UINTMAX_C (1));
  ASSERT (strtoumax ("0B10", NULL, 0) == UINTMAX_C (2));
  ASSERT (strtoumax ("0B11", NULL, 0) == UINTMAX_C (3));
  ASSERT (strtoumax ("+0B1", NULL, 0) == UINTMAX_C (1));
  ASSERT (strtoumax ("+0B10", NULL, 0) == UINTMAX_C (2));
  ASSERT (strtoumax ("+0B11", NULL, 0) == UINTMAX_C (3));
}

static void
test_strtoumax_base_10_implied (void)
{
  ASSERT (strtoumax ("1", NULL, 0) == UINTMAX_C (1));
  ASSERT (strtoumax ("10", NULL, 0) == UINTMAX_C (10));
  ASSERT (strtoumax ("11", NULL, 0) == UINTMAX_C (11));
  ASSERT (strtoumax ("+1", NULL, 0) == UINTMAX_C (1));
  ASSERT (strtoumax ("+10", NULL, 0) == UINTMAX_C (10));
  ASSERT (strtoumax ("+11", NULL, 0) == UINTMAX_C (11));
}

static void
test_strtoumax_base_16_implied (void)
{
  ASSERT (strtoumax ("0x0", NULL, 0) == UINTMAX_C (0));
  ASSERT (strtoumax ("0x1", NULL, 0) == UINTMAX_C (1));
  ASSERT (strtoumax ("0x10", NULL, 0) == UINTMAX_C (16));
  ASSERT (strtoumax ("0x11", NULL, 0) == UINTMAX_C (17));
  ASSERT (strtoumax ("+0x1", NULL, 0) == UINTMAX_C (1));
  ASSERT (strtoumax ("+0x10", NULL, 0) == UINTMAX_C (16));
  ASSERT (strtoumax ("+0x11", NULL, 0) == UINTMAX_C (17));
  ASSERT (strtoumax ("0X0", NULL, 0) == UINTMAX_C (0));
  ASSERT (strtoumax ("0X1", NULL, 0) == UINTMAX_C (1));
  ASSERT (strtoumax ("0X10", NULL, 0) == UINTMAX_C (16));
  ASSERT (strtoumax ("0X11", NULL, 0) == UINTMAX_C (17));
  ASSERT (strtoumax ("+0X1", NULL, 0) == UINTMAX_C (1));
  ASSERT (strtoumax ("+0X10", NULL, 0) == UINTMAX_C (16));
  ASSERT (strtoumax ("+0X11", NULL, 0) == UINTMAX_C (17));
}

static void
test_strtoumax_bounds (void)
{
#if UINTMAX_MAX == UINTMAX_C(255)
  errno = 0;
  ASSERT (strtoumax ("255", NULL, 0) == UINTMAX_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoumax ("256", NULL, 0) == UINTMAX_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
#elif UINTMAX_MAX == UINTMAX_C(65535)
  errno = 0;
  ASSERT (strtoumax ("65535", NULL, 0) == UINTMAX_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoumax ("65536", NULL, 0) == UINTMAX_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
#elif UINTMAX_MAX == UINTMAX_C(4294967295)
  errno = 0;
  ASSERT (strtoumax ("4294967295", NULL, 0) == UINTMAX_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoumax ("4294967296", NULL, 0) == UINTMAX_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
#elif UINTMAX_MAX == UINTMAX_C(18446744073709551615)
  errno = 0;
  ASSERT (strtoumax ("18446744073709551615", NULL, 0) == UINTMAX_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoumax ("18446744073709551616", NULL, 0) == UINTMAX_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
#endif
}
