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
  ASSERT (!isblank (0x00));
  ASSERT (!isblank (0x01));
  ASSERT (!isblank (0x02));
  ASSERT (!isblank (0x03));
  ASSERT (!isblank (0x04));
  ASSERT (!isblank (0x05));
  ASSERT (!isblank (0x06));
  ASSERT (!isblank ('\a'));
  ASSERT (!isblank ('\b'));
  ASSERT (isblank ('\t'));
  ASSERT (!isblank ('\n'));
  ASSERT (!isblank ('\v'));
  ASSERT (!isblank ('\f'));
  ASSERT (!isblank ('\r'));
  ASSERT (!isblank (0x0e));
  ASSERT (!isblank (0x0f));
  ASSERT (!isblank (0x10));
  ASSERT (!isblank (0x11));
  ASSERT (!isblank (0x12));
  ASSERT (!isblank (0x13));
  ASSERT (!isblank (0x14));
  ASSERT (!isblank (0x15));
  ASSERT (!isblank (0x16));
  ASSERT (!isblank (0x17));
  ASSERT (!isblank (0x18));
  ASSERT (!isblank (0x19));
  ASSERT (!isblank (0x1a));
  ASSERT (!isblank (0x1b));
  ASSERT (!isblank (0x1c));
  ASSERT (!isblank (0x1d));
  ASSERT (!isblank (0x1e));
  ASSERT (!isblank (0x1f));
  ASSERT (isblank (' '));
  ASSERT (!isblank ('!'));
  ASSERT (!isblank ('\"'));
  ASSERT (!isblank ('#'));
  ASSERT (!isblank ('$'));
  ASSERT (!isblank ('%'));
  ASSERT (!isblank ('&'));
  ASSERT (!isblank ('\''));
  ASSERT (!isblank ('('));
  ASSERT (!isblank (')'));
  ASSERT (!isblank ('*'));
  ASSERT (!isblank ('+'));
  ASSERT (!isblank (','));
  ASSERT (!isblank ('-'));
  ASSERT (!isblank ('.'));
  ASSERT (!isblank ('/'));
  ASSERT (!isblank ('0'));
  ASSERT (!isblank ('1'));
  ASSERT (!isblank ('2'));
  ASSERT (!isblank ('3'));
  ASSERT (!isblank ('4'));
  ASSERT (!isblank ('5'));
  ASSERT (!isblank ('6'));
  ASSERT (!isblank ('7'));
  ASSERT (!isblank ('8'));
  ASSERT (!isblank ('9'));
  ASSERT (!isblank (':'));
  ASSERT (!isblank (';'));
  ASSERT (!isblank ('<'));
  ASSERT (!isblank ('='));
  ASSERT (!isblank ('>'));
  ASSERT (!isblank ('\?'));
  ASSERT (!isblank ('@'));
  ASSERT (!isblank ('A'));
  ASSERT (!isblank ('B'));
  ASSERT (!isblank ('C'));
  ASSERT (!isblank ('D'));
  ASSERT (!isblank ('E'));
  ASSERT (!isblank ('F'));
  ASSERT (!isblank ('G'));
  ASSERT (!isblank ('H'));
  ASSERT (!isblank ('I'));
  ASSERT (!isblank ('J'));
  ASSERT (!isblank ('K'));
  ASSERT (!isblank ('L'));
  ASSERT (!isblank ('M'));
  ASSERT (!isblank ('N'));
  ASSERT (!isblank ('O'));
  ASSERT (!isblank ('P'));
  ASSERT (!isblank ('Q'));
  ASSERT (!isblank ('R'));
  ASSERT (!isblank ('S'));
  ASSERT (!isblank ('T'));
  ASSERT (!isblank ('U'));
  ASSERT (!isblank ('V'));
  ASSERT (!isblank ('W'));
  ASSERT (!isblank ('X'));
  ASSERT (!isblank ('Y'));
  ASSERT (!isblank ('Z'));
  ASSERT (!isblank ('['));
  ASSERT (!isblank ('\\'));
  ASSERT (!isblank (']'));
  ASSERT (!isblank ('^'));
  ASSERT (!isblank ('_'));
  ASSERT (!isblank ('`'));
  ASSERT (!isblank ('a'));
  ASSERT (!isblank ('b'));
  ASSERT (!isblank ('c'));
  ASSERT (!isblank ('d'));
  ASSERT (!isblank ('e'));
  ASSERT (!isblank ('f'));
  ASSERT (!isblank ('g'));
  ASSERT (!isblank ('h'));
  ASSERT (!isblank ('i'));
  ASSERT (!isblank ('j'));
  ASSERT (!isblank ('k'));
  ASSERT (!isblank ('l'));
  ASSERT (!isblank ('m'));
  ASSERT (!isblank ('n'));
  ASSERT (!isblank ('o'));
  ASSERT (!isblank ('p'));
  ASSERT (!isblank ('q'));
  ASSERT (!isblank ('r'));
  ASSERT (!isblank ('s'));
  ASSERT (!isblank ('t'));
  ASSERT (!isblank ('u'));
  ASSERT (!isblank ('v'));
  ASSERT (!isblank ('w'));
  ASSERT (!isblank ('x'));
  ASSERT (!isblank ('y'));
  ASSERT (!isblank ('z'));
  ASSERT (!isblank ('{'));
  ASSERT (!isblank ('|'));
  ASSERT (!isblank ('}'));
  ASSERT (!isblank ('~'));
  ASSERT (!isblank (127));
  return 0;
}
