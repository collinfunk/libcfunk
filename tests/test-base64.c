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

#include "base64.h"
#include "test-help.h"

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

int
main (void)
{
  test_base64_encode ();
  test_base64_string_len ();
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
