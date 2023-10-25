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
  ASSERT (!isupper (0x00));
  ASSERT (!isupper (0x01));
  ASSERT (!isupper (0x02));
  ASSERT (!isupper (0x03));
  ASSERT (!isupper (0x04));
  ASSERT (!isupper (0x05));
  ASSERT (!isupper (0x06));
  ASSERT (!isupper ('\a'));
  ASSERT (!isupper ('\b'));
  ASSERT (!isupper ('\t'));
  ASSERT (!isupper ('\n'));
  ASSERT (!isupper ('\v'));
  ASSERT (!isupper ('\f'));
  ASSERT (!isupper ('\r'));
  ASSERT (!isupper (0x0e));
  ASSERT (!isupper (0x0f));
  ASSERT (!isupper (0x10));
  ASSERT (!isupper (0x11));
  ASSERT (!isupper (0x12));
  ASSERT (!isupper (0x13));
  ASSERT (!isupper (0x14));
  ASSERT (!isupper (0x15));
  ASSERT (!isupper (0x16));
  ASSERT (!isupper (0x17));
  ASSERT (!isupper (0x18));
  ASSERT (!isupper (0x19));
  ASSERT (!isupper (0x1a));
  ASSERT (!isupper (0x1b));
  ASSERT (!isupper (0x1c));
  ASSERT (!isupper (0x1d));
  ASSERT (!isupper (0x1e));
  ASSERT (!isupper (0x1f));
  ASSERT (!isupper (' '));
  ASSERT (!isupper ('!'));
  ASSERT (!isupper ('\"'));
  ASSERT (!isupper ('#'));
  ASSERT (!isupper ('$'));
  ASSERT (!isupper ('%'));
  ASSERT (!isupper ('&'));
  ASSERT (!isupper ('\''));
  ASSERT (!isupper ('('));
  ASSERT (!isupper (')'));
  ASSERT (!isupper ('*'));
  ASSERT (!isupper ('+'));
  ASSERT (!isupper (','));
  ASSERT (!isupper ('-'));
  ASSERT (!isupper ('.'));
  ASSERT (!isupper ('/'));
  ASSERT (!isupper ('0'));
  ASSERT (!isupper ('1'));
  ASSERT (!isupper ('2'));
  ASSERT (!isupper ('3'));
  ASSERT (!isupper ('4'));
  ASSERT (!isupper ('5'));
  ASSERT (!isupper ('6'));
  ASSERT (!isupper ('7'));
  ASSERT (!isupper ('8'));
  ASSERT (!isupper ('9'));
  ASSERT (!isupper (':'));
  ASSERT (!isupper (';'));
  ASSERT (!isupper ('<'));
  ASSERT (!isupper ('='));
  ASSERT (!isupper ('>'));
  ASSERT (!isupper ('\?'));
  ASSERT (!isupper ('@'));
  ASSERT (isupper ('A'));
  ASSERT (isupper ('B'));
  ASSERT (isupper ('C'));
  ASSERT (isupper ('D'));
  ASSERT (isupper ('E'));
  ASSERT (isupper ('F'));
  ASSERT (isupper ('G'));
  ASSERT (isupper ('H'));
  ASSERT (isupper ('I'));
  ASSERT (isupper ('J'));
  ASSERT (isupper ('K'));
  ASSERT (isupper ('L'));
  ASSERT (isupper ('M'));
  ASSERT (isupper ('N'));
  ASSERT (isupper ('O'));
  ASSERT (isupper ('P'));
  ASSERT (isupper ('Q'));
  ASSERT (isupper ('R'));
  ASSERT (isupper ('S'));
  ASSERT (isupper ('T'));
  ASSERT (isupper ('U'));
  ASSERT (isupper ('V'));
  ASSERT (isupper ('W'));
  ASSERT (isupper ('X'));
  ASSERT (isupper ('Y'));
  ASSERT (isupper ('Z'));
  ASSERT (!isupper ('['));
  ASSERT (!isupper ('\\'));
  ASSERT (!isupper (']'));
  ASSERT (!isupper ('^'));
  ASSERT (!isupper ('_'));
  ASSERT (!isupper ('`'));
  ASSERT (!isupper ('a'));
  ASSERT (!isupper ('b'));
  ASSERT (!isupper ('c'));
  ASSERT (!isupper ('d'));
  ASSERT (!isupper ('e'));
  ASSERT (!isupper ('f'));
  ASSERT (!isupper ('g'));
  ASSERT (!isupper ('h'));
  ASSERT (!isupper ('i'));
  ASSERT (!isupper ('j'));
  ASSERT (!isupper ('k'));
  ASSERT (!isupper ('l'));
  ASSERT (!isupper ('m'));
  ASSERT (!isupper ('n'));
  ASSERT (!isupper ('o'));
  ASSERT (!isupper ('p'));
  ASSERT (!isupper ('q'));
  ASSERT (!isupper ('r'));
  ASSERT (!isupper ('s'));
  ASSERT (!isupper ('t'));
  ASSERT (!isupper ('u'));
  ASSERT (!isupper ('v'));
  ASSERT (!isupper ('w'));
  ASSERT (!isupper ('x'));
  ASSERT (!isupper ('y'));
  ASSERT (!isupper ('z'));
  ASSERT (!isupper ('{'));
  ASSERT (!isupper ('|'));
  ASSERT (!isupper ('}'));
  ASSERT (!isupper ('~'));
  ASSERT (!isupper (127));
  return 0;
}
