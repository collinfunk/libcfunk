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

#include "term-size.h"
#include "test-help.h"

int
main (void)
{
  int height1, height2;
  int width1, width2;

  /* Assume terminal size won't change during these calls. */
  height1 = term_get_height ();
  width1 = term_get_width ();
  if (term_get_size (&height2, &width2) < 0)
    {
      fprintf (stderr, "term_get_size () failed.\n");
      abort ();
    }

  if (height2 < 0)
    {
      fprintf (stderr, "term_get_height () failed.\n");
      abort ();
    }

  if (width2 < 0)
    {
      fprintf (stderr, "term_get_width () failed.\n");
      abort ();
    }

  if (height1 != height2)
    {
      fprintf (stderr, "term_get_size (height, NULL) != term_get_height ()\n");
      abort ();
    }

  if (width1 != width2)
    {
      fprintf (stderr, "term_get_size (NULL, width) != term_get_width ()\n");
      abort ();
    }

  printf ("height ($LINES):  %d\n", height1);
  printf ("width ($COLUMNS): %d\n", width2);

  return 0;
}
