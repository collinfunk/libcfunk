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
  return ARMAG[0] == '!' && ARMAG[1] == '<' && ARMAG[2] == 'a'
                 && ARMAG[3] == 'r' && ARMAG[4] == 'c' && ARMAG[5] == 'h'
                 && ARMAG[6] == '>' && ARMAG[7] == '\n' && ARMAG[8] == '\0'
                 && AR_EFMT1[0] == '#' && AR_EFMT1[1] == '1'
                 && AR_EFMT1[2] == '/' && AR_EFMT1[3] == '\0'
                 && ARFMAG[0] == '`' && ARFMAG[1] == '\n' && ARFMAG[2] == '\0'
             ? 0
             : 1;
}
