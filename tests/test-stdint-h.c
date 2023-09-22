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
#include <stdint.h>

#include "test-help.h"

#undef TYPE_MAX_SIGNED
#undef TYPE_MIN_SIGNED
#undef TYPE_MAX_UNSIGNED
#undef TYPE_MIN_UNSIGNED
#undef TYPE_IS_UNSIGNED
#undef TYPE_WIDTH

#define TYPE_MAX_SIGNED(type)                                                 \
  ((((((type) 1) << ((sizeof (type) * CHAR_BIT) - 2)) - 1) * 2) + 1)
#define TYPE_MIN_SIGNED(type) (~TYPE_MAX_SIGNED (type))

#define TYPE_MAX_UNSIGNED(type) ((type) -1)
#define TYPE_MIN_UNSIGNED(type) ((type) 0)

#define TYPE_IS_UNSIGNED(type) (((type) -1) > 0)
#define TYPE_WIDTH(type) ((type) (sizeof (type) * CHAR_BIT))

static void test_intn_type_predefined_macros (void);
static void test_uintn_type_predefined_macros (void);
static void test_int_leastn_type_predefined_macros (void);
static void test_uint_leastn_type_predefined_macros (void);
static void test_int_fastn_type_predefined_macros (void);
static void test_uint_fastn_type_predefined_macros (void);
static void test_intptr_predefined_macros (void);
static void test_uintptr_predefined_macros (void);
static void test_intmax_predefined_macros (void);
static void test_uintmax_predefined_macros (void);
static void test_intn_types (void);
static void test_uintn_types (void);

int
main (void)
{
  test_intn_type_predefined_macros ();
  test_uintn_type_predefined_macros ();
  test_int_leastn_type_predefined_macros ();
  test_uint_leastn_type_predefined_macros ();
  test_int_fastn_type_predefined_macros ();
  test_uint_fastn_type_predefined_macros ();
  test_intptr_predefined_macros ();
  test_uintptr_predefined_macros ();
  test_intmax_predefined_macros ();
  test_uintmax_predefined_macros ();
  test_intn_types ();
  test_uintn_types ();
  return 0;
}

static void
test_intn_type_predefined_macros (void)
{
  __INT8_TYPE__ max_var_8 = TYPE_MAX_SIGNED (__INT8_TYPE__);
  __INT16_TYPE__ max_var_16 = TYPE_MAX_SIGNED (__INT16_TYPE__);
  __INT32_TYPE__ max_var_32 = TYPE_MAX_SIGNED (__INT32_TYPE__);
  __INT64_TYPE__ max_var_64 = TYPE_MAX_SIGNED (__INT64_TYPE__);

  ASSERT (!TYPE_IS_UNSIGNED (__INT8_TYPE__));
  ASSERT (!TYPE_IS_UNSIGNED (__INT16_TYPE__));
  ASSERT (!TYPE_IS_UNSIGNED (__INT32_TYPE__));
  ASSERT (!TYPE_IS_UNSIGNED (__INT64_TYPE__));

  ASSERT (max_var_8 == __INT8_MAX__);
  ASSERT (max_var_16 == __INT16_MAX__);
  ASSERT (max_var_32 == __INT32_MAX__);
  ASSERT (max_var_64 == __INT64_MAX__);
}

static void
test_uintn_type_predefined_macros (void)
{
  __UINT8_TYPE__ max_var_8 = TYPE_MAX_UNSIGNED (__UINT8_TYPE__);
  __UINT16_TYPE__ max_var_16 = TYPE_MAX_UNSIGNED (__UINT16_TYPE__);
  __UINT32_TYPE__ max_var_32 = TYPE_MAX_UNSIGNED (__UINT32_TYPE__);
  __UINT64_TYPE__ max_var_64 = TYPE_MAX_UNSIGNED (__UINT64_TYPE__);

  ASSERT (TYPE_IS_UNSIGNED (__UINT8_TYPE__));
  ASSERT (TYPE_IS_UNSIGNED (__UINT16_TYPE__));
  ASSERT (TYPE_IS_UNSIGNED (__UINT32_TYPE__));
  ASSERT (TYPE_IS_UNSIGNED (__UINT64_TYPE__));

  ASSERT (max_var_8 == __UINT8_MAX__);
  ASSERT (max_var_16 == __UINT16_MAX__);
  ASSERT (max_var_32 == __UINT32_MAX__);
  ASSERT (max_var_64 == __UINT64_MAX__);
}

