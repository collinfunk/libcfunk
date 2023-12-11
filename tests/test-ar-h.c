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

#include <ar.h>

#include "attributes.h"

/* Old UNIX 'ar' magic values. */
static_assert (OARMAG1 == 0177555);
static_assert (OARMAG2 == 0177545);

/* Length of the 'ARMAG' string. */
static_assert (SARMAG == 8);

/* Make sure that 'struct ar_hdr' is the proper size. If this assertion fails
   then you should try adding '__attribute__ ((__packed__))' to the struct
   definition. This should nearly always be unnecessary though. */
static_assert (sizeof (struct ar_hdr) == 60);

/* Check that 'ar.h' can be included. */
int
main (void)
{
  char armag[] = ARMAG;
  char ar_efmt1[] = AR_EFMT1;
  char arfmag[] = ARFMAG;

  if ((armag[0] != '!') || (armag[1] != '<') || (armag[2] != 'a')
      || (armag[3] != 'r') || (armag[4] != 'c') || (armag[5] != 'h')
      || (armag[6] != '>') || (armag[7] != '\n') || (armag[8] != '\0'))
    return 1;
  if ((ar_efmt1[0] != '#') || (ar_efmt1[1] != '1') || (ar_efmt1[2] != '/')
      || (ar_efmt1[3] != '\0'))
    return 1;
  if ((arfmag[0] != '`') || (arfmag[1] != '\n') || (arfmag[2] != '\0'))
    return 1;

  return 0;
}
