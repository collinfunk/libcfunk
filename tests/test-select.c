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

#include <sys/select.h>
#include <sys/time.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "test-help.h"

static void test_select_invalid_nfds (void);
static void test_select_wait_stdin (void);
static void test_select_usleep_like (void);

int
main (void)
{
  test_select_invalid_nfds ();
  test_select_wait_stdin ();
  test_select_usleep_like ();
  return 0;
}

static void
test_select_invalid_nfds (void)
{
  int result;

  errno = 0;
  result = select (-1, NULL, NULL, NULL, NULL);
  ASSERT (result == -1);
  ASSERT (errno == EINVAL);

  /* See Linux man page for 'select'. */
#if 0
  errno = 0;
  result = select (FD_SETSIZE + 1, NULL, NULL, NULL, NULL);
  ASSERT (result == -1);
  ASSERT (errno == EINVAL);
#endif
}

static void
test_select_wait_stdin (void)
{
  if (isatty (STDIN_FILENO))
    {
      fd_set readfds;
      int result;

      FD_ZERO (&readfds);
      FD_SET (STDIN_FILENO, &readfds);

      printf ("Press enter to continue:\n");
      result = select (STDIN_FILENO + 1, &readfds, NULL, NULL, NULL);
      ASSERT (result == 1);
    }
}

static void
test_select_usleep_like (void)
{
  int result;
  struct timeval tv;

  tv.tv_sec = 2;
  tv.tv_usec = 1;

  result = select (0, NULL, NULL, NULL, &tv);
  ASSERT (result == 0);
}