static void
test_int_leastn_type_predefined_macros (void)
{
  __INT_LEAST8_TYPE__ max_var_8 = TYPE_MAX_SIGNED (__INT_LEAST8_TYPE__);
  __INT_LEAST16_TYPE__ max_var_16 = TYPE_MAX_SIGNED (__INT_LEAST16_TYPE__);
  __INT_LEAST32_TYPE__ max_var_32 = TYPE_MAX_SIGNED (__INT_LEAST32_TYPE__);
  __INT_LEAST64_TYPE__ max_var_64 = TYPE_MAX_SIGNED (__INT_LEAST64_TYPE__);

  ASSERT (TYPE_WIDTH (__INT_LEAST8_TYPE__) == __INT_LEAST8_WIDTH__);
  ASSERT (TYPE_WIDTH (__INT_LEAST16_TYPE__) == __INT_LEAST16_WIDTH__);
  ASSERT (TYPE_WIDTH (__INT_LEAST32_TYPE__) == __INT_LEAST32_WIDTH__);
  ASSERT (TYPE_WIDTH (__INT_LEAST64_TYPE__) == __INT_LEAST64_WIDTH__);

  ASSERT (!TYPE_IS_UNSIGNED (__INT_LEAST8_TYPE__));
  ASSERT (!TYPE_IS_UNSIGNED (__INT_LEAST16_TYPE__));
  ASSERT (!TYPE_IS_UNSIGNED (__INT_LEAST32_TYPE__));
  ASSERT (!TYPE_IS_UNSIGNED (__INT_LEAST64_TYPE__));

  ASSERT (max_var_8 >= __INT8_MAX__);
  ASSERT (max_var_16 >= __INT16_MAX__);
  ASSERT (max_var_32 >= __INT32_MAX__);
  ASSERT (max_var_64 >= __INT64_MAX__);
}

static void
test_uint_leastn_type_predefined_macros (void)
{
  __UINT_LEAST8_TYPE__ max_var_8 = TYPE_MAX_UNSIGNED (__UINT_LEAST8_TYPE__);
  __UINT_LEAST16_TYPE__ max_var_16 = TYPE_MAX_UNSIGNED (__UINT_LEAST16_TYPE__);
  __UINT_LEAST32_TYPE__ max_var_32 = TYPE_MAX_UNSIGNED (__UINT_LEAST32_TYPE__);
  __UINT_LEAST64_TYPE__ max_var_64 = TYPE_MAX_UNSIGNED (__UINT_LEAST64_TYPE__);

  ASSERT (TYPE_WIDTH (__UINT_LEAST8_TYPE__) == __INT_LEAST8_WIDTH__);
  ASSERT (TYPE_WIDTH (__UINT_LEAST16_TYPE__) == __INT_LEAST16_WIDTH__);
  ASSERT (TYPE_WIDTH (__UINT_LEAST32_TYPE__) == __INT_LEAST32_WIDTH__);
  ASSERT (TYPE_WIDTH (__UINT_LEAST64_TYPE__) == __INT_LEAST64_WIDTH__);

  ASSERT (TYPE_IS_UNSIGNED (__UINT_LEAST8_TYPE__));
  ASSERT (TYPE_IS_UNSIGNED (__UINT_LEAST16_TYPE__));
  ASSERT (TYPE_IS_UNSIGNED (__UINT_LEAST32_TYPE__));
  ASSERT (TYPE_IS_UNSIGNED (__UINT_LEAST64_TYPE__));

  ASSERT (max_var_8 >= __UINT8_MAX__);
  ASSERT (max_var_16 >= __UINT16_MAX__);
  ASSERT (max_var_32 >= __UINT32_MAX__);
  ASSERT (max_var_64 >= __UINT64_MAX__);
}

