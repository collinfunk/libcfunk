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
  ASSERT (!iswalnum (0x00));
  ASSERT (!iswalnum (0x01));
  ASSERT (!iswalnum (0x02));
  ASSERT (!iswalnum (0x03));
  ASSERT (!iswalnum (0x04));
  ASSERT (!iswalnum (0x05));
  ASSERT (!iswalnum (0x06));
  ASSERT (!iswalnum (L'\a'));
  ASSERT (!iswalnum (L'\b'));
  ASSERT (!iswalnum (L'\t'));
  ASSERT (!iswalnum (L'\n'));
  ASSERT (!iswalnum (L'\v'));
  ASSERT (!iswalnum (L'\f'));
  ASSERT (!iswalnum (L'\r'));
  ASSERT (!iswalnum (0x0e));
  ASSERT (!iswalnum (0x0f));
  ASSERT (!iswalnum (0x10));
  ASSERT (!iswalnum (0x11));
  ASSERT (!iswalnum (0x12));
  ASSERT (!iswalnum (0x13));
  ASSERT (!iswalnum (0x14));
  ASSERT (!iswalnum (0x15));
  ASSERT (!iswalnum (0x16));
  ASSERT (!iswalnum (0x17));
  ASSERT (!iswalnum (0x18));
  ASSERT (!iswalnum (0x19));
  ASSERT (!iswalnum (0x1a));
  ASSERT (!iswalnum (0x1b));
  ASSERT (!iswalnum (0x1c));
  ASSERT (!iswalnum (0x1d));
  ASSERT (!iswalnum (0x1e));
  ASSERT (!iswalnum (0x1f));
  ASSERT (!iswalnum (L' '));
  ASSERT (!iswalnum (L'!'));
  ASSERT (!iswalnum (L'\"'));
  ASSERT (!iswalnum (L'#'));
  ASSERT (!iswalnum (L'$'));
  ASSERT (!iswalnum (L'%'));
  ASSERT (!iswalnum (L'&'));
  ASSERT (!iswalnum (L'\''));
  ASSERT (!iswalnum (L'('));
  ASSERT (!iswalnum (L')'));
  ASSERT (!iswalnum (L'*'));
  ASSERT (!iswalnum (L'+'));
  ASSERT (!iswalnum (L','));
  ASSERT (!iswalnum (L'-'));
  ASSERT (!iswalnum (L'.'));
  ASSERT (!iswalnum (L'/'));
  ASSERT (iswalnum (L'0'));
  ASSERT (iswalnum (L'1'));
  ASSERT (iswalnum (L'2'));
  ASSERT (iswalnum (L'3'));
  ASSERT (iswalnum (L'4'));
  ASSERT (iswalnum (L'5'));
  ASSERT (iswalnum (L'6'));
  ASSERT (iswalnum (L'7'));
  ASSERT (iswalnum (L'8'));
  ASSERT (iswalnum (L'9'));
  ASSERT (!iswalnum (L':'));
  ASSERT (!iswalnum (L';'));
  ASSERT (!iswalnum (L'<'));
  ASSERT (!iswalnum (L'='));
  ASSERT (!iswalnum (L'>'));
  ASSERT (!iswalnum (L'\?'));
  ASSERT (!iswalnum (L'@'));
  ASSERT (iswalnum (L'A'));
  ASSERT (iswalnum (L'B'));
  ASSERT (iswalnum (L'C'));
  ASSERT (iswalnum (L'D'));
  ASSERT (iswalnum (L'E'));
  ASSERT (iswalnum (L'F'));
  ASSERT (iswalnum (L'G'));
  ASSERT (iswalnum (L'H'));
  ASSERT (iswalnum (L'I'));
  ASSERT (iswalnum (L'J'));
  ASSERT (iswalnum (L'K'));
  ASSERT (iswalnum (L'L'));
  ASSERT (iswalnum (L'M'));
  ASSERT (iswalnum (L'N'));
  ASSERT (iswalnum (L'O'));
  ASSERT (iswalnum (L'P'));
  ASSERT (iswalnum (L'Q'));
  ASSERT (iswalnum (L'R'));
  ASSERT (iswalnum (L'S'));
  ASSERT (iswalnum (L'T'));
  ASSERT (iswalnum (L'U'));
  ASSERT (iswalnum (L'V'));
  ASSERT (iswalnum (L'W'));
  ASSERT (iswalnum (L'X'));
  ASSERT (iswalnum (L'Y'));
  ASSERT (iswalnum (L'Z'));
  ASSERT (!iswalnum (L'['));
  ASSERT (!iswalnum (L'\\'));
  ASSERT (!iswalnum (L']'));
  ASSERT (!iswalnum (L'^'));
  ASSERT (!iswalnum (L'_'));
  ASSERT (!iswalnum (L'`'));
  ASSERT (iswalnum (L'a'));
  ASSERT (iswalnum (L'b'));
  ASSERT (iswalnum (L'c'));
  ASSERT (iswalnum (L'd'));
  ASSERT (iswalnum (L'e'));
  ASSERT (iswalnum (L'f'));
  ASSERT (iswalnum (L'g'));
  ASSERT (iswalnum (L'h'));
  ASSERT (iswalnum (L'i'));
  ASSERT (iswalnum (L'j'));
  ASSERT (iswalnum (L'k'));
  ASSERT (iswalnum (L'l'));
  ASSERT (iswalnum (L'm'));
  ASSERT (iswalnum (L'n'));
  ASSERT (iswalnum (L'o'));
  ASSERT (iswalnum (L'p'));
  ASSERT (iswalnum (L'q'));
  ASSERT (iswalnum (L'r'));
  ASSERT (iswalnum (L's'));
  ASSERT (iswalnum (L't'));
  ASSERT (iswalnum (L'u'));
  ASSERT (iswalnum (L'v'));
  ASSERT (iswalnum (L'w'));
  ASSERT (iswalnum (L'x'));
  ASSERT (iswalnum (L'y'));
  ASSERT (iswalnum (L'z'));
  ASSERT (!iswalnum (L'{'));
  ASSERT (!iswalnum (L'|'));
  ASSERT (!iswalnum (L'}'));
  ASSERT (!iswalnum (L'~'));
  ASSERT (!iswalnum (127));
  return 0;
}
