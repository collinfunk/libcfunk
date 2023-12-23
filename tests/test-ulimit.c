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

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <ulimit.h>
#include <unistd.h>

#include "root-uid.h"
#include "test-help.h"

static void test_ulimit_UL_GETFSIZE (void);
static void test_ulimit_UL_SETFSIZE_zero (void);
static void test_ulimit_UL_SETFSIZE_one (void);

int
main (void)
{
  test_ulimit_UL_GETFSIZE ();
  test_ulimit_UL_SETFSIZE_zero ();
  test_ulimit_UL_SETFSIZE_one ();
  return 0;
}

/* Test that 'ulimit (UL_GETFSIZE) returns a positive value. */
static void
test_ulimit_UL_GETFSIZE (void)
{
  long int result;

  result = ulimit (UL_GETFSIZE);
  ASSERT (result != -1L);
  printf ("Maximum file size: %ld * 512 bytes.\n", result);
}

/* Test that we can set the maximum file size to 0 bytes. */
static void
test_ulimit_UL_SETFSIZE_zero (void)
{
  ASSERT (ulimit (UL_SETFSIZE, 0L) == 0L);
  ASSERT (ulimit (UL_GETFSIZE) == 0L);
}

/* Test that we can only raise the maximum file size if we have the proper
   permissions. */
static void
test_ulimit_UL_SETFSIZE_one (void)
{
#if !HAVE_GETEUID
  {
    fprintf (stderr, "Skipping test_ulimit_UL_SETFSIZE_one: No geteuid ().\n");
    exit (77);
  }
#else /* HAVE_GETEUID */
  {
    long int result;

    errno = 0;
    result = ulimit (UL_SETFSIZE, 1L);
    /* Only the root user can increase the limit. */
    if (geteuid () == ROOT_UID)
      {
        ASSERT (result == 1L);
        ASSERT (ulimit (UL_GETFSIZE) == 1L);
      }
    else
      {
        ASSERT (result == -1L);
        ASSERT (errno == EPERM);
      }
  }
#endif
}
