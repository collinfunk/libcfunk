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

#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base16.h"
#include "test-help.h"

#ifndef CHAR_MIN
#  define CHAR_MIN 0
#endif

struct base16_testcase
{
  const char *str;
  const char *encoded;
};

/* RFC 4648 Section 10 */
static const struct base16_testcase tests[] = {
  { "", "" },
  { "f", "66" },
  { "fo", "666F" },
  { "foo", "666F6F" },
  { "foob", "666F6F62" },
  { "fooba", "666F6F6261" },
  { "foobar", "666F6F626172" },
};

static char buffer[4096];

static void test_base16_encode_unsafe (void);
static void test_base16_encode (void);
static void test_isbase16 (void);
static void test_base16_decode (void);

int
main (void)
{
  test_base16_encode_unsafe ();
  test_base16_encode ();
  test_isbase16 ();
  test_base16_decode ();
  return 0;
}

static void
test_base16_encode_unsafe (void)
{
  size_t i;

  /* In case this function isn't called first. */
  memset (buffer, 0, sizeof (buffer));
  for (i = 0; i < ARRAY_SIZE (tests); ++i)
    {
      size_t src_len = strlen (tests[i].str);
      base16_encode_unsafe (tests[i].str, src_len, buffer);
      ASSERT (strlen (buffer) == BASE16_LENGTH (src_len));
      ASSERT (buffer[BASE16_LENGTH (src_len)] == '\0');
      ASSERT (memcmp (buffer, tests[i].encoded, BASE16_LENGTH (src_len)) == 0);
    }
}

static void
test_base16_encode (void)
{
  size_t i;

  /* Make sure we are null-terminated by base16_encode. */
  memset (buffer, 0x55, sizeof (buffer));
  for (i = 0; i < ARRAY_SIZE (tests); ++i)
    {
      size_t src_len = strlen (tests[i].str);
      base16_encode (tests[i].str, src_len, buffer, sizeof (buffer));
      ASSERT (strlen (buffer) == BASE16_LENGTH (src_len));
      ASSERT (buffer[BASE16_LENGTH (src_len)] == '\0');
      if (BASE16_STRING_LENGTH (src_len) < sizeof (buffer))
        ASSERT (buffer[BASE16_STRING_LENGTH (src_len)] == 0x55);
      ASSERT (memcmp (buffer, tests[i].encoded, BASE16_LENGTH (src_len)) == 0);
      printf ("%s\n", buffer);
    }
}

