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

#include <stdint.h>

#include "test-help.h"

#undef TYPE_WIDTH
#undef TYPE_MAX
#undef TYPE_MIN

#define TYPE_WIDTH(type) ((type) (sizeof (type) * CHAR_BIT))
#define TYPE_MAX(type)                                                        \
  (((type) (-1) > 0)                                                          \
       ? ((type) (-1))                                                        \
       : ((((((type) 1) << ((sizeof (type) * CHAR_BIT) - 2)) - 1) * 2) + 1))
#define TYPE_MIN(type) (~TYPE_MAX (type))

/* C23 widths for int8_t, int16_t, int32_t, and int64_t. */
static_assert (TYPE_WIDTH (int8_t) == INT8_WIDTH);
static_assert (TYPE_WIDTH (int16_t) == INT16_WIDTH);
static_assert (TYPE_WIDTH (int32_t) == INT32_WIDTH);
static_assert (TYPE_WIDTH (int64_t) == INT64_WIDTH);

/* C23 widths for uint8_t, uint16_t, uint32_t, and uint64_t. */
static_assert (TYPE_WIDTH (uint8_t) == UINT8_WIDTH);
static_assert (TYPE_WIDTH (uint16_t) == UINT16_WIDTH);
static_assert (TYPE_WIDTH (uint32_t) == UINT32_WIDTH);
static_assert (TYPE_WIDTH (uint64_t) == UINT64_WIDTH);

/* C23 widths for int_fast8_t, int_fast16_t, int_fast32_t, and int_fast64_t. */
static_assert (TYPE_WIDTH (int_fast8_t) == INT_FAST8_WIDTH);
static_assert (TYPE_WIDTH (int_fast16_t) == INT_FAST16_WIDTH);
static_assert (TYPE_WIDTH (int_fast32_t) == INT_FAST32_WIDTH);
static_assert (TYPE_WIDTH (int_fast64_t) == INT_FAST64_WIDTH);

/* C23 widths for uint_fast8_t, uint_fast16_t, uint_fast32_t, and
   uint_fast64_t. */
static_assert (TYPE_WIDTH (uint_fast8_t) == UINT_FAST8_WIDTH);
static_assert (TYPE_WIDTH (uint_fast16_t) == UINT_FAST16_WIDTH);
static_assert (TYPE_WIDTH (uint_fast32_t) == UINT_FAST32_WIDTH);
static_assert (TYPE_WIDTH (uint_fast64_t) == UINT_FAST64_WIDTH);

/* C23 widths for int_least8_t, int_least16_t, int_least32_t, and
   int_least64_t. */
static_assert (TYPE_WIDTH (int_least8_t) == INT_LEAST8_WIDTH);
static_assert (TYPE_WIDTH (int_least16_t) == INT_LEAST16_WIDTH);
static_assert (TYPE_WIDTH (int_least32_t) == INT_LEAST32_WIDTH);
static_assert (TYPE_WIDTH (int_least64_t) == INT_LEAST64_WIDTH);

/* C23 widths for uint_least8_t, uint_least16_t, uint_least32_t, and
   uint_least64_t. */
static_assert (TYPE_WIDTH (uint_least8_t) == UINT_LEAST8_WIDTH);
static_assert (TYPE_WIDTH (uint_least16_t) == UINT_LEAST16_WIDTH);
static_assert (TYPE_WIDTH (uint_least32_t) == UINT_LEAST32_WIDTH);
static_assert (TYPE_WIDTH (uint_least64_t) == UINT_LEAST64_WIDTH);

/* C23 width for intptr_t. */
static_assert (TYPE_WIDTH (intptr_t) == INTPTR_WIDTH);

/* C23 width for uintptr_t. */
static_assert (TYPE_WIDTH (uintptr_t) == UINTPTR_WIDTH);

/* C23 width for intmax_t. */
static_assert (TYPE_WIDTH (intmax_t) == INTMAX_WIDTH);

/* C23 width for uintmax_t. */
static_assert (TYPE_WIDTH (uintmax_t) == UINTMAX_WIDTH);

/* Maximum value which can be held by int8_t, int16_t, int32_t, and int64_t. */
static_assert (TYPE_MAX (int8_t) == INT8_MAX);
static_assert (TYPE_MAX (int16_t) == INT16_MAX);
static_assert (TYPE_MAX (int32_t) == INT32_MAX);
static_assert (TYPE_MAX (int64_t) == INT64_MAX);

/* Maximum value which can be held by uint8_t, uint16_t, uint32_t, and
   uint64_t. */
static_assert (TYPE_MAX (uint8_t) == UINT8_MAX);
static_assert (TYPE_MAX (uint16_t) == UINT16_MAX);
static_assert (TYPE_MAX (uint32_t) == UINT32_MAX);
static_assert (TYPE_MAX (uint64_t) == UINT64_MAX);

