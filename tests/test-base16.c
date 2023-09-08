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

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base16.h"
#include "test-help.h"

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

int
main (void)
{
  test_base16_encode_unsafe ();
  test_base16_encode ();
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
    }
}