static void
test_isbase16 (void)
{
  char i;

  for (i = CHAR_MIN; i < 0; ++i)
    ASSERT (!isbase16 (i));

  ASSERT (!isbase16 ('\0'));
  ASSERT (!isbase16 (1));
  ASSERT (!isbase16 (2));
  ASSERT (!isbase16 (3));
  ASSERT (!isbase16 (4));
  ASSERT (!isbase16 (5));
  ASSERT (!isbase16 (6));
  ASSERT (!isbase16 ('\a'));
  ASSERT (!isbase16 ('\b'));
  ASSERT (!isbase16 ('\t'));
  ASSERT (!isbase16 ('\n'));
  ASSERT (!isbase16 ('\v'));
  ASSERT (!isbase16 ('\f'));
  ASSERT (!isbase16 ('\r'));
  ASSERT (!isbase16 (14));
  ASSERT (!isbase16 (14));
  ASSERT (!isbase16 (15));
  ASSERT (!isbase16 (16));
  ASSERT (!isbase16 (17));
  ASSERT (!isbase16 (18));
  ASSERT (!isbase16 (19));
  ASSERT (!isbase16 (20));
  ASSERT (!isbase16 (21));
  ASSERT (!isbase16 (22));
  ASSERT (!isbase16 (23));
  ASSERT (!isbase16 (24));
  ASSERT (!isbase16 (25));
  ASSERT (!isbase16 (26));
  ASSERT (!isbase16 (27));
  ASSERT (!isbase16 (28));
  ASSERT (!isbase16 (29));
  ASSERT (!isbase16 (30));
  ASSERT (!isbase16 (31));
  ASSERT (!isbase16 (' '));
  ASSERT (!isbase16 ('!'));
  ASSERT (!isbase16 ('"'));
  ASSERT (!isbase16 ('#'));
  ASSERT (!isbase16 ('$'));
  ASSERT (!isbase16 ('%'));
  ASSERT (!isbase16 ('&'));
  ASSERT (!isbase16 ('\''));
  ASSERT (!isbase16 ('('));
  ASSERT (!isbase16 (')'));
  ASSERT (!isbase16 ('*'));
  ASSERT (!isbase16 ('+'));
  ASSERT (!isbase16 (','));
  ASSERT (!isbase16 ('-'));
  ASSERT (!isbase16 ('.'));
  ASSERT (!isbase16 ('/'));
  ASSERT (isbase16 ('0'));
  ASSERT (isbase16 ('1'));
  ASSERT (isbase16 ('2'));
  ASSERT (isbase16 ('3'));
  ASSERT (isbase16 ('4'));
  ASSERT (isbase16 ('5'));
  ASSERT (isbase16 ('6'));
  ASSERT (isbase16 ('7'));
  ASSERT (isbase16 ('8'));
  ASSERT (isbase16 ('9'));
  ASSERT (!isbase16 (':'));
  ASSERT (!isbase16 (';'));
  ASSERT (!isbase16 ('<'));
  ASSERT (!isbase16 ('='));
  ASSERT (!isbase16 ('>'));
  ASSERT (!isbase16 ('?'));
  ASSERT (!isbase16 ('@'));
  ASSERT (isbase16 ('A'));
  ASSERT (isbase16 ('B'));
  ASSERT (isbase16 ('C'));
  ASSERT (isbase16 ('D'));
  ASSERT (isbase16 ('E'));
  ASSERT (isbase16 ('F'));
  ASSERT (!isbase16 ('G'));
  ASSERT (!isbase16 ('H'));
  ASSERT (!isbase16 ('I'));
  ASSERT (!isbase16 ('J'));
  ASSERT (!isbase16 ('K'));
  ASSERT (!isbase16 ('L'));
  ASSERT (!isbase16 ('M'));
  ASSERT (!isbase16 ('N'));
  ASSERT (!isbase16 ('O'));
  ASSERT (!isbase16 ('P'));
  ASSERT (!isbase16 ('Q'));
  ASSERT (!isbase16 ('R'));
  ASSERT (!isbase16 ('S'));
  ASSERT (!isbase16 ('T'));
  ASSERT (!isbase16 ('U'));
  ASSERT (!isbase16 ('V'));
  ASSERT (!isbase16 ('W'));
  ASSERT (!isbase16 ('X'));
  ASSERT (!isbase16 ('Y'));
  ASSERT (!isbase16 ('Z'));
  ASSERT (!isbase16 ('['));
  ASSERT (!isbase16 ('\\'));
  ASSERT (!isbase16 (']'));
  ASSERT (!isbase16 ('^'));
  ASSERT (!isbase16 ('_'));
  ASSERT (!isbase16 ('`'));
  ASSERT (isbase16 ('a'));
  ASSERT (isbase16 ('b'));
  ASSERT (isbase16 ('c'));
  ASSERT (isbase16 ('d'));
  ASSERT (isbase16 ('e'));
  ASSERT (isbase16 ('f'));
  ASSERT (!isbase16 ('g'));
  ASSERT (!isbase16 ('h'));
  ASSERT (!isbase16 ('i'));
  ASSERT (!isbase16 ('j'));
  ASSERT (!isbase16 ('k'));
  ASSERT (!isbase16 ('l'));
  ASSERT (!isbase16 ('m'));
  ASSERT (!isbase16 ('n'));
  ASSERT (!isbase16 ('o'));
  ASSERT (!isbase16 ('p'));
  ASSERT (!isbase16 ('q'));
  ASSERT (!isbase16 ('r'));
  ASSERT (!isbase16 ('s'));
  ASSERT (!isbase16 ('t'));
  ASSERT (!isbase16 ('u'));
  ASSERT (!isbase16 ('v'));
  ASSERT (!isbase16 ('w'));
  ASSERT (!isbase16 ('x'));
  ASSERT (!isbase16 ('y'));
  ASSERT (!isbase16 ('z'));
  ASSERT (!isbase16 ('{'));
  ASSERT (!isbase16 ('|'));
  ASSERT (!isbase16 ('}'));
  ASSERT (!isbase16 ('~'));
  ASSERT (!isbase16 (127));
}

static void
test_base16_decode (void)
{
  size_t i;
  struct base16_decode_ctx ctx;

  /* Make sure we are null-terminated by base16_decode. */
  memset (buffer, 0x12, sizeof (buffer));
  for (i = 0; i < ARRAY_SIZE (tests); ++i)
    {
      size_t encoded_len = strlen (tests[i].encoded);
      size_t src_len = strlen (tests[i].str);

      base16_decode_init (&ctx);
      ASSERT (base16_decode (&ctx, tests[i].encoded, encoded_len, buffer,
                             sizeof (buffer)));
      ASSERT (buffer[src_len] == '\0');
      ASSERT (buffer[src_len + 1] == 0x12);
      ASSERT (memcmp (buffer, tests[i].str, src_len) == 0);
      printf ("%s\n", buffer);
    }
}
