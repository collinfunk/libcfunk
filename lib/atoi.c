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
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

/* The name of this function. */
#ifndef ATOI_FUNC_NAME
#  define ATOI_FUNC_NAME atoi
#endif

/* The return type of this function. */
#ifndef ATOI_INT_TYPE
#  define ATOI_INT_TYPE int
#endif

/* The signed representation of the return type. */
#ifndef ATOI_SIGNED_INT_TYPE
#  define ATOI_SIGNED_INT_TYPE signed int
#endif

/* The unsigned representation of the return type. */
#ifndef ATOI_UNSIGNED_INT_TYPE
#  define ATOI_UNSIGNED_INT_TYPE unsigned int
#endif

/* The maximum value that can be held in the return type. */
#ifndef ATOI_INT_MAX
#  define ATOI_INT_MAX INT_MAX
#endif

/* The minimum value that can be held in the return type. */
#ifndef ATOI_INT_MIN
#  define ATOI_INT_MIN INT_MIN
#endif

/* The maximum value that can be held in the signed representation of the
   return type. */
#ifndef ATOI_SIGNED_INT_MAX
#  define ATOI_SIGNED_INT_MAX INT_MAX
#endif

/* The minimum value that can be held in the signed representation of the
   return type. */
#ifndef ATOI_SIGNED_INT_MIN
#  define ATOI_SIGNED_INT_MIN INT_MIN
#endif

/* The maximum value that can be held in the unsigned representation of the
   return type. */
#ifndef ATOI_UNSIGNED_INT_MAX
#  define ATOI_UNSIGNED_INT_MAX UINT_MAX
#endif

/* The minimum value that can be held in the unsigned representation of the
   return type. */
#ifndef ATOI_UNSIGNED_INT_MIN
#  define ATOI_UNSIGNED_INT_MIN UINT_MIN
#endif

ATOI_INT_TYPE
ATOI_FUNC_NAME (const char *str)
{
  int negative;
  ATOI_UNSIGNED_INT_TYPE value;

  /* Skip all white-space characters as specified by isspace(3). */
  while (isspace ((unsigned char) *str))
    str++;

  /* Check for a sign character like strtol(3). */
  switch (*str)
    {
    case '-':
      str++;
      negative = 1;
      break;
    case '+':
      str++;
      /* fallthrough */
    default:
      negative = 0;
      break;
    }

  for (value = 0;; ++str)
    {
      unsigned char ch = *str;

      /* End of string. */
      if (ch == '\0')
        break;

      if (isdigit (ch))
        ch -= '0';
      else /* !isdigit (ch) */
        break;

      /* If VALUE * 10 overflows ATOI_UNSIGNED_INT_TYPE, it will overflow
         ATOI_INT_TYPE. */
      if (value > ATOI_UNSIGNED_INT_MAX / 10)
        return negative ? ATOI_INT_MIN : ATOI_INT_MAX;
      else
        {
          value *= 10;
          /* If VALUE + CH overflows ATOI_UNSIGNED_INT_TYPE, it will overflow
             ATOI_INT_TYPE. */
          if (value > ATOI_UNSIGNED_INT_MAX - (ATOI_UNSIGNED_INT_TYPE) ch)
            return negative ? ATOI_INT_MIN : ATOI_INT_MAX;
          else
            value += (ATOI_UNSIGNED_INT_TYPE) ch;
        }
    }

  /* Check that VALUE can safely be converted to the return value type.
     If it cannot be done, return ATOI_INT_MIN if the input string had
     a '-' prefix or ATOI_INT_MAX if there was a '+' prefix or no prefix. */
  if (negative)
    {
      if (value > (ATOI_UNSIGNED_INT_TYPE) - (ATOI_INT_MIN + ATOI_INT_MAX)
                      + ATOI_INT_MAX)
        return ATOI_INT_MIN;
      else
        return (ATOI_INT_TYPE) -value;
    }
  else /* Positive */
    {
      if (value > (ATOI_UNSIGNED_INT_TYPE) ATOI_INT_MAX)
        return ATOI_INT_MAX;
      else
        return (ATOI_INT_TYPE) value;
    }
}

#undef ATOI_FUNC_NAME
#undef ATOI_INT_TYPE
#undef ATOI_SIGNED_INT_TYPE
#undef ATOI_UNSIGNED_INT_TYPE
#undef ATOI_INT_MAX
#undef ATOI_INT_MIN
#undef ATOI_SIGNED_INT_MAX
#undef ATOI_SIGNED_INT_MIN
#undef ATOI_UNSIGNED_INT_MAX
#undef ATOI_UNSIGNED_INT_MIN
