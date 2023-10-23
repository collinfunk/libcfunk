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
  ASSERT (!iswdigit (0x00));
  ASSERT (!iswdigit (0x01));
  ASSERT (!iswdigit (0x02));
  ASSERT (!iswdigit (0x03));
  ASSERT (!iswdigit (0x04));
  ASSERT (!iswdigit (0x05));
  ASSERT (!iswdigit (0x06));
  ASSERT (!iswdigit (L'\a'));
  ASSERT (!iswdigit (L'\b'));
  ASSERT (!iswdigit (L'\t'));
  ASSERT (!iswdigit (L'\n'));
  ASSERT (!iswdigit (L'\v'));
  ASSERT (!iswdigit (L'\f'));
  ASSERT (!iswdigit (L'\r'));
  ASSERT (!iswdigit (0x0e));
  ASSERT (!iswdigit (0x0f));
  ASSERT (!iswdigit (0x10));
  ASSERT (!iswdigit (0x11));
  ASSERT (!iswdigit (0x12));
  ASSERT (!iswdigit (0x13));
  ASSERT (!iswdigit (0x14));
  ASSERT (!iswdigit (0x15));
  ASSERT (!iswdigit (0x16));
  ASSERT (!iswdigit (0x17));
  ASSERT (!iswdigit (0x18));
  ASSERT (!iswdigit (0x19));
  ASSERT (!iswdigit (0x1a));
  ASSERT (!iswdigit (0x1b));
  ASSERT (!iswdigit (0x1c));
  ASSERT (!iswdigit (0x1d));
  ASSERT (!iswdigit (0x1e));
  ASSERT (!iswdigit (0x1f));
  ASSERT (!iswdigit (L' '));
  ASSERT (!iswdigit (L'!'));
  ASSERT (!iswdigit (L'\"'));
  ASSERT (!iswdigit (L'#'));
  ASSERT (!iswdigit (L'$'));
  ASSERT (!iswdigit (L'%'));
  ASSERT (!iswdigit (L'&'));
  ASSERT (!iswdigit (L'\''));
  ASSERT (!iswdigit (L'('));
  ASSERT (!iswdigit (L')'));
  ASSERT (!iswdigit (L'*'));
  ASSERT (!iswdigit (L'+'));
  ASSERT (!iswdigit (L','));
  ASSERT (!iswdigit (L'-'));
  ASSERT (!iswdigit (L'.'));
  ASSERT (!iswdigit (L'/'));
  ASSERT (iswdigit (L'0'));
  ASSERT (iswdigit (L'1'));
  ASSERT (iswdigit (L'2'));
  ASSERT (iswdigit (L'3'));
  ASSERT (iswdigit (L'4'));
  ASSERT (iswdigit (L'5'));
  ASSERT (iswdigit (L'6'));
  ASSERT (iswdigit (L'7'));
  ASSERT (iswdigit (L'8'));
  ASSERT (iswdigit (L'9'));
  ASSERT (!iswdigit (L':'));
  ASSERT (!iswdigit (L';'));
  ASSERT (!iswdigit (L'<'));
  ASSERT (!iswdigit (L'='));
  ASSERT (!iswdigit (L'>'));
  ASSERT (!iswdigit (L'\?'));
  ASSERT (!iswdigit (L'@'));
  ASSERT (!iswdigit (L'A'));
  ASSERT (!iswdigit (L'B'));
  ASSERT (!iswdigit (L'C'));
  ASSERT (!iswdigit (L'D'));
  ASSERT (!iswdigit (L'E'));
  ASSERT (!iswdigit (L'F'));
  ASSERT (!iswdigit (L'G'));
  ASSERT (!iswdigit (L'H'));
  ASSERT (!iswdigit (L'I'));
  ASSERT (!iswdigit (L'J'));
  ASSERT (!iswdigit (L'K'));
  ASSERT (!iswdigit (L'L'));
  ASSERT (!iswdigit (L'M'));
  ASSERT (!iswdigit (L'N'));
  ASSERT (!iswdigit (L'O'));
  ASSERT (!iswdigit (L'P'));
  ASSERT (!iswdigit (L'Q'));
  ASSERT (!iswdigit (L'R'));
  ASSERT (!iswdigit (L'S'));
  ASSERT (!iswdigit (L'T'));
  ASSERT (!iswdigit (L'U'));
  ASSERT (!iswdigit (L'V'));
  ASSERT (!iswdigit (L'W'));
  ASSERT (!iswdigit (L'X'));
  ASSERT (!iswdigit (L'Y'));
  ASSERT (!iswdigit (L'Z'));
  ASSERT (!iswdigit (L'['));
  ASSERT (!iswdigit (L'\\'));
  ASSERT (!iswdigit (L']'));
  ASSERT (!iswdigit (L'^'));
  ASSERT (!iswdigit (L'_'));
  ASSERT (!iswdigit (L'`'));
  ASSERT (!iswdigit (L'a'));
  ASSERT (!iswdigit (L'b'));
  ASSERT (!iswdigit (L'c'));
  ASSERT (!iswdigit (L'd'));
  ASSERT (!iswdigit (L'e'));
  ASSERT (!iswdigit (L'f'));
  ASSERT (!iswdigit (L'g'));
  ASSERT (!iswdigit (L'h'));
  ASSERT (!iswdigit (L'i'));
  ASSERT (!iswdigit (L'j'));
  ASSERT (!iswdigit (L'k'));
  ASSERT (!iswdigit (L'l'));
  ASSERT (!iswdigit (L'm'));
  ASSERT (!iswdigit (L'n'));
  ASSERT (!iswdigit (L'o'));
  ASSERT (!iswdigit (L'p'));
  ASSERT (!iswdigit (L'q'));
  ASSERT (!iswdigit (L'r'));
  ASSERT (!iswdigit (L's'));
  ASSERT (!iswdigit (L't'));
  ASSERT (!iswdigit (L'u'));
  ASSERT (!iswdigit (L'v'));
  ASSERT (!iswdigit (L'w'));
  ASSERT (!iswdigit (L'x'));
  ASSERT (!iswdigit (L'y'));
  ASSERT (!iswdigit (L'z'));
  ASSERT (!iswdigit (L'{'));
  ASSERT (!iswdigit (L'|'));
  ASSERT (!iswdigit (L'}'));
  ASSERT (!iswdigit (L'~'));
  ASSERT (!iswdigit (127));
  return 0;
}
