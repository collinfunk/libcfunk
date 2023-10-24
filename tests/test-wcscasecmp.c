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

int
main (void)
{
  ASSERT (wcscasecmp (L"", L"") == 0);
  ASSERT (wcscasecmp (L"TEST", L"test") == 0);
  ASSERT (wcscasecmp (L"test", L"TEST") == 0);
  ASSERT (wcscasecmp (L"A", L"B") < 0);
  ASSERT (wcscasecmp (L"A", L"b") < 0);
  ASSERT (wcscasecmp (L"a", L"B") < 0);
  ASSERT (wcscasecmp (L"a", L"b") < 0);
  ASSERT (wcscasecmp (L"B", L"A") > 0);
  ASSERT (wcscasecmp (L"B", L"a") > 0);
  ASSERT (wcscasecmp (L"b", L"A") > 0);
  ASSERT (wcscasecmp (L"b", L"a") > 0);
  ASSERT (wcscasecmp (L"abcde", L"abcd") > 0);
  ASSERT (wcscasecmp (L"abcd", L"abcde") < 0);
  return 0;
}
