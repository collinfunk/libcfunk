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
#include <stdlib.h>

#include "filename.h"

const char *
getprogname (void)
#undef getprogname
{

#if HAVE_PROGRAM_INVOCATION_SHORT_NAME
  {
    if (program_invocation_short_name != NULL
        && *program_invocation_short_name != '\0')
      return program_invocation_short_name;
  }
#endif

#if HAVE_PROGRAM_INVOCATION_NAME
  {
    if (program_invocation_name != NULL && *program_invocation_name != '\0')
      return filename_last_component (program_invocation_name);
  }
#endif

#if HAVE___ARGV
  {
    if (__argv != NULL && __argv[0] != NULL && __argv[0][0] != '\0')
      return filename_last_component (__argv[0]);
  }
#endif

#if HAVE_GETEXECNAME
  {
    const char *ptr = getexecname ();
    if (ptr != NULL)
      return filename_last_component (ptr);
  }
#endif

  /* TODO: Return something? */
  return "";
}
