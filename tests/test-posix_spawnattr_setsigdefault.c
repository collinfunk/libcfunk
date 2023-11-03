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

#include <signal.h>
#include <spawn.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

/* Signals described by ISO C99. */
static const int supported_signals[] = {
#ifdef SIGABRT
  SIGABRT,
#endif
#ifdef SIGFPE
  SIGFPE,
#endif
#ifdef SIGILL
  SIGILL,
#endif
#ifdef SIGINT
  SIGINT,
#endif
#ifdef SIGSEGV
  SIGSEGV,
#endif
#ifdef SIGTERM
  SIGTERM,
#endif
};

/* Test that 'posix_spawnattr_setsigdefault' is declared. */
int
main (void)
{
  posix_spawnattr_t attr;
  sigset_t set;
  int result;
  size_t i;

  ASSERT (posix_spawnattr_init (&attr) == 0);

  result = posix_spawnattr_getsigdefault (&attr, &set);
  ASSERT (result == 0);

  /* Initial value for this attribute is an empty signal set. */
  for (i = 0; i < ARRAY_SIZE (supported_signals); ++i)
    ASSERT (sigismember (&set, supported_signals[i]) == 0);

  /* Fill the set. */
  ASSERT (sigfillset (&set) == 0);

  /* Set the sigdefault attribute of ATTR. */
  result = posix_spawnattr_setsigdefault (&attr, &set);
  ASSERT (result == 0);

  /* Empty the set. */
  ASSERT (sigemptyset (&set) == 0);

  /* Get the sigdefault attribute from ATTR. */
  result = posix_spawnattr_getsigdefault (&attr, &set);
  ASSERT (result == 0);

  /* Now SET should be a full signal set. */
  for (i = 0; i < ARRAY_SIZE (supported_signals); ++i)
    ASSERT (sigismember (&set, supported_signals[i]) == 1);

  ASSERT (posix_spawnattr_destroy (&attr) == 0);

  return 0;
}
