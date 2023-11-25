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

static void test_static_assert_message (void);
static void test_static_assert_no_message (void);

/* Test that '_Static_assert' works without needing to include <assert.h>. */
int
main (void)
{
  test_static_assert_message ();
  test_static_assert_no_message ();
  return 0;
}

/* Test that '_Static_assert' works with a second message parameter. */
static void
test_static_assert_message (void)
{
  _Static_assert (1, "Static assert message test 1");
  _Static_assert (5 * 5 == 25, "Static assert message test 2");
  _Static_assert (sizeof (char) == 1, "Static assert message test 3");
}

/* Test that '_Static_assert' works without a second message parameter. */
static void
test_static_assert_no_message (void)
{
  _Static_assert (1);
  _Static_assert (5 * 5 == 25);
  _Static_assert (sizeof (char) == 1);
}