static void
test_int_fastn_type_predefined_macros (void)
{
  __INT_FAST8_TYPE__ max_var_8 = TYPE_MAX_SIGNED (__INT_FAST8_TYPE__);
  __INT_FAST16_TYPE__ max_var_16 = TYPE_MAX_SIGNED (__INT_FAST16_TYPE__);
  __INT_FAST32_TYPE__ max_var_32 = TYPE_MAX_SIGNED (__INT_FAST32_TYPE__);
  __INT_FAST64_TYPE__ max_var_64 = TYPE_MAX_SIGNED (__INT_FAST64_TYPE__);

  ASSERT (!TYPE_IS_UNSIGNED (__INT_FAST8_TYPE__));
  ASSERT (!TYPE_IS_UNSIGNED (__INT_FAST16_TYPE__));
  ASSERT (!TYPE_IS_UNSIGNED (__INT_FAST32_TYPE__));
  ASSERT (!TYPE_IS_UNSIGNED (__INT_FAST64_TYPE__));

  ASSERT (max_var_8 >= __INT8_MAX__);
  ASSERT (max_var_16 >= __INT16_MAX__);
  ASSERT (max_var_32 >= __INT32_MAX__);
  ASSERT (max_var_64 >= __INT64_MAX__);
}

static void
test_uint_fastn_type_predefined_macros (void)
{
  __UINT_FAST8_TYPE__ max_var_8 = TYPE_MAX_UNSIGNED (__UINT_FAST8_TYPE__);
  __UINT_FAST16_TYPE__ max_var_16 = TYPE_MAX_UNSIGNED (__UINT_FAST16_TYPE__);
  __UINT_FAST32_TYPE__ max_var_32 = TYPE_MAX_UNSIGNED (__UINT_FAST32_TYPE__);
  __UINT_FAST64_TYPE__ max_var_64 = TYPE_MAX_UNSIGNED (__UINT_FAST64_TYPE__);

  ASSERT (TYPE_IS_UNSIGNED (__UINT_FAST8_TYPE__));
  ASSERT (TYPE_IS_UNSIGNED (__UINT_FAST16_TYPE__));
  ASSERT (TYPE_IS_UNSIGNED (__UINT_FAST32_TYPE__));
  ASSERT (TYPE_IS_UNSIGNED (__UINT_FAST64_TYPE__));

  ASSERT (max_var_8 >= __UINT8_MAX__);
  ASSERT (max_var_16 >= __UINT16_MAX__);
  ASSERT (max_var_32 >= __UINT32_MAX__);
  ASSERT (max_var_64 >= __UINT64_MAX__);
}

static void
test_intptr_predefined_macros (void)
{
  __INTPTR_TYPE__ var = TYPE_MAX_SIGNED (__INTPTR_TYPE__);
  ASSERT (!TYPE_IS_UNSIGNED (__INTPTR_TYPE__));
  ASSERT (sizeof (__INTPTR_TYPE__) == sizeof (void *));
  ASSERT ((size_t) __INTPTR_WIDTH__ == sizeof (void *) * CHAR_BIT);
  ASSERT (var == __INTPTR_MAX__);
}

static void
test_uintptr_predefined_macros (void)
{
  __UINTPTR_TYPE__ var = TYPE_MAX_UNSIGNED (__UINTPTR_TYPE__);
  ASSERT (TYPE_IS_UNSIGNED (__UINTPTR_TYPE__));
  ASSERT (sizeof (__UINTPTR_TYPE__) == sizeof (void *));
  ASSERT ((size_t) __INTPTR_WIDTH__ == sizeof (void *) * CHAR_BIT);
  ASSERT (var == __UINTPTR_MAX__);
}

static void
test_intmax_predefined_macros (void)
{
  __INTMAX_TYPE__ var = TYPE_MAX_SIGNED (__INTMAX_TYPE__);
  ASSERT (!TYPE_IS_UNSIGNED (__INTMAX_TYPE__));
  ASSERT (__INTMAX_WIDTH__ >= 64);
  ASSERT ((size_t) __INTMAX_WIDTH__ == sizeof (__INTMAX_TYPE__) * CHAR_BIT);
  ASSERT (var == __INTMAX_MAX__);
}

