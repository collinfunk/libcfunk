/*-
 * Copyright (c) 2024, Collin Funk
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

#include <stdbit.h>

#include "attributes.h"

static void test_size_t_defined (void);
static void test_uint8_t_defined (void);
static void test_uint16_t_defined (void);
static void test_uint32_t_defined (void);
static void test_uint64_t_defined (void);
static void test_int8_t_defined (void);
static void test_int16_t_defined (void);
static void test_int32_t_defined (void);
static void test_int64_t_defined (void);
static void test_uint_least8_t_defined (void);
static void test_uint_least16_t_defined (void);
static void test_uint_least32_t_defined (void);
static void test_uint_least64_t_defined (void);
static void test_int_least8_t_defined (void);
static void test_int_least16_t_defined (void);
static void test_int_least32_t_defined (void);
static void test_int_least64_t_defined (void);

/* Test that 'stdbit.h' can be included. */
int
main (void)
{
  test_size_t_defined ();
  test_uint8_t_defined ();
  test_uint16_t_defined ();
  test_uint32_t_defined ();
  test_uint64_t_defined ();
  test_int8_t_defined ();
  test_int16_t_defined ();
  test_int32_t_defined ();
  test_int64_t_defined ();
  test_uint_least8_t_defined ();
  test_uint_least16_t_defined ();
  test_uint_least32_t_defined ();
  test_uint_least64_t_defined ();
  test_int_least8_t_defined ();
  test_int_least16_t_defined ();
  test_int_least32_t_defined ();
  test_int_least64_t_defined ();
  return 0;
}

static void
test_size_t_defined (void)
{
  size_t value ATTRIBUTE_UNUSED;
}

static void
test_uint8_t_defined (void)
{
  uint8_t value ATTRIBUTE_UNUSED;
}

static void
test_uint16_t_defined (void)
{
  uint16_t value ATTRIBUTE_UNUSED;
}

static void
test_uint32_t_defined (void)
{
  uint32_t value ATTRIBUTE_UNUSED;
}

static void
test_uint64_t_defined (void)
{
  uint64_t value ATTRIBUTE_UNUSED;
}

static void
test_int8_t_defined (void)
{
  int8_t value ATTRIBUTE_UNUSED;
}

static void
test_int16_t_defined (void)
{
  int16_t value ATTRIBUTE_UNUSED;
}

static void
test_int32_t_defined (void)
{
  int32_t value ATTRIBUTE_UNUSED;
}

static void
test_int64_t_defined (void)
{
  int64_t value ATTRIBUTE_UNUSED;
}

static void
test_uint_least8_t_defined (void)
{
  uint_least8_t value ATTRIBUTE_UNUSED;
}

static void
test_uint_least16_t_defined (void)
{
  uint_least16_t value ATTRIBUTE_UNUSED;
}

static void
test_uint_least32_t_defined (void)
{
  uint_least32_t value ATTRIBUTE_UNUSED;
}

static void
test_uint_least64_t_defined (void)
{
  uint_least64_t value ATTRIBUTE_UNUSED;
}

static void
test_int_least8_t_defined (void)
{
  int_least8_t value ATTRIBUTE_UNUSED;
}

static void
test_int_least16_t_defined (void)
{
  int_least16_t value ATTRIBUTE_UNUSED;
}

static void
test_int_least32_t_defined (void)
{
  int_least32_t value ATTRIBUTE_UNUSED;
}

static void
test_int_least64_t_defined (void)
{
  int_least64_t value ATTRIBUTE_UNUSED;
}
