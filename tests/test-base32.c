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

#include "base32.h"
#include "test-help.h"

#ifndef CHAR_MIN
#  define CHAR_MIN 0
#endif

struct base32_testcase
{
  const char *str;
  const char *encoded;
};

/* RFC 4328 Section 10 */
static const struct base32_testcase tests[] = {
  { "", "" },
  { "f", "MY======" },
  { "fo", "MZXQ====" },
  { "foo", "MZXW6===" },
  { "foob", "MZXW6YQ=" },
  { "fooba", "MZXW6YTB" },
  { "foobar", "MZXW6YTBOI======" },
};

static char buffer[4096];

static void test_base32_encode (void);
static void test_base32_string_len (void);
static void test_isbase32 (void);

int
main (void)
{
  test_base32_encode ();
  test_base32_string_len ();
  test_isbase32 ();
  return 0;
}

static void
test_base32_encode (void)
{
  size_t i;

  /* Make sure we are null-terminated by base32_encode. */
  memset (buffer, 0x55, sizeof (buffer));
  for (i = 0; i < ARRAY_SIZE (tests); ++i)
    {
      size_t src_len = strlen (tests[i].str);
      base32_encode (tests[i].str, src_len, buffer, sizeof (buffer));
      ASSERT (strlen (buffer) == BASE32_LENGTH (src_len));
      ASSERT (buffer[BASE32_LENGTH (src_len)] == '\0');
      printf ("%s\n", buffer);
      if (BASE32_STRING_LENGTH (src_len) < sizeof (buffer))
        ASSERT (buffer[BASE32_STRING_LENGTH (src_len)] == 0x55);
      ASSERT (memcmp (buffer, tests[i].encoded, BASE32_LENGTH (src_len)) == 0);
    }
}

static void
test_base32_string_len (void)
{
  char *str;
  size_t i, size, src_len;

  str = NULL;
  size = 0;
  for (i = 0; i < ARRAY_SIZE (tests); ++i)
    {
      src_len = strlen (tests[i].str);
      if (str == NULL)
        str = (char *) malloc (BASE32_STRING_LENGTH (src_len));
      else
        {
          if (size < BASE32_STRING_LENGTH (src_len))
            {
              size = BASE32_STRING_LENGTH (src_len);
              str = (char *) realloc (str, size);
            }
        }
      if (str == NULL)
        {
          fprintf (stderr, "Out of memory.\n");
          abort ();
        }
      base32_encode (tests[i].str, src_len, str, size);
      if (*tests[i].str != '\0')
        ASSERT (str[BASE32_LENGTH (src_len)] == '\0');
    }

  free (str);
}

