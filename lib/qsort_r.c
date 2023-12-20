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

#include <stdlib.h>

#include <stdint.h>
#include <stdio.h>

static void
qsort_swap (unsigned char *a, unsigned char *b, size_t size)
{
  do
    {
      unsigned char value = *a;
      *a++ = *b;
      *b++ = value;
    }
  while (--size > 0);
}

void
qsort_r (void *base, size_t nmemb, size_t size,
         int (*compar) (const void *, const void *, void *), void *arg)
#undef qsort_r
{
  const unsigned char *const floor_ptr = base;
  const unsigned char *const ceil_ptr = &floor_ptr[(nmemb - 1) * size];

  if (nmemb <= 1)
    return;

  /* FIXME: Insertion sort... */
  {
    unsigned char *position = (unsigned char *) &floor_ptr[size * 1];

    for (; position <= ceil_ptr; position += size)
      {
        unsigned char *p1 = position;
        unsigned char *p2 = &p1[size * -1];

        for (; p1 > floor_ptr; p1 -= size, p2 -= size)
          {
            if ((*compar) (p1, p2, arg) >= 0)
              break;
            qsort_swap (p1, p2, size);
          }
      }
  }
}
