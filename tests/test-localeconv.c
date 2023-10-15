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
#include <stdio.h>
#include <locale.h>

#include "test-help.h"

int
main (void)
{
  struct lconv *buffer = localeconv ();
  ASSERT (buffer != NULL);
  printf ("decimal_point:      %s\n", buffer->decimal_point);
  printf ("thousands_sep:      %s\n", buffer->thousands_sep);
  printf ("grouping:           %s\n", buffer->grouping);
  printf ("int_curr_symbol:    %s\n", buffer->int_curr_symbol);
  printf ("currency_symbol:    %s\n", buffer->currency_symbol);
  printf ("mon_decimal_point:  %s\n", buffer->mon_decimal_point);
  printf ("mon_thousands_sep:  %s\n", buffer->mon_thousands_sep);
  printf ("mon_grouping:       %s\n", buffer->mon_grouping);
  printf ("positive_sign:      %s\n", buffer->positive_sign);
  printf ("negative_sign:      %s\n", buffer->negative_sign);
  printf ("int_frac_digits:    %d\n", buffer->int_frac_digits);
  printf ("frac_digits:        %d\n", buffer->frac_digits);
  printf ("p_cs_precedes:      %d\n", buffer->p_cs_precedes);
  printf ("p_sep_by_space:     %d\n", buffer->p_sep_by_space);
  printf ("n_cs_precedes:      %d\n", buffer->n_cs_precedes);
  printf ("n_sep_by_space:     %d\n", buffer->n_sep_by_space);
  printf ("p_sign_posn:        %d\n", buffer->p_sign_posn);
  printf ("n_sign_posn:        %d\n", buffer->n_sign_posn);

  /* FIXME: Missing on some systems.
     printf ("int_p_cs_precedes:  %d\n", buffer->int_p_cs_precedes);
     printf ("int_p_sep_by_space: %d\n", buffer->int_p_sep_by_space);
     printf ("int_n_cs_precedes:  %d\n", buffer->int_n_cs_precedes);
     printf ("int_n_sep_by_space: %d\n", buffer->int_n_sep_by_space);
     printf ("int_p_sign_posn:    %d\n", buffer->int_p_sign_posn);
     printf ("int_n_sign_posn:    %d\n", buffer->int_n_sign_posn);
  */

  return 0;
}
