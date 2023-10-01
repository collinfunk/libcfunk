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

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "cloexec.h"
#include "safe-creat.h"

#undef ASSERT
#define ASSERT(condition)                                                     \
  do                                                                          \
    {                                                                         \
      if (!(condition))                                                       \
        {                                                                     \
          abort ();                                                           \
        }                                                                     \
    }                                                                         \
  while (0)

int
main (void)
{
  int fd, i;

  /* Clean all files that might remain from earlier tests. */
  remove ("test-safe-creat-cloexec-set.tmp");
  remove ("test-safe-creat.tmp");
  remove ("test-safe-creat-cloexec.tmp");

  /* Test that 'safe_creat_cloexec' sets the close-on-exec flag even if it
     doesn't need to return a duplicate file descriptor. */
  fd = safe_creat_cloexec ("test-safe-creat-cloexec-set.tmp", 0600);
  ASSERT (fd > STDERR_FILENO);
  ASSERT (cloexec_is_set (fd) == 1);
  ASSERT (close (fd) == 0);

  /* Close standard streams. */
  ASSERT (close (STDIN_FILENO) == 0);
  ASSERT (close (STDOUT_FILENO) == 0);
  ASSERT (close (STDERR_FILENO) == 0);

  /* Test each function while gradually opening the standard IO streams. */
  for (i = STDIN_FILENO; i <= STDERR_FILENO; ++i)
    {
      /* Test 'safe_creat'. */
      fd = safe_creat ("test-safe-creat.tmp", 0600);
      ASSERT (fd > STDERR_FILENO);
      ASSERT (close (fd) == 0);

      /* Test 'safe_creat_cloexec'. */
      fd = safe_creat_cloexec ("test-safe-creat-cloexec.tmp", 0600);
      ASSERT (fd > STDERR_FILENO);
      ASSERT (cloexec_is_set (fd) == 1);
      ASSERT (close (fd) == 0);

      /* Cleanup the files. */
      ASSERT (remove ("test-safe-creat.tmp") == 0);
      ASSERT (remove ("test-safe-creat-cloexec.tmp") == 0);

      /* Open file descriptor #I in the wrong direction. */
      if (i == STDIN_FILENO)
        ASSERT (open ("test-safe-creat-cloexec-set.tmp", O_WRONLY) == i);
      else
        ASSERT (open ("test-safe-creat-cloexec-set.tmp", O_RDONLY) == i);
    }

  /* Close the standard streams. */
  ASSERT (close (STDIN_FILENO) == 0);
  ASSERT (close (STDOUT_FILENO) == 0);
  ASSERT (close (STDERR_FILENO) == 0);

  /* Remove the file used to replace STDIN, STDOUT, and STDERR. */
  ASSERT (remove ("test-safe-creat-cloexec-set.tmp") == 0);

  return 0;
}
