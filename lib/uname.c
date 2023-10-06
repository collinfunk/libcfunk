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

#include <sys/utsname.h>

#include <string.h>

#if HAVE_WINDOWS_H
#  include <windows.h>
#endif

#if HAVE_SYSINFOAPI_H
#  include <sysinfoapi.h>
#endif

#if HAVE_WINDOWS_H

int
uname (struct utsname *name)
{
  SYSTEM_INFO system_info;

  /* FIXME */
  strcpy (name->sysname, "Windows");

  /* Don't care about casting to int since name->nodename is small. */
  if (gethostname (name->nodename, (int) sizeof (name->nodename)) < 0)
    name->nodename[0] = '\0';

  GetSystemInfo (&system_info);

  switch (system_info.wProcessorArchitecture)
    {
    case PROCESSOR_ARCHITECTURE_INTEL:
      name->machine[0] = 'i';
      /* The 'wProcessorLevel' isn't documented well but seems roughly match
         the CPU family as returned by the cpuid instruction. */
      if (system_info.wProcessorLevel < 3)
        name->machine[1] = '3';
      else if (system_info.wProcessorLevel > 6)
        name->machine[1] = '6';
      else
        name->machine[1] = system_info.wProcessorLevel + '0';
      name->machine[2] = '8';
      name->machine[3] = '6';
      name->machine[4] = '\0';
      break;
    case PROCESSOR_ARCHITECTURE_ARM:
      strcpy (name->machine, "arm");
      break;
    case PROCESSOR_ARCHITECTURE_IA64:
      strcpy (name->machine, "ia64");
      break;
    case PROCESSOR_ARCHITECTURE_AMD64:
      strcpy (name->machine, "x86_64");
      break;
    case PROCESSOR_ARCHITECTURE_ARM64:
      strcpy (name->machine, "aarch64");
      break;
    default:
      *name->machine = '\0';
      break;
    }

  /* FIXME */
  *name->release = '\0';
  *name->version = '\0';

  return 0;
}

#else /* !HAVE_WINDOWS_H */

/* Not sure of any Non-Windows systems without uname. Just make sure each
   member is NUL terminated. */
int
uname (struct utsname *name)
{
  *name->sysname = '\0';
  *name->nodename = '\0';
  *name->release = '\0';
  *name->version = '\0';
  *name->machine = '\0';
  return 0;
}

#endif
