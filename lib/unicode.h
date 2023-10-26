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

#ifndef UNICODE_H
#define UNICODE_H

#include <stddef.h>
#include <stdint.h>

/* All functions written using the Unicode 15.1.0 standard:
   https://www.unicode.org/versions/Unicode15.1.0/
 */

/* Returns the number of code units which make up the character starting at
   the first unit of S. If there is an invalid sequence -1 is returned. */
extern int utf8_mblen (const uint8_t *s, size_t n);
extern int utf16_mblen (const uint16_t *s, size_t n);
extern int utf32_mblen (const uint32_t *s, size_t n);

/* Returns the number of code units which make up the character starting at the
   first unit of S. The character is then stored in PWC as a 32-bit wide
   character. We use 'uint32_t' since Windows uses a 16-bit short int for
   'wchar_t'. If S contains an invalid sequence -1 is returned. If S contains
   an incomplete multibyte character than -2 is returned. In both cases 0xfffd
   is placed in PWC. */
/* extern int utf8_mbtowc (uint32_t *pwc, const uint8_t *s, size_t n); */
extern int utf16_mbtowc (uint32_t *pwc, const uint16_t *s, size_t n);
extern int utf32_mbtowc (uint32_t *pwc, const uint32_t *s, size_t n);

/* These functions are the exact same as 'strcpy' as specified by ISO C except
   that they operate on 8-bit, 16-bit, or 32-bit code units. */
extern uint8_t *utf8_strcpy (uint8_t *s1, const uint8_t *s2);
extern uint16_t *utf16_strcpy (uint16_t *s1, const uint16_t *s2);
extern uint32_t *utf32_strcpy (uint32_t *s1, const uint32_t *s2);

/* These functions are the exact same as 'stpcpy' as specified by POSIX except
   that they operate on 8-bit, 16-bit, or 32-bit code units. */
extern uint8_t *utf8_stpcpy (uint8_t *s1, const uint8_t *s2);
extern uint16_t *utf16_stpcpy (uint16_t *s1, const uint16_t *s2);
extern uint32_t *utf32_stpcpy (uint32_t *s1, const uint32_t *s2);

/* These functions are the exact same as 'strlen' as specified by ISO C except
   that they operate on 8-bit, 16-bit, or 32-bit code units. */
extern size_t utf8_strlen (const uint8_t *s1);
extern size_t utf16_strlen (const uint16_t *s1);
extern size_t utf32_strlen (const uint32_t *s1);

#endif /* UNICODE_H */
