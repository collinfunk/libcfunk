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

#include <argz.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

static void test_argz_count0 (void);
static void test_argz_count1 (void);
static void test_argz_count2 (void);
static void test_argz_count3 (void);

int
main (void)
{
  test_argz_count0 ();
  test_argz_count1 ();
  test_argz_count2 ();
  test_argz_count3 ();
  return 0;
}

static void
test_argz_count0 (void)
{
  {
    char input[] = { 'a', '\0' };
    ASSERT (argz_count (input, 0) == 0);
  }
  {
    char input[] = { 'a', 'b', '\0' };
    ASSERT (argz_count (input, 0) == 0);
  }
  {
    char input[] = { 'a', 'b', 'c', '\0' };
    ASSERT (argz_count (input, 0) == 0);
  }
}

static void
test_argz_count1 (void)
{
  {
    char input[] = { 'a', '\0' };
    ASSERT (argz_count (input, sizeof (input)) == 1);
  }
  {
    char input[] = { 'a', 'b', '\0' };
    ASSERT (argz_count (input, sizeof (input)) == 1);
  }
  {
    char input[] = { 'a', 'b', 'c', '\0' };
    ASSERT (argz_count (input, sizeof (input)) == 1);
  }
}

static void
test_argz_count2 (void)
{
  {
    char input[] = { 'a', '\0', 'b', '\0' };
    ASSERT (argz_count (input, sizeof (input)) == 2);
  }
  {
    char input[] = { 'a', 'b', '\0', 'c', 'd', '\0' };
    ASSERT (argz_count (input, sizeof (input)) == 2);
  }
  {
    char input[] = { 'a', 'b', 'c', '\0', 'd', 'e', 'f', '\0' };
    ASSERT (argz_count (input, sizeof (input)) == 2);
  }
}

static void
test_argz_count3 (void)
{
  {
    char input[] = { 'a', '\0', 'b', '\0', 'c', '\0' };
    ASSERT (argz_count (input, sizeof (input)) == 3);
  }
  {
    char input[] = { 'a', 'b', '\0', 'c', 'd', '\0', 'e', 'f', '\0' };
    ASSERT (argz_count (input, sizeof (input)) == 3);
  }
  {
    char input[]
        = { 'a', 'b', 'c', '\0', 'd', 'e', 'f', '\0', 'g', 'h', 'i', '\0' };
    ASSERT (argz_count (input, sizeof (input)) == 3);
  }
}
