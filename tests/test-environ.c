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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "test-help.h"

/* Make sure that 'environ' is declared in 'unistd.h'. */
int
main (void)
{
  char **envp = environ;
  char *curr;
  int found = 0;

  /* Search for the environment variable 'TEST_ENVIRON_VALUE' which is set to
     the value 'ok' by CTest. Don't depend on the users actual environment
     which may not be set. */
  for (;;)
    {
      curr = *envp++;
      if (curr == NULL)
        break;
      if (strcmp (curr, "TEST_ENVIRON_VALUE=ok") == 0)
        found = 1;
    }

  /* Check that we found the variable set by CTest. If not return failure but
     print a message in case this program is run by the user in a shell. */
  if (found)
    return 0;
  else
    {
      fprintf (stderr,
               "This test expects to be run automatically from CTest "
               "or a shell script which sets 'TEST_ENVIRON_VALUE=ok'.\n");
      return 1;
    }
}
