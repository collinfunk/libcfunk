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

#include <stdlib.h>

#include "attributes.h"

static_assert (EXIT_SUCCESS == 0);
static_assert (EXIT_FAILURE == 1);

static void test_struct_random_data_defined (void);
static void test_size_t_defined (void);
static void test_wchar_t_defined (void);
static void test_div_t_defined (void);
static void test_ldiv_t_defined (void);
static void test_lldiv_t_defined (void);
static void test_NULL_defined (void);

/* Test that 'stdlib.h' can be included. */
int
main (void)
{
  test_struct_random_data_defined ();
  test_size_t_defined ();
  test_wchar_t_defined ();
  test_div_t_defined ();
  test_ldiv_t_defined ();
  test_lldiv_t_defined ();
  test_NULL_defined ();
  return 0;
}

static void
test_struct_random_data_defined (void)
{
  struct random_data value ATTRIBUTE_UNUSED;
}

static void
test_size_t_defined (void)
{
  size_t value ATTRIBUTE_UNUSED;
}

static void
test_wchar_t_defined (void)
{
  size_t value ATTRIBUTE_UNUSED;
}

static void
test_div_t_defined (void)
{
  div_t value ATTRIBUTE_UNUSED;
}

static void
test_ldiv_t_defined (void)
{
  ldiv_t value ATTRIBUTE_UNUSED;
}

static void
test_lldiv_t_defined (void)
{
  lldiv_t value ATTRIBUTE_UNUSED;
}

static void
test_NULL_defined (void)
{
  char *ptr ATTRIBUTE_UNUSED;

  ptr = NULL;
}
