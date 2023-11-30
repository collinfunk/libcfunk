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

static void test_strtoull_invalid_base (void);
static void test_strtoull_base_2 (void);
static void test_strtoull_base_10 (void);
static void test_strtoull_base_16 (void);
static void test_strtoull_base_2_implied (void);
static void test_strtoull_base_10_implied (void);
static void test_strtoull_base_16_implied (void);
static void test_strtoull_bounds (void);

int
main (void)
{
  test_strtoull_invalid_base ();
  test_strtoull_base_2 ();
  test_strtoull_base_10 ();
  test_strtoull_base_16 ();
  test_strtoull_base_2_implied ();
  test_strtoull_base_10_implied ();
  test_strtoull_base_16_implied ();
  test_strtoull_bounds ();
  return 0;
}

static void
test_strtoull_invalid_base (void)
{
  errno = 0;
  ASSERT (strtoull ("1", NULL, -1) == 0);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (strtoull ("1", NULL, 1) == 0);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (strtoull ("1", NULL, 37) == 0);
  ASSERT (errno == EINVAL);
  errno = 0;
}

static void
test_strtoull_base_2 (void)
{
  ASSERT (strtoull ("0", NULL, 2) == 0ULL);
  ASSERT (strtoull ("1", NULL, 2) == 1ULL);
  ASSERT (strtoull ("10", NULL, 2) == 2ULL);
  ASSERT (strtoull ("11", NULL, 2) == 3ULL);
  ASSERT (strtoull ("+1", NULL, 2) == 1ULL);
  ASSERT (strtoull ("+10", NULL, 2) == 2ULL);
  ASSERT (strtoull ("+11", NULL, 2) == 3ULL);
}

static void
test_strtoull_base_10 (void)
{
  ASSERT (strtoull ("0", NULL, 10) == 0ULL);
  ASSERT (strtoull ("1", NULL, 10) == 1ULL);
  ASSERT (strtoull ("10", NULL, 10) == 10ULL);
  ASSERT (strtoull ("11", NULL, 10) == 11ULL);
  ASSERT (strtoull ("+1", NULL, 10) == 1ULL);
  ASSERT (strtoull ("+10", NULL, 10) == 10ULL);
  ASSERT (strtoull ("+11", NULL, 10) == 11ULL);
}

static void
test_strtoull_base_16 (void)
{
  ASSERT (strtoull ("0", NULL, 16) == 0ULL);
  ASSERT (strtoull ("1", NULL, 16) == 1ULL);
  ASSERT (strtoull ("10", NULL, 16) == 16ULL);
  ASSERT (strtoull ("11", NULL, 16) == 17ULL);
  ASSERT (strtoull ("+1", NULL, 16) == 1ULL);
  ASSERT (strtoull ("+10", NULL, 16) == 16ULL);
  ASSERT (strtoull ("+11", NULL, 16) == 17ULL);
}

static void
test_strtoull_base_2_implied (void)
{
  ASSERT (strtoull ("0b0", NULL, 0) == 0ULL);
  ASSERT (strtoull ("0b1", NULL, 0) == 1ULL);
  ASSERT (strtoull ("0b10", NULL, 0) == 2ULL);
  ASSERT (strtoull ("0b11", NULL, 0) == 3ULL);
  ASSERT (strtoull ("+0b1", NULL, 0) == 1ULL);
  ASSERT (strtoull ("+0b10", NULL, 0) == 2ULL);
  ASSERT (strtoull ("+0b11", NULL, 0) == 3ULL);
  ASSERT (strtoull ("0B0", NULL, 0) == 0ULL);
  ASSERT (strtoull ("0B1", NULL, 0) == 1ULL);
  ASSERT (strtoull ("0B10", NULL, 0) == 2ULL);
  ASSERT (strtoull ("0B11", NULL, 0) == 3ULL);
  ASSERT (strtoull ("+0B1", NULL, 0) == 1ULL);
  ASSERT (strtoull ("+0B10", NULL, 0) == 2ULL);
  ASSERT (strtoull ("+0B11", NULL, 0) == 3ULL);
}

static void
test_strtoull_base_10_implied (void)
{
  ASSERT (strtoull ("1", NULL, 0) == 1ULL);
  ASSERT (strtoull ("10", NULL, 0) == 10ULL);
  ASSERT (strtoull ("11", NULL, 0) == 11ULL);
  ASSERT (strtoull ("+1", NULL, 0) == 1ULL);
  ASSERT (strtoull ("+10", NULL, 0) == 10ULL);
  ASSERT (strtoull ("+11", NULL, 0) == 11ULL);
}

static void
test_strtoull_base_16_implied (void)
{
  ASSERT (strtoull ("0x0", NULL, 0) == 0ULL);
  ASSERT (strtoull ("0x1", NULL, 0) == 1ULL);
  ASSERT (strtoull ("0x10", NULL, 0) == 16ULL);
  ASSERT (strtoull ("0x11", NULL, 0) == 17ULL);
  ASSERT (strtoull ("+0x1", NULL, 0) == 1ULL);
  ASSERT (strtoull ("+0x10", NULL, 0) == 16ULL);
  ASSERT (strtoull ("+0x11", NULL, 0) == 17ULL);
  ASSERT (strtoull ("0X0", NULL, 0) == 0ULL);
  ASSERT (strtoull ("0X1", NULL, 0) == 1ULL);
  ASSERT (strtoull ("0X10", NULL, 0) == 16ULL);
  ASSERT (strtoull ("0X11", NULL, 0) == 17ULL);
  ASSERT (strtoull ("+0X1", NULL, 0) == 1ULL);
  ASSERT (strtoull ("+0X10", NULL, 0) == 16ULL);
  ASSERT (strtoull ("+0X11", NULL, 0) == 17ULL);
}

static void
test_strtoull_bounds (void)
{
#if ULLONG_MAX == 255ULL
  errno = 0;
  ASSERT (strtoull ("255", NULL, 0) == ULLONG_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoull ("256", NULL, 0) == ULLONG_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
#elif ULLONG_MAX == 65535ULL
  errno = 0;
  ASSERT (strtoull ("65535", NULL, 0) == ULLONG_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoull ("65536", NULL, 0) == ULLONG_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
#elif ULLONG_MAX == 4294967295ULL
  errno = 0;
  ASSERT (strtoull ("4294967295", NULL, 0) == ULLONG_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoull ("4294967296", NULL, 0) == ULLONG_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
#elif ULLONG_MAX == 18446744073709551615ULL
  errno = 0;
  ASSERT (strtoull ("18446744073709551615", NULL, 0) == ULLONG_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoull ("18446744073709551616", NULL, 0) == ULLONG_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
#endif
}
