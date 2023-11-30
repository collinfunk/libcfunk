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

static void test_strtoul_invalid_base (void);
static void test_strtoul_base_2 (void);
static void test_strtoul_base_10 (void);
static void test_strtoul_base_16 (void);
static void test_strtoul_base_2_implied (void);
static void test_strtoul_base_10_implied (void);
static void test_strtoul_base_16_implied (void);
static void test_strtoul_bounds (void);

int
main (void)
{
  test_strtoul_invalid_base ();
  test_strtoul_base_2 ();
  test_strtoul_base_10 ();
  test_strtoul_base_16 ();
  test_strtoul_base_2_implied ();
  test_strtoul_base_10_implied ();
  test_strtoul_base_16_implied ();
  test_strtoul_bounds ();
  return 0;
}

static void
test_strtoul_invalid_base (void)
{
  errno = 0;
  ASSERT (strtoul ("1", NULL, -1) == 0);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (strtoul ("1", NULL, 1) == 0);
  ASSERT (errno == EINVAL);
  errno = 0;
  ASSERT (strtoul ("1", NULL, 37) == 0);
  ASSERT (errno == EINVAL);
  errno = 0;
}

static void
test_strtoul_base_2 (void)
{
  ASSERT (strtoul ("0", NULL, 2) == 0UL);
  ASSERT (strtoul ("1", NULL, 2) == 1UL);
  ASSERT (strtoul ("10", NULL, 2) == 2UL);
  ASSERT (strtoul ("11", NULL, 2) == 3UL);
  ASSERT (strtoul ("+1", NULL, 2) == 1UL);
  ASSERT (strtoul ("+10", NULL, 2) == 2UL);
  ASSERT (strtoul ("+11", NULL, 2) == 3UL);
}

static void
test_strtoul_base_10 (void)
{
  ASSERT (strtoul ("0", NULL, 10) == 0UL);
  ASSERT (strtoul ("1", NULL, 10) == 1UL);
  ASSERT (strtoul ("10", NULL, 10) == 10UL);
  ASSERT (strtoul ("11", NULL, 10) == 11UL);
  ASSERT (strtoul ("+1", NULL, 10) == 1UL);
  ASSERT (strtoul ("+10", NULL, 10) == 10UL);
  ASSERT (strtoul ("+11", NULL, 10) == 11UL);
}

static void
test_strtoul_base_16 (void)
{
  ASSERT (strtoul ("0", NULL, 16) == 0UL);
  ASSERT (strtoul ("1", NULL, 16) == 1UL);
  ASSERT (strtoul ("10", NULL, 16) == 16UL);
  ASSERT (strtoul ("11", NULL, 16) == 17UL);
  ASSERT (strtoul ("+1", NULL, 16) == 1UL);
  ASSERT (strtoul ("+10", NULL, 16) == 16UL);
  ASSERT (strtoul ("+11", NULL, 16) == 17UL);
}

static void
test_strtoul_base_2_implied (void)
{
  ASSERT (strtoul ("0b0", NULL, 0) == 0UL);
  ASSERT (strtoul ("0b1", NULL, 0) == 1UL);
  ASSERT (strtoul ("0b10", NULL, 0) == 2UL);
  ASSERT (strtoul ("0b11", NULL, 0) == 3UL);
  ASSERT (strtoul ("+0b1", NULL, 0) == 1UL);
  ASSERT (strtoul ("+0b10", NULL, 0) == 2UL);
  ASSERT (strtoul ("+0b11", NULL, 0) == 3UL);
  ASSERT (strtoul ("0B0", NULL, 0) == 0UL);
  ASSERT (strtoul ("0B1", NULL, 0) == 1UL);
  ASSERT (strtoul ("0B10", NULL, 0) == 2UL);
  ASSERT (strtoul ("0B11", NULL, 0) == 3UL);
  ASSERT (strtoul ("+0B1", NULL, 0) == 1UL);
  ASSERT (strtoul ("+0B10", NULL, 0) == 2UL);
  ASSERT (strtoul ("+0B11", NULL, 0) == 3UL);
}

static void
test_strtoul_base_10_implied (void)
{
  ASSERT (strtoul ("1", NULL, 0) == 1UL);
  ASSERT (strtoul ("10", NULL, 0) == 10UL);
  ASSERT (strtoul ("11", NULL, 0) == 11UL);
  ASSERT (strtoul ("+1", NULL, 0) == 1UL);
  ASSERT (strtoul ("+10", NULL, 0) == 10UL);
  ASSERT (strtoul ("+11", NULL, 0) == 11UL);
}

static void
test_strtoul_base_16_implied (void)
{
  ASSERT (strtoul ("0x0", NULL, 0) == 0UL);
  ASSERT (strtoul ("0x1", NULL, 0) == 1UL);
  ASSERT (strtoul ("0x10", NULL, 0) == 16UL);
  ASSERT (strtoul ("0x11", NULL, 0) == 17UL);
  ASSERT (strtoul ("+0x1", NULL, 0) == 1UL);
  ASSERT (strtoul ("+0x10", NULL, 0) == 16UL);
  ASSERT (strtoul ("+0x11", NULL, 0) == 17UL);
  ASSERT (strtoul ("0X0", NULL, 0) == 0UL);
  ASSERT (strtoul ("0X1", NULL, 0) == 1UL);
  ASSERT (strtoul ("0X10", NULL, 0) == 16UL);
  ASSERT (strtoul ("0X11", NULL, 0) == 17UL);
  ASSERT (strtoul ("+0X1", NULL, 0) == 1UL);
  ASSERT (strtoul ("+0X10", NULL, 0) == 16UL);
  ASSERT (strtoul ("+0X11", NULL, 0) == 17UL);
}

static void
test_strtoul_bounds (void)
{
#if ULONG_MAX == 255UL
  errno = 0;
  ASSERT (strtoul ("255", NULL, 0) == ULONG_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoul ("256", NULL, 0) == ULONG_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
#elif ULONG_MAX == 65535UL
  errno = 0;
  ASSERT (strtoul ("65535", NULL, 0) == ULONG_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoul ("65536", NULL, 0) == ULONG_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
#elif ULONG_MAX == 4294967295UL
  errno = 0;
  ASSERT (strtoul ("4294967295", NULL, 0) == ULONG_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoul ("4294967296", NULL, 0) == ULONG_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
#elif ULONG_MAX == 18446744073709551615UL
  errno = 0;
  ASSERT (strtoul ("18446744073709551615", NULL, 0) == ULONG_MAX);
  ASSERT (errno == 0);
  ASSERT (strtoul ("18446744073709551616", NULL, 0) == ULONG_MAX);
  ASSERT (errno == ERANGE);
  errno = 0;
#endif
}
