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

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test-help.h"

int
main (void)
{
  struct in_addr addr;
  char buffer[16];

  addr.s_addr = htonl (0x00000000U);
  ASSERT (inet_ntop (AF_INET, &addr, buffer, sizeof (buffer)) == buffer);
  ASSERT (strcmp (buffer, "0.0.0.0") == 0);

  addr.s_addr = htonl (0xff000000U);
  ASSERT (inet_ntop (AF_INET, &addr, buffer, sizeof (buffer)) == buffer);
  ASSERT (strcmp (buffer, "255.0.0.0") == 0);

  addr.s_addr = htonl (0x00ff0000U);
  ASSERT (inet_ntop (AF_INET, &addr, buffer, sizeof (buffer)) == buffer);
  ASSERT (strcmp (buffer, "0.255.0.0") == 0);

  addr.s_addr = htonl (0x0000ff00U);
  ASSERT (inet_ntop (AF_INET, &addr, buffer, sizeof (buffer)) == buffer);
  ASSERT (strcmp (buffer, "0.0.255.0") == 0);

  addr.s_addr = htonl (0x000000ffU);
  ASSERT (inet_ntop (AF_INET, &addr, buffer, sizeof (buffer)) == buffer);
  ASSERT (strcmp (buffer, "0.0.0.255") == 0);

  addr.s_addr = htonl (0x0000ffffU);
  ASSERT (inet_ntop (AF_INET, &addr, buffer, sizeof (buffer)) == buffer);
  ASSERT (strcmp (buffer, "0.0.255.255") == 0);

  addr.s_addr = htonl (0x00ffffffU);
  ASSERT (inet_ntop (AF_INET, &addr, buffer, sizeof (buffer)) == buffer);
  ASSERT (strcmp (buffer, "0.255.255.255") == 0);

  addr.s_addr = htonl (0xffffffffU);
  ASSERT (inet_ntop (AF_INET, &addr, buffer, sizeof (buffer)) == buffer);
  ASSERT (strcmp (buffer, "255.255.255.255") == 0);

  return 0;
}
