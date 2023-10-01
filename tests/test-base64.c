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

#include "base64.h"
#include "test-help.h"

#ifndef CHAR_MIN
#  define CHAR_MIN 0
#endif

struct base64_testcase
{
  const char *str;
  const char *encoded;
};

/* RFC 4648 Section 10 */
static const struct base64_testcase tests[] = {
  { "", "" },
  { "f", "Zg==" },
  { "fo", "Zm8=" },
  { "foo", "Zm9v" },
  { "foob", "Zm9vYg==" },
  { "fooba", "Zm9vYmE=" },
  { "foobar", "Zm9vYmFy" },
};

static char buffer[4096];

static void test_base64_encode (void);
static void test_base64_string_len (void);
static void test_isbase64 (void);

int
main (void)
{
  test_base64_encode ();
  test_base64_string_len ();
  test_isbase64 ();
  return 0;
}

static void
test_base64_encode (void)
{
  size_t i;

  /* Make sure we are null-terminated by base64_encode. */
  memset (buffer, 0x55, sizeof (buffer));
  for (i = 0; i < ARRAY_SIZE (tests); ++i)
    {
      size_t src_len = strlen (tests[i].str);
      base64_encode (tests[i].str, src_len, buffer, sizeof (buffer));
      ASSERT (strlen (buffer) == BASE64_LENGTH (src_len));
      ASSERT (buffer[BASE64_LENGTH (src_len)] == '\0');
      printf ("%s\n", buffer);
      if (BASE64_STRING_LENGTH (src_len) < sizeof (buffer))
        ASSERT (buffer[BASE64_STRING_LENGTH (src_len)] == 0x55);
      ASSERT (memcmp (buffer, tests[i].encoded, BASE64_LENGTH (src_len)) == 0);
    }
}

static void
test_base64_string_len (void)
{
  char *str;
  size_t i, size, src_len;

  str = NULL;
  size = 0;
  for (i = 0; i < ARRAY_SIZE (tests); ++i)
    {
      src_len = strlen (tests[i].str);
      if (str == NULL)
        str = (char *) malloc (BASE64_STRING_LENGTH (src_len));
      else
        {
          if (size < BASE64_STRING_LENGTH (src_len))
            {
              size = BASE64_STRING_LENGTH (src_len);
              str = (char *) realloc (str, size);
            }
        }
      if (str == NULL)
        {
          fprintf (stderr, "Out of memory.\n");
          abort ();
        }
      base64_encode (tests[i].str, src_len, str, size);
      if (*tests[i].str != '\0')
        ASSERT (str[BASE64_LENGTH (src_len)] == '\0');
    }

  free (str);
}

