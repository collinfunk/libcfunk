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
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

/* XXX: Changes to stroul.c, strtoull.c, and strtoumax.c files should, in most
   cases, be used in all of the functions. The example sed commands given
   below can help with this. */
/* sed -e 's/strtoul/strtoull/g' -e 's/unsigned long int/unsigned long long int/g' \
   -e 's/ULONG_MAX/ULLONG_MAX/g' strtoul.c */
/* sed -e 's/strtoul/strtoumax/g' -e 's/unsigned long int/uintmax_t/g' \
   -e 's/ULONG_MAX/UINTMAX_MAX/g' strtoul.c */

unsigned long long int
strtoull (const char *str, char **endptr, int base)
{
  const char *p;
  const char *start;
  unsigned long long int value;
  unsigned char ch;
  int negative;
  int overflow;

  /* Base must be a value between 2 and 36. If it is 0, then assumptions are
     made based on the prefix of the string. */
  if (base < 0 || base == 1 || base > 36)
    {
      errno = EINVAL;
      return 0;
    }

  /* Skip leading whitespace characters. */
  for (p = str; isspace ((unsigned char) *p); ++p)
    ;

  /* Check for a sign character. */
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
    case '\0':
      /* Empty string. */
      if (endptr != NULL)
        *endptr = (char *) str;
      return 0;
    default:
      negative = 0;
      break;
    }

  if (*p != '0')
    {
      /* Default to a base 10 integer. */
      if (base == 0)
        base = 10;
    }
  else /* *p == '0' */
    {
      switch (p[1])
        {
        case 'x':
          /* Fallthrough */
        case 'X':
          /* Hexadecimal constant. */
          if (base == 0 || base == 16)
            {
              p += 2;
              base = 16;
            }
          break;
        default:
          /* Octal constant. */
          base = 8;
          break;
        }
    }

  /* Save the starting position. Note that START refers to the start of the
     digit sequence (after any whitespace), while STR refers to the start of
     the string passed by the user. This is used to check whether any
     conversion was performed. If none was performed ENDPTR must be set
     to STR. */
  start = p;

  value = 0;
  overflow = 0;
  for (;; ++p)
    {
      ch = *p;

      if (ch == '\0')
        break;

      if (isdigit (ch))
        ch -= '0';
      else if (isalpha (ch))
        ch = isupper (ch) ? ch - 55 : ch - 87;

      /* Check if the current character exceeds our base. */
      if ((int) ch >= base)
        break;

      /* Check if VALUE * BASE would overflow unsigned long long int. */
      if (value > ULLONG_MAX / (unsigned long long int) base)
        {
          overflow = 1;
          break;
        }
      else
        {
          value *= (unsigned long long int) base;

          /* Check if VALUE + CH would overflow unsigned long long int. */
          if (value > ULLONG_MAX - (unsigned long long int) ch)
            {
              overflow = 1;
              break;
            }
          value += (unsigned long long int) ch;
        }
    }

  if (p == start)
    {
      /* FIXME: The don't think the else case (no prefix) is possible since we
         check for an empty string after whitespace in the switch statement.
         Also maybe set EINVAL here? */
      if (endptr != NULL)
        {
          /* Return a pointer to the 'x' of the "0x" prefix if we have one. */
          if (p - str >= 2 && p[-2] == '0' && (p[-1] == 'x' || p[-1] == 'X'))
            *endptr = (char *) p - 1;
          else
            *endptr = (char *) str;
        }
      return 0;
    }

  /* If ENDPTR isn't NULL, set it to the character that caused the loop
     to break. */
  if (endptr != NULL)
    *endptr = (char *) p;

  /* Check if we broke the loop because of an overflow. */
  if (overflow)
    {
      errno = ERANGE;
      return ULLONG_MAX;
    }

  return negative ? -value : value;
}