/* Maximum value which can be held by int_fast8_t, int_fast16_t, int_fast32_t,
   and int_fast64_t. */
static_assert (TYPE_MAX (int_fast8_t) == INT_FAST8_MAX);
static_assert (TYPE_MAX (int_fast16_t) == INT_FAST16_MAX);
static_assert (TYPE_MAX (int_fast32_t) == INT_FAST32_MAX);
static_assert (TYPE_MAX (int_fast64_t) == INT_FAST64_MAX);

/* Maximum value which can be held by uint_fast8_t, uint_fast16_t,
   uint_fast32_t, and uint_fast64_t. */
static_assert (TYPE_MAX (uint_fast8_t) == UINT_FAST8_MAX);
static_assert (TYPE_MAX (uint_fast16_t) == UINT_FAST16_MAX);
static_assert (TYPE_MAX (uint_fast32_t) == UINT_FAST32_MAX);
static_assert (TYPE_MAX (uint_fast64_t) == UINT_FAST64_MAX);

/* Maximum value which can be held by int_least8_t, int_least16_t,
   int_least32_t, and int_least64_t. */
static_assert (TYPE_MAX (int_least8_t) == INT_LEAST8_MAX);
static_assert (TYPE_MAX (int_least16_t) == INT_LEAST16_MAX);
static_assert (TYPE_MAX (int_least32_t) == INT_LEAST32_MAX);
static_assert (TYPE_MAX (int_least64_t) == INT_LEAST64_MAX);

/* Maximum value which can be held by uint_least8_t, uint_least16_t,
   uint_least32_t, and uint_least64_t. */
static_assert (TYPE_MAX (uint_least8_t) == UINT_LEAST8_MAX);
static_assert (TYPE_MAX (uint_least16_t) == UINT_LEAST16_MAX);
static_assert (TYPE_MAX (uint_least32_t) == UINT_LEAST32_MAX);
static_assert (TYPE_MAX (uint_least64_t) == UINT_LEAST64_MAX);

/* Maximum value which can be held by intptr_t. */
static_assert (TYPE_MAX (intptr_t) == INTPTR_MAX);

/* Maximum value which can be held by uintptr_t. */
static_assert (TYPE_MAX (uintptr_t) == UINTPTR_MAX);

/* Maximum value which can be held by intmax_t. */
static_assert (TYPE_MAX (intmax_t) == INTMAX_MAX);

/* Maximum value which can be held by uintmax_t. */
static_assert (TYPE_MAX (uintmax_t) == UINTMAX_MAX);

/* Minimum value which can be held by int8_t, int16_t, int32_t, and int64_t. */
static_assert (TYPE_MIN (int8_t) == INT8_MIN);
static_assert (TYPE_MIN (int16_t) == INT16_MIN);
static_assert (TYPE_MIN (int32_t) == INT32_MIN);
static_assert (TYPE_MIN (int64_t) == INT64_MIN);

/* Minimum value which can be held by int_fast8_t, int_fast16_t, int_fast32_t,
   and int_fast64_t. */
static_assert (TYPE_MIN (int_fast8_t) == INT_FAST8_MIN);
static_assert (TYPE_MIN (int_fast16_t) == INT_FAST16_MIN);
static_assert (TYPE_MIN (int_fast32_t) == INT_FAST32_MIN);
static_assert (TYPE_MIN (int_fast64_t) == INT_FAST64_MIN);

/* Minimum value which can be held by int_least8_t, int_least16_t,
   int_least32_t, and int_least64_t. */
static_assert (TYPE_MIN (int_least8_t) == INT_LEAST8_MIN);
static_assert (TYPE_MIN (int_least16_t) == INT_LEAST16_MIN);
static_assert (TYPE_MIN (int_least32_t) == INT_LEAST32_MIN);
static_assert (TYPE_MIN (int_least64_t) == INT_LEAST64_MIN);

/* Minimum value which can be held by intptr_t. */
static_assert (TYPE_MIN (intptr_t) == INTPTR_MIN);

/* Minimum value which can be held by intmax_t. */
static_assert (TYPE_MIN (intmax_t) == INTMAX_MIN);

/* Signed cast macros. */
static_assert (INT8_C (0) == INT8_C (0));
static_assert (INT16_C (0) == INT16_C (0));
static_assert (INT32_C (0) == INT32_C (0));
static_assert (INT64_C (0) == INT64_C (0));
static_assert (INTMAX_C (0) == INTMAX_C (0));

/* Unsigned cast macros. */
static_assert (UINT8_C (0) == UINT8_C (0));
static_assert (UINT16_C (0) == UINT16_C (0));
static_assert (UINT32_C (0) == UINT32_C (0));
static_assert (UINT64_C (0) == UINT64_C (0));
static_assert (UINTMAX_C (0) == UINTMAX_C (0));

int
main (void)
{
  return 0;
}
