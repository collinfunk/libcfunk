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

#include <sys/random.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#undef ARRAY_SIZE

#define ARRAY_SIZE(array) (sizeof (array) / sizeof (array[0]))

/* Characters that are valid for a filename. These are placed randomly at the
   end of a temporary filename. Copy pasted from the Base64 alphabet - "+/". */
static const char tempname_chars[62]
    = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

/* Given that the characters for the suffix are generated with decent
   randomness, creating two files with the same suffix should be rare.
   This function will retry for MKDTMP_TRIES just incase. */
#define MKDTEMP_TRIES 32

char *
mkdtemp (char *template)
{
  int result;
  size_t template_len;
  char *xsuffix;
  int tries;
  unsigned char rand_buffer[6];
  size_t i;

  if (template == NULL)
    goto bad_input;

  /* Make sure template is at least 6 characters. */
  template_len = strlen (template);
  if (template_len < 6)
    goto bad_input;

  /* Make sure the last 6 characters are all 'X'. */
  xsuffix = template + template_len - 6;
  if (memcmp (xsuffix, "XXXXXX", 6) != 0)
    goto bad_input;

  /* Try to make a temporary directory until we reach MKDTMP_TRIES. */
  for (tries = 0; tries < MKDTEMP_TRIES; ++tries)
    {
      /* TODO: Use a backup for getrandom(2)? */
      if (getrandom (rand_buffer, sizeof (rand_buffer), GRND_NONBLOCK)
          == sizeof (rand_buffer))
        {
          /* Map the random bytes to filename characters. */
          for (i = 0; i < sizeof (rand_buffer); ++i)
            {
              xsuffix[i] = tempname_chars[rand_buffer[i]
                                          % ARRAY_SIZE (tempname_chars)];
            }
          /* 0700 */
          result = mkdir (template, S_IRUSR | S_IWUSR | S_IXUSR);
          if (result == 0)
            return template;
          else
            {
              if (errno != EEXIST)
                return NULL;
            }
        }
    }

  errno = EEXIST;
  return NULL;
bad_input:
  errno = EINVAL;
  return NULL;
}

#if 0
int
main (void)
{
  char name[] = "fileXXXXXX";
  if (mkdtemp (name) == NULL)
    abort ();
  return 0;
}
#endif
