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

#include "test-help.h"

#undef TYPE_MAX_SIGNED
#undef TYPE_MIN_SIGNED

#define TYPE_MAX_SIGNED(type)                                                 \
  ((((((type) 1) << ((sizeof (type) * CHAR_BIT) - 2)) - 1) * 2) + 1)

#define TYPE_MIN_SIGNED(type) (~TYPE_MAX_SIGNED (type))

static void test_sane_widths (void);
static void test_signed_unsigned_widths_equal (void);
static void test_signed_type_max (void);
static void test_signed_type_min (void);
static void test_unsigned_type_max (void);
static void test_maybe_unsigned_char (void);
static void test_old_gnu_long_long (void);

int
main (void)
{
  test_sane_widths ();
  test_signed_unsigned_widths_equal ();
  test_signed_type_max ();
  test_signed_type_min ();
  test_unsigned_type_max ();
  test_maybe_unsigned_char ();
  test_old_gnu_long_long ();
  return 0;
}

/* This should pass on any common architecture. */
static void
test_sane_widths (void)
{
  ASSERT (CHAR_WIDTH == 8);
  ASSERT (SHRT_WIDTH == 16);
  ASSERT (INT_WIDTH == 32);
  ASSERT (LONG_WIDTH == 32 || LONG_WIDTH == 64);
  ASSERT (LLONG_WIDTH == 64);

  /* Check for the POSIX <TYPE>_BIT macros. */
  ASSERT (CHAR_BIT == CHAR_WIDTH);
  ASSERT (WORD_BIT == INT_WIDTH);
  ASSERT (LONG_BIT == LONG_WIDTH);
}

/* Make sure signed and unsigned types have the same width. */
static void
test_signed_unsigned_widths_equal (void)
{
  ASSERT (CHAR_WIDTH == SCHAR_WIDTH);
  ASSERT (CHAR_WIDTH == UCHAR_WIDTH);
  ASSERT (SHRT_WIDTH == USHRT_WIDTH);
  ASSERT (INT_WIDTH == UINT_WIDTH);
  ASSERT (LONG_WIDTH == ULONG_WIDTH);
  ASSERT (LLONG_WIDTH == ULLONG_WIDTH);
}

static void
test_signed_type_max (void)
{
  ASSERT (SCHAR_MAX == TYPE_MAX_SIGNED (signed char));
  ASSERT (SHRT_MAX == TYPE_MAX_SIGNED (short int));
  ASSERT (INT_MAX == TYPE_MAX_SIGNED (int));
  ASSERT (LONG_MAX == TYPE_MAX_SIGNED (long int));
  ASSERT (LLONG_MAX == TYPE_MAX_SIGNED (long long int));
}

static void
test_signed_type_min (void)
{
  ASSERT (SCHAR_MIN == TYPE_MIN_SIGNED (signed char));
  ASSERT (SHRT_MIN == TYPE_MIN_SIGNED (short int));
  ASSERT (INT_MIN == TYPE_MIN_SIGNED (int));
  ASSERT (LONG_MIN == TYPE_MIN_SIGNED (long int));
  ASSERT (LLONG_MIN == TYPE_MIN_SIGNED (long long int));
}

static void
test_unsigned_type_max (void)
{
  ASSERT (UCHAR_MAX == ((unsigned char) -1));
  ASSERT (USHRT_MAX == ((unsigned short) -1));
  ASSERT (UINT_MAX == ((unsigned int) -1));
  ASSERT (ULONG_MAX == ((unsigned long int) -1));
  ASSERT (ULLONG_MAX == ((unsigned long long int) -1));
}

/* Check `char' which may be signed or unsigned. This can be checked using
   the __CHAR_UNSIGNED__ macro. If it is defined, `char' is unsigned. */
static void
test_maybe_unsigned_char (void)
{
#ifdef __CHAR_UNSIGNED__
#  if SCHAR_MAX == INT_MAX
  ASSERT (CHAR_MIN == 0U);
#  else
  ASSERT (CHAR_MIN == 0);
#  endif
  ASSERT (CHAR_MAX == SCHAR_MAX);
#else
  ASSERT (CHAR_MIN == SCHAR_MIN);
  ASSERT (CHAR_MAX == SCHAR_MAX);
#endif
}

/* Some old versions of the GNU C library used different names for `long long'
   limit macros. Check that they are defined correctly for compatability. */
static void
test_old_gnu_long_long (void)
{
  ASSERT (LONG_LONG_MIN == LLONG_MIN);
  ASSERT (LONG_LONG_MAX == LLONG_MAX);
  ASSERT (ULONG_LONG_MAX == ULLONG_MAX);
}
