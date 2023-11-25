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

#undef TYPE_WIDTH
#undef TYPE_MAX
#undef TYPE_MIN

#define TYPE_WIDTH(type) ((type) (sizeof (type) * CHAR_BIT))
#define TYPE_MAX(type)                                                        \
  (((type) (-1) > 0)                                                          \
       ? ((type) (-1))                                                        \
       : ((((((type) 1) << ((sizeof (type) * CHAR_BIT) - 2)) - 1) * 2) + 1))
#define TYPE_MIN(type) (~TYPE_MAX (type))

/* POSIX bit widths. */
static_assert (TYPE_WIDTH (char) == CHAR_BIT);
static_assert (TYPE_WIDTH (int) == WORD_BIT);
static_assert (TYPE_WIDTH (long int) == LONG_BIT);

/* C23 signed type widths. */
static_assert (TYPE_WIDTH (signed char) == SCHAR_WIDTH);
static_assert (TYPE_WIDTH (short int) == SHRT_WIDTH);
static_assert (TYPE_WIDTH (int) == INT_WIDTH);
static_assert (TYPE_WIDTH (long int) == LONG_WIDTH);
static_assert (TYPE_WIDTH (long long int) == LLONG_WIDTH);

/* C23 unsigned type widths. */
static_assert (TYPE_WIDTH (unsigned char) == UCHAR_WIDTH);
static_assert (TYPE_WIDTH (unsigned short int) == USHRT_WIDTH);
static_assert (TYPE_WIDTH (unsigned int) == UINT_WIDTH);
static_assert (TYPE_WIDTH (unsigned long int) == ULONG_WIDTH);
static_assert (TYPE_WIDTH (unsigned long long int) == ULLONG_WIDTH);

/* Signed type maximums. */
static_assert (TYPE_MAX (signed char) == SCHAR_MAX);
static_assert (TYPE_MAX (short int) == SHRT_MAX);
static_assert (TYPE_MAX (int) == INT_MAX);
static_assert (TYPE_MAX (long int) == LONG_MAX);
static_assert (TYPE_MAX (long long int) == LLONG_MAX);

/* Unsigned type maximums. */
static_assert (TYPE_MAX (unsigned char) == UCHAR_MAX);
static_assert (TYPE_MAX (unsigned short int) == USHRT_MAX);
static_assert (TYPE_MAX (unsigned int) == UINT_MAX);
static_assert (TYPE_MAX (unsigned long int) == ULONG_MAX);
static_assert (TYPE_MAX (unsigned long long int) == ULLONG_MAX);

/* Signed type minimums. */
static_assert (TYPE_MIN (signed char) == SCHAR_MIN);
static_assert (TYPE_MIN (short int) == SHRT_MIN);
static_assert (TYPE_MIN (int) == INT_MIN);
static_assert (TYPE_MIN (long int) == LONG_MIN);
static_assert (TYPE_MIN (long long int) == LLONG_MIN);

/* Plain char macros. */
static_assert (TYPE_WIDTH (char) == CHAR_WIDTH);
static_assert (TYPE_MAX (char) == CHAR_MAX);
static_assert (TYPE_MIN (char) == CHAR_MIN);

/* Old GNU macros for 'long long int'. */
static_assert (LONG_LONG_MAX == LLONG_MAX);
static_assert (LONG_LONG_MIN == LLONG_MIN);
static_assert (ULONG_LONG_MAX == ULLONG_MAX);

/* Make sure 'HOST_NAME_MAX' is defined to a positive integer. */
static_assert (HOST_NAME_MAX > 0);

/* Make sure 'MB_LEN_MAX' is defined to a positive integer. */
static_assert (MB_LEN_MAX > 0);

/* Make sure 'SSIZE_MAX' is defined to a positive integer. It would be
   nice to check this here but that would require including <sys/types.h>. */
static_assert (SSIZE_MAX > 0);

int
main (void)
{
  return 0;
}
