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

#include <alloca.h>
#include <errno.h>
#include <stdarg.h>
#include <unistd.h>

/* POSIX requires that this function is async-signal-safe. Therefore we use
   alloca instead of malloc even though it is not as portable. This also means
   that a large argument vector could cause a stack overflow. After this
   program behavior is undefined. */
int
execl (const char *path, const char *arg0, ...)
{
  int i, argc;
  char **argv;
  va_list ap;

  va_start (ap, arg0);
  for (argc = 1; va_arg (ap, const char *) != NULL; ++argc)
    ;
  va_end (ap);

  argv = (char **) alloca ((argc + 1) * sizeof (const char *));
  if (argv == NULL)
    {
      errno = ENOMEM;
      return -1;
    }

  argv[0] = (char *) arg0;
  va_start (ap, arg0);
  for (i = 1; i <= argc; ++i)
    argv[i] = (char *) va_arg (ap, const char *);
  va_end (ap);

  return execve (path, argv, environ);
}
