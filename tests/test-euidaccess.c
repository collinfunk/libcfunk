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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef EUIDACCESS_FUNCTION_NAME
#  define EUIDACCESS_FUNCTION_NAME euidaccess
#endif

#ifndef EUIDACCESS_FUNCTION_STRING
#  define EUIDACCESS_FUNCTION_STRING "euidaccess"
#endif

#ifndef X_OK
#  define X_OK 0
#endif

/* Basic program to test weather euidaccess/eaccess was compiled and is
   visible. It can be autotested by running it with no arguments. In
   this case it will run euidaccess/eaccess on the current file, which
   should always be successful. It can also be tested manually with a
   filename and/or mode argument. */
int
main (int argc, char **argv)
{
  int mode, result;
  char *pathname;

  switch (argc)
    {
    case 0:
      abort ();
      break;
    case 1:
      mode = X_OK;
      pathname = argv[0];
      break;
    case 2:
      if (argv[1][0] >= '0' && argv[1][0] <= '9')
        {
          mode = atoi (argv[1]);
          pathname = argv[0];
        }
      else
        {
          mode = X_OK;
          pathname = argv[1];
        }
      break;
    default: /* 3+ */
      if (argv[1][0] >= '0' && argv[1][0] <= '9')
        {
          mode = atoi (argv[1]);
          pathname = argv[2];
        }
      else if (argv[2][0] >= '0' && argv[2][0] <= '9')
        {
          mode = atoi (argv[2]);
          pathname = argv[1];
        }
      else
        {
          mode = X_OK;
          pathname = argv[0];
        }
      break;
    }

  if (mode < 0)
    mode = X_OK;

  result = EUIDACCESS_FUNCTION_NAME (pathname, mode);
  if (result < 0)
    {
      fprintf (stderr, "%s (%s, %d): %s.\n", EUIDACCESS_FUNCTION_STRING,
               pathname, mode, strerror (errno));
      return 1;
    }

  printf ("%s (%s, %d): SUCCESS.\n", EUIDACCESS_FUNCTION_STRING, pathname,
          mode);
  return 0;
}