static void
test_uintmax_predefined_macros (void)
{
  __UINTMAX_TYPE__ var = TYPE_MAX_UNSIGNED (__UINTMAX_TYPE__);
  ASSERT (TYPE_IS_UNSIGNED (__UINTMAX_TYPE__));
  ASSERT ((size_t) __INTMAX_WIDTH__ == sizeof (__UINTMAX_TYPE__) * CHAR_BIT);
  ASSERT (var == __UINTMAX_MAX__);
}

static void
test_intn_types (void)
{
  int8_t max_var_8 = TYPE_MAX_SIGNED (int8_t);
  int16_t max_var_16 = TYPE_MAX_SIGNED (int16_t);
  int32_t max_var_32 = TYPE_MAX_SIGNED (int32_t);
  int64_t max_var_64 = TYPE_MAX_SIGNED (int64_t);
  int8_t min_var_8 = TYPE_MIN_SIGNED (int8_t);
  int16_t min_var_16 = TYPE_MIN_SIGNED (int16_t);
  int32_t min_var_32 = TYPE_MIN_SIGNED (int32_t);
  int64_t min_var_64 = TYPE_MIN_SIGNED (int64_t);

  ASSERT (!TYPE_IS_UNSIGNED (int8_t));
  ASSERT (!TYPE_IS_UNSIGNED (int16_t));
  ASSERT (!TYPE_IS_UNSIGNED (int32_t));
  ASSERT (!TYPE_IS_UNSIGNED (int64_t));

  ASSERT (TYPE_WIDTH (int8_t) == INT8_WIDTH);
  ASSERT (TYPE_WIDTH (int16_t) == INT16_WIDTH);
  ASSERT (TYPE_WIDTH (int32_t) == INT32_WIDTH);
  ASSERT (TYPE_WIDTH (int64_t) == INT64_WIDTH);

  ASSERT (max_var_8 == INT8_MAX);
  ASSERT (max_var_16 == INT16_MAX);
  ASSERT (max_var_32 == INT32_MAX);
  ASSERT (max_var_64 == INT64_MAX);
  ASSERT (min_var_8 == INT8_MIN);
  ASSERT (min_var_16 == INT16_MIN);
  ASSERT (min_var_32 == INT32_MIN);
  ASSERT (min_var_64 == INT64_MIN);
}

static void
test_uintn_types (void)
{
  uint8_t max_var_8 = TYPE_MAX_UNSIGNED (uint8_t);
  uint16_t max_var_16 = TYPE_MAX_UNSIGNED (uint16_t);
  uint32_t max_var_32 = TYPE_MAX_UNSIGNED (uint32_t);
  uint64_t max_var_64 = TYPE_MAX_UNSIGNED (uint64_t);
  uint8_t min_var_8 = TYPE_MIN_UNSIGNED (uint8_t);
  uint16_t min_var_16 = TYPE_MIN_UNSIGNED (uint16_t);
  uint32_t min_var_32 = TYPE_MIN_UNSIGNED (uint32_t);
  uint64_t min_var_64 = TYPE_MIN_UNSIGNED (uint64_t);

  ASSERT (TYPE_IS_UNSIGNED (uint8_t));
  ASSERT (TYPE_IS_UNSIGNED (uint16_t));
  ASSERT (TYPE_IS_UNSIGNED (uint32_t));
  ASSERT (TYPE_IS_UNSIGNED (uint64_t));

  ASSERT (TYPE_WIDTH (uint8_t) == UINT8_WIDTH);
  ASSERT (TYPE_WIDTH (uint16_t) == UINT16_WIDTH);
  ASSERT (TYPE_WIDTH (uint32_t) == UINT32_WIDTH);
  ASSERT (TYPE_WIDTH (uint64_t) == UINT64_WIDTH);

  ASSERT (max_var_8 == UINT8_MAX);
  ASSERT (max_var_16 == UINT16_MAX);
  ASSERT (max_var_32 == UINT32_MAX);
  ASSERT (max_var_64 == UINT64_MAX);
  ASSERT (min_var_8 == 0);
  ASSERT (min_var_16 == 0);
  ASSERT (min_var_32 == 0);
  ASSERT (min_var_64 == 0);
}
