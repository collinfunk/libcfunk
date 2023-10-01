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

/* `echo | gcc -dM -E - | grep' hurd on Debian GNU Hurd. */
/* GNU Hurd has the getumask(2) system call which should be used if available.
   These macros should be enough to show the prototype but on my system I still
   get warnings.
     GNU debian 0.9 GNU-Mach 1.8+git20230526-486/Hurd-0.9 i686-AT386 GNU
 */
#if defined(__gnu_hurd__)
#  define __USE_GNU
#  define __GNU_SOURCE
#  if defined(__GNUC__) || defined(__clang__)
#    pragma GCC diagnostic ignored "-Wmissing-prototypes"
#    pragma GCC diagnostic ignored "-Wimplicit-function-declaration"
#  endif
#endif

#include <config.h>

#include <sys/stat.h>
#include <sys/types.h>

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Buffer required for reading "/proc/self/status" on Linux to get the
   processes current umask. This size can probably be changed to something
   smaller. */
#define BUFFER_SIZE 8192

mode_t
get_umask_unsafe (void)
{
#if defined(__gnu_hurd__)
  return getumask ();
#else
  mode_t current_mask = umask (0);
  umask (current_mask);
  return current_mask;
#endif
}

/* TODO: The parsing for the "Umask:" field in "/proc/self/status" isn't
   very strict. The following commit shows it is placed with the following
   printf statement:

     printf ("Umask:\t%#04o\n", umask);
     https://github.com/torvalds/linux/commit/3e42979e65dace1f9268dd5440e5ab096b8dee59

   This function accepts spaces and tabs, and does not check for exactly 4
   digits. I'm not sure if this format changed in following versions.
 */
mode_t
get_umask (void)
{
#if defined(__gnu_hurd__)
  return getumask ();
#elif defined(__linux__)
  unsigned char buffer[BUFFER_SIZE];
  unsigned int value = 0;
  int fd;

  fd = open ("/proc/self/status", O_RDONLY | O_CLOEXEC);
  if (fd < 0)
    goto fail;

  for (;;)
    {
      ssize_t current_read = read (fd, buffer, sizeof (buffer));
      const unsigned char *p;
      const unsigned char *end;

      if (current_read <= 0)
        goto fail_close;

      p = (const unsigned char *) buffer;
      end = p + current_read;
      while (p < end)
        {
          /* Skip any line that doesn't start with 'U'. */
          if (*p != 'U')
            {
              do
                ++p;
              while (*p != '\n' && p < end);
              if (p < end && *p == '\n')
                ++p;
              else
                break;
            }
          else /* *p == 'U' */
            {
              /* Check that we are at the line that gives the umask. */
              if (p + 6 < end && memcmp (p, "Umask:", 6) == 0)
                {
                  /* Skip any horizontal whitespace. */
                  for (p += 6; (*p == ' ' || *p == '\t') && p < end; ++p)
                    ;
                  /* Convert the octal umask string to an integer. */
                  for (; p < end; ++p)
                    {
                      if (*p >= '0' && *p <= '7')
                        value = value * 8 + *p - '0';
                      else
                        break;
                    }
                  /* Make sure we read the complete umask. It should always
                     be followed by a newline. */
                  if (*p == '\n')
                    goto done;
                  else
                    goto fail_close;
                }
            }
        }
    }

done:
  close (fd);
  return (mode_t) value;
fail_close:
  close (fd);
fail:
  return 0077;
#else
#  error "get_umask does not have an implementation for your operating system."
  return 0077;
#endif
}

#if 0
int
main (void)
{
  printf ("%#04o\n", (unsigned int) get_umask_unsafe ());
  printf ("%#04o\n", (unsigned int) get_umask ());
  return 0;
}
#endif
