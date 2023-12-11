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

#include <errno.h>
#include <error.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* GNU-like error message functions.
   Error messages are printed in one of the following forms:
     error ():
       program-name: message
       program-name: message: strerror (errno)
     error_at_line ():
       program-name:source-file:line-number: message
       program-name:source-file:line-number: message: strerror (errno)
   Functions attempt to use the filename set with set_program_name (). If it
   has not been set, then getprogname(3) is used instead.
   Both functions quit by calling exit(3) with the value passed as STATUS if it
   is a non-zero value.
   Both functions print an error string using CODE as the value for errno if it
   is a non-zero value.
   The method for printing the program name can be modified by setting the
   function pointer error_print_progname. If this value is not NULL, the
   function is called and expected to print a program name.
   The error_at_line can be modified by the integer value error_one_per_line.
   If this value is zero it will print the program name, source file, and line
   number on each call. If error_one_per_line is 1, consecutive calls with
   the same file name and line number will only print one message.
 */

/* Global variables used to check if error_at_line () is called with
   the same file name and line number as the previous call. */
#if !HAVE_ERROR_AT_LINE
static const char *prev_file_name = NULL;
static unsigned int prev_line_number = 0;
#endif

/* Global counter used to track the number of error messages printed with
   error () and error_at_line () */
#if !HAVE_ERROR_MESSAGE_COUNT
unsigned int error_message_count = 0;
#endif

/* Value used to control whether subsequent calls from the same line number
   of a given file are ignored or printed. */
#if !HAVE_ERROR_ONE_PER_LINE
int error_one_per_line = 0;
#endif

/* Function pointer that is called if it is set to a non-NULL pointer instead
   of printing the return value of get_program_name () or getprogname (). */
#if !HAVE_ERROR_PRINT_PROGNAME
void (*error_print_progname) (void) = NULL;
#endif

#if !HAVE_ERROR || !HAVE_ERROR_AT_LINE
static void
print_errno_string (int code)
{
  char error_buffer[2048];
  int result = strerror_r (code, error_buffer, sizeof (error_buffer));
  if (result == 0)
    fprintf (stderr, ": %s", error_buffer);
  else /* Print a generic message. */
    fprintf (stderr, ": Unknown error %d", code);
}
#endif

#if !HAVE_ERROR
void
error (int status, int code, const char *format, ...)
{
  va_list args;

  if (error_print_progname != NULL)
    {
      fflush (stdout);
      (*error_print_progname) ();
    }
  else
    {
      fflush (stdout);
      fprintf (stderr, "%s: ", getprogname ());
    }

  va_start (args, format);
  vfprintf (stderr, format, args);
  va_end (args);

  if (code != 0)
    print_errno_string (code);
  fprintf (stderr, "\n");

  error_message_count++;

  if (status != 0)
    exit (status);
}
#endif

#if !HAVE_ERROR_AT_LINE
void
error_at_line (int status, int code, const char *file_name,
               unsigned int line_number, const char *format, ...)
{
  va_list args;

  /* Check if we are at the same file and line as the last call if
     error_one_per_line is set. */
  if (error_one_per_line != 0)
    {
      /* If line numbers are equal, previous file is set and the
         same as the current file. */
      if (line_number == prev_line_number
          && (prev_file_name != NULL && file_name != NULL
              && strcmp (prev_file_name, file_name) == 0))
        return;
      else
        {
          prev_file_name = file_name;
          prev_line_number = line_number;
        }
    }

  if (error_print_progname != NULL)
    {
      fflush (stdout);
      (*error_print_progname) ();
    }
  else
    {
      fflush (stdout);
      fprintf (stderr, "%s:", getprogname ());
    }

  if (file_name != NULL)
    fprintf (stderr, "%s:%d: ", file_name, line_number);
  else
    fprintf (stderr, " ");

  va_start (args, format);
  vfprintf (stderr, format, args);
  va_end (args);

  if (code != 0)
    print_errno_string (code);
  fprintf (stderr, "\n");

  error_message_count++;

  if (status != 0)
    exit (status);
}
#endif
