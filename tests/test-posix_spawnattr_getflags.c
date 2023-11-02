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

#include <spawn.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

/* Test that 'posix_spawnattr_getflags' is declared and works properly. */
int
main (void)
{
  posix_spawnattr_t attr;
  int result;
  short int flags;

  ASSERT (posix_spawnattr_init (&attr) == 0);

  result = posix_spawnattr_setflags (
      &attr, POSIX_SPAWN_RESETIDS | POSIX_SPAWN_SETPGROUP
                 | POSIX_SPAWN_SETSIGDEF | POSIX_SPAWN_SETSIGMASK
                 | POSIX_SPAWN_SETSCHEDPARAM | POSIX_SPAWN_SETSCHEDULER);
  ASSERT (result == 0);

  result = posix_spawnattr_getflags (&attr, &flags);
  ASSERT (result == 0);
  ASSERT ((flags & POSIX_SPAWN_RESETIDS) == POSIX_SPAWN_RESETIDS);
  ASSERT ((flags & POSIX_SPAWN_SETPGROUP) == POSIX_SPAWN_SETPGROUP);
  ASSERT ((flags & POSIX_SPAWN_SETSIGDEF) == POSIX_SPAWN_SETSIGDEF);
  ASSERT ((flags & POSIX_SPAWN_SETSIGMASK) == POSIX_SPAWN_SETSIGMASK);
  ASSERT ((flags & POSIX_SPAWN_SETSCHEDPARAM) == POSIX_SPAWN_SETSCHEDPARAM);
  ASSERT ((flags & POSIX_SPAWN_SETSCHEDULER) == POSIX_SPAWN_SETSCHEDULER);

  ASSERT (posix_spawnattr_destroy (&attr) == 0);

  return 0;
}
