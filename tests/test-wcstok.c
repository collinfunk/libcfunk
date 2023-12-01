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
#include <stdlib.h>
#include <wchar.h>

#include "test-help.h"

static wchar_t test_string[] = { L'1',  L'2', L' ', L'4', L'5', L'6', L'\t',
                                 L'\t', L' ', L'a', L'b', L'c', L'\0' };

int
main (void)
{
  wchar_t *result;
  wchar_t *ptr;
  const wchar_t delimiters[] = { L' ', L'\t', L'\0' };

  result = wcstok (test_string, delimiters, &ptr);
  ASSERT (result == test_string);
  ASSERT (wcscmp (result, L"12") == 0);

  result = wcstok (NULL, delimiters, &ptr);
  ASSERT (result == test_string + 3);
  ASSERT (wcscmp (result, L"456") == 0);

  result = wcstok (NULL, delimiters, &ptr);
  ASSERT (result == test_string + 9);
  ASSERT (wcscmp (result, L"abc") == 0);

  result = wcstok (NULL, delimiters, &ptr);
  ASSERT (result == NULL);

  return 0;
}