static void
test_isbase64 (void)
{
  char i;

  for (i = CHAR_MIN; i < 0; ++i)
    ASSERT (!isbase64 (i));

  ASSERT (!isbase64 ('\0'));
  ASSERT (!isbase64 (1));
  ASSERT (!isbase64 (2));
  ASSERT (!isbase64 (3));
  ASSERT (!isbase64 (4));
  ASSERT (!isbase64 (5));
  ASSERT (!isbase64 (6));
  ASSERT (!isbase64 ('\a'));
  ASSERT (!isbase64 ('\b'));
  ASSERT (!isbase64 ('\t'));
  ASSERT (!isbase64 ('\n'));
  ASSERT (!isbase64 ('\v'));
  ASSERT (!isbase64 ('\f'));
  ASSERT (!isbase64 ('\r'));
  ASSERT (!isbase64 (14));
  ASSERT (!isbase64 (14));
  ASSERT (!isbase64 (15));
  ASSERT (!isbase64 (16));
  ASSERT (!isbase64 (17));
  ASSERT (!isbase64 (18));
  ASSERT (!isbase64 (19));
  ASSERT (!isbase64 (20));
  ASSERT (!isbase64 (21));
  ASSERT (!isbase64 (22));
  ASSERT (!isbase64 (23));
  ASSERT (!isbase64 (24));
  ASSERT (!isbase64 (25));
  ASSERT (!isbase64 (26));
  ASSERT (!isbase64 (27));
  ASSERT (!isbase64 (28));
  ASSERT (!isbase64 (29));
  ASSERT (!isbase64 (30));
  ASSERT (!isbase64 (31));
  ASSERT (!isbase64 (' '));
  ASSERT (!isbase64 ('!'));
  ASSERT (!isbase64 ('"'));
  ASSERT (!isbase64 ('#'));
  ASSERT (!isbase64 ('$'));
  ASSERT (!isbase64 ('%'));
  ASSERT (!isbase64 ('&'));
  ASSERT (!isbase64 ('\''));
  ASSERT (!isbase64 ('('));
  ASSERT (!isbase64 (')'));
  ASSERT (!isbase64 ('*'));
  ASSERT (isbase64 ('+'));
  ASSERT (!isbase64 (','));
  ASSERT (!isbase64 ('-'));
  ASSERT (!isbase64 ('.'));
  ASSERT (isbase64 ('/'));
  ASSERT (isbase64 ('0'));
  ASSERT (isbase64 ('1'));
  ASSERT (isbase64 ('2'));
  ASSERT (isbase64 ('3'));
  ASSERT (isbase64 ('4'));
  ASSERT (isbase64 ('5'));
  ASSERT (isbase64 ('6'));
  ASSERT (isbase64 ('7'));
  ASSERT (isbase64 ('8'));
  ASSERT (isbase64 ('9'));
  ASSERT (!isbase64 (':'));
  ASSERT (!isbase64 (';'));
  ASSERT (!isbase64 ('<'));
  ASSERT (!isbase64 ('='));
  ASSERT (!isbase64 ('>'));
  ASSERT (!isbase64 ('?'));
  ASSERT (!isbase64 ('@'));
  ASSERT (isbase64 ('A'));
  ASSERT (isbase64 ('B'));
  ASSERT (isbase64 ('C'));
  ASSERT (isbase64 ('D'));
  ASSERT (isbase64 ('E'));
  ASSERT (isbase64 ('F'));
  ASSERT (isbase64 ('G'));
  ASSERT (isbase64 ('H'));
  ASSERT (isbase64 ('I'));
  ASSERT (isbase64 ('J'));
  ASSERT (isbase64 ('K'));
  ASSERT (isbase64 ('L'));
  ASSERT (isbase64 ('M'));
  ASSERT (isbase64 ('N'));
  ASSERT (isbase64 ('O'));
  ASSERT (isbase64 ('P'));
  ASSERT (isbase64 ('Q'));
  ASSERT (isbase64 ('R'));
  ASSERT (isbase64 ('S'));
  ASSERT (isbase64 ('T'));
  ASSERT (isbase64 ('U'));
  ASSERT (isbase64 ('V'));
  ASSERT (isbase64 ('W'));
  ASSERT (isbase64 ('X'));
  ASSERT (isbase64 ('Y'));
  ASSERT (isbase64 ('Z'));
  ASSERT (!isbase64 ('['));
  ASSERT (!isbase64 ('\\'));
  ASSERT (!isbase64 (']'));
  ASSERT (!isbase64 ('^'));
  ASSERT (!isbase64 ('_'));
  ASSERT (!isbase64 ('`'));
  ASSERT (isbase64 ('a'));
  ASSERT (isbase64 ('b'));
  ASSERT (isbase64 ('c'));
  ASSERT (isbase64 ('d'));
  ASSERT (isbase64 ('e'));
  ASSERT (isbase64 ('f'));
  ASSERT (isbase64 ('g'));
  ASSERT (isbase64 ('h'));
  ASSERT (isbase64 ('i'));
  ASSERT (isbase64 ('j'));
  ASSERT (isbase64 ('k'));
  ASSERT (isbase64 ('l'));
  ASSERT (isbase64 ('m'));
  ASSERT (isbase64 ('n'));
  ASSERT (isbase64 ('o'));
  ASSERT (isbase64 ('p'));
  ASSERT (isbase64 ('q'));
  ASSERT (isbase64 ('r'));
  ASSERT (isbase64 ('s'));
  ASSERT (isbase64 ('t'));
  ASSERT (isbase64 ('u'));
  ASSERT (isbase64 ('v'));
  ASSERT (isbase64 ('w'));
  ASSERT (isbase64 ('x'));
  ASSERT (isbase64 ('y'));
  ASSERT (isbase64 ('z'));
  ASSERT (!isbase64 ('{'));
  ASSERT (!isbase64 ('|'));
  ASSERT (!isbase64 ('}'));
  ASSERT (!isbase64 ('~'));
  ASSERT (!isbase64 (127));
}
