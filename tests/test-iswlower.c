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
  ASSERT (!iswlower (0x00));
  ASSERT (!iswlower (0x01));
  ASSERT (!iswlower (0x02));
  ASSERT (!iswlower (0x03));
  ASSERT (!iswlower (0x04));
  ASSERT (!iswlower (0x05));
  ASSERT (!iswlower (0x06));
  ASSERT (!iswlower (L'\a'));
  ASSERT (!iswlower (L'\b'));
  ASSERT (!iswlower (L'\t'));
  ASSERT (!iswlower (L'\n'));
  ASSERT (!iswlower (L'\v'));
  ASSERT (!iswlower (L'\f'));
  ASSERT (!iswlower (L'\r'));
  ASSERT (!iswlower (0x0e));
  ASSERT (!iswlower (0x0f));
  ASSERT (!iswlower (0x10));
  ASSERT (!iswlower (0x11));
  ASSERT (!iswlower (0x12));
  ASSERT (!iswlower (0x13));
  ASSERT (!iswlower (0x14));
  ASSERT (!iswlower (0x15));
  ASSERT (!iswlower (0x16));
  ASSERT (!iswlower (0x17));
  ASSERT (!iswlower (0x18));
  ASSERT (!iswlower (0x19));
  ASSERT (!iswlower (0x1a));
  ASSERT (!iswlower (0x1b));
  ASSERT (!iswlower (0x1c));
  ASSERT (!iswlower (0x1d));
  ASSERT (!iswlower (0x1e));
  ASSERT (!iswlower (0x1f));
  ASSERT (!iswlower (L' '));
  ASSERT (!iswlower (L'!'));
  ASSERT (!iswlower (L'\"'));
  ASSERT (!iswlower (L'#'));
  ASSERT (!iswlower (L'$'));
  ASSERT (!iswlower (L'%'));
  ASSERT (!iswlower (L'&'));
  ASSERT (!iswlower (L'\''));
  ASSERT (!iswlower (L'('));
  ASSERT (!iswlower (L')'));
  ASSERT (!iswlower (L'*'));
  ASSERT (!iswlower (L'+'));
  ASSERT (!iswlower (L','));
  ASSERT (!iswlower (L'-'));
  ASSERT (!iswlower (L'.'));
  ASSERT (!iswlower (L'/'));
  ASSERT (!iswlower (L'0'));
  ASSERT (!iswlower (L'1'));
  ASSERT (!iswlower (L'2'));
  ASSERT (!iswlower (L'3'));
  ASSERT (!iswlower (L'4'));
  ASSERT (!iswlower (L'5'));
  ASSERT (!iswlower (L'6'));
  ASSERT (!iswlower (L'7'));
  ASSERT (!iswlower (L'8'));
  ASSERT (!iswlower (L'9'));
  ASSERT (!iswlower (L':'));
  ASSERT (!iswlower (L';'));
  ASSERT (!iswlower (L'<'));
  ASSERT (!iswlower (L'='));
  ASSERT (!iswlower (L'>'));
  ASSERT (!iswlower (L'\?'));
  ASSERT (!iswlower (L'@'));
  ASSERT (!iswlower (L'A'));
  ASSERT (!iswlower (L'B'));
  ASSERT (!iswlower (L'C'));
  ASSERT (!iswlower (L'D'));
  ASSERT (!iswlower (L'E'));
  ASSERT (!iswlower (L'F'));
  ASSERT (!iswlower (L'G'));
  ASSERT (!iswlower (L'H'));
  ASSERT (!iswlower (L'I'));
  ASSERT (!iswlower (L'J'));
  ASSERT (!iswlower (L'K'));
  ASSERT (!iswlower (L'L'));
  ASSERT (!iswlower (L'M'));
  ASSERT (!iswlower (L'N'));
  ASSERT (!iswlower (L'O'));
  ASSERT (!iswlower (L'P'));
  ASSERT (!iswlower (L'Q'));
  ASSERT (!iswlower (L'R'));
  ASSERT (!iswlower (L'S'));
  ASSERT (!iswlower (L'T'));
  ASSERT (!iswlower (L'U'));
  ASSERT (!iswlower (L'V'));
  ASSERT (!iswlower (L'W'));
  ASSERT (!iswlower (L'X'));
  ASSERT (!iswlower (L'Y'));
  ASSERT (!iswlower (L'Z'));
  ASSERT (!iswlower (L'['));
  ASSERT (!iswlower (L'\\'));
  ASSERT (!iswlower (L']'));
  ASSERT (!iswlower (L'^'));
  ASSERT (!iswlower (L'_'));
  ASSERT (!iswlower (L'`'));
  ASSERT (iswlower (L'a'));
  ASSERT (iswlower (L'b'));
  ASSERT (iswlower (L'c'));
  ASSERT (iswlower (L'd'));
  ASSERT (iswlower (L'e'));
  ASSERT (iswlower (L'f'));
  ASSERT (iswlower (L'g'));
  ASSERT (iswlower (L'h'));
  ASSERT (iswlower (L'i'));
  ASSERT (iswlower (L'j'));
  ASSERT (iswlower (L'k'));
  ASSERT (iswlower (L'l'));
  ASSERT (iswlower (L'm'));
  ASSERT (iswlower (L'n'));
  ASSERT (iswlower (L'o'));
  ASSERT (iswlower (L'p'));
  ASSERT (iswlower (L'q'));
  ASSERT (iswlower (L'r'));
  ASSERT (iswlower (L's'));
  ASSERT (iswlower (L't'));
  ASSERT (iswlower (L'u'));
  ASSERT (iswlower (L'v'));
  ASSERT (iswlower (L'w'));
  ASSERT (iswlower (L'x'));
  ASSERT (iswlower (L'y'));
  ASSERT (iswlower (L'z'));
  ASSERT (!iswlower (L'{'));
  ASSERT (!iswlower (L'|'));
  ASSERT (!iswlower (L'}'));
  ASSERT (!iswlower (L'~'));
  ASSERT (!iswlower (127));
  return 0;
}
