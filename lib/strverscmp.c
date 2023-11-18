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
#include <stddef.h>
#include <string.h>

int
strverscmp (const char *s1, const char *s2)
#undef strverscmp
{
  const unsigned char *p1 = (const unsigned char *) s1;
  const unsigned char *p2 = (const unsigned char *) s2;

  while (*p1 != '\0' && *p2 != '\0')
    {
      /* Unless both strings are at digits, act like strcmp(3). */
      if (!isdigit (*p1) || !isdigit (*p2))
        {
          do
            {
              if (*p1 != *p2)
                return *p1 - *p2;
              else
                {
                  ++p1;
                  ++p2;
                  if (*p1 == '\0')
                    return *p1 - *p2;
                }
            }
          while (!isdigit (*p1) || !isdigit (*p2));
        }
      /* Treat numbers with more leading zero's as smaller. */
      if (*p1 == '0' || *p2 == '0')
        {
          size_t leading_zeros1 = 0;
          size_t leading_zeros2 = 0;

          /* Count the leading zeros in each string. */
          for (; *p1 == '0'; ++p1, ++leading_zeros1)
            ;
          for (; *p2 == '0'; ++p2, ++leading_zeros2)
            ;

          if (leading_zeros1 != leading_zeros2)
            return (int) (leading_zeros2 - leading_zeros1) < 0 ? -1 : 1;
          else /* leading_zeros1 == leading_zeros2 */
            {
              if (!isdigit (*p1) && isdigit (*p2))
                return 1;
              if (isdigit (*p1) && !isdigit (*p2))
                return -1;
            }
        }
      else /* *p1 != '0' && *p2 != '0' */
        {
          const unsigned char *save1 = p1;
          const unsigned char *save2 = p2;
          size_t digit_len1, digit_len2;

          /* Count the number if digits in each string. */
          for (; isdigit (*p1); ++p1)
            ;
          for (; isdigit (*p2); ++p2)
            ;

          digit_len1 = p1 - save1;
          digit_len2 = p2 - save2;

          if (digit_len1 != digit_len2)
            return digit_len1 - digit_len2;
          else /* digit_len1 == digit_len2 */
            {
              p1 = save1;
              p2 = save2;
            }
        }

      /* Compare each digit. */
      for (; isdigit (*p1) && isdigit (*p2); ++p1, ++p2)
        {
          if (*p1 != *p2)
            return *p1 - *p2;
        }
    }

  return *p1 - *p2;
}
