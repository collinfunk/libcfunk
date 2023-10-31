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

#include <limits.h>
#include <stddef.h>
#include <stdint.h>

#include "test-help.h"

#undef TYPE_WIDTH
#undef TYPE_MAX_UNSIGNED
#undef TYPE_MAX_SIGNED
#undef TYPE_MIN_SIGNED

#define TYPE_WIDTH(type) ((type) (sizeof (type) * CHAR_BIT))
#define TYPE_MAX_UNSIGNED(type) ((type) -1)
#define TYPE_MAX_SIGNED(type)                                                 \
  ((((((type) 1) << ((sizeof (type) * CHAR_BIT) - 2)) - 1) * 2) + 1)
#define TYPE_MIN_SIGNED(type) (~TYPE_MAX_SIGNED (type))

static void test_intn_width (void);
static void test_uintn_width (void);
static void test_int_fastn_width (void);
static void test_uint_fastn_width (void);
static void test_int_leastn_width (void);
static void test_uint_leastn_width (void);
static void test_intptr_width (void);
static void test_uintptr_width (void);
static void test_intmax_width (void);
static void test_uintmax_width (void);
static void test_intn_max (void);
static void test_uintn_max (void);
static void test_intn_min (void);
static void test_int_fastn_max (void);
static void test_uint_fastn_max (void);
static void test_int_fastn_min (void);
static void test_int_leastn_max (void);
static void test_uint_leastn_max (void);
static void test_int_leastn_min (void);
static void test_intptr_max (void);
static void test_uintptr_max (void);
static void test_intptr_min (void);
static void test_intmax_max (void);
static void test_uintmax_max (void);
static void test_intmax_min (void);
static void test_size_max (void);

int
main (void)
{
  test_intn_width ();
  test_uintn_width ();
  test_int_fastn_width ();
  test_uint_fastn_width ();
  test_int_leastn_width ();
  test_uint_leastn_width ();
  test_intptr_width ();
  test_uintptr_width ();
  test_intmax_width ();
  test_uintmax_width ();
  test_intn_max ();
  test_uintn_max ();
  test_intn_min ();
  test_int_fastn_max ();
  test_uint_fastn_max ();
  test_int_fastn_min ();
  test_int_leastn_max ();
  test_uint_leastn_max ();
  test_int_leastn_min ();
  test_intptr_max ();
  test_uintptr_max ();
  test_intptr_min ();
  test_intmax_max ();
  test_uintmax_max ();
  test_intmax_min ();
  test_size_max ();
  return 0;
}

static void
test_intn_width (void)
{
  ASSERT (TYPE_WIDTH (int8_t) == INT8_WIDTH);
  ASSERT (TYPE_WIDTH (int16_t) == INT16_WIDTH);
  ASSERT (TYPE_WIDTH (int32_t) == INT32_WIDTH);
  ASSERT (TYPE_WIDTH (int64_t) == INT64_WIDTH);
}

static void
test_uintn_width (void)
{
  ASSERT (TYPE_WIDTH (uint8_t) == UINT8_WIDTH);
  ASSERT (TYPE_WIDTH (uint16_t) == UINT16_WIDTH);
  ASSERT (TYPE_WIDTH (uint32_t) == UINT32_WIDTH);
  ASSERT (TYPE_WIDTH (uint64_t) == UINT64_WIDTH);
}

static void
test_int_fastn_width (void)
{
  ASSERT (TYPE_WIDTH (int_fast8_t) == INT_FAST8_WIDTH);
  ASSERT (TYPE_WIDTH (int_fast16_t) == INT_FAST16_WIDTH);
  ASSERT (TYPE_WIDTH (int_fast32_t) == INT_FAST32_WIDTH);
  ASSERT (TYPE_WIDTH (int_fast64_t) == INT_FAST64_WIDTH);
}

static void
test_uint_fastn_width (void)
{
  ASSERT (TYPE_WIDTH (uint_fast8_t) == UINT_FAST8_WIDTH);
  ASSERT (TYPE_WIDTH (uint_fast16_t) == UINT_FAST16_WIDTH);
  ASSERT (TYPE_WIDTH (uint_fast32_t) == UINT_FAST32_WIDTH);
  ASSERT (TYPE_WIDTH (uint_fast64_t) == UINT_FAST64_WIDTH);
}

static void
test_int_leastn_width (void)
{
  ASSERT (TYPE_WIDTH (int_least8_t) == INT_LEAST8_WIDTH);
  ASSERT (TYPE_WIDTH (int_least16_t) == INT_LEAST16_WIDTH);
  ASSERT (TYPE_WIDTH (int_least32_t) == INT_LEAST32_WIDTH);
  ASSERT (TYPE_WIDTH (int_least64_t) == INT_LEAST64_WIDTH);
}

static void
test_uint_leastn_width (void)
{
  ASSERT (TYPE_WIDTH (uint_least8_t) == UINT_LEAST8_WIDTH);
  ASSERT (TYPE_WIDTH (uint_least16_t) == UINT_LEAST16_WIDTH);
  ASSERT (TYPE_WIDTH (uint_least32_t) == UINT_LEAST32_WIDTH);
  ASSERT (TYPE_WIDTH (uint_least64_t) == UINT_LEAST64_WIDTH);
}

static void
test_intptr_width (void)
{
  ASSERT (TYPE_WIDTH (intptr_t) == INTPTR_WIDTH);
}

static void
test_uintptr_width (void)
{
  ASSERT (TYPE_WIDTH (uintptr_t) == UINTPTR_WIDTH);
}

