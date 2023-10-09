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

#include <sys/socket.h>

#include <stdio.h>
#include <stdlib.h>

#include "sockets.h"
#include "test-help.h"

static void test_socket_version (void);
static void test_windows_socket_versions (void);

int
main (void)
{
  test_socket_version ();
  test_windows_socket_versions ();
  return 0;
}

/* Make sure SOCKET_VERSION does the same thing as MAKEWORD on Windows. */
static void
test_socket_version (void)
{
  ASSERT (SOCKET_VERSION (1, 0) == 0x0001);
  ASSERT (SOCKET_VERSION (1, 1) == 0x0101);
  ASSERT (SOCKET_VERSION (2, 0) == 0x0002);
  ASSERT (SOCKET_VERSION (2, 1) == 0x0102);
  ASSERT (SOCKET_VERSION (2, 2) == 0x0202);
#ifdef MAKEWORD
  ASSERT (SOCKET_VERSION (1, 0) == MAKEWORD (1, 0));
  ASSERT (SOCKET_VERSION (1, 1) == MAKEWORD (1, 1));
  ASSERT (SOCKET_VERSION (2, 0) == MAKEWORD (2, 0));
  ASSERT (SOCKET_VERSION (2, 1) == MAKEWORD (2, 1));
  ASSERT (SOCKET_VERSION (2, 2) == MAKEWORD (2, 2));
#endif
}

/* Test all current socket versions supported by Windows. */
/* https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-wsastartup */
static void
test_windows_socket_versions (void)
{
  /* Version 1.0 */
  ASSERT (socket_startup (SOCKET_VERSION (1, 0)) == 0);
  ASSERT (socket_cleanup () == 0);

  /* Version 1.1 */
  ASSERT (socket_startup (SOCKET_VERSION (1, 1)) == 0);
  ASSERT (socket_cleanup () == 0);

  /* Version 2.0 */
  ASSERT (socket_startup (SOCKET_VERSION (2, 0)) == 0);
  ASSERT (socket_cleanup () == 0);

  /* Version 2.1 */
  ASSERT (socket_startup (SOCKET_VERSION (2, 1)) == 0);
  ASSERT (socket_cleanup () == 0);

  /* Version 2.2 */
  ASSERT (socket_startup (SOCKET_VERSION (2, 2)) == 0);
  ASSERT (socket_cleanup () == 0);
}
