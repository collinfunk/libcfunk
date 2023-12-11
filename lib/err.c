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

#include <err.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* BSD-like error message functions.
   Functions with the name `warn' print a warning to stderr.
   Functions with the name `err' print an error to stderr and then call `exit'.
   Functions with the `v' prefix take a `va_list' argument.

   Functions with the `x' suffix print the following message (where "format"
   is the given string):
     program-name: format

   All other functions print the following message (where "format" is the given
   string and "errno message" is the return value of `strerror(3)'):
     program-name: format: errno message

   The error number used is passed by the user for functions that end with `c'.
   The other functions use current value in `errno'.
 */

#if !HAVE_ERR
void
err (int status, const char *format, ...)
{
  va_list args;
  va_start (args, format);
  verr (status, format, args);
  va_end (args);
}
#endif

#if !HAVE_VERR
void
verr (int status, const char *format, va_list args)
{
  int real_errno = errno;
  fprintf (stderr, "%s: ", getprogname ());
  if (format != NULL)
    {
      vfprintf (stderr, format, args);
      fprintf (stderr, ": ");
    }
  fprintf (stderr, "%s\n", strerror (real_errno));
  exit (status);
}
#endif

#if !HAVE_ERRC
void
errc (int status, int code, const char *format, ...)
{
  va_list args;
  va_start (args, format);
  verrc (status, code, format, args);
  va_end (args);
}
#endif

#if !HAVE_VERRC
void
verrc (int status, int code, const char *format, va_list args)
{
  fprintf (stderr, "%s: ", getprogname ());
  if (format != NULL)
    {
      vfprintf (stderr, format, args);
      fprintf (stderr, ": ");
    }
  fprintf (stderr, "%s\n", strerror (code));
  exit (status);
}
#endif

#if !HAVE_ERRX
void
errx (int status, const char *format, ...)
{
  va_list args;
  va_start (args, format);
  verrx (status, format, args);
  va_end (args);
}
#endif

#if !HAVE_VERRX
void
verrx (int status, const char *format, va_list args)
{
  fprintf (stderr, "%s: ", getprogname ());
  if (format != NULL)
    vfprintf (stderr, format, args);
  fprintf (stderr, "\n");
  exit (status);
}
#endif

#if !HAVE_WARN
void
warn (const char *format, ...)
{
  va_list args;
  va_start (args, format);
  vwarn (format, args);
  va_end (args);
}
#endif

#if !HAVE_VWARN
void
vwarn (const char *format, va_list args)
{
  int real_errno = errno;
  fprintf (stderr, "%s: ", getprogname ());
  if (format != NULL)
    {
      vfprintf (stderr, format, args);
      fprintf (stderr, ": ");
    }
  fprintf (stderr, "%s\n", strerror (real_errno));
}
#endif

#if !HAVE_WARNC
void
warnc (int code, const char *format, ...)
{
  va_list args;
  va_start (args, format);
  vwarnc (code, format, args);
  va_end (args);
}
#endif

#if !HAVE_VWARNC
void
vwarnc (int code, const char *format, va_list args)
{
  fprintf (stderr, "%s: ", getprogname ());
  if (format != NULL)
    {
      vfprintf (stderr, format, args);
      fprintf (stderr, ": ");
    }
  fprintf (stderr, "%s\n", strerror (code));
}
#endif

#if !HAVE_WARNX
void
warnx (const char *format, ...)
{
  va_list args;
  va_start (args, format);
  vwarnx (format, args);
  va_end (args);
}
#endif

#if !HAVE_VWARNX
void
vwarnx (const char *format, va_list args)
{
  fprintf (stderr, "%s: ", getprogname ());
  if (format != NULL)
    vfprintf (stderr, format, args);
  fprintf (stderr, "\n");
}
#endif
