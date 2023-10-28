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
  ASSERT (tolower (0x00) == 0x00);
  ASSERT (tolower (0x01) == 0x01);
  ASSERT (tolower (0x02) == 0x02);
  ASSERT (tolower (0x03) == 0x03);
  ASSERT (tolower (0x04) == 0x04);
  ASSERT (tolower (0x05) == 0x05);
  ASSERT (tolower (0x06) == 0x06);
  ASSERT (tolower ('\a') == '\a');
  ASSERT (tolower ('\b') == '\b');
  ASSERT (tolower ('\t') == '\t');
  ASSERT (tolower ('\n') == '\n');
  ASSERT (tolower ('\v') == '\v');
  ASSERT (tolower ('\f') == '\f');
  ASSERT (tolower ('\r') == '\r');
  ASSERT (tolower (0x0e) == 0x0e);
  ASSERT (tolower (0x0f) == 0x0f);
  ASSERT (tolower (0x10) == 0x10);
  ASSERT (tolower (0x11) == 0x11);
  ASSERT (tolower (0x12) == 0x12);
  ASSERT (tolower (0x13) == 0x13);
  ASSERT (tolower (0x14) == 0x14);
  ASSERT (tolower (0x15) == 0x15);
  ASSERT (tolower (0x16) == 0x16);
  ASSERT (tolower (0x17) == 0x17);
  ASSERT (tolower (0x18) == 0x18);
  ASSERT (tolower (0x19) == 0x19);
  ASSERT (tolower (0x1a) == 0x1a);
  ASSERT (tolower (0x1b) == 0x1b);
  ASSERT (tolower (0x1c) == 0x1c);
  ASSERT (tolower (0x1d) == 0x1d);
  ASSERT (tolower (0x1e) == 0x1e);
  ASSERT (tolower (0x1f) == 0x1f);
  ASSERT (tolower (' ') == ' ');
  ASSERT (tolower ('!') == '!');
  ASSERT (tolower ('\"') == '\"');
  ASSERT (tolower ('#') == '#');
  ASSERT (tolower ('$') == '$');
  ASSERT (tolower ('%') == '%');
  ASSERT (tolower ('&') == '&');
  ASSERT (tolower ('\'') == '\'');
  ASSERT (tolower ('(') == '(');
  ASSERT (tolower (')') == ')');
  ASSERT (tolower ('*') == '*');
  ASSERT (tolower ('+') == '+');
  ASSERT (tolower (',') == ',');
  ASSERT (tolower ('-') == '-');
  ASSERT (tolower ('.') == '.');
  ASSERT (tolower ('/') == '/');
  ASSERT (tolower ('0') == '0');
  ASSERT (tolower ('1') == '1');
  ASSERT (tolower ('2') == '2');
  ASSERT (tolower ('3') == '3');
  ASSERT (tolower ('4') == '4');
  ASSERT (tolower ('5') == '5');
  ASSERT (tolower ('6') == '6');
  ASSERT (tolower ('7') == '7');
  ASSERT (tolower ('8') == '8');
  ASSERT (tolower ('9') == '9');
  ASSERT (tolower (':') == ':');
  ASSERT (tolower (';') == ';');
  ASSERT (tolower ('<') == '<');
  ASSERT (tolower ('=') == '=');
  ASSERT (tolower ('>') == '>');
  ASSERT (tolower ('\?') == '\?');
  ASSERT (tolower ('@') == '@');
  ASSERT (tolower ('A') == 'a');
  ASSERT (tolower ('B') == 'b');
  ASSERT (tolower ('C') == 'c');
  ASSERT (tolower ('D') == 'd');
  ASSERT (tolower ('E') == 'e');
  ASSERT (tolower ('F') == 'f');
  ASSERT (tolower ('G') == 'g');
  ASSERT (tolower ('H') == 'h');
  ASSERT (tolower ('I') == 'i');
  ASSERT (tolower ('J') == 'j');
  ASSERT (tolower ('K') == 'k');
  ASSERT (tolower ('L') == 'l');
  ASSERT (tolower ('M') == 'm');
  ASSERT (tolower ('N') == 'n');
  ASSERT (tolower ('O') == 'o');
  ASSERT (tolower ('P') == 'p');
  ASSERT (tolower ('Q') == 'q');
  ASSERT (tolower ('R') == 'r');
  ASSERT (tolower ('S') == 's');
  ASSERT (tolower ('T') == 't');
  ASSERT (tolower ('U') == 'u');
  ASSERT (tolower ('V') == 'v');
  ASSERT (tolower ('W') == 'w');
  ASSERT (tolower ('X') == 'x');
  ASSERT (tolower ('Y') == 'y');
  ASSERT (tolower ('Z') == 'z');
  ASSERT (tolower ('[') == '[');
  ASSERT (tolower ('\\') == '\\');
  ASSERT (tolower (']') == ']');
  ASSERT (tolower ('^') == '^');
  ASSERT (tolower ('_') == '_');
  ASSERT (tolower ('`') == '`');
  ASSERT (tolower ('a') == 'a');
  ASSERT (tolower ('b') == 'b');
  ASSERT (tolower ('c') == 'c');
  ASSERT (tolower ('d') == 'd');
  ASSERT (tolower ('e') == 'e');
  ASSERT (tolower ('f') == 'f');
  ASSERT (tolower ('g') == 'g');
  ASSERT (tolower ('h') == 'h');
  ASSERT (tolower ('i') == 'i');
  ASSERT (tolower ('j') == 'j');
  ASSERT (tolower ('k') == 'k');
  ASSERT (tolower ('l') == 'l');
  ASSERT (tolower ('m') == 'm');
  ASSERT (tolower ('n') == 'n');
  ASSERT (tolower ('o') == 'o');
  ASSERT (tolower ('p') == 'p');
  ASSERT (tolower ('q') == 'q');
  ASSERT (tolower ('r') == 'r');
  ASSERT (tolower ('s') == 's');
  ASSERT (tolower ('t') == 't');
  ASSERT (tolower ('u') == 'u');
  ASSERT (tolower ('v') == 'v');
  ASSERT (tolower ('w') == 'w');
  ASSERT (tolower ('x') == 'x');
  ASSERT (tolower ('y') == 'y');
  ASSERT (tolower ('z') == 'z');
  ASSERT (tolower ('{') == '{');
  ASSERT (tolower ('|') == '|');
  ASSERT (tolower ('}') == '}');
  ASSERT (tolower ('~') == '~');
  ASSERT (tolower (127) == 127);

  /* This define is broken on MinGW. */
