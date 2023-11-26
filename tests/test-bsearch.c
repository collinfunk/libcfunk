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

#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

struct item
{
  int value;
  char *string;
};

static const struct item items[10]
    = { { 0, "zero" },  { 1, "one" },  { 2, "two" }, { 3, "three" },
        { 4, "four" },  { 5, "five" }, { 6, "six" }, { 7, "seven" },
        { 8, "eight" }, { 9, "nine" } };

static int item_compare (const void *a_ptr, const void *b_ptr);

int
main (void)
{
  size_t i;
  struct item key;
  struct item *ptr;

  for (i = 0; i < ARRAY_SIZE (items) * 2; ++i)
    {
      key.value = (int) i;
      ptr = bsearch (&key, items, ARRAY_SIZE (items), sizeof (struct item),
                     item_compare);
      if (i < ARRAY_SIZE (items))
        {
          ASSERT (ptr != NULL);
          ASSERT (ptr->value == key.value);
        }
      else
        ASSERT (ptr == NULL);
    }

  return 0;
}

static int
item_compare (const void *a_ptr, const void *b_ptr)
{
  const struct item *a = (const struct item *) a_ptr;
  const struct item *b = (const struct item *) b_ptr;

  return a->value - b->value;
}
