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

int
main (void)
{
  ASSERT (wctype ("invalid string") == (wctype_t) 0);
  ASSERT (wctype ("alnum") != (wctype_t) 0);
  ASSERT (wctype ("alpha") != (wctype_t) 0);
  /* FIXME: Windows doesn't have this... */
#if !HAVE_WINDOWS_H
  ASSERT (wctype ("blank") != (wctype_t) 0);
#endif
  ASSERT (wctype ("cntrl") != (wctype_t) 0);
  ASSERT (wctype ("digit") != (wctype_t) 0);
  ASSERT (wctype ("graph") != (wctype_t) 0);
  ASSERT (wctype ("lower") != (wctype_t) 0);
  ASSERT (wctype ("print") != (wctype_t) 0);
  ASSERT (wctype ("space") != (wctype_t) 0);
  ASSERT (wctype ("upper") != (wctype_t) 0);
  ASSERT (wctype ("xdigit") != (wctype_t) 0);
  return 0;
}
