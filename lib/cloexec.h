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

#ifndef CLOEXEC_H
#define CLOEXEC_H

/* These functions use fcntl to set and unset the FD_CLOEXEC flag on opened
   file descriptors. This method should generally be avoided if possible by
   using safer methods such as opening file descriptors with the O_CLOEXEC
   flag. In multithreaded programs using fcntl to set the FD_CLOEXEC flag
   has the potential to leak file descriptors to child processes. A race
   condition occurs when one thread is setting the flag and the other thread
   is calling fork and exec. If the fork & exec thread finishes first then
   the file descriptor is not closed and is leaked to the child process.
   See CWE-403. */

/* Returns 1 if the FD_CLOEXEC flag is set on FD or 0 if it is not set.
   If this function returns -1, an error occurred and errno is set. */
extern int cloexec_is_set (int fd);

/* Sets the FD_CLOEXEC flag on FD. If 0 is returned either the FD_CLOEXEC flag
   was already set or it has successfully been set by a call to fcntl. If -1
   is returned then the call to fcntl failed and errno is set. */
extern int set_cloexec (int fd);

/* Unsets the FD_CLOEXEC flag on FD. If 0 is returned either the FD_CLOEXEC
   flag was already unset on FD or it has successfully been removed by a call
   to fcntl. If -1 is returned then the call to fcntl failed and errno
   is set. */
extern int unset_cloexec (int fd);

/* Duplicates a file descriptor and sets the FD_CLOEXEC flag. This avoids the
   race conditions caused by calling fcntl after calling dup. */
extern int dup_cloexec (int fd);

#endif /* CLOEXEC_H */
