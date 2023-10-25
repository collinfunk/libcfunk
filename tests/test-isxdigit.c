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
  ASSERT (!isxdigit (0x00));
  ASSERT (!isxdigit (0x01));
  ASSERT (!isxdigit (0x02));
  ASSERT (!isxdigit (0x03));
  ASSERT (!isxdigit (0x04));
  ASSERT (!isxdigit (0x05));
  ASSERT (!isxdigit (0x06));
  ASSERT (!isxdigit ('\a'));
  ASSERT (!isxdigit ('\b'));
  ASSERT (!isxdigit ('\t'));
  ASSERT (!isxdigit ('\n'));
  ASSERT (!isxdigit ('\v'));
  ASSERT (!isxdigit ('\f'));
  ASSERT (!isxdigit ('\r'));
  ASSERT (!isxdigit (0x0e));
  ASSERT (!isxdigit (0x0f));
  ASSERT (!isxdigit (0x10));
  ASSERT (!isxdigit (0x11));
  ASSERT (!isxdigit (0x12));
  ASSERT (!isxdigit (0x13));
  ASSERT (!isxdigit (0x14));
  ASSERT (!isxdigit (0x15));
  ASSERT (!isxdigit (0x16));
  ASSERT (!isxdigit (0x17));
  ASSERT (!isxdigit (0x18));
  ASSERT (!isxdigit (0x19));
  ASSERT (!isxdigit (0x1a));
  ASSERT (!isxdigit (0x1b));
  ASSERT (!isxdigit (0x1c));
  ASSERT (!isxdigit (0x1d));
  ASSERT (!isxdigit (0x1e));
  ASSERT (!isxdigit (0x1f));
  ASSERT (!isxdigit (' '));
  ASSERT (!isxdigit ('!'));
  ASSERT (!isxdigit ('\"'));
  ASSERT (!isxdigit ('#'));
  ASSERT (!isxdigit ('$'));
  ASSERT (!isxdigit ('%'));
  ASSERT (!isxdigit ('&'));
  ASSERT (!isxdigit ('\''));
  ASSERT (!isxdigit ('('));
  ASSERT (!isxdigit (')'));
  ASSERT (!isxdigit ('*'));
  ASSERT (!isxdigit ('+'));
  ASSERT (!isxdigit (','));
  ASSERT (!isxdigit ('-'));
  ASSERT (!isxdigit ('.'));
  ASSERT (!isxdigit ('/'));
  ASSERT (isxdigit ('0'));
  ASSERT (isxdigit ('1'));
  ASSERT (isxdigit ('2'));
  ASSERT (isxdigit ('3'));
  ASSERT (isxdigit ('4'));
  ASSERT (isxdigit ('5'));
  ASSERT (isxdigit ('6'));
  ASSERT (isxdigit ('7'));
  ASSERT (isxdigit ('8'));
  ASSERT (isxdigit ('9'));
  ASSERT (!isxdigit (':'));
  ASSERT (!isxdigit (';'));
  ASSERT (!isxdigit ('<'));
  ASSERT (!isxdigit ('='));
  ASSERT (!isxdigit ('>'));
  ASSERT (!isxdigit ('\?'));
  ASSERT (!isxdigit ('@'));
  ASSERT (isxdigit ('A'));
  ASSERT (isxdigit ('B'));
  ASSERT (isxdigit ('C'));
  ASSERT (isxdigit ('D'));
  ASSERT (isxdigit ('E'));
  ASSERT (isxdigit ('F'));
  ASSERT (!isxdigit ('G'));
  ASSERT (!isxdigit ('H'));
  ASSERT (!isxdigit ('I'));
  ASSERT (!isxdigit ('J'));
  ASSERT (!isxdigit ('K'));
  ASSERT (!isxdigit ('L'));
  ASSERT (!isxdigit ('M'));
  ASSERT (!isxdigit ('N'));
  ASSERT (!isxdigit ('O'));
  ASSERT (!isxdigit ('P'));
  ASSERT (!isxdigit ('Q'));
  ASSERT (!isxdigit ('R'));
  ASSERT (!isxdigit ('S'));
  ASSERT (!isxdigit ('T'));
  ASSERT (!isxdigit ('U'));
  ASSERT (!isxdigit ('V'));
  ASSERT (!isxdigit ('W'));
  ASSERT (!isxdigit ('X'));
  ASSERT (!isxdigit ('Y'));
  ASSERT (!isxdigit ('Z'));
  ASSERT (!isxdigit ('['));
  ASSERT (!isxdigit ('\\'));
  ASSERT (!isxdigit (']'));
  ASSERT (!isxdigit ('^'));
  ASSERT (!isxdigit ('_'));
  ASSERT (!isxdigit ('`'));
  ASSERT (isxdigit ('a'));
  ASSERT (isxdigit ('b'));
  ASSERT (isxdigit ('c'));
  ASSERT (isxdigit ('d'));
  ASSERT (isxdigit ('e'));
  ASSERT (isxdigit ('f'));
  ASSERT (!isxdigit ('g'));
  ASSERT (!isxdigit ('h'));
  ASSERT (!isxdigit ('i'));
  ASSERT (!isxdigit ('j'));
  ASSERT (!isxdigit ('k'));
  ASSERT (!isxdigit ('l'));
  ASSERT (!isxdigit ('m'));
  ASSERT (!isxdigit ('n'));
  ASSERT (!isxdigit ('o'));
  ASSERT (!isxdigit ('p'));
  ASSERT (!isxdigit ('q'));
  ASSERT (!isxdigit ('r'));
  ASSERT (!isxdigit ('s'));
  ASSERT (!isxdigit ('t'));
  ASSERT (!isxdigit ('u'));
  ASSERT (!isxdigit ('v'));
  ASSERT (!isxdigit ('w'));
  ASSERT (!isxdigit ('x'));
  ASSERT (!isxdigit ('y'));
  ASSERT (!isxdigit ('z'));
  ASSERT (!isxdigit ('{'));
  ASSERT (!isxdigit ('|'));
  ASSERT (!isxdigit ('}'));
  ASSERT (!isxdigit ('~'));
  ASSERT (!isxdigit (127));
  return 0;
}