#if !HAVE_WINDOWS_H
  ASSERT (_tolower (0x00) == 0x00);
  ASSERT (_tolower (0x01) == 0x01);
  ASSERT (_tolower (0x02) == 0x02);
  ASSERT (_tolower (0x03) == 0x03);
  ASSERT (_tolower (0x04) == 0x04);
  ASSERT (_tolower (0x05) == 0x05);
  ASSERT (_tolower (0x06) == 0x06);
  ASSERT (_tolower ('\a') == '\a');
  ASSERT (_tolower ('\b') == '\b');
  ASSERT (_tolower ('\t') == '\t');
  ASSERT (_tolower ('\n') == '\n');
  ASSERT (_tolower ('\v') == '\v');
  ASSERT (_tolower ('\f') == '\f');
  ASSERT (_tolower ('\r') == '\r');
  ASSERT (_tolower (0x0e) == 0x0e);
  ASSERT (_tolower (0x0f) == 0x0f);
  ASSERT (_tolower (0x10) == 0x10);
  ASSERT (_tolower (0x11) == 0x11);
  ASSERT (_tolower (0x12) == 0x12);
  ASSERT (_tolower (0x13) == 0x13);
  ASSERT (_tolower (0x14) == 0x14);
  ASSERT (_tolower (0x15) == 0x15);
  ASSERT (_tolower (0x16) == 0x16);
  ASSERT (_tolower (0x17) == 0x17);
  ASSERT (_tolower (0x18) == 0x18);
  ASSERT (_tolower (0x19) == 0x19);
  ASSERT (_tolower (0x1a) == 0x1a);
  ASSERT (_tolower (0x1b) == 0x1b);
  ASSERT (_tolower (0x1c) == 0x1c);
  ASSERT (_tolower (0x1d) == 0x1d);
  ASSERT (_tolower (0x1e) == 0x1e);
  ASSERT (_tolower (0x1f) == 0x1f);
  ASSERT (_tolower (' ') == ' ');
  ASSERT (_tolower ('!') == '!');
  ASSERT (_tolower ('\"') == '\"');
  ASSERT (_tolower ('#') == '#');
  ASSERT (_tolower ('$') == '$');
  ASSERT (_tolower ('%') == '%');
  ASSERT (_tolower ('&') == '&');
  ASSERT (_tolower ('\'') == '\'');
  ASSERT (_tolower ('(') == '(');
  ASSERT (_tolower (')') == ')');
  ASSERT (_tolower ('*') == '*');
  ASSERT (_tolower ('+') == '+');
  ASSERT (_tolower (',') == ',');
  ASSERT (_tolower ('-') == '-');
  ASSERT (_tolower ('.') == '.');
  ASSERT (_tolower ('/') == '/');
  ASSERT (_tolower ('0') == '0');
  ASSERT (_tolower ('1') == '1');
  ASSERT (_tolower ('2') == '2');
  ASSERT (_tolower ('3') == '3');
  ASSERT (_tolower ('4') == '4');
  ASSERT (_tolower ('5') == '5');
  ASSERT (_tolower ('6') == '6');
  ASSERT (_tolower ('7') == '7');
  ASSERT (_tolower ('8') == '8');
  ASSERT (_tolower ('9') == '9');
  ASSERT (_tolower (':') == ':');
  ASSERT (_tolower (';') == ';');
  ASSERT (_tolower ('<') == '<');
  ASSERT (_tolower ('=') == '=');
  ASSERT (_tolower ('>') == '>');
  ASSERT (_tolower ('\?') == '\?');
  ASSERT (_tolower ('@') == '@');
  ASSERT (_tolower ('A') == 'a');
  ASSERT (_tolower ('B') == 'b');
  ASSERT (_tolower ('C') == 'c');
  ASSERT (_tolower ('D') == 'd');
  ASSERT (_tolower ('E') == 'e');
  ASSERT (_tolower ('F') == 'f');
  ASSERT (_tolower ('G') == 'g');
  ASSERT (_tolower ('H') == 'h');
  ASSERT (_tolower ('I') == 'i');
  ASSERT (_tolower ('J') == 'j');
  ASSERT (_tolower ('K') == 'k');
  ASSERT (_tolower ('L') == 'l');
  ASSERT (_tolower ('M') == 'm');
  ASSERT (_tolower ('N') == 'n');
  ASSERT (_tolower ('O') == 'o');
  ASSERT (_tolower ('P') == 'p');
  ASSERT (_tolower ('Q') == 'q');
  ASSERT (_tolower ('R') == 'r');
  ASSERT (_tolower ('S') == 's');
  ASSERT (_tolower ('T') == 't');
  ASSERT (_tolower ('U') == 'u');
  ASSERT (_tolower ('V') == 'v');
  ASSERT (_tolower ('W') == 'w');
  ASSERT (_tolower ('X') == 'x');
  ASSERT (_tolower ('Y') == 'y');
  ASSERT (_tolower ('Z') == 'z');
  ASSERT (_tolower ('[') == '[');
  ASSERT (_tolower ('\\') == '\\');
  ASSERT (_tolower (']') == ']');
  ASSERT (_tolower ('^') == '^');
  ASSERT (_tolower ('_') == '_');
  ASSERT (_tolower ('`') == '`');
  ASSERT (_tolower ('a') == 'a');
  ASSERT (_tolower ('b') == 'b');
  ASSERT (_tolower ('c') == 'c');
  ASSERT (_tolower ('d') == 'd');
  ASSERT (_tolower ('e') == 'e');
  ASSERT (_tolower ('f') == 'f');
  ASSERT (_tolower ('g') == 'g');
  ASSERT (_tolower ('h') == 'h');
  ASSERT (_tolower ('i') == 'i');
  ASSERT (_tolower ('j') == 'j');
  ASSERT (_tolower ('k') == 'k');
  ASSERT (_tolower ('l') == 'l');
  ASSERT (_tolower ('m') == 'm');
  ASSERT (_tolower ('n') == 'n');
  ASSERT (_tolower ('o') == 'o');
  ASSERT (_tolower ('p') == 'p');
  ASSERT (_tolower ('q') == 'q');
  ASSERT (_tolower ('r') == 'r');
  ASSERT (_tolower ('s') == 's');
  ASSERT (_tolower ('t') == 't');
  ASSERT (_tolower ('u') == 'u');
  ASSERT (_tolower ('v') == 'v');
  ASSERT (_tolower ('w') == 'w');
  ASSERT (_tolower ('x') == 'x');
  ASSERT (_tolower ('y') == 'y');
  ASSERT (_tolower ('z') == 'z');
  ASSERT (_tolower ('{') == '{');
  ASSERT (_tolower ('|') == '|');
  ASSERT (_tolower ('}') == '}');
  ASSERT (_tolower ('~') == '~');
  ASSERT (_tolower (127) == 127);
#endif

  return 0;
}
