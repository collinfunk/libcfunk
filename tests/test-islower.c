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
  ASSERT (!islower (0x00));
  ASSERT (!islower (0x01));
  ASSERT (!islower (0x02));
  ASSERT (!islower (0x03));
  ASSERT (!islower (0x04));
  ASSERT (!islower (0x05));
  ASSERT (!islower (0x06));
  ASSERT (!islower ('\a'));
  ASSERT (!islower ('\b'));
  ASSERT (!islower ('\t'));
  ASSERT (!islower ('\n'));
  ASSERT (!islower ('\v'));
  ASSERT (!islower ('\f'));
  ASSERT (!islower ('\r'));
  ASSERT (!islower (0x0e));
  ASSERT (!islower (0x0f));
  ASSERT (!islower (0x10));
  ASSERT (!islower (0x11));
  ASSERT (!islower (0x12));
  ASSERT (!islower (0x13));
  ASSERT (!islower (0x14));
  ASSERT (!islower (0x15));
  ASSERT (!islower (0x16));
  ASSERT (!islower (0x17));
  ASSERT (!islower (0x18));
  ASSERT (!islower (0x19));
  ASSERT (!islower (0x1a));
  ASSERT (!islower (0x1b));
  ASSERT (!islower (0x1c));
  ASSERT (!islower (0x1d));
  ASSERT (!islower (0x1e));
  ASSERT (!islower (0x1f));
  ASSERT (!islower (' '));
  ASSERT (!islower ('!'));
  ASSERT (!islower ('\"'));
  ASSERT (!islower ('#'));
  ASSERT (!islower ('$'));
  ASSERT (!islower ('%'));
  ASSERT (!islower ('&'));
  ASSERT (!islower ('\''));
  ASSERT (!islower ('('));
  ASSERT (!islower (')'));
  ASSERT (!islower ('*'));
  ASSERT (!islower ('+'));
  ASSERT (!islower (','));
  ASSERT (!islower ('-'));
  ASSERT (!islower ('.'));
  ASSERT (!islower ('/'));
  ASSERT (!islower ('0'));
  ASSERT (!islower ('1'));
  ASSERT (!islower ('2'));
  ASSERT (!islower ('3'));
  ASSERT (!islower ('4'));
  ASSERT (!islower ('5'));
  ASSERT (!islower ('6'));
  ASSERT (!islower ('7'));
  ASSERT (!islower ('8'));
  ASSERT (!islower ('9'));
  ASSERT (!islower (':'));
  ASSERT (!islower (';'));
  ASSERT (!islower ('<'));
  ASSERT (!islower ('='));
  ASSERT (!islower ('>'));
  ASSERT (!islower ('\?'));
  ASSERT (!islower ('@'));
  ASSERT (!islower ('A'));
  ASSERT (!islower ('B'));
  ASSERT (!islower ('C'));
  ASSERT (!islower ('D'));
  ASSERT (!islower ('E'));
  ASSERT (!islower ('F'));
  ASSERT (!islower ('G'));
  ASSERT (!islower ('H'));
  ASSERT (!islower ('I'));
  ASSERT (!islower ('J'));
  ASSERT (!islower ('K'));
  ASSERT (!islower ('L'));
  ASSERT (!islower ('M'));
  ASSERT (!islower ('N'));
  ASSERT (!islower ('O'));
  ASSERT (!islower ('P'));
  ASSERT (!islower ('Q'));
  ASSERT (!islower ('R'));
  ASSERT (!islower ('S'));
  ASSERT (!islower ('T'));
  ASSERT (!islower ('U'));
  ASSERT (!islower ('V'));
  ASSERT (!islower ('W'));
  ASSERT (!islower ('X'));
  ASSERT (!islower ('Y'));
  ASSERT (!islower ('Z'));
  ASSERT (!islower ('['));
  ASSERT (!islower ('\\'));
  ASSERT (!islower (']'));
  ASSERT (!islower ('^'));
  ASSERT (!islower ('_'));
  ASSERT (!islower ('`'));
  ASSERT (islower ('a'));
  ASSERT (islower ('b'));
  ASSERT (islower ('c'));
  ASSERT (islower ('d'));
  ASSERT (islower ('e'));
  ASSERT (islower ('f'));
  ASSERT (islower ('g'));
  ASSERT (islower ('h'));
  ASSERT (islower ('i'));
  ASSERT (islower ('j'));
  ASSERT (islower ('k'));
  ASSERT (islower ('l'));
  ASSERT (islower ('m'));
  ASSERT (islower ('n'));
  ASSERT (islower ('o'));
  ASSERT (islower ('p'));
  ASSERT (islower ('q'));
  ASSERT (islower ('r'));
  ASSERT (islower ('s'));
  ASSERT (islower ('t'));
  ASSERT (islower ('u'));
  ASSERT (islower ('v'));
  ASSERT (islower ('w'));
  ASSERT (islower ('x'));
  ASSERT (islower ('y'));
  ASSERT (islower ('z'));
  ASSERT (!islower ('{'));
  ASSERT (!islower ('|'));
  ASSERT (!islower ('}'));
  ASSERT (!islower ('~'));
  ASSERT (!islower (127));
  return 0;
}
