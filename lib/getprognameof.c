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

#include <sys/types.h>

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef __linux__
#  error "This file is not portable."
#endif

/* Like getprogname(2) except that it malloc's and returns the program name
   of PID instead of returning the name of the current process. */
char *
getprognameof (pid_t pid)
{
  int fd;
  char *prog_name = NULL;
  char buffer[4096];

  sprintf (buffer, "/proc/%u/status", (unsigned int) pid);
  fd = open (buffer, O_RDONLY | O_CLOEXEC);
  if (fd < 0)
    return 0;

  for (;;)
    {
      ssize_t bytes_read = read (fd, buffer, sizeof (buffer));
      char *p;
      char *end;

      if (bytes_read <= 0)
        goto finished;

      p = buffer;
      end = buffer + bytes_read;
      for (;;)
        {
          if (p + 5 < end && memcmp (p, "Name:", 5) == 0)
            {
              char *name_start;
              char *name_end;
              size_t name_len;

              p += 5;
              while (*p == '\t' || *p == ' ')
                ++p;
              name_start = p;
              name_end = memchr (name_start, '\n', end - name_start);
              if (name_end != NULL)
                {
                  name_len = name_end - name_start;
                  prog_name = (char *) malloc (name_len + 1);
                  if (prog_name != NULL)
                    {
                      memcpy (prog_name, name_start, name_len);
                      prog_name[name_len] = '\0';
                    }
                }
              goto finished;
            }
          p = memchr (p, '\n', end - p);
          if (p == NULL)
            goto finished;
          else
            ++p;
        }
    }

finished:
  close (fd);
  return prog_name;
}

#if 0
int
main (void)
{
  char *name = getprognameof (getpid ());
  if (name == NULL)
    return 1;
  else
    {
      printf ("%s\n", name);
      free (name);
    }
  return 0;
}
#endif
