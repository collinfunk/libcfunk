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

static void test_argz_next_zero_length (void);
static void test_argz_next_argc1 (void);
static void test_argz_next_argc2 (void);
static void test_argz_next_argc3 (void);

int
main (void)
{
  test_argz_next_zero_length ();
  test_argz_next_argc1 ();
  test_argz_next_argc2 ();
  test_argz_next_argc3 ();
  return 0;
}

static void
test_argz_next_zero_length (void)
{
  ASSERT (argz_next (NULL, 0, NULL) == NULL);
  ASSERT (argz_next ("", 0, NULL) == NULL);
}

void
test_argz_next_argc1 (void)
{
  char *result;

  {
    char input[] = { 'a', '\0' };
    result = argz_next (input, sizeof (input), NULL);
    ASSERT (result == input);
    result = argz_next (input, sizeof (input), result);
    ASSERT (result == NULL);
  }
  {
    char input[] = { 'a', 'b', '\0' };
    result = argz_next (input, sizeof (input), NULL);
    ASSERT (result == input);
    result = argz_next (input, sizeof (input), result);
    ASSERT (result == NULL);
  }
  {
    char input[] = { 'a', 'b', 'c', '\0' };
    result = argz_next (input, sizeof (input), NULL);
    ASSERT (result == input);
    result = argz_next (input, sizeof (input), result);
    ASSERT (result == NULL);
  }
}

static void
test_argz_next_argc2 (void)
{
  char *result;

  {
    char input[] = { 'a', '\0', 'b', '\0' };
    result = argz_next (input, sizeof (input), NULL);
    ASSERT (result == input);
    result = argz_next (input, sizeof (input), result);
    ASSERT (result == input + 2);
    result = argz_next (input, sizeof (input), result);
    ASSERT (result == NULL);
  }
  {
    char input[] = { 'a', 'b', '\0', 'c', 'd', '\0' };
    result = argz_next (input, sizeof (input), NULL);
    ASSERT (result == input);
    result = argz_next (input, sizeof (input), result);
    ASSERT (result == input + 3);
    result = argz_next (input, sizeof (input), result);
    ASSERT (result == NULL);
  }
  {
    char input[] = { 'a', 'b', 'c', '\0', 'd', 'e', 'f', '\0' };
    result = argz_next (input, sizeof (input), NULL);
    ASSERT (result == input);
    result = argz_next (input, sizeof (input), result);
    ASSERT (result == input + 4);
    result = argz_next (input, sizeof (input), result);
    ASSERT (result == NULL);
  }
}

static void
test_argz_next_argc3 (void)
{
  char *result;

  {
    char input[] = { 'a', '\0', 'b', '\0', 'c', '\0' };
    result = argz_next (input, sizeof (input), NULL);
    ASSERT (result == input);
    result = argz_next (input, sizeof (input), result);
    ASSERT (result == input + 2);
    result = argz_next (input, sizeof (input), result);
    ASSERT (result == input + 4);
    result = argz_next (input, sizeof (input), result);
    ASSERT (result == NULL);
  }
  {
    char input[] = { 'a', 'b', '\0', 'c', 'd', '\0', 'e', 'f', '\0' };
    result = argz_next (input, sizeof (input), NULL);
    ASSERT (result == input);
    result = argz_next (input, sizeof (input), result);
    ASSERT (result == input + 3);
    result = argz_next (input, sizeof (input), result);
    ASSERT (result == input + 6);
    result = argz_next (input, sizeof (input), result);
    ASSERT (result == NULL);
  }
  {
    char input[]
        = { 'a', 'b', 'c', '\0', 'd', 'e', 'f', '\0', 'g', 'h', 'i', '\0' };
    result = argz_next (input, sizeof (input), NULL);
    ASSERT (result == input);
    result = argz_next (input, sizeof (input), result);
    ASSERT (result == input + 4);
    result = argz_next (input, sizeof (input), result);
    ASSERT (result == input + 8);
    result = argz_next (input, sizeof (input), result);
    ASSERT (result == NULL);
  }
}
