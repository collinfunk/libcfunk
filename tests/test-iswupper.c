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
  ASSERT (!iswupper (0x00));
  ASSERT (!iswupper (0x01));
  ASSERT (!iswupper (0x02));
  ASSERT (!iswupper (0x03));
  ASSERT (!iswupper (0x04));
  ASSERT (!iswupper (0x05));
  ASSERT (!iswupper (0x06));
  ASSERT (!iswupper (L'\a'));
  ASSERT (!iswupper (L'\b'));
  ASSERT (!iswupper (L'\t'));
  ASSERT (!iswupper (L'\n'));
  ASSERT (!iswupper (L'\v'));
  ASSERT (!iswupper (L'\f'));
  ASSERT (!iswupper (L'\r'));
  ASSERT (!iswupper (0x0e));
  ASSERT (!iswupper (0x0f));
  ASSERT (!iswupper (0x10));
  ASSERT (!iswupper (0x11));
  ASSERT (!iswupper (0x12));
  ASSERT (!iswupper (0x13));
  ASSERT (!iswupper (0x14));
  ASSERT (!iswupper (0x15));
  ASSERT (!iswupper (0x16));
  ASSERT (!iswupper (0x17));
  ASSERT (!iswupper (0x18));
  ASSERT (!iswupper (0x19));
  ASSERT (!iswupper (0x1a));
  ASSERT (!iswupper (0x1b));
  ASSERT (!iswupper (0x1c));
  ASSERT (!iswupper (0x1d));
  ASSERT (!iswupper (0x1e));
  ASSERT (!iswupper (0x1f));
  ASSERT (!iswupper (L' '));
  ASSERT (!iswupper (L'!'));
  ASSERT (!iswupper (L'\"'));
  ASSERT (!iswupper (L'#'));
  ASSERT (!iswupper (L'$'));
  ASSERT (!iswupper (L'%'));
  ASSERT (!iswupper (L'&'));
  ASSERT (!iswupper (L'\''));
  ASSERT (!iswupper (L'('));
  ASSERT (!iswupper (L')'));
  ASSERT (!iswupper (L'*'));
  ASSERT (!iswupper (L'+'));
  ASSERT (!iswupper (L','));
  ASSERT (!iswupper (L'-'));
  ASSERT (!iswupper (L'.'));
  ASSERT (!iswupper (L'/'));
  ASSERT (!iswupper (L'0'));
  ASSERT (!iswupper (L'1'));
  ASSERT (!iswupper (L'2'));
  ASSERT (!iswupper (L'3'));
  ASSERT (!iswupper (L'4'));
  ASSERT (!iswupper (L'5'));
  ASSERT (!iswupper (L'6'));
  ASSERT (!iswupper (L'7'));
  ASSERT (!iswupper (L'8'));
  ASSERT (!iswupper (L'9'));
  ASSERT (!iswupper (L':'));
  ASSERT (!iswupper (L';'));
  ASSERT (!iswupper (L'<'));
  ASSERT (!iswupper (L'='));
  ASSERT (!iswupper (L'>'));
  ASSERT (!iswupper (L'\?'));
  ASSERT (!iswupper (L'@'));
  ASSERT (iswupper (L'A'));
  ASSERT (iswupper (L'B'));
  ASSERT (iswupper (L'C'));
  ASSERT (iswupper (L'D'));
  ASSERT (iswupper (L'E'));
  ASSERT (iswupper (L'F'));
  ASSERT (iswupper (L'G'));
  ASSERT (iswupper (L'H'));
  ASSERT (iswupper (L'I'));
  ASSERT (iswupper (L'J'));
  ASSERT (iswupper (L'K'));
  ASSERT (iswupper (L'L'));
  ASSERT (iswupper (L'M'));
  ASSERT (iswupper (L'N'));
  ASSERT (iswupper (L'O'));
  ASSERT (iswupper (L'P'));
  ASSERT (iswupper (L'Q'));
  ASSERT (iswupper (L'R'));
  ASSERT (iswupper (L'S'));
  ASSERT (iswupper (L'T'));
  ASSERT (iswupper (L'U'));
  ASSERT (iswupper (L'V'));
  ASSERT (iswupper (L'W'));
  ASSERT (iswupper (L'X'));
  ASSERT (iswupper (L'Y'));
  ASSERT (iswupper (L'Z'));
  ASSERT (!iswupper (L'['));
  ASSERT (!iswupper (L'\\'));
  ASSERT (!iswupper (L']'));
  ASSERT (!iswupper (L'^'));
  ASSERT (!iswupper (L'_'));
  ASSERT (!iswupper (L'`'));
  ASSERT (!iswupper (L'a'));
  ASSERT (!iswupper (L'b'));
  ASSERT (!iswupper (L'c'));
  ASSERT (!iswupper (L'd'));
  ASSERT (!iswupper (L'e'));
  ASSERT (!iswupper (L'f'));
  ASSERT (!iswupper (L'g'));
  ASSERT (!iswupper (L'h'));
  ASSERT (!iswupper (L'i'));
  ASSERT (!iswupper (L'j'));
  ASSERT (!iswupper (L'k'));
  ASSERT (!iswupper (L'l'));
  ASSERT (!iswupper (L'm'));
  ASSERT (!iswupper (L'n'));
  ASSERT (!iswupper (L'o'));
  ASSERT (!iswupper (L'p'));
  ASSERT (!iswupper (L'q'));
  ASSERT (!iswupper (L'r'));
  ASSERT (!iswupper (L's'));
  ASSERT (!iswupper (L't'));
  ASSERT (!iswupper (L'u'));
  ASSERT (!iswupper (L'v'));
  ASSERT (!iswupper (L'w'));
  ASSERT (!iswupper (L'x'));
  ASSERT (!iswupper (L'y'));
  ASSERT (!iswupper (L'z'));
  ASSERT (!iswupper (L'{'));
  ASSERT (!iswupper (L'|'));
  ASSERT (!iswupper (L'}'));
  ASSERT (!iswupper (L'~'));
  ASSERT (!iswupper (127));
  return 0;
}
