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

#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

#include "physical-memory.h"

#if HAVE_SYS_SYSCTL_H
#  include <sys/sysctl.h>
#endif

#ifdef _WIN32
#  include <windows.h>
#else
/* POSIX issue 7 says these should both be defined.
   Make sure we get a defined value just incase only 1 is defined. */
#  if defined(_SC_PAGE_SIZE) || defined(_SC_PAGESIZE)
#    ifndef _SC_PAGE_SIZE
#      define _SC_PAGE_SIZE _SC_PAGESIZE
#    endif
#    ifndef _SC_PAGESIZE
#      define _SC_PAGESIZE _SC_PAGE_SIZE
#    endif
#  endif
#endif

#include <stdio.h>

uint64_t
physical_memory_available (void)
{
#ifdef _WIN32
  struct _MEMORYSTATUSEX memory_status_ex;

  memory_status_ex.dwLength = sizeof (memory_status_ex);
  if (!GlobalMemoryStatusEx (&memory_status_ex))
    return 0;

  return (uint64_t) memory_status_ex.ullAvailPhys;
#elif defined(_SC_AVPHYS_PAGES)
  long int page_count = sysconf (_SC_AVPHYS_PAGES);
  long int page_size = sysconf (_SC_PAGE_SIZE);

  /* TODO: Better way to handle this? */
  if (page_count <= 0 || page_size <= 0)
    return 0;

  /* Check for overflow. If so return the maximum that be stored in size_t. */
  if ((uint64_t) page_count > (UINT64_MAX / (uint64_t) page_size))
    return UINT64_MAX;

  return page_count * page_size;
#elif defined(HW_USERMEM64)
  uint64_t user_mem;
  int mib[2] = { CTL_HW, HW_USERMEM64 };
  size_t len = sizeof (user_mem);

  if (sysctl (mib, 2, &user_mem, &len, NULL, 0) == 0
      && len == sizeof (user_mem) && user_mem > 0)
    return user_mem;
  return 0;
#elif defined(HW_USERMEM)
  /* XXX: Leave this as a 64-bit value. NetBSD and OpenBSD say it uses
     a 32-bit integer (deprecated for HW_USERMEM64). FreeBSD just says
     it returns an "integer". FreeBSD 13.2 will fail with a 32-bit
     integer on my machine, but it works fine with a 64-bit integer. */
  uint64_t user_mem;
  int mib[2] = { CTL_HW, HW_USERMEM };
  size_t len = sizeof (user_mem);

  if (sysctl (mib, 2, &user_mem, &len, NULL, 0) == 0
      && len == sizeof (user_mem) && user_mem > 0)
    return user_mem;
  return 0;
#endif
  return 0;
}

uint64_t
physical_memory_total (void)
{
#ifdef _WIN32
  struct _MEMORYSTATUSEX memory_status_ex;

  memory_status_ex.dwLength = sizeof (memory_status_ex);
  if (!GlobalMemoryStatusEx (&memory_status_ex))
    return 0;

  return (uint64_t) memory_status_ex.ullTotalPhys;
#elif defined(_SC_PHYS_PAGES)
  long int page_count = sysconf (_SC_PHYS_PAGES);
  long int page_size = sysconf (_SC_PAGE_SIZE);

  /* TODO: Better way to handle this? */
  if (page_count <= 0 || page_size <= 0)
    return 0;

  /* Check for overflow. If so return the maximum that be stored in size_t. */
  if ((uint64_t) page_count > (UINT64_MAX / (uint64_t) page_size))
    return UINT64_MAX;

  return page_count * page_size;
#elif defined(HW_PHYSMEM64)
  uint64_t phys_mem;
  int mib[2] = { CTL_HW, HW_PHYSMEM64 };
  size_t len = sizeof (phys_mem);

  if (sysctl (mib, 2, &phys_mem, &len, NULL, 0) == 0
      && len == sizeof (phys_mem) && phys_mem > 0)
    return phys_mem;
  return 0;
#elif defined(HW_PHYSMEM)
  /* XXX: Leave this as a 64-bit value. NetBSD and OpenBSD say it uses
     a 32-bit integer (deprecated for HW_PHYSMEM64). FreeBSD just says
     it returns an "integer". FreeBSD 13.2 will fail with a 32-bit
     integer on my machine, but it works fine with a 64-bit integer. */
  uint64_t phys_mem;
  int mib[2] = { CTL_HW, HW_PHYSMEM };
  size_t len = sizeof (phys_mem);

  if (sysctl (mib, 2, &phys_mem, &len, NULL, 0) == 0
      && len == sizeof (phys_mem) && phys_mem > 0)
    return phys_mem;
  return 0;
#endif
  return 0;
}
