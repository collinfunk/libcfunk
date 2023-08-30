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

#ifndef PROGRAM_NAME_H
#define PROGRAM_NAME_H

/* These functions act similarly to 4.4BSD's setprogname(3) and getprogname(3).
   4.4BSD would set __progname to the basename of the executable in crt0 before
   invoking main. This means that getprogname(3) would work without calling
   setprogname(3) first. Since we cannot do this, set_program_name () must be
   called before using get_program_name () or else it will return NULL. The
   string given to set_program_name () should exist for the entire lifetime
   of the program. Typically it should be argv[0]. */

/* Sets the internal program name pointer to the basename of FILE_NAME. */
extern void set_program_name (const char *file_name);

/* Returns the program name from the last set_program_name () call or NULL if
   has not been called. */
extern const char *get_program_name (void);

/* This function emulates getprogname(3) from BSD with OS-specific interfaces.
   If an operating system does not have an implementation then a default
   string is returned. This function prioritizes operating system interfaces
   that return the basename of the current process. If the program is executed
   by the shell command `/usr/bin/abc', then this function would try to
   return `abc'. */
extern const char *getprogname (void);

/* This function emulates getprogname(3) from Solaris with OS-specific
   interfaces. If an operating system does not have an implementation a default
   string is returned. This function prioritizes operating system interfaces
   that return the complete path of the current process. If the program is
   executed by the shell command `abc' where `abc' is a program in the user's
   $PATH, this function would try to return the full path to the executable. */
extern const char *getexecname (void);

#endif /* PROGRAM_NAME_H */
