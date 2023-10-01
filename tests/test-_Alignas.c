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
#include <stdint.h>

#include "_Alignas.h"
#include "test-help.h"

#define CHECK_ALIGNMENT(variable, alignment)                                  \
  (((uintptr_t) & (variable) % (alignment)) == 0)

int
main (void)
{
  _Alignas (16) char aligned_char = 0;
  _Alignas (16) short aligned_short = 0;
  _Alignas (16) int aligned_int = 0;
  _Alignas (16) long int aligned_long = 0;
  _Alignas (16) long long int aligned_long_long = 0;
  _Alignas (16) unsigned char aligned_uchar = 0;
  _Alignas (16) unsigned short aligned_ushort = 0;
  _Alignas (16) unsigned int aligned_uint = 0;
  _Alignas (16) unsigned long int aligned_ulong = 0;
  _Alignas (16) unsigned long long int aligned_ulong_long = 0;
  ASSERT (CHECK_ALIGNMENT (aligned_char, 16));
  ASSERT (CHECK_ALIGNMENT (aligned_short, 16));
  ASSERT (CHECK_ALIGNMENT (aligned_int, 16));
  ASSERT (CHECK_ALIGNMENT (aligned_long, 16));
  ASSERT (CHECK_ALIGNMENT (aligned_long_long, 16));
  ASSERT (CHECK_ALIGNMENT (aligned_uchar, 16));
  ASSERT (CHECK_ALIGNMENT (aligned_ushort, 16));
  ASSERT (CHECK_ALIGNMENT (aligned_uint, 16));
  ASSERT (CHECK_ALIGNMENT (aligned_ulong, 16));
  ASSERT (CHECK_ALIGNMENT (aligned_ulong_long, 16));
  return 0;
}
