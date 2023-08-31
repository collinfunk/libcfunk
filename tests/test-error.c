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

#include <errno.h>
#include <error.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "program-name.h"
#include "test-help.h"

static void custom_print_name (void);

int
main (int argc, char **argv)
{
  int i;

  /* Silence warnings. */
  if (argc < 0)
    abort ();

  /* This should print 5 times. */
  for (i = 0; i < 5; ++i)
    error_at_line (0, EACCES, __FILE__, __LINE__, "%d print multple", i);
  ASSERT (error_message_count == 5);

  /* This should print 1 time. */
  error_one_per_line = 1;
  for (i = 0; i < 5; ++i)
    error_at_line (0, EEXIST, __FILE__, __LINE__, "%d print once", i);
  ASSERT (error_message_count == 6);

  /* Use get_program_name instead of getprogname. */
  set_program_name (argv[0]);
  error (0, ENOENT, "%d %s", 1, "error");
  ASSERT (error_message_count == 7);

  /* Use a function pointer to print the program name. */
  error_print_progname = custom_print_name;
  error (0, 0, "%d %s", 2, "function pointer print");
  ASSERT (error_message_count == 8);

  return 0;
}

static void
custom_print_name (void)
{
  fprintf (stderr, "custom_print_name (): ");
}
