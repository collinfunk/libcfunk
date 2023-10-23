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
  ASSERT (!iswalpha (0x00));
  ASSERT (!iswalpha (0x01));
  ASSERT (!iswalpha (0x02));
  ASSERT (!iswalpha (0x03));
  ASSERT (!iswalpha (0x04));
  ASSERT (!iswalpha (0x05));
  ASSERT (!iswalpha (0x06));
  ASSERT (!iswalpha (L'\a'));
  ASSERT (!iswalpha (L'\b'));
  ASSERT (!iswalpha (L'\t'));
  ASSERT (!iswalpha (L'\n'));
  ASSERT (!iswalpha (L'\v'));
  ASSERT (!iswalpha (L'\f'));
  ASSERT (!iswalpha (L'\r'));
  ASSERT (!iswalpha (0x0e));
  ASSERT (!iswalpha (0x0f));
  ASSERT (!iswalpha (0x10));
  ASSERT (!iswalpha (0x11));
  ASSERT (!iswalpha (0x12));
  ASSERT (!iswalpha (0x13));
  ASSERT (!iswalpha (0x14));
  ASSERT (!iswalpha (0x15));
  ASSERT (!iswalpha (0x16));
  ASSERT (!iswalpha (0x17));
  ASSERT (!iswalpha (0x18));
  ASSERT (!iswalpha (0x19));
  ASSERT (!iswalpha (0x1a));
  ASSERT (!iswalpha (0x1b));
  ASSERT (!iswalpha (0x1c));
  ASSERT (!iswalpha (0x1d));
  ASSERT (!iswalpha (0x1e));
  ASSERT (!iswalpha (0x1f));
  ASSERT (!iswalpha (L' '));
  ASSERT (!iswalpha (L'!'));
  ASSERT (!iswalpha (L'\"'));
  ASSERT (!iswalpha (L'#'));
  ASSERT (!iswalpha (L'$'));
  ASSERT (!iswalpha (L'%'));
  ASSERT (!iswalpha (L'&'));
  ASSERT (!iswalpha (L'\''));
  ASSERT (!iswalpha (L'('));
  ASSERT (!iswalpha (L')'));
  ASSERT (!iswalpha (L'*'));
  ASSERT (!iswalpha (L'+'));
  ASSERT (!iswalpha (L','));
  ASSERT (!iswalpha (L'-'));
  ASSERT (!iswalpha (L'.'));
  ASSERT (!iswalpha (L'/'));
  ASSERT (!iswalpha (L'0'));
  ASSERT (!iswalpha (L'1'));
  ASSERT (!iswalpha (L'2'));
  ASSERT (!iswalpha (L'3'));
  ASSERT (!iswalpha (L'4'));
  ASSERT (!iswalpha (L'5'));
  ASSERT (!iswalpha (L'6'));
  ASSERT (!iswalpha (L'7'));
  ASSERT (!iswalpha (L'8'));
  ASSERT (!iswalpha (L'9'));
  ASSERT (!iswalpha (L':'));
  ASSERT (!iswalpha (L';'));
  ASSERT (!iswalpha (L'<'));
  ASSERT (!iswalpha (L'='));
  ASSERT (!iswalpha (L'>'));
  ASSERT (!iswalpha (L'\?'));
  ASSERT (!iswalpha (L'@'));
  ASSERT (iswalpha (L'A'));
  ASSERT (iswalpha (L'B'));
  ASSERT (iswalpha (L'C'));
  ASSERT (iswalpha (L'D'));
  ASSERT (iswalpha (L'E'));
  ASSERT (iswalpha (L'F'));
  ASSERT (iswalpha (L'G'));
  ASSERT (iswalpha (L'H'));
  ASSERT (iswalpha (L'I'));
  ASSERT (iswalpha (L'J'));
  ASSERT (iswalpha (L'K'));
  ASSERT (iswalpha (L'L'));
  ASSERT (iswalpha (L'M'));
  ASSERT (iswalpha (L'N'));
  ASSERT (iswalpha (L'O'));
  ASSERT (iswalpha (L'P'));
  ASSERT (iswalpha (L'Q'));
  ASSERT (iswalpha (L'R'));
  ASSERT (iswalpha (L'S'));
  ASSERT (iswalpha (L'T'));
  ASSERT (iswalpha (L'U'));
  ASSERT (iswalpha (L'V'));
  ASSERT (iswalpha (L'W'));
  ASSERT (iswalpha (L'X'));
  ASSERT (iswalpha (L'Y'));
  ASSERT (iswalpha (L'Z'));
  ASSERT (!iswalpha (L'['));
  ASSERT (!iswalpha (L'\\'));
  ASSERT (!iswalpha (L']'));
  ASSERT (!iswalpha (L'^'));
  ASSERT (!iswalpha (L'_'));
  ASSERT (!iswalpha (L'`'));
  ASSERT (iswalpha (L'a'));
  ASSERT (iswalpha (L'b'));
  ASSERT (iswalpha (L'c'));
  ASSERT (iswalpha (L'd'));
  ASSERT (iswalpha (L'e'));
  ASSERT (iswalpha (L'f'));
  ASSERT (iswalpha (L'g'));
  ASSERT (iswalpha (L'h'));
  ASSERT (iswalpha (L'i'));
  ASSERT (iswalpha (L'j'));
  ASSERT (iswalpha (L'k'));
  ASSERT (iswalpha (L'l'));
  ASSERT (iswalpha (L'm'));
  ASSERT (iswalpha (L'n'));
  ASSERT (iswalpha (L'o'));
  ASSERT (iswalpha (L'p'));
  ASSERT (iswalpha (L'q'));
  ASSERT (iswalpha (L'r'));
  ASSERT (iswalpha (L's'));
  ASSERT (iswalpha (L't'));
  ASSERT (iswalpha (L'u'));
  ASSERT (iswalpha (L'v'));
  ASSERT (iswalpha (L'w'));
  ASSERT (iswalpha (L'x'));
  ASSERT (iswalpha (L'y'));
  ASSERT (iswalpha (L'z'));
  ASSERT (!iswalpha (L'{'));
  ASSERT (!iswalpha (L'|'));
  ASSERT (!iswalpha (L'}'));
  ASSERT (!iswalpha (L'~'));
  ASSERT (!iswalpha (127));
  return 0;
}
