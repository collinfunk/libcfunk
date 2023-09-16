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

#include "test-help.h"

/* Get rid of any definition brought in from system headers. */
#undef offsetof
#include "offsetof.h"

/* Typically compilers shouldn't pad between chars. */
struct char_struct
{
  char zero;
  char one;
  char two;
  char three;
};

/* array and word will have padding inbetween. */
struct pad_struct
{
  char array[9];
  long int word;
};

int
main (void)
{
  ASSERT (offsetof (struct char_struct, zero) == 0);
  ASSERT (offsetof (struct char_struct, one) == 1);
  ASSERT (offsetof (struct char_struct, two) == 2);
  ASSERT (offsetof (struct char_struct, three) == 3);
  ASSERT (offsetof (struct pad_struct, array) == 0);
  /* This is system-dependent but is typically 12 or 16. */
  ASSERT (offsetof (struct pad_struct, word) == 12
          || offsetof (struct pad_struct, word) == 16);
  return 0;
}
