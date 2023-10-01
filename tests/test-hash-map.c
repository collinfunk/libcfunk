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
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash-map.h"
#include "test-help.h"

static struct hash_map *map = NULL;

struct number_pair
{
  const char *string;
  const int value;
};

static const struct number_pair input[] = {
  { "zero", 0 },
  { "one", 1 },
  { "two", 2 },
  { "three", 3 },
  { "four", 4 },
  { "five", 5 },
  { "six", 6 },
  { "seven", 7 },
  { "eight", 8 },
  { "nine", 9 },
  { "ten", 10 },
  { "eleven", 11 },
  { "twelve", 12 },
  { "thirteen", 13 },
  { "fourteen", 14 },
  { "fifteen", 15 },
  { "sixteen", 16 },
  { "seventeen", 17 },
  { "eighteen", 18 },
  { "nineteen", 19 },
  { "twenty", 20 },
  { "twenty-one", 21 },
  { "twenty-two", 22 },
  { "twenty-three", 23 },
  { "twenty-four", 24 },
  { "twenty-five", 25 },
  { "twenty-six", 26 },
  { "twenty-seven", 27 },
  { "twenty-eight", 28 },
  { "twenty-nine", 29 },
  { "thirty", 30 },
  { "thirty-one", 31 },
  { "thirty-two", 32 },
  { "thirty-three", 33 },
  { "thirty-four", 34 },
  { "thirty-five", 35 },
  { "thirty-six", 36 },
  { "thirty-seven", 37 },
  { "thirty-eight", 38 },
  { "thirty-nine", 39 },
  { "forty", 40 },
  { "forty-one", 41 },
  { "forty-two", 42 },
  { "forty-three", 43 },
  { "forty-four", 44 },
  { "forty-five", 45 },
  { "forty-six", 46 },
  { "forty-seven", 47 },
  { "forty-eight", 48 },
  { "forty-nine", 49 },
  { "fifty", 50 },
  { "fifty-one", 51 },
  { "fifty-two", 52 },
  { "fifty-three", 53 },
  { "fifty-four", 54 },
  { "fifty-five", 55 },
  { "fifty-six", 56 },
  { "fifty-seven", 57 },
  { "fifty-eight", 58 },
  { "fifty-nine", 59 },
  { "sixty", 60 },
  { "sixty-one", 61 },
  { "sixty-two", 62 },
  { "sixty-three", 63 },
  { "sixty-four", 64 },
  { "sixty-five", 65 },
  { "sixty-six", 66 },
  { "sixty-seven", 67 },
  { "sixty-eight", 68 },
  { "sixty-nine", 69 },
  { "seventy", 70 },
  { "seventy-one", 71 },
  { "seventy-two", 72 },
  { "seventy-three", 73 },
  { "seventy-four", 74 },
  { "seventy-five", 75 },
  { "seventy-six", 76 },
  { "seventy-seven", 77 },
  { "seventy-eight", 78 },
  { "seventy-nine", 79 },
  { "eighty", 80 },
  { "eighty-one", 81 },
  { "eighty-two", 82 },
  { "eighty-three", 83 },
  { "eighty-four", 84 },
  { "eighty-five", 85 },
  { "eighty-six", 86 },
  { "eighty-seven", 87 },
  { "eighty-eight", 88 },
  { "eighty-nine", 89 },
  { "ninety", 90 },
  { "ninety-one", 91 },
  { "ninety-two", 92 },
  { "ninety-three", 93 },
  { "ninety-four", 94 },
  { "ninety-five", 95 },
  { "ninety-six", 96 },
  { "ninety-seven", 97 },
  { "ninety-eight", 98 },
  { "ninety-nine", 99 },
  { "one hundred", 100 },
};

static bool string_equal (const void *str1, const void *str2);
static size_t string_hash (const void *str);
static void setup_hash_map (void);
static void test_hash_map_get (void);

int
main (void)
{
  setup_hash_map ();
  test_hash_map_get ();

  if (map != NULL)
    hash_map_delete (map);
  return 0;
}

static bool
string_equal (const void *str1, const void *str2)
{
  return strcmp ((const char *) str1, (const char *) str2) == 0;
}

/* djb2 hash */
static size_t
string_hash (const void *str)
{
  size_t hash = 5381;
  const unsigned char *p = (const unsigned char *) str;

  for (; *p != '\0'; ++p)
    hash = ((hash << 5) + hash) + *p;

  return hash;
}

static void
setup_hash_map (void)
{
  size_t i;

  map = hash_map_new (string_hash, string_equal);
  ASSERT (map != NULL);

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    ASSERT (hash_map_put (map, input[i].string, &input[i].value) != NULL);
}

static void
test_hash_map_get (void)
{
  size_t i;
  const void *value;

  for (i = 0; i < ARRAY_SIZE (input); ++i)
    {
      value = hash_map_get (map, input[i].string);
      ASSERT (value != NULL);
      ASSERT (*(const int *) value == (int) i);
      printf ("%s: %d\n", input[i].string, *(const int *) value);
    }

  value = hash_map_get (map, "not in map");
  ASSERT (value == NULL);
}
