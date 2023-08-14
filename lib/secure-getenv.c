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

#include <stdlib.h>
#include <unistd.h>

/* Emulation of the glibc function secure_getenv for other systems.
   The main use of this function is to protect against returning environment
   variables and trusting them when the current process is affected by setuid
   and/or setgid. I believe it has some other Linux-specific features but
   the main use can be implemented for other systems.

   For the BSD's we can use the the issetugid(2) system call. This returns 1
   if the current process is affected by setuid or setgid from previous
   execve(2) calls. This function was first implemented in OpenBSD 2.0.
   It has been available on FreeBSD since version 3.0 and NetBSD since
   version 1.5.
      https://man.openbsd.org/issetugid.2
      https://man.freebsd.org/cgi/man.cgi?query=issetugid
      https://man.netbsd.org/issetugid.2

   For systems that are POSIX-compliant, we can use the getgid(2), geteguid(2),
   getuid(2), and geteuid(2) system calls. If the effective and real ID's
   are the same, then return the environment variables.
 */

char *
secure_getenv (const char *name)
{
#if HAVE_ISSETUGID
  /* Check if we are effected by setgid or setuid. */
  if (issetugid ())
    return NULL;
  return getenv (name);
#elif HAVE_GETGID && HAVE_GETEGID && HAVE_GETUID && HAVE_GETEUID
  /* Check if effected by setgid. */
  if (getgid () != getegid ())
    return NULL;
  /* Check if effected by setuid. */
  if (getuid () != geteuid ())
    return NULL;
  return getenv (name);
#else
#  error "secure_getenv not implemented for your system."
#endif
  return NULL;
}
