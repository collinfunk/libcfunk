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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "program-name.h"
#include "test-help.h"

/* The name of this executable without any directory components.
   If you run this program from "/home/user/src/test-program-name",
   get_program_name () should return "test-program-name" */
#ifndef PROGRAM_NAME
#  define PROGRAM_NAME "test-program-name"
#endif

int
main (int argc, char **argv)
{
  /* Pointless check to silence compiler errors :) */
  if (argc < 0)
    abort ();

  ASSERT (get_program_name () == NULL);
  set_program_name (argv[0]);
  ASSERT (get_program_name () != NULL);
  ASSERT (getprogname () != NULL);
  ASSERT (getexecname () != NULL);

  printf ("argv[0]:             \"%s\"\n", argv[0]);
  printf ("get_program_name (): \"%s\"\n", get_program_name ());
  printf ("getprogname ():      \"%s\"\n", getprogname ());
  printf ("getexecname ():      \"%s\"\n", getexecname ());
  printf ("\n\n");

  /* Make sure any needed required internal buffers are set. */
  printf ("argv[0]:             \"%s\"\n", argv[0]);
  printf ("get_program_name (): \"%s\"\n", get_program_name ());
  printf ("getprogname ():      \"%s\"\n", getprogname ());
  printf ("getexecname ():      \"%s\"\n", getexecname ());

  /* These may fail on some operating systems. */
  ASSERT (strcmp (get_program_name (), PROGRAM_NAME) == 0);
  ASSERT (strcmp (get_program_name (), getprogname ()) == 0);
  ASSERT (strcmp (getexecname (), argv[0]) == 0);

  return 0;
}
