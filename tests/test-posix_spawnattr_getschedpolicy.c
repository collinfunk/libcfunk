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

#include <sched.h>
#include <spawn.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

/* The initial schedule policy is not defined by POSIX. Since we can't
   just check the initial value, this test is the same as the one for
   'posix_spawnattr_setschedpolicy'. */
int
main (void)
{
  posix_spawnattr_t attr;
  int policy;
  int result;

  ASSERT (posix_spawnattr_init (&attr) == 0);

  /* SCHED_OTHER */
  policy = SCHED_OTHER;
  result = posix_spawnattr_setschedpolicy (&attr, policy);
  ASSERT (result == 0);

  /* SCHED_OTHER */
  policy = -1;
  result = posix_spawnattr_getschedpolicy (&attr, &policy);
  ASSERT (result == 0);
  ASSERT (policy == SCHED_OTHER);

  /* SCHED_FIFO */
  policy = SCHED_FIFO;
  result = posix_spawnattr_setschedpolicy (&attr, policy);
  ASSERT (result == 0);

  /* SCHED_FIFO */
  policy = -1;
  result = posix_spawnattr_getschedpolicy (&attr, &policy);
  ASSERT (result == 0);
  ASSERT (policy == SCHED_FIFO);

  /* SCHED_RR */
  policy = SCHED_RR;
  result = posix_spawnattr_setschedpolicy (&attr, policy);
  ASSERT (result == 0);

  /* SCHED_RR */
  policy = -1;
  result = posix_spawnattr_getschedpolicy (&attr, &policy);
  ASSERT (result == 0);
  ASSERT (policy == SCHED_RR);

  ASSERT (posix_spawnattr_destroy (&attr) == 0);

  return 0;
}
