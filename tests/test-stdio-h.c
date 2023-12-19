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

#include <stdio.h>

#include "attributes.h"

/* Integer constants denoting implementation limits. */
static_assert (FILENAME_MAX > 0);
static_assert (FOPEN_MAX > 0);

/* EOF must be a negative integer constant. */
static_assert (EOF < 0);

static void test_fpos_t_defined (void);
static void test_off_t_defined (void);
static void test_size_t_defined (void);
static void test_ssize_t_defined (void);
static void test_va_list_defined (void);
static void test_NULL_defined (void);
static void test_setvbuf_macros_defined (void);
static void test_seek_macros_defined (void);

/* Test that 'stdio.h' can be included. */
int
main (void)
{
  test_fpos_t_defined ();
  test_off_t_defined ();
  test_size_t_defined ();
  test_ssize_t_defined ();
  test_va_list_defined ();
  test_NULL_defined ();
  test_setvbuf_macros_defined ();
  test_seek_macros_defined ();
  return 0;
}

static void
test_fpos_t_defined (void)
{
  fpos_t value ATTRIBUTE_UNUSED;
}

static void
test_off_t_defined (void)
{
  off_t value ATTRIBUTE_UNUSED;
}

static void
test_size_t_defined (void)
{
  size_t value ATTRIBUTE_UNUSED;
}

static void
test_ssize_t_defined (void)
{
  ssize_t value ATTRIBUTE_UNUSED;
}

static void
test_va_list_defined (void)
{
  va_list value ATTRIBUTE_UNUSED;
}

static void
test_NULL_defined (void)
{
  char *ptr ATTRIBUTE_UNUSED;

  ptr = NULL;
}

static void
test_setvbuf_macros_defined (void)
{
  switch (0)
    {
    case _IOFBF:
      break;
    case _IOLBF:
      break;
    case _IONBF:
      break;
    default:
      break;
    }
}

static void
test_seek_macros_defined (void)
{
  switch (0)
    {
    case SEEK_CUR:
      break;
    case SEEK_END:
      break;
    case SEEK_SET:
      break;
    default:
      break;
    }
}
