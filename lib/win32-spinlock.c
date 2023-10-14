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
#include <windows.h>

#include "attributes.h"
#include "win32-spinlock.h"

/* https://learn.microsoft.com/en-us/windows/win32/api/winnt/nf-winnt-memorybarrier */
int
win32_spin_init (struct win32_spinlock *lock, int pshared ATTRIBUTE_UNUSED)
{
  lock->value = 0;
  MemoryBarrier ();
  return 0;
}

int
win32_spin_destroy (struct win32_spinlock *lock ATTRIBUTE_UNUSED)
{
  return 0;
}

/* https://learn.microsoft.com/en-us/windows/win32/api/winnt/nf-winnt-interlockedcompareexchange */
int
win32_spin_lock (struct win32_spinlock *lock)
{
  while (InterlockedCompareExchange (&lock->value, 1, 0))
    ;
  return 0;
}

/* https://learn.microsoft.com/en-us/windows/win32/api/winnt/nf-winnt-interlockedcompareexchange */
int
win32_spin_trylock (struct win32_spinlock *lock)
{
  if (InterlockedCompareExchange (&lock->value, 1, 0))
    return EBUSY;
  return 0;
}

/* https://learn.microsoft.com/en-us/windows/win32/api/winnt/nf-winnt-interlockedcompareexchange */
int
win32_spin_unlock (struct win32_spinlock *lock)
{
  if (!InterlockedCompareExchange (&lock->value, 0, 1))
    return EINVAL;
  return 0;
}
