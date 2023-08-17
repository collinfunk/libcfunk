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

#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

/* TODO: This implementation only works on Linux, FreeBSD, recent versions
   of NetBSD, and maybe Solaris. */

#if (!defined(_SC_PAGE_SIZE) && !defined(_SC_PAGESIZE))                       \
    || !defined(_SC_PHYS_PAGES)
#  error "physical_memory_total () is unsupported."
#endif

/* POSIX issue 7 says these should both be defined.
   Make sure we get a defined value just incase only 1 is defined. */
#ifndef _SC_PAGE_SIZE
#  define _SC_PAGE_SIZE _SC_PAGESIZE
#endif

#ifndef _SC_PAGESIZE
#  define _SC_PAGESIZE _SC_PAGE_SIZE
#endif

size_t
physical_memory_total (void)
{
  long int page_count = sysconf (_SC_PHYS_PAGES);
  long int page_size = sysconf (_SC_PAGE_SIZE);

  /* TODO: Better way to handle this? */
  if (page_count <= 0 || page_size <= 0)
    return 0;

  /* Check for overflow. If so return the maximum that be stored in size_t. */
  if ((size_t) page_count > (SIZE_MAX / (size_t) page_size))
    return SIZE_MAX;

  return page_count * page_size;
}
