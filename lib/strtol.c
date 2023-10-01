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

/* The name of this function. */
#ifndef STRTOL_FUNC_NAME
#  define STRTOL_FUNC_NAME strtol
#endif

/* The integer type that this function returns. May be signed or unsigned. */
#ifndef STRTOL_INT_TYPE
#  define STRTOL_INT_TYPE long int
#endif

/* The signed integer representation of the return type. */
#ifndef STRTOL_SIGNED_INT_TYPE
#  define STRTOL_SIGNED_INT_TYPE signed long int
#endif

/* The unsigned integer representation of the return type. */
#ifndef STRTOL_UNSIGNED_INT_TYPE
#  define STRTOL_UNSIGNED_INT_TYPE unsigned long int
#endif

/* The maximum value that can be represented in the return type. */
#ifndef STRTOL_INT_MAX
#  define STRTOL_INT_MAX LONG_MAX
#endif

/* The minimum value that can be represented in the return type. */
#ifndef STRTOL_INT_MIN
#  define STRTOL_INT_MIN LONG_MIN
#endif

/* The maximum value that can be held in the signed representation of the
   return type. */
#ifndef STRTOL_SIGNED_INT_MAX
#  define STRTOL_SIGNED_INT_MAX LONG_MAX
#endif

/* The minimum value that can be held in the signed representation of the
   return type. */
#ifndef STRTOL_SIGNED_INT_MIN
#  define STRTOL_SIGNED_INT_MIN LONG_MIN
#endif

/* The maximum value that can be held in the unsigned representation of the
   return type. */
#ifndef STRTOL_UNSIGNED_INT_MAX
#  define STRTOL_UNSIGNED_INT_MAX ULONG_MAX
#endif

/* The minimum value that can be held in the unsigned representation of the
   return type. */
#ifndef STRTOL_UNSIGNED_INT_MIN
#  define STRTOL_UNSIGNED_INT_MIN 0UL
#endif

/* Defined to 1 if this function is returning an unsigned integer or 0 if it
   is returning a signed integer. */
#ifndef STRTOL_RETURN_UNSIGNED
#  define STRTOL_RETURN_UNSIGNED 0
#endif

/* This should be defined to 1 if the resulting function should recognize
   base 2 integers with the '0b' or '0B' prefix. */
#ifndef STRTOL_SUPPORT_C23
#  define STRTOL_SUPPORT_C23 1
#endif

STRTOL_INT_TYPE
STRTOL_FUNC_NAME (const char *str, char **endptr, int base)
{
  const char *p;
  const char *start;
  STRTOL_UNSIGNED_INT_TYPE value;
  unsigned char ch;
  int negative;
  int overflow;

  /* If a non-zero base is given it must be between 2 and 36. */
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

  /* Check for a prefix only if the first character is '0'. */
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
#if STRTOL_SUPPORT_C23
        case 'b':
          /* Fallthrough */
        case 'B':
          /* Binary constant. */
          if (base == 0 || base == 2)
            {
              p += 2;
              base = 2;
            }
          break;
#endif
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

      /* Check if VALUE * BASE would overflow unsigned long int. */
      if (value > STRTOL_UNSIGNED_INT_MAX / (STRTOL_UNSIGNED_INT_TYPE) base)
        {
          overflow = 1;
          break;
        }
      else
        {
          value *= (STRTOL_UNSIGNED_INT_TYPE) base;

          /* Check if VALUE + CH would overflow unsigned long int. */
          if (value > STRTOL_UNSIGNED_INT_MAX - (STRTOL_UNSIGNED_INT_TYPE) ch)
            {
              overflow = 1;
              break;
            }
          value += (STRTOL_UNSIGNED_INT_TYPE) ch;
        }
    }

  if (p == start)
    {
      /* FIXME: I don't think the else case (no prefix) is possible since we
         check for an empty string after whitespace in the switch statement.
         Also maybe set EINVAL here? */
      if (endptr != NULL)
        {
          /* Return the last character of the prefix if we have one. */
          if (p - str >= 2 && p[-2] == '0')
            {
              if (p[-1] == 'x' || p[-1] == 'X')
                *endptr = (char *) p - 1;
#if STRTOL_SUPPORT_C23
              if (p[-1] == 'b' || p[-1] == 'B')
                *endptr = (char *) p - 1;
#endif
              else
                *endptr = (char *) str;
            }
          else
            *endptr = (char *) str;
        }
      return 0;
    }

  /* If ENDPTR isn't NULL, set it to the character that caused the loop
     to break. */
  if (endptr != NULL)
    *endptr = (char *) p;

#if STRTOL_RETURN_UNSIGNED
  if (overflow)
    {
      errno = ERANGE;
      return STRTOL_INT_MAX;
    }
#else
  /* Check for overflow that did not terminate the loop. */
  if (!overflow)
    {
      if (!negative)
        overflow = value > (STRTOL_UNSIGNED_INT_TYPE) STRTOL_INT_MAX;
      else
        {
          overflow = value > (STRTOL_UNSIGNED_INT_TYPE)
                                 - (STRTOL_INT_MIN + STRTOL_INT_MAX)
                                 + STRTOL_INT_MAX;
        }
    }

  /* Actually check for overflow. */
  if (overflow)
    {
      errno = ERANGE;
      return negative ? STRTOL_INT_MIN : STRTOL_INT_MAX;
    }
#endif

  return negative ? (STRTOL_INT_TYPE) -value : (STRTOL_INT_TYPE) value;
}

#undef STRTOL_FUNC_NAME
#undef STRTOL_INT_TYPE
#undef STRTOL_SIGNED_INT_TYPE
#undef STRTOL_UNSIGNED_INT_TYPE
#undef STRTOL_INT_MAX
#undef STRTOL_INT_MIN
#undef STRTOL_SIGNED_INT_MAX
#undef STRTOL_SIGNED_INT_MIN
#undef STRTOL_UNSIGNED_INT_MAX
#undef STRTOL_UNSIGNED_INT_MIN
#undef STRTOL_RETURN_UNSIGNED
#undef STRTOL_SUPPORT_C23
