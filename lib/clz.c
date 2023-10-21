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

#include <limits.h>

#include "__has_builtin.h"
#include "clz.h"

int
clz (unsigned int value)
{
#if __has_builtin(__builtin_clz)
  if (value == 0)
    return CHAR_BIT * value;
  return __builtin_clz (value);
#else
  unsigned int bit = 1U << ((sizeof (value) * CHAR_BIT) - 1);
  int count = 0;

  if (value == 0)
    return CHAR_BIT * value;

  while (!(value & bit))
    {
      bit >>= 1;
      ++count;
    }
  return count;
#endif
}

int
clzl (unsigned long int value)
{
#if __has_builtin(__builtin_clzl)
  if (value == 0)
    return CHAR_BIT * value;
  return __builtin_clzl (value);
#else
  unsigned long int bit = 1UL << ((sizeof (value) * CHAR_BIT) - 1);
  int count = 0;

  if (value == 0)
    return CHAR_BIT * value;

  while (!(value & bit))
    {
      bit >>= 1;
      ++count;
    }
  return count;
#endif
}

int
clzll (unsigned long long int value)
{
#if __has_builtin(__builtin_clzll)
  if (value == 0)
    return CHAR_BIT * value;
  return __builtin_clzll (value);
#else
  unsigned long long int bit = 1ULL << ((sizeof (value) * CHAR_BIT) - 1);
  int count = 0;

  if (value == 0)
    return CHAR_BIT * value;

  while (!(value & bit))
    {
      bit >>= 1;
      ++count;
    }
  return count;
#endif
}
