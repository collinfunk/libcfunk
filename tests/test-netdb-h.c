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

#include <netdb.h>

#include "attributes.h"

static void struct_hostent_defined (void);
static void struct_netent_defined (void);
static void struct_protoent_defined (void);
static void struct_servent_defined (void);
static void struct_addrinfo_defined (void);

/* Test that <netdb.h> is generated and included correctly. */
int
main (void)
{
  struct_hostent_defined ();
  struct_netent_defined ();
  struct_protoent_defined ();
  struct_servent_defined ();
  struct_addrinfo_defined ();
  return 0;
}

static void
struct_hostent_defined (void)
{
  struct hostent value ATTRIBUTE_UNUSED;
}

static void
struct_netent_defined (void)
{
  struct netent value ATTRIBUTE_UNUSED;
}

static void
struct_protoent_defined (void)
{
  struct protoent value ATTRIBUTE_UNUSED;
}

static void
struct_servent_defined (void)
{
  struct servent value ATTRIBUTE_UNUSED;
}

static void
struct_addrinfo_defined (void)
{
  struct addrinfo value ATTRIBUTE_UNUSED;
}
