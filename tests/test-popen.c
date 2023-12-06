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

#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test-help.h"

static int parent_main (int argc, char **argv);
static int child1_main (int argc, char **argv);
static int child2_main (int argc, char **argv);

/* Test that 'popen' and 'pclose' are defined. */
int
main (int argc, char **argv)
{
  if (argc < 2)
    return parent_main (argc, argv);
  else if (argv[1][0] == '1')
    return child1_main (argc, argv);
  else if (argv[1][0] == '2')
    return child2_main (argc, argv);
  else
    return 1;
}

/* Main process. */
int
parent_main (int argc, char **argv)
{
  char *command1;
  char *command2;
  FILE *child1;
  FILE *child2;
  int result1;
  int result2;
  size_t program_name_len;

  /* Silence warnings. argv[0] is the current executable. */
  ASSERT (argc >= 1);
  ASSERT (argv[0] != NULL);

  /* Get the length of the program name. */
  program_name_len = strlen (argv[0]);

  /* Setup the command for child 1. */
  command1 = malloc (program_name_len + 3);
  ASSERT (command1 != NULL);
  strcpy (command1, argv[0]);
  command1[program_name_len] = ' ';
  command1[program_name_len + 1] = '1';
  command1[program_name_len + 2] = '\0';

  /* Setup the command for child 2. */
  command2 = malloc (program_name_len + 3);
  ASSERT (command2 != NULL);
  strcpy (command2, argv[0]);
  command2[program_name_len] = ' ';
  command2[program_name_len + 1] = '2';
  command2[program_name_len + 2] = '\0';

  /* Create two child processes. The parent reads from child1 and writes to
     child2. */
  child1 = popen (command1, "r");
  child2 = popen (command2, "w");

  /* Make sure the processes run. */
  ASSERT (child1 != NULL);
  ASSERT (child2 != NULL);

  /* Read '1' and nothing else from child1. */
  ASSERT (fgetc (child1) == '1');
  ASSERT (fgetc (child1) == EOF);

  /* Get the exit status from child1. */
  result1 = pclose (child1);
  ASSERT (WIFEXITED (result1));
  ASSERT (WEXITSTATUS (result1) == 1);

  /* child2 expects to read '2' and nothing else. */
  ASSERT (fputc ('2', child2) == '2');

  /* Get the exit status from child2. */
  result2 = pclose (child2);
  ASSERT (WIFEXITED (result2));
  ASSERT (WEXITSTATUS (result2) == 2);

  /* Free up the memory. */
  free (command1);
  free (command2);

  return 0;
}

/* Writes '1' to stdout and returns 1. */
static int
child1_main (int argc, char **argv)
{
  /* Silence warnings. */
  ASSERT (argc > 1);
  ASSERT (argv[1][0] == '1');

  /* Parent expects to read '1'. */
  ASSERT (putchar ('1') == '1');

  return 1;
}

/* Reads '2' and nothing else from stdin and returns 2. */
static int
child2_main (int argc, char **argv)
{
  /* Silence warnings. */
  ASSERT (argc > 1);
  ASSERT (argv[1][0] == '2');

  /* Parent writes '2' and nothing else. */
  ASSERT (getchar () == '2');
  ASSERT (getchar () == EOF);

  return 2;
}
