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

#include <byteswap.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

#define VAL16 ((uint16_t) 0x1234U)
#define VAL32 ((uint32_t) 0x12345678UL)
#define VAL64 ((uint64_t) 0x1234567890abcdefULL)

#define VAL16_SWAPPED ((uint16_t) 0x3412U)
#define VAL32_SWAPPED ((uint32_t) 0x78563412UL)
#define VAL64_SWAPPED ((uint64_t) 0xefcdab9078563412ULL)

int
main (void)
{
  ASSERT (bswap_16 (VAL16) == VAL16_SWAPPED);
  ASSERT (bswap_32 (VAL32) == VAL32_SWAPPED);
  ASSERT (bswap_64 (VAL64) == VAL64_SWAPPED);
  ASSERT (bswap_16 (VAL16_SWAPPED) == VAL16);
  ASSERT (bswap_32 (VAL32_SWAPPED) == VAL32);
  ASSERT (bswap_64 (VAL64_SWAPPED) == VAL64);
  return 0;
}
