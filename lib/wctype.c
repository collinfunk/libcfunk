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

#include <string.h>
#include <wchar.h>
#include <wctype.h>

/* FIXME: Least optimal way to do this... */
wctype_t
wctype (const char *property)
{
  if (strcmp (property, "alnum") == 0)
    return (wctype_t) iswalnum;
  if (strcmp (property, "alpha") == 0)
    return (wctype_t) iswalpha;
  if (strcmp (property, "blank") == 0)
    return (wctype_t) iswblank;
  if (strcmp (property, "cntrl") == 0)
    return (wctype_t) iswcntrl;
  if (strcmp (property, "digit") == 0)
    return (wctype_t) iswdigit;
  if (strcmp (property, "graph") == 0)
    return (wctype_t) iswgraph;
  if (strcmp (property, "lower") == 0)
    return (wctype_t) iswlower;
  if (strcmp (property, "print") == 0)
    return (wctype_t) iswprint;
  if (strcmp (property, "punct") == 0)
    return (wctype_t) iswpunct;
  if (strcmp (property, "space") == 0)
    return (wctype_t) iswspace;
  if (strcmp (property, "upper") == 0)
    return (wctype_t) iswupper;
  if (strcmp (property, "xdigit") == 0)
    return (wctype_t) iswxdigit;
  else
    return (wctype_t) NULL;
}
