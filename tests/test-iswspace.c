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
  ASSERT (!iswspace (0x00));
  ASSERT (!iswspace (0x01));
  ASSERT (!iswspace (0x02));
  ASSERT (!iswspace (0x03));
  ASSERT (!iswspace (0x04));
  ASSERT (!iswspace (0x05));
  ASSERT (!iswspace (0x06));
  ASSERT (!iswspace (L'\a'));
  ASSERT (!iswspace (L'\b'));
  ASSERT (iswspace (L'\t'));
  ASSERT (iswspace (L'\n'));
  ASSERT (iswspace (L'\v'));
  ASSERT (iswspace (L'\f'));
  ASSERT (iswspace (L'\r'));
  ASSERT (!iswspace (0x0e));
  ASSERT (!iswspace (0x0f));
  ASSERT (!iswspace (0x10));
  ASSERT (!iswspace (0x11));
  ASSERT (!iswspace (0x12));
  ASSERT (!iswspace (0x13));
  ASSERT (!iswspace (0x14));
  ASSERT (!iswspace (0x15));
  ASSERT (!iswspace (0x16));
  ASSERT (!iswspace (0x17));
  ASSERT (!iswspace (0x18));
  ASSERT (!iswspace (0x19));
  ASSERT (!iswspace (0x1a));
  ASSERT (!iswspace (0x1b));
  ASSERT (!iswspace (0x1c));
  ASSERT (!iswspace (0x1d));
  ASSERT (!iswspace (0x1e));
  ASSERT (!iswspace (0x1f));
  ASSERT (iswspace (L' '));
  ASSERT (!iswspace (L'!'));
  ASSERT (!iswspace (L'\"'));
  ASSERT (!iswspace (L'#'));
  ASSERT (!iswspace (L'$'));
  ASSERT (!iswspace (L'%'));
  ASSERT (!iswspace (L'&'));
  ASSERT (!iswspace (L'\''));
  ASSERT (!iswspace (L'('));
  ASSERT (!iswspace (L')'));
  ASSERT (!iswspace (L'*'));
  ASSERT (!iswspace (L'+'));
  ASSERT (!iswspace (L','));
  ASSERT (!iswspace (L'-'));
  ASSERT (!iswspace (L'.'));
  ASSERT (!iswspace (L'/'));
  ASSERT (!iswspace (L'0'));
  ASSERT (!iswspace (L'1'));
  ASSERT (!iswspace (L'2'));
  ASSERT (!iswspace (L'3'));
  ASSERT (!iswspace (L'4'));
  ASSERT (!iswspace (L'5'));
  ASSERT (!iswspace (L'6'));
  ASSERT (!iswspace (L'7'));
  ASSERT (!iswspace (L'8'));
  ASSERT (!iswspace (L'9'));
  ASSERT (!iswspace (L':'));
  ASSERT (!iswspace (L';'));
  ASSERT (!iswspace (L'<'));
  ASSERT (!iswspace (L'='));
  ASSERT (!iswspace (L'>'));
  ASSERT (!iswspace (L'\?'));
  ASSERT (!iswspace (L'@'));
  ASSERT (!iswspace (L'A'));
  ASSERT (!iswspace (L'B'));
  ASSERT (!iswspace (L'C'));
  ASSERT (!iswspace (L'D'));
  ASSERT (!iswspace (L'E'));
  ASSERT (!iswspace (L'F'));
  ASSERT (!iswspace (L'G'));
  ASSERT (!iswspace (L'H'));
  ASSERT (!iswspace (L'I'));
  ASSERT (!iswspace (L'J'));
  ASSERT (!iswspace (L'K'));
  ASSERT (!iswspace (L'L'));
  ASSERT (!iswspace (L'M'));
  ASSERT (!iswspace (L'N'));
  ASSERT (!iswspace (L'O'));
  ASSERT (!iswspace (L'P'));
  ASSERT (!iswspace (L'Q'));
  ASSERT (!iswspace (L'R'));
  ASSERT (!iswspace (L'S'));
  ASSERT (!iswspace (L'T'));
  ASSERT (!iswspace (L'U'));
  ASSERT (!iswspace (L'V'));
  ASSERT (!iswspace (L'W'));
  ASSERT (!iswspace (L'X'));
  ASSERT (!iswspace (L'Y'));
  ASSERT (!iswspace (L'Z'));
  ASSERT (!iswspace (L'['));
  ASSERT (!iswspace (L'\\'));
  ASSERT (!iswspace (L']'));
  ASSERT (!iswspace (L'^'));
  ASSERT (!iswspace (L'_'));
  ASSERT (!iswspace (L'`'));
  ASSERT (!iswspace (L'a'));
  ASSERT (!iswspace (L'b'));
  ASSERT (!iswspace (L'c'));
  ASSERT (!iswspace (L'd'));
  ASSERT (!iswspace (L'e'));
  ASSERT (!iswspace (L'f'));
  ASSERT (!iswspace (L'g'));
  ASSERT (!iswspace (L'h'));
  ASSERT (!iswspace (L'i'));
  ASSERT (!iswspace (L'j'));
  ASSERT (!iswspace (L'k'));
  ASSERT (!iswspace (L'l'));
  ASSERT (!iswspace (L'm'));
  ASSERT (!iswspace (L'n'));
  ASSERT (!iswspace (L'o'));
  ASSERT (!iswspace (L'p'));
  ASSERT (!iswspace (L'q'));
  ASSERT (!iswspace (L'r'));
  ASSERT (!iswspace (L's'));
  ASSERT (!iswspace (L't'));
  ASSERT (!iswspace (L'u'));
  ASSERT (!iswspace (L'v'));
  ASSERT (!iswspace (L'w'));
  ASSERT (!iswspace (L'x'));
  ASSERT (!iswspace (L'y'));
  ASSERT (!iswspace (L'z'));
  ASSERT (!iswspace (L'{'));
  ASSERT (!iswspace (L'|'));
  ASSERT (!iswspace (L'}'));
  ASSERT (!iswspace (L'~'));
  ASSERT (!iswspace (127));
  return 0;
}
