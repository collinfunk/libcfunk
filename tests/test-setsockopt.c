/*-
 * Copyright (c) 2024, Collin Funk
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

#include <sys/socket.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "sockets.h"
#include "test-help.h"

static void test_setsockopt_ebadf (void);

int
main (void)
{
  ASSERT (socket_startup (SOCKET_VERSION (2, 2)) == 0);
  test_setsockopt_ebadf ();
  ASSERT (socket_cleanup () == 0);
  return 0;
}

static void
test_setsockopt_ebadf (void)
{
  int value = 1;

  /* Negative file descriptor. */
  errno = 0;
  ASSERT (setsockopt (-1, SOL_SOCKET, SO_REUSEPORT, &value, sizeof (value))
          == -1);
  ASSERT (errno == EBADF);

  /* Positive but closed file descriptor. */
  (void) close (10);
  errno = 0;
  ASSERT (setsockopt (10, SOL_SOCKET, SO_REUSEPORT, &value, sizeof (value))
          == -1);
  ASSERT (errno == EBADF);
}
