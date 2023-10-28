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

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

int
main (void)
{
  ASSERT (toupper (0x00) == 0x00);
  ASSERT (toupper (0x01) == 0x01);
  ASSERT (toupper (0x02) == 0x02);
  ASSERT (toupper (0x03) == 0x03);
  ASSERT (toupper (0x04) == 0x04);
  ASSERT (toupper (0x05) == 0x05);
  ASSERT (toupper (0x06) == 0x06);
  ASSERT (toupper ('\a') == '\a');
  ASSERT (toupper ('\b') == '\b');
  ASSERT (toupper ('\t') == '\t');
  ASSERT (toupper ('\n') == '\n');
  ASSERT (toupper ('\v') == '\v');
  ASSERT (toupper ('\f') == '\f');
  ASSERT (toupper ('\r') == '\r');
  ASSERT (toupper (0x0e) == 0x0e);
  ASSERT (toupper (0x0f) == 0x0f);
  ASSERT (toupper (0x10) == 0x10);
  ASSERT (toupper (0x11) == 0x11);
  ASSERT (toupper (0x12) == 0x12);
  ASSERT (toupper (0x13) == 0x13);
  ASSERT (toupper (0x14) == 0x14);
  ASSERT (toupper (0x15) == 0x15);
  ASSERT (toupper (0x16) == 0x16);
  ASSERT (toupper (0x17) == 0x17);
  ASSERT (toupper (0x18) == 0x18);
  ASSERT (toupper (0x19) == 0x19);
  ASSERT (toupper (0x1a) == 0x1a);
  ASSERT (toupper (0x1b) == 0x1b);
  ASSERT (toupper (0x1c) == 0x1c);
  ASSERT (toupper (0x1d) == 0x1d);
  ASSERT (toupper (0x1e) == 0x1e);
  ASSERT (toupper (0x1f) == 0x1f);
  ASSERT (toupper (' ') == ' ');
  ASSERT (toupper ('!') == '!');
  ASSERT (toupper ('\"') == '\"');
  ASSERT (toupper ('#') == '#');
  ASSERT (toupper ('$') == '$');
  ASSERT (toupper ('%') == '%');
  ASSERT (toupper ('&') == '&');
  ASSERT (toupper ('\'') == '\'');
  ASSERT (toupper ('(') == '(');
  ASSERT (toupper (')') == ')');
  ASSERT (toupper ('*') == '*');
  ASSERT (toupper ('+') == '+');
  ASSERT (toupper (',') == ',');
  ASSERT (toupper ('-') == '-');
  ASSERT (toupper ('.') == '.');
  ASSERT (toupper ('/') == '/');
  ASSERT (toupper ('0') == '0');
  ASSERT (toupper ('1') == '1');
  ASSERT (toupper ('2') == '2');
  ASSERT (toupper ('3') == '3');
  ASSERT (toupper ('4') == '4');
  ASSERT (toupper ('5') == '5');
  ASSERT (toupper ('6') == '6');
  ASSERT (toupper ('7') == '7');
  ASSERT (toupper ('8') == '8');
  ASSERT (toupper ('9') == '9');
  ASSERT (toupper (':') == ':');
  ASSERT (toupper (';') == ';');
  ASSERT (toupper ('<') == '<');
  ASSERT (toupper ('=') == '=');
  ASSERT (toupper ('>') == '>');
  ASSERT (toupper ('\?') == '\?');
  ASSERT (toupper ('@') == '@');
  ASSERT (toupper ('A') == 'A');
  ASSERT (toupper ('B') == 'B');
  ASSERT (toupper ('C') == 'C');
  ASSERT (toupper ('D') == 'D');
  ASSERT (toupper ('E') == 'E');
  ASSERT (toupper ('F') == 'F');
  ASSERT (toupper ('G') == 'G');
  ASSERT (toupper ('H') == 'H');
  ASSERT (toupper ('I') == 'I');
  ASSERT (toupper ('J') == 'J');
  ASSERT (toupper ('K') == 'K');
  ASSERT (toupper ('L') == 'L');
  ASSERT (toupper ('M') == 'M');
  ASSERT (toupper ('N') == 'N');
  ASSERT (toupper ('O') == 'O');
  ASSERT (toupper ('P') == 'P');
  ASSERT (toupper ('Q') == 'Q');
  ASSERT (toupper ('R') == 'R');
  ASSERT (toupper ('S') == 'S');
  ASSERT (toupper ('T') == 'T');
  ASSERT (toupper ('U') == 'U');
  ASSERT (toupper ('V') == 'V');
  ASSERT (toupper ('W') == 'W');
  ASSERT (toupper ('X') == 'X');
  ASSERT (toupper ('Y') == 'Y');
  ASSERT (toupper ('Z') == 'Z');
  ASSERT (toupper ('[') == '[');
  ASSERT (toupper ('\\') == '\\');
  ASSERT (toupper (']') == ']');
  ASSERT (toupper ('^') == '^');
  ASSERT (toupper ('_') == '_');
  ASSERT (toupper ('`') == '`');
  ASSERT (toupper ('a') == 'A');
  ASSERT (toupper ('b') == 'B');
  ASSERT (toupper ('c') == 'C');
  ASSERT (toupper ('d') == 'D');
  ASSERT (toupper ('e') == 'E');
  ASSERT (toupper ('f') == 'F');
  ASSERT (toupper ('g') == 'G');
  ASSERT (toupper ('h') == 'H');
  ASSERT (toupper ('i') == 'I');
  ASSERT (toupper ('j') == 'J');
  ASSERT (toupper ('k') == 'K');
  ASSERT (toupper ('l') == 'L');
  ASSERT (toupper ('m') == 'M');
  ASSERT (toupper ('n') == 'N');
  ASSERT (toupper ('o') == 'O');
  ASSERT (toupper ('p') == 'P');
  ASSERT (toupper ('q') == 'Q');
  ASSERT (toupper ('r') == 'R');
  ASSERT (toupper ('s') == 'S');
  ASSERT (toupper ('t') == 'T');
  ASSERT (toupper ('u') == 'U');
  ASSERT (toupper ('v') == 'V');
  ASSERT (toupper ('w') == 'W');
  ASSERT (toupper ('x') == 'X');
  ASSERT (toupper ('y') == 'Y');
  ASSERT (toupper ('z') == 'Z');
  ASSERT (toupper ('{') == '{');
  ASSERT (toupper ('|') == '|');
  ASSERT (toupper ('}') == '}');
  ASSERT (toupper ('~') == '~');
  ASSERT (toupper (127) == 127);

  /* This define is broken on MinGW. */
#if !HAVE_WINDOWS_H
  ASSERT (_toupper (0x00) == 0x00);
  ASSERT (_toupper (0x01) == 0x01);
  ASSERT (_toupper (0x02) == 0x02);
  ASSERT (_toupper (0x03) == 0x03);
  ASSERT (_toupper (0x04) == 0x04);
  ASSERT (_toupper (0x05) == 0x05);
  ASSERT (_toupper (0x06) == 0x06);
  ASSERT (_toupper ('\a') == '\a');
  ASSERT (_toupper ('\b') == '\b');
  ASSERT (_toupper ('\t') == '\t');
  ASSERT (_toupper ('\n') == '\n');
  ASSERT (_toupper ('\v') == '\v');
  ASSERT (_toupper ('\f') == '\f');
  ASSERT (_toupper ('\r') == '\r');
  ASSERT (_toupper (0x0e) == 0x0e);
  ASSERT (_toupper (0x0f) == 0x0f);
  ASSERT (_toupper (0x10) == 0x10);
  ASSERT (_toupper (0x11) == 0x11);
  ASSERT (_toupper (0x12) == 0x12);
  ASSERT (_toupper (0x13) == 0x13);
  ASSERT (_toupper (0x14) == 0x14);
  ASSERT (_toupper (0x15) == 0x15);
  ASSERT (_toupper (0x16) == 0x16);
  ASSERT (_toupper (0x17) == 0x17);
  ASSERT (_toupper (0x18) == 0x18);
  ASSERT (_toupper (0x19) == 0x19);
  ASSERT (_toupper (0x1a) == 0x1a);
  ASSERT (_toupper (0x1b) == 0x1b);
  ASSERT (_toupper (0x1c) == 0x1c);
  ASSERT (_toupper (0x1d) == 0x1d);
  ASSERT (_toupper (0x1e) == 0x1e);
  ASSERT (_toupper (0x1f) == 0x1f);
  ASSERT (_toupper (' ') == ' ');
  ASSERT (_toupper ('!') == '!');
  ASSERT (_toupper ('\"') == '\"');
  ASSERT (_toupper ('#') == '#');
  ASSERT (_toupper ('$') == '$');
  ASSERT (_toupper ('%') == '%');
  ASSERT (_toupper ('&') == '&');
  ASSERT (_toupper ('\'') == '\'');
  ASSERT (_toupper ('(') == '(');
  ASSERT (_toupper (')') == ')');
  ASSERT (_toupper ('*') == '*');
  ASSERT (_toupper ('+') == '+');
  ASSERT (_toupper (',') == ',');
  ASSERT (_toupper ('-') == '-');
  ASSERT (_toupper ('.') == '.');
  ASSERT (_toupper ('/') == '/');
  ASSERT (_toupper ('0') == '0');
  ASSERT (_toupper ('1') == '1');
  ASSERT (_toupper ('2') == '2');
  ASSERT (_toupper ('3') == '3');
  ASSERT (_toupper ('4') == '4');
  ASSERT (_toupper ('5') == '5');
  ASSERT (_toupper ('6') == '6');
  ASSERT (_toupper ('7') == '7');
  ASSERT (_toupper ('8') == '8');
  ASSERT (_toupper ('9') == '9');
  ASSERT (_toupper (':') == ':');
  ASSERT (_toupper (';') == ';');
  ASSERT (_toupper ('<') == '<');
  ASSERT (_toupper ('=') == '=');
  ASSERT (_toupper ('>') == '>');
  ASSERT (_toupper ('\?') == '\?');
  ASSERT (_toupper ('@') == '@');
  ASSERT (_toupper ('A') == 'A');
  ASSERT (_toupper ('B') == 'B');
  ASSERT (_toupper ('C') == 'C');
  ASSERT (_toupper ('D') == 'D');
  ASSERT (_toupper ('E') == 'E');
  ASSERT (_toupper ('F') == 'F');
  ASSERT (_toupper ('G') == 'G');
  ASSERT (_toupper ('H') == 'H');
  ASSERT (_toupper ('I') == 'I');
  ASSERT (_toupper ('J') == 'J');
  ASSERT (_toupper ('K') == 'K');
  ASSERT (_toupper ('L') == 'L');
  ASSERT (_toupper ('M') == 'M');
  ASSERT (_toupper ('N') == 'N');
  ASSERT (_toupper ('O') == 'O');
  ASSERT (_toupper ('P') == 'P');
  ASSERT (_toupper ('Q') == 'Q');
  ASSERT (_toupper ('R') == 'R');
  ASSERT (_toupper ('S') == 'S');
  ASSERT (_toupper ('T') == 'T');
  ASSERT (_toupper ('U') == 'U');
  ASSERT (_toupper ('V') == 'V');
  ASSERT (_toupper ('W') == 'W');
  ASSERT (_toupper ('X') == 'X');
  ASSERT (_toupper ('Y') == 'Y');
  ASSERT (_toupper ('Z') == 'Z');
  ASSERT (_toupper ('[') == '[');
  ASSERT (_toupper ('\\') == '\\');
  ASSERT (_toupper (']') == ']');
  ASSERT (_toupper ('^') == '^');
  ASSERT (_toupper ('_') == '_');
  ASSERT (_toupper ('`') == '`');
  ASSERT (_toupper ('a') == 'A');
  ASSERT (_toupper ('b') == 'B');
  ASSERT (_toupper ('c') == 'C');
  ASSERT (_toupper ('d') == 'D');
  ASSERT (_toupper ('e') == 'E');
  ASSERT (_toupper ('f') == 'F');
  ASSERT (_toupper ('g') == 'G');
  ASSERT (_toupper ('h') == 'H');
  ASSERT (_toupper ('i') == 'I');
  ASSERT (_toupper ('j') == 'J');
  ASSERT (_toupper ('k') == 'K');
  ASSERT (_toupper ('l') == 'L');
  ASSERT (_toupper ('m') == 'M');
  ASSERT (_toupper ('n') == 'N');
  ASSERT (_toupper ('o') == 'O');
  ASSERT (_toupper ('p') == 'P');
  ASSERT (_toupper ('q') == 'Q');
  ASSERT (_toupper ('r') == 'R');
  ASSERT (_toupper ('s') == 'S');
  ASSERT (_toupper ('t') == 'T');
  ASSERT (_toupper ('u') == 'U');
  ASSERT (_toupper ('v') == 'V');
  ASSERT (_toupper ('w') == 'W');
  ASSERT (_toupper ('x') == 'X');
  ASSERT (_toupper ('y') == 'Y');
  ASSERT (_toupper ('z') == 'Z');
  ASSERT (_toupper ('{') == '{');
  ASSERT (_toupper ('|') == '|');
  ASSERT (_toupper ('}') == '}');
  ASSERT (_toupper ('~') == '~');
  ASSERT (_toupper (127) == 127);
#endif

  return 0;
}
