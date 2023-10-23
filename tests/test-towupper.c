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
  ASSERT (towupper (0x00) == 0x00);
  ASSERT (towupper (0x01) == 0x01);
  ASSERT (towupper (0x02) == 0x02);
  ASSERT (towupper (0x03) == 0x03);
  ASSERT (towupper (0x04) == 0x04);
  ASSERT (towupper (0x05) == 0x05);
  ASSERT (towupper (0x06) == 0x06);
  ASSERT (towupper (L'\a') == L'\a');
  ASSERT (towupper (L'\b') == L'\b');
  ASSERT (towupper (L'\t') == L'\t');
  ASSERT (towupper (L'\n') == L'\n');
  ASSERT (towupper (L'\v') == L'\v');
  ASSERT (towupper (L'\f') == L'\f');
  ASSERT (towupper (L'\r') == L'\r');
  ASSERT (towupper (0x0e) == 0x0e);
  ASSERT (towupper (0x0f) == 0x0f);
  ASSERT (towupper (0x10) == 0x10);
  ASSERT (towupper (0x11) == 0x11);
  ASSERT (towupper (0x12) == 0x12);
  ASSERT (towupper (0x13) == 0x13);
  ASSERT (towupper (0x14) == 0x14);
  ASSERT (towupper (0x15) == 0x15);
  ASSERT (towupper (0x16) == 0x16);
  ASSERT (towupper (0x17) == 0x17);
  ASSERT (towupper (0x18) == 0x18);
  ASSERT (towupper (0x19) == 0x19);
  ASSERT (towupper (0x1a) == 0x1a);
  ASSERT (towupper (0x1b) == 0x1b);
  ASSERT (towupper (0x1c) == 0x1c);
  ASSERT (towupper (0x1d) == 0x1d);
  ASSERT (towupper (0x1e) == 0x1e);
  ASSERT (towupper (0x1f) == 0x1f);
  ASSERT (towupper (L' ') == L' ');
  ASSERT (towupper (L'!') == L'!');
  ASSERT (towupper (L'\"') == L'\"');
  ASSERT (towupper (L'#') == L'#');
  ASSERT (towupper (L'$') == L'$');
  ASSERT (towupper (L'%') == L'%');
  ASSERT (towupper (L'&') == L'&');
  ASSERT (towupper (L'\'') == L'\'');
  ASSERT (towupper (L'(') == L'(');
  ASSERT (towupper (L')') == L')');
  ASSERT (towupper (L'*') == L'*');
  ASSERT (towupper (L'+') == L'+');
  ASSERT (towupper (L',') == L',');
  ASSERT (towupper (L'-') == L'-');
  ASSERT (towupper (L'.') == L'.');
  ASSERT (towupper (L'/') == L'/');
  ASSERT (towupper (L'0') == L'0');
  ASSERT (towupper (L'1') == L'1');
  ASSERT (towupper (L'2') == L'2');
  ASSERT (towupper (L'3') == L'3');
  ASSERT (towupper (L'4') == L'4');
  ASSERT (towupper (L'5') == L'5');
  ASSERT (towupper (L'6') == L'6');
  ASSERT (towupper (L'7') == L'7');
  ASSERT (towupper (L'8') == L'8');
  ASSERT (towupper (L'9') == L'9');
  ASSERT (towupper (L':') == L':');
  ASSERT (towupper (L';') == L';');
  ASSERT (towupper (L'<') == L'<');
  ASSERT (towupper (L'=') == L'=');
  ASSERT (towupper (L'>') == L'>');
  ASSERT (towupper (L'\?') == L'\?');
  ASSERT (towupper (L'@') == L'@');
  ASSERT (towupper (L'A') == L'A');
  ASSERT (towupper (L'B') == L'B');
  ASSERT (towupper (L'C') == L'C');
  ASSERT (towupper (L'D') == L'D');
  ASSERT (towupper (L'E') == L'E');
  ASSERT (towupper (L'F') == L'F');
  ASSERT (towupper (L'G') == L'G');
  ASSERT (towupper (L'H') == L'H');
  ASSERT (towupper (L'I') == L'I');
  ASSERT (towupper (L'J') == L'J');
  ASSERT (towupper (L'K') == L'K');
  ASSERT (towupper (L'L') == L'L');
  ASSERT (towupper (L'M') == L'M');
  ASSERT (towupper (L'N') == L'N');
  ASSERT (towupper (L'O') == L'O');
  ASSERT (towupper (L'P') == L'P');
  ASSERT (towupper (L'Q') == L'Q');
  ASSERT (towupper (L'R') == L'R');
  ASSERT (towupper (L'S') == L'S');
  ASSERT (towupper (L'T') == L'T');
  ASSERT (towupper (L'U') == L'U');
  ASSERT (towupper (L'V') == L'V');
  ASSERT (towupper (L'W') == L'W');
  ASSERT (towupper (L'X') == L'X');
  ASSERT (towupper (L'Y') == L'Y');
  ASSERT (towupper (L'Z') == L'Z');
  ASSERT (towupper (L'[') == L'[');
  ASSERT (towupper (L'\\') == L'\\');
  ASSERT (towupper (L']') == L']');
  ASSERT (towupper (L'^') == L'^');
  ASSERT (towupper (L'_') == L'_');
  ASSERT (towupper (L'`') == L'`');
  ASSERT (towupper (L'a') == L'A');
  ASSERT (towupper (L'b') == L'B');
  ASSERT (towupper (L'c') == L'C');
  ASSERT (towupper (L'd') == L'D');
  ASSERT (towupper (L'e') == L'E');
  ASSERT (towupper (L'f') == L'F');
  ASSERT (towupper (L'g') == L'G');
  ASSERT (towupper (L'h') == L'H');
  ASSERT (towupper (L'i') == L'I');
  ASSERT (towupper (L'j') == L'J');
  ASSERT (towupper (L'k') == L'K');
  ASSERT (towupper (L'l') == L'L');
  ASSERT (towupper (L'm') == L'M');
  ASSERT (towupper (L'n') == L'N');
  ASSERT (towupper (L'o') == L'O');
  ASSERT (towupper (L'p') == L'P');
  ASSERT (towupper (L'q') == L'Q');
  ASSERT (towupper (L'r') == L'R');
  ASSERT (towupper (L's') == L'S');
  ASSERT (towupper (L't') == L'T');
  ASSERT (towupper (L'u') == L'U');
  ASSERT (towupper (L'v') == L'V');
  ASSERT (towupper (L'w') == L'W');
  ASSERT (towupper (L'x') == L'X');
  ASSERT (towupper (L'y') == L'Y');
  ASSERT (towupper (L'z') == L'Z');
  ASSERT (towupper (L'{') == L'{');
  ASSERT (towupper (L'|') == L'|');
  ASSERT (towupper (L'}') == L'}');
  ASSERT (towupper (L'~') == L'~');
  ASSERT (towupper (127) == 127);

  return 0;
}
