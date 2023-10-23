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
#include <wchar.h>
#include <wctype.h>

#include "test-help.h"

static void validate_equal (const char *charclass, int (*function) (wint_t));

int
main (void)
{
  validate_equal ("alnum", iswalnum);
  validate_equal ("alpha", iswalpha);
  /* FIXME: Windows doesn't have this... */
#if !HAVE_WINDOWS_H
  validate_equal ("blank", iswblank);
#endif
  validate_equal ("cntrl", iswcntrl);
  validate_equal ("digit", iswdigit);
  validate_equal ("graph", iswgraph);
  validate_equal ("lower", iswlower);
  validate_equal ("print", iswprint);
  validate_equal ("space", iswspace);
  validate_equal ("upper", iswupper);
  validate_equal ("xdigit", iswxdigit);
  return 0;
}

/* Checks the input CHARCLASS string for 'wctype' is equal to the given
   function from 'wctype.h'. */
static void
validate_equal (const char *charclass, int (*function) (wint_t))
{
  wint_t i;
  wctype_t desc;

  desc = wctype (charclass);
  ASSERT (desc != (wctype_t) 0);

  for (i = 0; i < 256; ++i)
    ASSERT ((iswctype (i, desc) > 0) == ((*function) (i) > 0));
}