static void
test_isbase32 (void)
{
  char i;

  for (i = CHAR_MIN; i < 0; ++i)
    ASSERT (!isbase32 (i));

  ASSERT (!isbase32 ('\0'));
  ASSERT (!isbase32 (1));
  ASSERT (!isbase32 (2));
  ASSERT (!isbase32 (3));
  ASSERT (!isbase32 (4));
  ASSERT (!isbase32 (5));
  ASSERT (!isbase32 (6));
  ASSERT (!isbase32 ('\a'));
  ASSERT (!isbase32 ('\b'));
  ASSERT (!isbase32 ('\t'));
  ASSERT (!isbase32 ('\n'));
  ASSERT (!isbase32 ('\v'));
  ASSERT (!isbase32 ('\f'));
  ASSERT (!isbase32 ('\r'));
  ASSERT (!isbase32 (14));
  ASSERT (!isbase32 (14));
  ASSERT (!isbase32 (15));
  ASSERT (!isbase32 (16));
  ASSERT (!isbase32 (17));
  ASSERT (!isbase32 (18));
  ASSERT (!isbase32 (19));
  ASSERT (!isbase32 (20));
  ASSERT (!isbase32 (21));
  ASSERT (!isbase32 (22));
  ASSERT (!isbase32 (23));
  ASSERT (!isbase32 (24));
  ASSERT (!isbase32 (25));
  ASSERT (!isbase32 (26));
  ASSERT (!isbase32 (27));
  ASSERT (!isbase32 (28));
  ASSERT (!isbase32 (29));
  ASSERT (!isbase32 (30));
  ASSERT (!isbase32 (31));
  ASSERT (!isbase32 (' '));
  ASSERT (!isbase32 ('!'));
  ASSERT (!isbase32 ('"'));
  ASSERT (!isbase32 ('#'));
  ASSERT (!isbase32 ('$'));
  ASSERT (!isbase32 ('%'));
  ASSERT (!isbase32 ('&'));
  ASSERT (!isbase32 ('\''));
  ASSERT (!isbase32 ('('));
  ASSERT (!isbase32 (')'));
  ASSERT (!isbase32 ('*'));
  ASSERT (!isbase32 ('+'));
  ASSERT (!isbase32 (','));
  ASSERT (!isbase32 ('-'));
  ASSERT (!isbase32 ('.'));
  ASSERT (!isbase32 ('/'));
  ASSERT (!isbase32 ('0'));
  ASSERT (!isbase32 ('1'));
  ASSERT (isbase32 ('2'));
  ASSERT (isbase32 ('3'));
  ASSERT (isbase32 ('4'));
  ASSERT (isbase32 ('5'));
  ASSERT (isbase32 ('6'));
  ASSERT (isbase32 ('7'));
  ASSERT (!isbase32 ('8'));
  ASSERT (!isbase32 ('9'));
  ASSERT (!isbase32 (':'));
  ASSERT (!isbase32 (';'));
  ASSERT (!isbase32 ('<'));
  ASSERT (!isbase32 ('='));
  ASSERT (!isbase32 ('>'));
  ASSERT (!isbase32 ('?'));
  ASSERT (!isbase32 ('@'));
  ASSERT (isbase32 ('A'));
  ASSERT (isbase32 ('B'));
  ASSERT (isbase32 ('C'));
  ASSERT (isbase32 ('D'));
  ASSERT (isbase32 ('E'));
  ASSERT (isbase32 ('F'));
  ASSERT (isbase32 ('G'));
  ASSERT (isbase32 ('H'));
  ASSERT (isbase32 ('I'));
  ASSERT (isbase32 ('J'));
  ASSERT (isbase32 ('K'));
  ASSERT (isbase32 ('L'));
  ASSERT (isbase32 ('M'));
  ASSERT (isbase32 ('N'));
  ASSERT (isbase32 ('O'));
  ASSERT (isbase32 ('P'));
  ASSERT (isbase32 ('Q'));
  ASSERT (isbase32 ('R'));
  ASSERT (isbase32 ('S'));
  ASSERT (isbase32 ('T'));
  ASSERT (isbase32 ('U'));
  ASSERT (isbase32 ('V'));
  ASSERT (isbase32 ('W'));
  ASSERT (isbase32 ('X'));
  ASSERT (isbase32 ('Y'));
  ASSERT (isbase32 ('Z'));
  ASSERT (!isbase32 ('['));
  ASSERT (!isbase32 ('\\'));
  ASSERT (!isbase32 (']'));
  ASSERT (!isbase32 ('^'));
  ASSERT (!isbase32 ('_'));
  ASSERT (!isbase32 ('`'));
  ASSERT (!isbase32 ('a'));
  ASSERT (!isbase32 ('b'));
  ASSERT (!isbase32 ('c'));
  ASSERT (!isbase32 ('d'));
  ASSERT (!isbase32 ('e'));
  ASSERT (!isbase32 ('f'));
  ASSERT (!isbase32 ('g'));
  ASSERT (!isbase32 ('h'));
  ASSERT (!isbase32 ('i'));
  ASSERT (!isbase32 ('j'));
  ASSERT (!isbase32 ('k'));
  ASSERT (!isbase32 ('l'));
  ASSERT (!isbase32 ('m'));
  ASSERT (!isbase32 ('n'));
  ASSERT (!isbase32 ('o'));
  ASSERT (!isbase32 ('p'));
  ASSERT (!isbase32 ('q'));
  ASSERT (!isbase32 ('r'));
  ASSERT (!isbase32 ('s'));
  ASSERT (!isbase32 ('t'));
  ASSERT (!isbase32 ('u'));
  ASSERT (!isbase32 ('v'));
  ASSERT (!isbase32 ('w'));
  ASSERT (!isbase32 ('x'));
  ASSERT (!isbase32 ('y'));
  ASSERT (!isbase32 ('z'));
  ASSERT (!isbase32 ('{'));
  ASSERT (!isbase32 ('|'));
  ASSERT (!isbase32 ('}'));
  ASSERT (!isbase32 ('~'));
  ASSERT (!isbase32 (127));
}
