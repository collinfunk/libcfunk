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

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#if HAVE_LANGINFO_H
#  include <langinfo.h>
#endif

#if HAVE_LOCALE_H
#  include <locale.h>
#endif

#if HAVE_XLOCALE_H
#  include <xlocale.h>
#endif

#if HAVE_WINDOWS_H
#  include <windows.h>
#endif

#if HAVE_WINNLS_H
#  include <winnls.h>
#endif

/* TODO: OS-specific locales. */

const char *
locale_charset (void)
{
  const char *charset = NULL;

#if HAVE_NL_LANGINFO_CODESET
  charset = nl_langinfo (CODESET);
#endif

  if (charset == NULL)
    charset = "ASCII";
  else
    {
      if (charset[0] == 'C' && charset[1] == '\0')
        charset = "ASCII";
    }

  return charset;
}
