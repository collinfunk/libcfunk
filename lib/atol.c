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

/* #include <config.h> */

#include <ctype.h>
#include <limits.h>
#include <stddef.h>
#include <string.h>

/* XXX: Changes to atoi.c, atol.c, and atoll.c files should, in most cases, be
   used in all of the functions. The example sed commands given below can help
   with this. */
/* sed -e 's/atoi/atol/g' -e 's/int/long int/g' -e 's/INT_MAX/LONG_MAX/g' atoi.c */
/* sed -e 's/atoi/atoll/g' -e 's/int/long long int/g' -e 's/INT_MAX/LLONG_MAX/g' atoi.c */
/* sed -e 's/atoll/atoi/g' -e 's/long long int/int/g' -e 's/LLONG_MAX/INT_MAX/g' atoi.c */

/* Use strol instead of this. */
long int
atol (const char *str)
{
  unsigned char ch;
  long int value;
  long int negative;

  /* Skip leading whitespace characters. */
  while (isspace ((unsigned char) *str))
    str++;

  /* Check for a sign character. */
  switch (*str)
    {
    case '-':
      negative = 1;
      str++;
      break;
    case '+':
      negative = 0;
      str++;
      break;
    default:
      negative = 0;
      break;
    }

  value = 0;
  for (;; ++str)
    {
      ch = *str;

      if (ch == '\0')
        break;
      if (isdigit (ch))
        ch -= '0';
      else
        break;

      /* VALUE * 10 overflows long int. */
      if (value > LONG_MAX / 10)
        return negative ? -LONG_MAX : LONG_MAX;
      else
        {
          value *= 10;
          /* VALUE + CH overflows long int. */
          if (value > LONG_MAX - (long int) ch)
            return negative ? -LONG_MAX : LONG_MAX;
          else
            value += (long int) ch;
        }
    }

  return negative ? -value : value;
}
