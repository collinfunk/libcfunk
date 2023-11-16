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

#include <netinet/in.h>

#include "attributes.h"

static void test_in_port_t_defined (void);
static void test_in_addr_t_defined (void);
static void test_struct_in_addr_defined (void);
static void test_struct_sockaddr_in_defined (void);
static void test_struct_in6_addr_defined (void);
static void test_struct_sockaddr_in6_defined (void);

/* Test that 'netinet/in.h' can be included. */
int
main (void)
{
  test_in_port_t_defined ();
  test_in_addr_t_defined ();
  test_struct_in_addr_defined ();
  test_struct_sockaddr_in_defined ();
  test_struct_in6_addr_defined ();
  test_struct_sockaddr_in6_defined ();
  return 0;
}

/* Test that the 'in_port_t' type is defined. */
static void
test_in_port_t_defined (void)
{
  in_port_t value ATTRIBUTE_UNUSED;
}

/* Test that the 'in_addr_t' type is defined. */
static void
test_in_addr_t_defined (void)
{
  in_addr_t value ATTRIBUTE_UNUSED;
}

/* Test that the 'struct in_addr' type is defined. */
static void
test_struct_in_addr_defined (void)
{
  struct in_addr value ATTRIBUTE_UNUSED;
}

/* Test that the 'struct sockaddr_in' type is defined. */
static void
test_struct_sockaddr_in_defined (void)
{
  struct sockaddr_in value ATTRIBUTE_UNUSED;
}

/* Test that the 'struct in6_addr' type is defined. */
static void
test_struct_in6_addr_defined (void)
{
  struct in6_addr value ATTRIBUTE_UNUSED;
}

/* Test that the 'struct sockaddr_in6' type is defined. */
static void
test_struct_sockaddr_in6_defined (void)
{
  struct sockaddr_in6 value ATTRIBUTE_UNUSED;
}
