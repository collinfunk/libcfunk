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
  ASSERT (!iswblank (0x00));
  ASSERT (!iswblank (0x01));
  ASSERT (!iswblank (0x02));
  ASSERT (!iswblank (0x03));
  ASSERT (!iswblank (0x04));
  ASSERT (!iswblank (0x05));
  ASSERT (!iswblank (0x06));
  ASSERT (!iswblank (L'\a'));
  ASSERT (!iswblank (L'\b'));
  ASSERT (iswblank (L'\t'));
  ASSERT (!iswblank (L'\n'));
  ASSERT (!iswblank (L'\v'));
  ASSERT (!iswblank (L'\f'));
  ASSERT (!iswblank (L'\r'));
  ASSERT (!iswblank (0x0e));
  ASSERT (!iswblank (0x0f));
  ASSERT (!iswblank (0x10));
  ASSERT (!iswblank (0x11));
  ASSERT (!iswblank (0x12));
  ASSERT (!iswblank (0x13));
  ASSERT (!iswblank (0x14));
  ASSERT (!iswblank (0x15));
  ASSERT (!iswblank (0x16));
  ASSERT (!iswblank (0x17));
  ASSERT (!iswblank (0x18));
  ASSERT (!iswblank (0x19));
  ASSERT (!iswblank (0x1a));
  ASSERT (!iswblank (0x1b));
  ASSERT (!iswblank (0x1c));
  ASSERT (!iswblank (0x1d));
  ASSERT (!iswblank (0x1e));
  ASSERT (!iswblank (0x1f));
  ASSERT (iswblank (L' '));
  ASSERT (!iswblank (L'!'));
  ASSERT (!iswblank (L'\"'));
  ASSERT (!iswblank (L'#'));
  ASSERT (!iswblank (L'$'));
  ASSERT (!iswblank (L'%'));
  ASSERT (!iswblank (L'&'));
  ASSERT (!iswblank (L'\''));
  ASSERT (!iswblank (L'('));
  ASSERT (!iswblank (L')'));
  ASSERT (!iswblank (L'*'));
  ASSERT (!iswblank (L'+'));
  ASSERT (!iswblank (L','));
  ASSERT (!iswblank (L'-'));
  ASSERT (!iswblank (L'.'));
  ASSERT (!iswblank (L'/'));
  ASSERT (!iswblank (L'0'));
  ASSERT (!iswblank (L'1'));
  ASSERT (!iswblank (L'2'));
  ASSERT (!iswblank (L'3'));
  ASSERT (!iswblank (L'4'));
  ASSERT (!iswblank (L'5'));
  ASSERT (!iswblank (L'6'));
  ASSERT (!iswblank (L'7'));
  ASSERT (!iswblank (L'8'));
  ASSERT (!iswblank (L'9'));
  ASSERT (!iswblank (L':'));
  ASSERT (!iswblank (L';'));
  ASSERT (!iswblank (L'<'));
  ASSERT (!iswblank (L'='));
  ASSERT (!iswblank (L'>'));
  ASSERT (!iswblank (L'\?'));
  ASSERT (!iswblank (L'@'));
  ASSERT (!iswblank (L'A'));
  ASSERT (!iswblank (L'B'));
  ASSERT (!iswblank (L'C'));
  ASSERT (!iswblank (L'D'));
  ASSERT (!iswblank (L'E'));
  ASSERT (!iswblank (L'F'));
  ASSERT (!iswblank (L'G'));
  ASSERT (!iswblank (L'H'));
  ASSERT (!iswblank (L'I'));
  ASSERT (!iswblank (L'J'));
  ASSERT (!iswblank (L'K'));
  ASSERT (!iswblank (L'L'));
  ASSERT (!iswblank (L'M'));
  ASSERT (!iswblank (L'N'));
  ASSERT (!iswblank (L'O'));
  ASSERT (!iswblank (L'P'));
  ASSERT (!iswblank (L'Q'));
  ASSERT (!iswblank (L'R'));
  ASSERT (!iswblank (L'S'));
  ASSERT (!iswblank (L'T'));
  ASSERT (!iswblank (L'U'));
  ASSERT (!iswblank (L'V'));
  ASSERT (!iswblank (L'W'));
  ASSERT (!iswblank (L'X'));
  ASSERT (!iswblank (L'Y'));
  ASSERT (!iswblank (L'Z'));
  ASSERT (!iswblank (L'['));
  ASSERT (!iswblank (L'\\'));
  ASSERT (!iswblank (L']'));
  ASSERT (!iswblank (L'^'));
  ASSERT (!iswblank (L'_'));
  ASSERT (!iswblank (L'`'));
  ASSERT (!iswblank (L'a'));
  ASSERT (!iswblank (L'b'));
  ASSERT (!iswblank (L'c'));
  ASSERT (!iswblank (L'd'));
  ASSERT (!iswblank (L'e'));
  ASSERT (!iswblank (L'f'));
  ASSERT (!iswblank (L'g'));
  ASSERT (!iswblank (L'h'));
  ASSERT (!iswblank (L'i'));
  ASSERT (!iswblank (L'j'));
  ASSERT (!iswblank (L'k'));
  ASSERT (!iswblank (L'l'));
  ASSERT (!iswblank (L'm'));
  ASSERT (!iswblank (L'n'));
  ASSERT (!iswblank (L'o'));
  ASSERT (!iswblank (L'p'));
  ASSERT (!iswblank (L'q'));
  ASSERT (!iswblank (L'r'));
  ASSERT (!iswblank (L's'));
  ASSERT (!iswblank (L't'));
  ASSERT (!iswblank (L'u'));
  ASSERT (!iswblank (L'v'));
  ASSERT (!iswblank (L'w'));
  ASSERT (!iswblank (L'x'));
  ASSERT (!iswblank (L'y'));
  ASSERT (!iswblank (L'z'));
  ASSERT (!iswblank (L'{'));
  ASSERT (!iswblank (L'|'));
  ASSERT (!iswblank (L'}'));
  ASSERT (!iswblank (L'~'));
  ASSERT (!iswblank (127));
  return 0;
}
