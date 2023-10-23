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
  ASSERT (!iswgraph (0x00));
  ASSERT (!iswgraph (0x01));
  ASSERT (!iswgraph (0x02));
  ASSERT (!iswgraph (0x03));
  ASSERT (!iswgraph (0x04));
  ASSERT (!iswgraph (0x05));
  ASSERT (!iswgraph (0x06));
  ASSERT (!iswgraph (L'\a'));
  ASSERT (!iswgraph (L'\b'));
  ASSERT (!iswgraph (L'\t'));
  ASSERT (!iswgraph (L'\n'));
  ASSERT (!iswgraph (L'\v'));
  ASSERT (!iswgraph (L'\f'));
  ASSERT (!iswgraph (L'\r'));
  ASSERT (!iswgraph (0x0e));
  ASSERT (!iswgraph (0x0f));
  ASSERT (!iswgraph (0x10));
  ASSERT (!iswgraph (0x11));
  ASSERT (!iswgraph (0x12));
  ASSERT (!iswgraph (0x13));
  ASSERT (!iswgraph (0x14));
  ASSERT (!iswgraph (0x15));
  ASSERT (!iswgraph (0x16));
  ASSERT (!iswgraph (0x17));
  ASSERT (!iswgraph (0x18));
  ASSERT (!iswgraph (0x19));
  ASSERT (!iswgraph (0x1a));
  ASSERT (!iswgraph (0x1b));
  ASSERT (!iswgraph (0x1c));
  ASSERT (!iswgraph (0x1d));
  ASSERT (!iswgraph (0x1e));
  ASSERT (!iswgraph (0x1f));
  ASSERT (!iswgraph (L' '));
  ASSERT (iswgraph (L'!'));
  ASSERT (iswgraph (L'\"'));
  ASSERT (iswgraph (L'#'));
  ASSERT (iswgraph (L'$'));
  ASSERT (iswgraph (L'%'));
  ASSERT (iswgraph (L'&'));
  ASSERT (iswgraph (L'\''));
  ASSERT (iswgraph (L'('));
  ASSERT (iswgraph (L')'));
  ASSERT (iswgraph (L'*'));
  ASSERT (iswgraph (L'+'));
  ASSERT (iswgraph (L','));
  ASSERT (iswgraph (L'-'));
  ASSERT (iswgraph (L'.'));
  ASSERT (iswgraph (L'/'));
  ASSERT (iswgraph (L'0'));
  ASSERT (iswgraph (L'1'));
  ASSERT (iswgraph (L'2'));
  ASSERT (iswgraph (L'3'));
  ASSERT (iswgraph (L'4'));
  ASSERT (iswgraph (L'5'));
  ASSERT (iswgraph (L'6'));
  ASSERT (iswgraph (L'7'));
  ASSERT (iswgraph (L'8'));
  ASSERT (iswgraph (L'9'));
  ASSERT (iswgraph (L':'));
  ASSERT (iswgraph (L';'));
  ASSERT (iswgraph (L'<'));
  ASSERT (iswgraph (L'='));
  ASSERT (iswgraph (L'>'));
  ASSERT (iswgraph (L'\?'));
  ASSERT (iswgraph (L'@'));
  ASSERT (iswgraph (L'A'));
  ASSERT (iswgraph (L'B'));
  ASSERT (iswgraph (L'C'));
  ASSERT (iswgraph (L'D'));
  ASSERT (iswgraph (L'E'));
  ASSERT (iswgraph (L'F'));
  ASSERT (iswgraph (L'G'));
  ASSERT (iswgraph (L'H'));
  ASSERT (iswgraph (L'I'));
  ASSERT (iswgraph (L'J'));
  ASSERT (iswgraph (L'K'));
  ASSERT (iswgraph (L'L'));
  ASSERT (iswgraph (L'M'));
  ASSERT (iswgraph (L'N'));
  ASSERT (iswgraph (L'O'));
  ASSERT (iswgraph (L'P'));
  ASSERT (iswgraph (L'Q'));
  ASSERT (iswgraph (L'R'));
  ASSERT (iswgraph (L'S'));
  ASSERT (iswgraph (L'T'));
  ASSERT (iswgraph (L'U'));
  ASSERT (iswgraph (L'V'));
  ASSERT (iswgraph (L'W'));
  ASSERT (iswgraph (L'X'));
  ASSERT (iswgraph (L'Y'));
  ASSERT (iswgraph (L'Z'));
  ASSERT (iswgraph (L'['));
  ASSERT (iswgraph (L'\\'));
  ASSERT (iswgraph (L']'));
  ASSERT (iswgraph (L'^'));
  ASSERT (iswgraph (L'_'));
  ASSERT (iswgraph (L'`'));
  ASSERT (iswgraph (L'a'));
  ASSERT (iswgraph (L'b'));
  ASSERT (iswgraph (L'c'));
  ASSERT (iswgraph (L'd'));
  ASSERT (iswgraph (L'e'));
  ASSERT (iswgraph (L'f'));
  ASSERT (iswgraph (L'g'));
  ASSERT (iswgraph (L'h'));
  ASSERT (iswgraph (L'i'));
  ASSERT (iswgraph (L'j'));
  ASSERT (iswgraph (L'k'));
  ASSERT (iswgraph (L'l'));
  ASSERT (iswgraph (L'm'));
  ASSERT (iswgraph (L'n'));
  ASSERT (iswgraph (L'o'));
  ASSERT (iswgraph (L'p'));
  ASSERT (iswgraph (L'q'));
  ASSERT (iswgraph (L'r'));
  ASSERT (iswgraph (L's'));
  ASSERT (iswgraph (L't'));
  ASSERT (iswgraph (L'u'));
  ASSERT (iswgraph (L'v'));
  ASSERT (iswgraph (L'w'));
  ASSERT (iswgraph (L'x'));
  ASSERT (iswgraph (L'y'));
  ASSERT (iswgraph (L'z'));
  ASSERT (iswgraph (L'{'));
  ASSERT (iswgraph (L'|'));
  ASSERT (iswgraph (L'}'));
  ASSERT (iswgraph (L'~'));
  ASSERT (!iswgraph (127));
  return 0;
}
