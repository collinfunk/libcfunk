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
#include "test-help.h"

int
main (int argc, char **argv)
{
  char *file_name = argc > 1 ? argv[1] : argv[0];
  int cloexec_fd;
  int no_cloexec_fd;

  cloexec_fd = open (file_name, O_RDONLY | O_CLOEXEC);
  if (cloexec_fd < 0)
    {
      file_name = argv[0];
      cloexec_fd = open (file_name, O_RDONLY | O_CLOEXEC);
    }

  no_cloexec_fd = open (file_name, O_RDONLY);
  if (cloexec_fd < 0 || no_cloexec_fd < 0)
    {
      fprintf (stderr, "Can't open file descriptors for testing.\n");
      abort ();
    }

  /* Make sure bad file descriptors return errors. */
  ASSERT (cloexec_is_set (-1) == -1);
  ASSERT (cloexec_is_set (255) == -1);

  /* Check cloexec_is_set against the flags used with open. */
  ASSERT (cloexec_is_set (cloexec_fd) == 1);
  ASSERT (cloexec_is_set (no_cloexec_fd) == 0);

  /* Make sure bad file descriptors return errors. */
  ASSERT (set_cloexec (-1) == -1);
  ASSERT (unset_cloexec (-1) == -1);
  ASSERT (set_cloexec (255) == -1);
  ASSERT (unset_cloexec (255) == -1);

  /* Check that set_cloexec and unset_cloexec return 0 if the flag is in the
     desired state before calling. */
  ASSERT (set_cloexec (cloexec_fd) == 0);
  ASSERT (unset_cloexec (no_cloexec_fd) == 0);

  /* Make sure no operation was performed. */
  ASSERT (cloexec_is_set (cloexec_fd) == 1);
  ASSERT (cloexec_is_set (no_cloexec_fd) == 0);

  /* Now actually toggle the flags on our file descriptors. */
  ASSERT (unset_cloexec (cloexec_fd) == 0);
  ASSERT (set_cloexec (no_cloexec_fd) == 0);

  /* Check them with cloexec_is_set. */
  ASSERT (cloexec_is_set (cloexec_fd) == 0);
  ASSERT (cloexec_is_set (no_cloexec_fd) == 1);

  /* Perform the NOP test again. */
  ASSERT (unset_cloexec (cloexec_fd) == 0);
  ASSERT (set_cloexec (no_cloexec_fd) == 0);

  /* Check. */
  ASSERT (cloexec_is_set (cloexec_fd) == 0);
  ASSERT (cloexec_is_set (no_cloexec_fd) == 1);

  /* Return them back to their original state. */
  ASSERT (set_cloexec (cloexec_fd) == 0);
  ASSERT (unset_cloexec (no_cloexec_fd) == 0);

  /* Check. */
  ASSERT (cloexec_is_set (cloexec_fd) == 1);
  ASSERT (cloexec_is_set (no_cloexec_fd) == 0);

  /* Cleanup. */
  close (cloexec_fd);
  close (no_cloexec_fd);

  return 0;
}