static void
test_intmax_width (void)
{
  ASSERT (TYPE_WIDTH (intmax_t) == INTMAX_WIDTH);
}

static void
test_uintmax_width (void)
{
  ASSERT (TYPE_WIDTH (uintmax_t) == UINTMAX_WIDTH);
}

static void
test_intn_max (void)
{
  ASSERT (TYPE_MAX_SIGNED (int8_t) == INT8_MAX);
  ASSERT (TYPE_MAX_SIGNED (int16_t) == INT16_MAX);
  ASSERT (TYPE_MAX_SIGNED (int32_t) == INT32_MAX);
  ASSERT (TYPE_MAX_SIGNED (int64_t) == INT64_MAX);
}

static void
test_uintn_max (void)
{
  ASSERT (TYPE_MAX_UNSIGNED (uint8_t) == UINT8_MAX);
  ASSERT (TYPE_MAX_UNSIGNED (uint16_t) == UINT16_MAX);
  ASSERT (TYPE_MAX_UNSIGNED (uint32_t) == UINT32_MAX);
  ASSERT (TYPE_MAX_UNSIGNED (uint64_t) == UINT64_MAX);
}

static void
test_intn_min (void)
{
  ASSERT (TYPE_MIN_SIGNED (int8_t) == INT8_MIN);
  ASSERT (TYPE_MIN_SIGNED (int16_t) == INT16_MIN);
  ASSERT (TYPE_MIN_SIGNED (int32_t) == INT32_MIN);
  ASSERT (TYPE_MIN_SIGNED (int64_t) == INT64_MIN);
}

static void
test_int_fastn_max (void)
{
  ASSERT (TYPE_MAX_SIGNED (int_fast8_t) == INT_FAST8_MAX);
  ASSERT (TYPE_MAX_SIGNED (int_fast16_t) == INT_FAST16_MAX);
  ASSERT (TYPE_MAX_SIGNED (int_fast32_t) == INT_FAST32_MAX);
  ASSERT (TYPE_MAX_SIGNED (int_fast64_t) == INT_FAST64_MAX);
}

static void
test_uint_fastn_max (void)
{
  ASSERT (TYPE_MAX_UNSIGNED (uint_fast8_t) == UINT_FAST8_MAX);
  ASSERT (TYPE_MAX_UNSIGNED (uint_fast16_t) == UINT_FAST16_MAX);
  ASSERT (TYPE_MAX_UNSIGNED (uint_fast32_t) == UINT_FAST32_MAX);
  ASSERT (TYPE_MAX_UNSIGNED (uint_fast64_t) == UINT_FAST64_MAX);
}

static void
test_int_fastn_min (void)
{
  ASSERT (TYPE_MIN_SIGNED (int_fast8_t) == INT_FAST8_MIN);
  ASSERT (TYPE_MIN_SIGNED (int_fast16_t) == INT_FAST16_MIN);
  ASSERT (TYPE_MIN_SIGNED (int_fast32_t) == INT_FAST32_MIN);
  ASSERT (TYPE_MIN_SIGNED (int_fast64_t) == INT_FAST64_MIN);
}

static void
test_int_leastn_max (void)
{
  ASSERT (TYPE_MAX_SIGNED (int_least8_t) == INT_LEAST8_MAX);
  ASSERT (TYPE_MAX_SIGNED (int_least16_t) == INT_LEAST16_MAX);
  ASSERT (TYPE_MAX_SIGNED (int_least32_t) == INT_LEAST32_MAX);
  ASSERT (TYPE_MAX_SIGNED (int_least64_t) == INT_LEAST64_MAX);
}

static void
test_uint_leastn_max (void)
{
  ASSERT (TYPE_MAX_UNSIGNED (uint_least8_t) == UINT_LEAST8_MAX);
  ASSERT (TYPE_MAX_UNSIGNED (uint_least16_t) == UINT_LEAST16_MAX);
  ASSERT (TYPE_MAX_UNSIGNED (uint_least32_t) == UINT_LEAST32_MAX);
  ASSERT (TYPE_MAX_UNSIGNED (uint_least64_t) == UINT_LEAST64_MAX);
}

static void
test_int_leastn_min (void)
{
  ASSERT (TYPE_MIN_SIGNED (int_least8_t) == INT_LEAST8_MIN);
  ASSERT (TYPE_MIN_SIGNED (int_least16_t) == INT_LEAST16_MIN);
  ASSERT (TYPE_MIN_SIGNED (int_least32_t) == INT_LEAST32_MIN);
  ASSERT (TYPE_MIN_SIGNED (int_least64_t) == INT_LEAST64_MIN);
}

static void
test_intptr_max (void)
{
  ASSERT (TYPE_MAX_SIGNED (intptr_t) == INTPTR_MAX);
}

static void
test_uintptr_max (void)
{
  ASSERT (TYPE_MAX_UNSIGNED (uintptr_t) == UINTPTR_MAX);
}

static void
test_intptr_min (void)
{
  ASSERT (TYPE_MIN_SIGNED (intptr_t) == INTPTR_MIN);
}

static void
test_intmax_max (void)
{
  ASSERT (TYPE_MAX_SIGNED (intmax_t) == INTMAX_MAX);
}

static void
test_uintmax_max (void)
{
  ASSERT (TYPE_MAX_UNSIGNED (uintmax_t) == UINTMAX_MAX);
}

static void
test_intmax_min (void)
{
  ASSERT (TYPE_MIN_SIGNED (intmax_t) == INTMAX_MIN);
}

static void
test_size_max (void)
{
  ASSERT (TYPE_MAX_UNSIGNED (size_t) == SIZE_MAX);
}
