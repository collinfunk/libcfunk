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
  ASSERT (towlower (0x00) == 0x00);
  ASSERT (towlower (0x01) == 0x01);
  ASSERT (towlower (0x02) == 0x02);
  ASSERT (towlower (0x03) == 0x03);
  ASSERT (towlower (0x04) == 0x04);
  ASSERT (towlower (0x05) == 0x05);
  ASSERT (towlower (0x06) == 0x06);
  ASSERT (towlower (L'\a') == L'\a');
  ASSERT (towlower (L'\b') == L'\b');
  ASSERT (towlower (L'\t') == L'\t');
  ASSERT (towlower (L'\n') == L'\n');
  ASSERT (towlower (L'\v') == L'\v');
  ASSERT (towlower (L'\f') == L'\f');
  ASSERT (towlower (L'\r') == L'\r');
  ASSERT (towlower (0x0e) == 0x0e);
  ASSERT (towlower (0x0f) == 0x0f);
  ASSERT (towlower (0x10) == 0x10);
  ASSERT (towlower (0x11) == 0x11);
  ASSERT (towlower (0x12) == 0x12);
  ASSERT (towlower (0x13) == 0x13);
  ASSERT (towlower (0x14) == 0x14);
  ASSERT (towlower (0x15) == 0x15);
  ASSERT (towlower (0x16) == 0x16);
  ASSERT (towlower (0x17) == 0x17);
  ASSERT (towlower (0x18) == 0x18);
  ASSERT (towlower (0x19) == 0x19);
  ASSERT (towlower (0x1a) == 0x1a);
  ASSERT (towlower (0x1b) == 0x1b);
  ASSERT (towlower (0x1c) == 0x1c);
  ASSERT (towlower (0x1d) == 0x1d);
  ASSERT (towlower (0x1e) == 0x1e);
  ASSERT (towlower (0x1f) == 0x1f);
  ASSERT (towlower (L' ') == L' ');
  ASSERT (towlower (L'!') == L'!');
  ASSERT (towlower (L'\"') == L'\"');
  ASSERT (towlower (L'#') == L'#');
  ASSERT (towlower (L'$') == L'$');
  ASSERT (towlower (L'%') == L'%');
  ASSERT (towlower (L'&') == L'&');
  ASSERT (towlower (L'\'') == L'\'');
  ASSERT (towlower (L'(') == L'(');
  ASSERT (towlower (L')') == L')');
  ASSERT (towlower (L'*') == L'*');
  ASSERT (towlower (L'+') == L'+');
  ASSERT (towlower (L',') == L',');
  ASSERT (towlower (L'-') == L'-');
  ASSERT (towlower (L'.') == L'.');
  ASSERT (towlower (L'/') == L'/');
  ASSERT (towlower (L'0') == L'0');
  ASSERT (towlower (L'1') == L'1');
  ASSERT (towlower (L'2') == L'2');
  ASSERT (towlower (L'3') == L'3');
  ASSERT (towlower (L'4') == L'4');
  ASSERT (towlower (L'5') == L'5');
  ASSERT (towlower (L'6') == L'6');
  ASSERT (towlower (L'7') == L'7');
  ASSERT (towlower (L'8') == L'8');
  ASSERT (towlower (L'9') == L'9');
  ASSERT (towlower (L':') == L':');
  ASSERT (towlower (L';') == L';');
  ASSERT (towlower (L'<') == L'<');
  ASSERT (towlower (L'=') == L'=');
  ASSERT (towlower (L'>') == L'>');
  ASSERT (towlower (L'\?') == L'\?');
  ASSERT (towlower (L'@') == L'@');
  ASSERT (towlower (L'A') == L'a');
  ASSERT (towlower (L'B') == L'b');
  ASSERT (towlower (L'C') == L'c');
  ASSERT (towlower (L'D') == L'd');
  ASSERT (towlower (L'E') == L'e');
  ASSERT (towlower (L'F') == L'f');
  ASSERT (towlower (L'G') == L'g');
  ASSERT (towlower (L'H') == L'h');
  ASSERT (towlower (L'I') == L'i');
  ASSERT (towlower (L'J') == L'j');
  ASSERT (towlower (L'K') == L'k');
  ASSERT (towlower (L'L') == L'l');
  ASSERT (towlower (L'M') == L'm');
  ASSERT (towlower (L'N') == L'n');
  ASSERT (towlower (L'O') == L'o');
  ASSERT (towlower (L'P') == L'p');
  ASSERT (towlower (L'Q') == L'q');
  ASSERT (towlower (L'R') == L'r');
  ASSERT (towlower (L'S') == L's');
  ASSERT (towlower (L'T') == L't');
  ASSERT (towlower (L'U') == L'u');
  ASSERT (towlower (L'V') == L'v');
  ASSERT (towlower (L'W') == L'w');
  ASSERT (towlower (L'X') == L'x');
  ASSERT (towlower (L'Y') == L'y');
  ASSERT (towlower (L'Z') == L'z');
  ASSERT (towlower (L'[') == L'[');
  ASSERT (towlower (L'\\') == L'\\');
  ASSERT (towlower (L']') == L']');
  ASSERT (towlower (L'^') == L'^');
  ASSERT (towlower (L'_') == L'_');
  ASSERT (towlower (L'`') == L'`');
  ASSERT (towlower (L'a') == L'a');
  ASSERT (towlower (L'b') == L'b');
  ASSERT (towlower (L'c') == L'c');
  ASSERT (towlower (L'd') == L'd');
  ASSERT (towlower (L'e') == L'e');
  ASSERT (towlower (L'f') == L'f');
  ASSERT (towlower (L'g') == L'g');
  ASSERT (towlower (L'h') == L'h');
  ASSERT (towlower (L'i') == L'i');
  ASSERT (towlower (L'j') == L'j');
  ASSERT (towlower (L'k') == L'k');
  ASSERT (towlower (L'l') == L'l');
  ASSERT (towlower (L'm') == L'm');
  ASSERT (towlower (L'n') == L'n');
  ASSERT (towlower (L'o') == L'o');
  ASSERT (towlower (L'p') == L'p');
  ASSERT (towlower (L'q') == L'q');
  ASSERT (towlower (L'r') == L'r');
  ASSERT (towlower (L's') == L's');
  ASSERT (towlower (L't') == L't');
  ASSERT (towlower (L'u') == L'u');
  ASSERT (towlower (L'v') == L'v');
  ASSERT (towlower (L'w') == L'w');
  ASSERT (towlower (L'x') == L'x');
  ASSERT (towlower (L'y') == L'y');
  ASSERT (towlower (L'z') == L'z');
  ASSERT (towlower (L'{') == L'{');
  ASSERT (towlower (L'|') == L'|');
  ASSERT (towlower (L'}') == L'}');
  ASSERT (towlower (L'~') == L'~');
  ASSERT (towlower (127) == 127);

  return 0;
}
