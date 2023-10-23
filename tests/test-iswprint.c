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
  ASSERT (!iswprint (0x00));
  ASSERT (!iswprint (0x01));
  ASSERT (!iswprint (0x02));
  ASSERT (!iswprint (0x03));
  ASSERT (!iswprint (0x04));
  ASSERT (!iswprint (0x05));
  ASSERT (!iswprint (0x06));
  ASSERT (!iswprint (L'\a'));
  ASSERT (!iswprint (L'\b'));
  /* ? */
#if !HAVE_WINDOWS_H
  ASSERT (!iswprint (L'\t'));
#endif
  ASSERT (!iswprint (L'\n'));
  ASSERT (!iswprint (L'\v'));
  ASSERT (!iswprint (L'\f'));
  ASSERT (!iswprint (L'\r'));
  ASSERT (!iswprint (0x0e));
  ASSERT (!iswprint (0x0f));
  ASSERT (!iswprint (0x10));
  ASSERT (!iswprint (0x11));
  ASSERT (!iswprint (0x12));
  ASSERT (!iswprint (0x13));
  ASSERT (!iswprint (0x14));
  ASSERT (!iswprint (0x15));
  ASSERT (!iswprint (0x16));
  ASSERT (!iswprint (0x17));
  ASSERT (!iswprint (0x18));
  ASSERT (!iswprint (0x19));
  ASSERT (!iswprint (0x1a));
  ASSERT (!iswprint (0x1b));
  ASSERT (!iswprint (0x1c));
  ASSERT (!iswprint (0x1d));
  ASSERT (!iswprint (0x1e));
  ASSERT (!iswprint (0x1f));
  ASSERT (iswprint (L' '));
  ASSERT (iswprint (L'!'));
  ASSERT (iswprint (L'\"'));
  ASSERT (iswprint (L'#'));
  ASSERT (iswprint (L'$'));
  ASSERT (iswprint (L'%'));
  ASSERT (iswprint (L'&'));
  ASSERT (iswprint (L'\''));
  ASSERT (iswprint (L'('));
  ASSERT (iswprint (L')'));
  ASSERT (iswprint (L'*'));
  ASSERT (iswprint (L'+'));
  ASSERT (iswprint (L','));
  ASSERT (iswprint (L'-'));
  ASSERT (iswprint (L'.'));
  ASSERT (iswprint (L'/'));
  ASSERT (iswprint (L'0'));
  ASSERT (iswprint (L'1'));
  ASSERT (iswprint (L'2'));
  ASSERT (iswprint (L'3'));
  ASSERT (iswprint (L'4'));
  ASSERT (iswprint (L'5'));
  ASSERT (iswprint (L'6'));
  ASSERT (iswprint (L'7'));
  ASSERT (iswprint (L'8'));
  ASSERT (iswprint (L'9'));
  ASSERT (iswprint (L':'));
  ASSERT (iswprint (L';'));
  ASSERT (iswprint (L'<'));
  ASSERT (iswprint (L'='));
  ASSERT (iswprint (L'>'));
  ASSERT (iswprint (L'\?'));
  ASSERT (iswprint (L'@'));
  ASSERT (iswprint (L'A'));
  ASSERT (iswprint (L'B'));
  ASSERT (iswprint (L'C'));
  ASSERT (iswprint (L'D'));
  ASSERT (iswprint (L'E'));
  ASSERT (iswprint (L'F'));
  ASSERT (iswprint (L'G'));
  ASSERT (iswprint (L'H'));
  ASSERT (iswprint (L'I'));
  ASSERT (iswprint (L'J'));
  ASSERT (iswprint (L'K'));
  ASSERT (iswprint (L'L'));
  ASSERT (iswprint (L'M'));
  ASSERT (iswprint (L'N'));
  ASSERT (iswprint (L'O'));
  ASSERT (iswprint (L'P'));
  ASSERT (iswprint (L'Q'));
  ASSERT (iswprint (L'R'));
  ASSERT (iswprint (L'S'));
  ASSERT (iswprint (L'T'));
  ASSERT (iswprint (L'U'));
  ASSERT (iswprint (L'V'));
  ASSERT (iswprint (L'W'));
  ASSERT (iswprint (L'X'));
  ASSERT (iswprint (L'Y'));
  ASSERT (iswprint (L'Z'));
  ASSERT (iswprint (L'['));
  ASSERT (iswprint (L'\\'));
  ASSERT (iswprint (L']'));
  ASSERT (iswprint (L'^'));
  ASSERT (iswprint (L'_'));
  ASSERT (iswprint (L'`'));
  ASSERT (iswprint (L'a'));
  ASSERT (iswprint (L'b'));
  ASSERT (iswprint (L'c'));
  ASSERT (iswprint (L'd'));
  ASSERT (iswprint (L'e'));
  ASSERT (iswprint (L'f'));
  ASSERT (iswprint (L'g'));
  ASSERT (iswprint (L'h'));
  ASSERT (iswprint (L'i'));
  ASSERT (iswprint (L'j'));
  ASSERT (iswprint (L'k'));
  ASSERT (iswprint (L'l'));
  ASSERT (iswprint (L'm'));
  ASSERT (iswprint (L'n'));
  ASSERT (iswprint (L'o'));
  ASSERT (iswprint (L'p'));
  ASSERT (iswprint (L'q'));
  ASSERT (iswprint (L'r'));
  ASSERT (iswprint (L's'));
  ASSERT (iswprint (L't'));
  ASSERT (iswprint (L'u'));
  ASSERT (iswprint (L'v'));
  ASSERT (iswprint (L'w'));
  ASSERT (iswprint (L'x'));
  ASSERT (iswprint (L'y'));
  ASSERT (iswprint (L'z'));
  ASSERT (iswprint (L'{'));
  ASSERT (iswprint (L'|'));
  ASSERT (iswprint (L'}'));
  ASSERT (iswprint (L'~'));
  ASSERT (!iswprint (127));
  return 0;
}
