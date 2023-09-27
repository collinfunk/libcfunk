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

#ifndef OPEN_STANDARD_STREAMS_H
#define OPEN_STANDARD_STREAMS_H

/* Check that STDIN, STDOUT, and STDERR are open. If they are not open this
   function will open them pointing to the systems null device with the
   opposite mode than is expected (O_WRONLY vs O_RDONLY). If STDIN, STDOUT,
   or STDERR are closed and fail to open then -1 is returned. If this function
   returns 0 then all 3 streams are opened.

   Many POSIX functions (dup, pipe, open, creat, etc) allocate new file
   descriptors using the lowest unused (unopened) integer to return.
   If STDIN (0), STDOUT (1), or STDERR (2) are closed, use of any of these
   functions would result in unintentionally setting them to an unassociated
   file.

   Since files are opened in the opposite mode than is expected, normal reads
   and writes will fail with errno == EBADF. This behavior only occurs in the
   rare case that one of these streams is closed.
 */
extern int open_standard_streams (void);

#endif /* OPEN_STANDARD_STREAMS_H */
