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

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <fcntl.h>
#include <spawn.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include "test-help.h"

#undef TEST_FILE_NAME

#define TEST_FILE_NAME "test-posix_spawn1.tmp"

static int child_main (int argc, char **argv);
static int parent_main (int argc, char **argv);

/* Basic test to see that 'posix_spawn' executes a program. */
int
main (int argc, char **argv)
{
  int child = argc > 1 && argv[1][0] == '-' && argv[1][1] == 'c'
              && argv[1][2] == '\0';

  /* Execute the actual program. */
  if (child)
    return child_main (argc, argv);
  else
    return parent_main (argc, argv);
}

/* Child program which simply creates a file and then exits. This is called
   when the program is invoked with:
     ./test-prosix_spawn -c "test-posix_spawn1.tmp" */
static int
child_main (int argc, char **argv)
{
  int fd;

  ASSERT (argc == 3);
  ASSERT (argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] == '\0');

  fd = creat (argv[2], 0600);

  ASSERT (close (fd) == 0);

  return 0;
}

/* Parent program that spawns a child. */
static int
parent_main (int argc, char **argv)
{
  pid_t child_pid;
  int child_status;
  int result;
  const char *program_name = argv[0];
  const char *program_argv[] = { program_name, "-c", TEST_FILE_NAME, NULL };
  struct stat st;

  /* Remove the file from any previous test. */
  unlink (TEST_FILE_NAME);

  /* Spawn the program name. */
  result = posix_spawn (&child_pid, program_name, NULL, NULL,
                        (char *const *) program_argv, environ);
  if (result != 0)
    {
      fprintf (stderr, "posix_spawn (): Failed to execute program.\n");
      exit (1);
    }

  /* Wait for the child process to exit. */
  while (waitpid (child_pid, &child_status, 0) != child_pid)
    ;

  /* Make sure it exited normally. */
  ASSERT (WIFEXITED (child_status));
  ASSERT (WEXITSTATUS (child_status) == 0);

  /* Check that it created TEST_FILE_NAME. */
  ASSERT (stat (TEST_FILE_NAME, &st) == 0);
  ASSERT (S_ISREG (st.st_mode));

  /* Remove the file. */
  ASSERT (unlink (TEST_FILE_NAME) == 0);

  return 0;
}
