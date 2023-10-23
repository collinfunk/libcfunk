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
  ASSERT (!iswpunct (0x00));
  ASSERT (!iswpunct (0x01));
  ASSERT (!iswpunct (0x02));
  ASSERT (!iswpunct (0x03));
  ASSERT (!iswpunct (0x04));
  ASSERT (!iswpunct (0x05));
  ASSERT (!iswpunct (0x06));
  ASSERT (!iswpunct (L'\a'));
  ASSERT (!iswpunct (L'\b'));
  ASSERT (!iswpunct (L'\t'));
  ASSERT (!iswpunct (L'\n'));
  ASSERT (!iswpunct (L'\v'));
  ASSERT (!iswpunct (L'\f'));
  ASSERT (!iswpunct (L'\r'));
  ASSERT (!iswpunct (0x0e));
  ASSERT (!iswpunct (0x0f));
  ASSERT (!iswpunct (0x10));
  ASSERT (!iswpunct (0x11));
  ASSERT (!iswpunct (0x12));
  ASSERT (!iswpunct (0x13));
  ASSERT (!iswpunct (0x14));
  ASSERT (!iswpunct (0x15));
  ASSERT (!iswpunct (0x16));
  ASSERT (!iswpunct (0x17));
  ASSERT (!iswpunct (0x18));
  ASSERT (!iswpunct (0x19));
  ASSERT (!iswpunct (0x1a));
  ASSERT (!iswpunct (0x1b));
  ASSERT (!iswpunct (0x1c));
  ASSERT (!iswpunct (0x1d));
  ASSERT (!iswpunct (0x1e));
  ASSERT (!iswpunct (0x1f));
  ASSERT (!iswpunct (L' '));
  ASSERT (iswpunct (L'!'));
  ASSERT (iswpunct (L'\"'));
  ASSERT (iswpunct (L'#'));
  ASSERT (iswpunct (L'$'));
  ASSERT (iswpunct (L'%'));
  ASSERT (iswpunct (L'&'));
  ASSERT (iswpunct (L'\''));
  ASSERT (iswpunct (L'('));
  ASSERT (iswpunct (L')'));
  ASSERT (iswpunct (L'*'));
  ASSERT (iswpunct (L'+'));
  ASSERT (iswpunct (L','));
  ASSERT (iswpunct (L'-'));
  ASSERT (iswpunct (L'.'));
  ASSERT (iswpunct (L'/'));
  ASSERT (!iswpunct (L'0'));
  ASSERT (!iswpunct (L'1'));
  ASSERT (!iswpunct (L'2'));
  ASSERT (!iswpunct (L'3'));
  ASSERT (!iswpunct (L'4'));
  ASSERT (!iswpunct (L'5'));
  ASSERT (!iswpunct (L'6'));
  ASSERT (!iswpunct (L'7'));
  ASSERT (!iswpunct (L'8'));
  ASSERT (!iswpunct (L'9'));
  ASSERT (iswpunct (L':'));
  ASSERT (iswpunct (L';'));
  ASSERT (iswpunct (L'<'));
  ASSERT (iswpunct (L'='));
  ASSERT (iswpunct (L'>'));
  ASSERT (iswpunct (L'\?'));
  ASSERT (iswpunct (L'@'));
  ASSERT (!iswpunct (L'A'));
  ASSERT (!iswpunct (L'B'));
  ASSERT (!iswpunct (L'C'));
  ASSERT (!iswpunct (L'D'));
  ASSERT (!iswpunct (L'E'));
  ASSERT (!iswpunct (L'F'));
  ASSERT (!iswpunct (L'G'));
  ASSERT (!iswpunct (L'H'));
  ASSERT (!iswpunct (L'I'));
  ASSERT (!iswpunct (L'J'));
  ASSERT (!iswpunct (L'K'));
  ASSERT (!iswpunct (L'L'));
  ASSERT (!iswpunct (L'M'));
  ASSERT (!iswpunct (L'N'));
  ASSERT (!iswpunct (L'O'));
  ASSERT (!iswpunct (L'P'));
  ASSERT (!iswpunct (L'Q'));
  ASSERT (!iswpunct (L'R'));
  ASSERT (!iswpunct (L'S'));
  ASSERT (!iswpunct (L'T'));
  ASSERT (!iswpunct (L'U'));
  ASSERT (!iswpunct (L'V'));
  ASSERT (!iswpunct (L'W'));
  ASSERT (!iswpunct (L'X'));
  ASSERT (!iswpunct (L'Y'));
  ASSERT (!iswpunct (L'Z'));
  ASSERT (iswpunct (L'['));
  ASSERT (iswpunct (L'\\'));
  ASSERT (iswpunct (L']'));
  ASSERT (iswpunct (L'^'));
  ASSERT (iswpunct (L'_'));
  ASSERT (iswpunct (L'`'));
  ASSERT (!iswpunct (L'a'));
  ASSERT (!iswpunct (L'b'));
  ASSERT (!iswpunct (L'c'));
  ASSERT (!iswpunct (L'd'));
  ASSERT (!iswpunct (L'e'));
  ASSERT (!iswpunct (L'f'));
  ASSERT (!iswpunct (L'g'));
  ASSERT (!iswpunct (L'h'));
  ASSERT (!iswpunct (L'i'));
  ASSERT (!iswpunct (L'j'));
  ASSERT (!iswpunct (L'k'));
  ASSERT (!iswpunct (L'l'));
  ASSERT (!iswpunct (L'm'));
  ASSERT (!iswpunct (L'n'));
  ASSERT (!iswpunct (L'o'));
  ASSERT (!iswpunct (L'p'));
  ASSERT (!iswpunct (L'q'));
  ASSERT (!iswpunct (L'r'));
  ASSERT (!iswpunct (L's'));
  ASSERT (!iswpunct (L't'));
  ASSERT (!iswpunct (L'u'));
  ASSERT (!iswpunct (L'v'));
  ASSERT (!iswpunct (L'w'));
  ASSERT (!iswpunct (L'x'));
  ASSERT (!iswpunct (L'y'));
  ASSERT (!iswpunct (L'z'));
  ASSERT (iswpunct (L'{'));
  ASSERT (iswpunct (L'|'));
  ASSERT (iswpunct (L'}'));
  ASSERT (iswpunct (L'~'));
  ASSERT (!iswpunct (127));
  return 0;
}
