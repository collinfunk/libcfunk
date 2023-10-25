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
  ASSERT (!isdigit (0x00));
  ASSERT (!isdigit (0x01));
  ASSERT (!isdigit (0x02));
  ASSERT (!isdigit (0x03));
  ASSERT (!isdigit (0x04));
  ASSERT (!isdigit (0x05));
  ASSERT (!isdigit (0x06));
  ASSERT (!isdigit ('\a'));
  ASSERT (!isdigit ('\b'));
  ASSERT (!isdigit ('\t'));
  ASSERT (!isdigit ('\n'));
  ASSERT (!isdigit ('\v'));
  ASSERT (!isdigit ('\f'));
  ASSERT (!isdigit ('\r'));
  ASSERT (!isdigit (0x0e));
  ASSERT (!isdigit (0x0f));
  ASSERT (!isdigit (0x10));
  ASSERT (!isdigit (0x11));
  ASSERT (!isdigit (0x12));
  ASSERT (!isdigit (0x13));
  ASSERT (!isdigit (0x14));
  ASSERT (!isdigit (0x15));
  ASSERT (!isdigit (0x16));
  ASSERT (!isdigit (0x17));
  ASSERT (!isdigit (0x18));
  ASSERT (!isdigit (0x19));
  ASSERT (!isdigit (0x1a));
  ASSERT (!isdigit (0x1b));
  ASSERT (!isdigit (0x1c));
  ASSERT (!isdigit (0x1d));
  ASSERT (!isdigit (0x1e));
  ASSERT (!isdigit (0x1f));
  ASSERT (!isdigit (' '));
  ASSERT (!isdigit ('!'));
  ASSERT (!isdigit ('\"'));
  ASSERT (!isdigit ('#'));
  ASSERT (!isdigit ('$'));
  ASSERT (!isdigit ('%'));
  ASSERT (!isdigit ('&'));
  ASSERT (!isdigit ('\''));
  ASSERT (!isdigit ('('));
  ASSERT (!isdigit (')'));
  ASSERT (!isdigit ('*'));
  ASSERT (!isdigit ('+'));
  ASSERT (!isdigit (','));
  ASSERT (!isdigit ('-'));
  ASSERT (!isdigit ('.'));
  ASSERT (!isdigit ('/'));
  ASSERT (isdigit ('0'));
  ASSERT (isdigit ('1'));
  ASSERT (isdigit ('2'));
  ASSERT (isdigit ('3'));
  ASSERT (isdigit ('4'));
  ASSERT (isdigit ('5'));
  ASSERT (isdigit ('6'));
  ASSERT (isdigit ('7'));
  ASSERT (isdigit ('8'));
  ASSERT (isdigit ('9'));
  ASSERT (!isdigit (':'));
  ASSERT (!isdigit (';'));
  ASSERT (!isdigit ('<'));
  ASSERT (!isdigit ('='));
  ASSERT (!isdigit ('>'));
  ASSERT (!isdigit ('\?'));
  ASSERT (!isdigit ('@'));
  ASSERT (!isdigit ('A'));
  ASSERT (!isdigit ('B'));
  ASSERT (!isdigit ('C'));
  ASSERT (!isdigit ('D'));
  ASSERT (!isdigit ('E'));
  ASSERT (!isdigit ('F'));
  ASSERT (!isdigit ('G'));
  ASSERT (!isdigit ('H'));
  ASSERT (!isdigit ('I'));
  ASSERT (!isdigit ('J'));
  ASSERT (!isdigit ('K'));
  ASSERT (!isdigit ('L'));
  ASSERT (!isdigit ('M'));
  ASSERT (!isdigit ('N'));
  ASSERT (!isdigit ('O'));
  ASSERT (!isdigit ('P'));
  ASSERT (!isdigit ('Q'));
  ASSERT (!isdigit ('R'));
  ASSERT (!isdigit ('S'));
  ASSERT (!isdigit ('T'));
  ASSERT (!isdigit ('U'));
  ASSERT (!isdigit ('V'));
  ASSERT (!isdigit ('W'));
  ASSERT (!isdigit ('X'));
  ASSERT (!isdigit ('Y'));
  ASSERT (!isdigit ('Z'));
  ASSERT (!isdigit ('['));
  ASSERT (!isdigit ('\\'));
  ASSERT (!isdigit (']'));
  ASSERT (!isdigit ('^'));
  ASSERT (!isdigit ('_'));
  ASSERT (!isdigit ('`'));
  ASSERT (!isdigit ('a'));
  ASSERT (!isdigit ('b'));
  ASSERT (!isdigit ('c'));
  ASSERT (!isdigit ('d'));
  ASSERT (!isdigit ('e'));
  ASSERT (!isdigit ('f'));
  ASSERT (!isdigit ('g'));
  ASSERT (!isdigit ('h'));
  ASSERT (!isdigit ('i'));
  ASSERT (!isdigit ('j'));
  ASSERT (!isdigit ('k'));
  ASSERT (!isdigit ('l'));
  ASSERT (!isdigit ('m'));
  ASSERT (!isdigit ('n'));
  ASSERT (!isdigit ('o'));
  ASSERT (!isdigit ('p'));
  ASSERT (!isdigit ('q'));
  ASSERT (!isdigit ('r'));
  ASSERT (!isdigit ('s'));
  ASSERT (!isdigit ('t'));
  ASSERT (!isdigit ('u'));
  ASSERT (!isdigit ('v'));
  ASSERT (!isdigit ('w'));
  ASSERT (!isdigit ('x'));
  ASSERT (!isdigit ('y'));
  ASSERT (!isdigit ('z'));
  ASSERT (!isdigit ('{'));
  ASSERT (!isdigit ('|'));
  ASSERT (!isdigit ('}'));
  ASSERT (!isdigit ('~'));
  ASSERT (!isdigit (127));
  return 0;
}
