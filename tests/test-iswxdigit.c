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
#include <wctype.h>

#include "test-help.h"

int
main (void)
{
  ASSERT (iswxdigit (L'0'));
  ASSERT (iswxdigit (L'1'));
  ASSERT (iswxdigit (L'2'));
  ASSERT (iswxdigit (L'3'));
  ASSERT (iswxdigit (L'4'));
  ASSERT (iswxdigit (L'5'));
  ASSERT (iswxdigit (L'6'));
  ASSERT (iswxdigit (L'7'));
  ASSERT (iswxdigit (L'8'));
  ASSERT (iswxdigit (L'9'));
  ASSERT (iswxdigit (L'a'));
  ASSERT (iswxdigit (L'b'));
  ASSERT (iswxdigit (L'c'));
  ASSERT (iswxdigit (L'd'));
  ASSERT (iswxdigit (L'e'));
  ASSERT (iswxdigit (L'f'));
  ASSERT (iswxdigit (L'A'));
  ASSERT (iswxdigit (L'B'));
  ASSERT (iswxdigit (L'C'));
  ASSERT (iswxdigit (L'D'));
  ASSERT (iswxdigit (L'E'));
  ASSERT (iswxdigit (L'F'));
  ASSERT (!iswxdigit (L'g'));
  ASSERT (!iswxdigit (L'G'));
  return 0;
}
