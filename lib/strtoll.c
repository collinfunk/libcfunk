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

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

long long int
strtoll (const char *restrict nptr, char **restrict endptr, int base)
#undef strtoll
{
  const char *p;
  const char *start;
  unsigned long long int value;
  unsigned long long int mul_max;
  unsigned long long int add_max;
  int negative;
  int overflow;

  if (base < 0 || base == 1 || base > 36)
    {
      errno = EINVAL;
      return 0;
    }

  for (p = nptr; isspace ((unsigned char) *p); ++p)
    ;

  switch (*p)
    {
    case '-':
      negative = 1;
      p++;
      break;
    case '+':
      negative = 0;
      p++;
      break;
    default:
      negative = 0;
      break;
    }

  if (p[0] != '0')
    {
      if (base == 0)
        base = 10;
    }
  else
    {
      if (p[1] == 'X' || p[1] == 'x')
        {
          if (base == 0 || base == 16)
            {
              p += 2;
              base = 16;
            }
        }
      else if (p[1] == 'B' || p[1] == 'b')
        {
          if (base == 0 || base == 2)
            {
              p += 2;
              base = 2;
            }
        }
      else
        base = 8;
    }

  mul_max = ULLONG_MAX / (unsigned long long int) base;
  add_max = ULLONG_MAX % (unsigned long long int) base;

  start = p;

  value = 0ULL;
  overflow = 0;
  for (;; ++p)
    {
      unsigned char ch = (unsigned char) *p;
      if (ch == '\0')
        break;
      if (isdigit (ch))
        ch -= '0';
      else if (isalpha (ch))
        ch = isupper (ch) ? ch - 'A' : ch - 'a';
      if ((int) ch >= base)
        break;
      if (value > mul_max
          || (value == mul_max && (unsigned long long int) ch > add_max))
        overflow = 1;
      else
        {
          value *= (unsigned long long int) base;
          value += (unsigned long long int) ch;
        }
    }

  if (p == start)
    {
      if (endptr != NULL)
        {
          if (p - nptr >= 2 && p[-2] == '0'
              && ((p[-1] == 'X' || p[-1] == 'x')
                  || (p[-1] == 'B' || p[-1] == 'b')))
            *endptr = (char *) p - 1;
          else
            *endptr = (char *) nptr;
        }
      return 0LL;
    }

  if (endptr != NULL)
    *endptr = (char *) p;

  if (!overflow)
    {
      if (value > (negative ? -((unsigned long long int) (LLONG_MIN + 1)) + 1
                            : LLONG_MAX))
        overflow = 1;
    }

  if (overflow)
    {
      errno = ERANGE;
      return negative ? LLONG_MIN : LLONG_MAX;
    }

  return negative ? (long long int) -value : (long long int) value;
}
