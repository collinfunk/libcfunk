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

#include <tar.h>

static_assert (TMAGLEN == 6);
static_assert (TVERSLEN == 2);
static_assert (REGTYPE == '0');
static_assert (AREGTYPE == '\0');
static_assert (LNKTYPE == '1');
static_assert (SYMTYPE == '2');
static_assert (CHRTYPE == '3');
static_assert (BLKTYPE == '4');
static_assert (DIRTYPE == '5');
static_assert (FIFOTYPE == '6');
static_assert (CONTTYPE == '7');
static_assert (TSUID == 04000);
static_assert (TSGID == 02000);
static_assert (TSVTX == 01000);
static_assert (TUREAD == 00400);
static_assert (TUWRITE == 00200);
static_assert (TUEXEC == 00100);
static_assert (TGREAD == 00040);
static_assert (TGWRITE == 00020);
static_assert (TGEXEC == 00010);
static_assert (TOREAD == 00004);
static_assert (TOWRITE == 00002);
static_assert (TOEXEC == 00001);

int
main (void)
{
  char tmagic[] = TMAGIC;
  char tversion[] = TVERSION;

  if ((tmagic[0] != 'u') || (tmagic[1] != 's') || (tmagic[2] != 't')
      || (tmagic[3] != 'a') || (tmagic[4] != 'r') || (tmagic[5] != '\0'))
    return 1;
  if ((tversion[0] != '0') || (tversion[1] != '0') || (tversion[2] != '\0'))
    return 1;
  return 0;
}
