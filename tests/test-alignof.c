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
#include <stdio.h>
#include <stdlib.h>

#include "alignof.h"
#include "offsetof.h"
#include "test-help.h"

struct char_struct
{
  char a;
  char b;
};

struct short_struct
{
  char a;
  short b;
};

struct int_struct
{
  char a;
  int b;
};

struct long_struct
{
  char a;
  long int b;
};

struct long_long_struct
{
  char a;
  long long int b;
};

struct uchar_struct
{
  char a;
  unsigned char b;
};

struct ushort_struct
{
  char a;
  unsigned short b;
};

struct uint_struct
{
  char a;
  unsigned int b;
};

struct ulong_struct
{
  char a;
  unsigned long int b;
};

struct ulong_long_struct
{
  char a;
  unsigned long long int b;
};

int
main (void)
{
  ASSERT (alignof (char) == 1);
  ASSERT (alignof (int8_t) == 1);
  ASSERT (alignof (int16_t) == 2);
  ASSERT (alignof (int32_t) == 4);
  ASSERT (alignof (int64_t) == 8);
  ASSERT (alignof (unsigned char) == 1);
  ASSERT (alignof (uint8_t) == 1);
  ASSERT (alignof (uint16_t) == 2);
  ASSERT (alignof (uint32_t) == 4);
  ASSERT (alignof (uint64_t) == 8);
  ASSERT (alignof (struct char_struct) == offsetof (struct char_struct, b));
  ASSERT (alignof (struct short_struct) == offsetof (struct short_struct, b));
  ASSERT (alignof (struct long_struct) == offsetof (struct long_struct, b));
  ASSERT (alignof (struct long_long_struct)
          == offsetof (struct long_long_struct, b));
  ASSERT (alignof (struct uchar_struct) == offsetof (struct uchar_struct, b));
  ASSERT (alignof (struct ushort_struct)
          == offsetof (struct ushort_struct, b));
  ASSERT (alignof (struct ulong_struct) == offsetof (struct ulong_struct, b));
  ASSERT (alignof (struct ulong_long_struct)
          == offsetof (struct ulong_long_struct, b));
  return 0;
}
