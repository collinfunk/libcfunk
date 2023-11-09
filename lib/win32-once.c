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

/* #include <config.h> */

#ifndef _WIN32_WINNT
#  define _WIN32_WINNT 0x0600
#endif

#include <windows.h>

#include "attributes.h"
#include "win32-once.h"

#ifndef CALLBACK
#  define CALLBACK __stdcall
#endif

/* https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nc-synchapi-pinit_once_fn */
static BOOL CALLBACK
win32_once_entry_point (INIT_ONCE *control, void *param,
                        void **context ATTRIBUTE_UNUSED)
{
  void (*init_routine) (void) = (void (*) (void)) param;
  (*init_routine) ();
  return TRUE;
}

/* https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-initonceexecuteonce */
int
win32_once (struct win32_once *once_control, void (*init_routine) (void))
{
  BOOL result;

  result = InitOnceExecuteOnce (&once_control->control, win32_once_entry_point,
                                (void *) init_routine, NULL);
  if (!result)
    return EINVAL;
  else
    return 0;
}
