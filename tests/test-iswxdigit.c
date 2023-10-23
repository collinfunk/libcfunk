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
  ASSERT (!iswxdigit (0x00));
  ASSERT (!iswxdigit (0x01));
  ASSERT (!iswxdigit (0x02));
  ASSERT (!iswxdigit (0x03));
  ASSERT (!iswxdigit (0x04));
  ASSERT (!iswxdigit (0x05));
  ASSERT (!iswxdigit (0x06));
  ASSERT (!iswxdigit (L'\a'));
  ASSERT (!iswxdigit (L'\b'));
  ASSERT (!iswxdigit (L'\t'));
  ASSERT (!iswxdigit (L'\n'));
  ASSERT (!iswxdigit (L'\v'));
  ASSERT (!iswxdigit (L'\f'));
  ASSERT (!iswxdigit (L'\r'));
  ASSERT (!iswxdigit (0x0e));
  ASSERT (!iswxdigit (0x0f));
  ASSERT (!iswxdigit (0x10));
  ASSERT (!iswxdigit (0x11));
  ASSERT (!iswxdigit (0x12));
  ASSERT (!iswxdigit (0x13));
  ASSERT (!iswxdigit (0x14));
  ASSERT (!iswxdigit (0x15));
  ASSERT (!iswxdigit (0x16));
  ASSERT (!iswxdigit (0x17));
  ASSERT (!iswxdigit (0x18));
  ASSERT (!iswxdigit (0x19));
  ASSERT (!iswxdigit (0x1a));
  ASSERT (!iswxdigit (0x1b));
  ASSERT (!iswxdigit (0x1c));
  ASSERT (!iswxdigit (0x1d));
  ASSERT (!iswxdigit (0x1e));
  ASSERT (!iswxdigit (0x1f));
  ASSERT (!iswxdigit (L' '));
  ASSERT (!iswxdigit (L'!'));
  ASSERT (!iswxdigit (L'\"'));
  ASSERT (!iswxdigit (L'#'));
  ASSERT (!iswxdigit (L'$'));
  ASSERT (!iswxdigit (L'%'));
  ASSERT (!iswxdigit (L'&'));
  ASSERT (!iswxdigit (L'\''));
  ASSERT (!iswxdigit (L'('));
  ASSERT (!iswxdigit (L')'));
  ASSERT (!iswxdigit (L'*'));
  ASSERT (!iswxdigit (L'+'));
  ASSERT (!iswxdigit (L','));
  ASSERT (!iswxdigit (L'-'));
  ASSERT (!iswxdigit (L'.'));
  ASSERT (!iswxdigit (L'/'));
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
  ASSERT (!iswxdigit (L':'));
  ASSERT (!iswxdigit (L';'));
  ASSERT (!iswxdigit (L'<'));
  ASSERT (!iswxdigit (L'='));
  ASSERT (!iswxdigit (L'>'));
  ASSERT (!iswxdigit (L'\?'));
  ASSERT (!iswxdigit (L'@'));
  ASSERT (iswxdigit (L'A'));
  ASSERT (iswxdigit (L'B'));
  ASSERT (iswxdigit (L'C'));
  ASSERT (iswxdigit (L'D'));
  ASSERT (iswxdigit (L'E'));
  ASSERT (iswxdigit (L'F'));
  ASSERT (!iswxdigit (L'G'));
  ASSERT (!iswxdigit (L'H'));
  ASSERT (!iswxdigit (L'I'));
  ASSERT (!iswxdigit (L'J'));
  ASSERT (!iswxdigit (L'K'));
  ASSERT (!iswxdigit (L'L'));
  ASSERT (!iswxdigit (L'M'));
  ASSERT (!iswxdigit (L'N'));
  ASSERT (!iswxdigit (L'O'));
  ASSERT (!iswxdigit (L'P'));
  ASSERT (!iswxdigit (L'Q'));
  ASSERT (!iswxdigit (L'R'));
  ASSERT (!iswxdigit (L'S'));
  ASSERT (!iswxdigit (L'T'));
  ASSERT (!iswxdigit (L'U'));
  ASSERT (!iswxdigit (L'V'));
  ASSERT (!iswxdigit (L'W'));
  ASSERT (!iswxdigit (L'X'));
  ASSERT (!iswxdigit (L'Y'));
  ASSERT (!iswxdigit (L'Z'));
  ASSERT (!iswxdigit (L'['));
  ASSERT (!iswxdigit (L'\\'));
  ASSERT (!iswxdigit (L']'));
  ASSERT (!iswxdigit (L'^'));
  ASSERT (!iswxdigit (L'_'));
  ASSERT (!iswxdigit (L'`'));
  ASSERT (iswxdigit (L'a'));
  ASSERT (iswxdigit (L'b'));
  ASSERT (iswxdigit (L'c'));
  ASSERT (iswxdigit (L'd'));
  ASSERT (iswxdigit (L'e'));
  ASSERT (iswxdigit (L'f'));
  ASSERT (!iswxdigit (L'g'));
  ASSERT (!iswxdigit (L'h'));
  ASSERT (!iswxdigit (L'i'));
  ASSERT (!iswxdigit (L'j'));
  ASSERT (!iswxdigit (L'k'));
  ASSERT (!iswxdigit (L'l'));
  ASSERT (!iswxdigit (L'm'));
  ASSERT (!iswxdigit (L'n'));
  ASSERT (!iswxdigit (L'o'));
  ASSERT (!iswxdigit (L'p'));
  ASSERT (!iswxdigit (L'q'));
  ASSERT (!iswxdigit (L'r'));
  ASSERT (!iswxdigit (L's'));
  ASSERT (!iswxdigit (L't'));
  ASSERT (!iswxdigit (L'u'));
  ASSERT (!iswxdigit (L'v'));
  ASSERT (!iswxdigit (L'w'));
  ASSERT (!iswxdigit (L'x'));
  ASSERT (!iswxdigit (L'y'));
  ASSERT (!iswxdigit (L'z'));
  ASSERT (!iswxdigit (L'{'));
  ASSERT (!iswxdigit (L'|'));
  ASSERT (!iswxdigit (L'}'));
  ASSERT (!iswxdigit (L'~'));
  ASSERT (!iswxdigit (127));
  return 0;
}
