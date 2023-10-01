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

#include <sys/types.h>

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef __linux__
#  error "This file is not portable."
#endif

/* Similar to getppid(2) except that it returns the parent process id of PID
   instead of the calling process. */
pid_t
getppidof (pid_t pid)
{
  int fd;
  unsigned int ppid = 0;
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
          if (p + 5 < end && memcmp (p, "PPid:", 5) == 0)
            {
              p += 5;
              while (*p == '\t' || *p == ' ')
                ++p;
              for (; *p >= '0' && *p <= '9' && p < end; ++p)
                {
                  ppid *= 10;
                  ppid += *p - '0';
                }
              if (p >= end || *p != '\n')
                ppid = 0;
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
  return (pid_t) ppid;
}

#if 0
int
main (void)
{
  printf ("%u\n", (unsigned int) getppidof (getpid ()));
  return 0;
}
#endif
