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

/* Test that 'posix_spawnattr_setschedparam' is declared and working. */
int
main (void)
{
  posix_spawnattr_t attr;
  struct sched_param param;
  int result;

  ASSERT (posix_spawnattr_init (&attr) == 0);

  /* Initial value is undefined so set it to a defined value. */
  param.sched_priority = 1;
  result = posix_spawnattr_setschedparam (&attr, &param);
  ASSERT (result == 0);

  /* Check the returned parameter from 'posix_spawnattr_getschedparam'. */
  param.sched_priority = -1;
  result = posix_spawnattr_getschedparam (&attr, &param);
  ASSERT (result == 0);
  ASSERT (param.sched_priority == 1);

  /* Set the value again. */
  param.sched_priority = 2;
  result = posix_spawnattr_setschedparam (&attr, &param);
  ASSERT (result == 0);

  /* Check the returned parameter from 'posix_spawnattr_getschedparam'. */
  param.sched_priority = -2;
  result = posix_spawnattr_getschedparam (&attr, &param);
  ASSERT (result == 0);
  ASSERT (param.sched_priority == 2);

  ASSERT (posix_spawnattr_destroy (&attr) == 0);

  return 0;
}
