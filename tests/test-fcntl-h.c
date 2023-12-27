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

#include <fcntl.h>

#include "attributes.h"

static void test_mode_t_defined (void);
static void test_off_t_defined (void);
static void test_pid_t_defined (void);
static void test_O_macros_defined (void);

/* Test that 'fcntl.h' can be included. */
int
main (void)
{
  test_mode_t_defined ();
  test_off_t_defined ();
  test_pid_t_defined ();
  test_O_macros_defined ();
  return 0;
}

/* Test that 'mode_t' is defined. */
static void
test_mode_t_defined (void)
{
  mode_t value ATTRIBUTE_UNUSED;
}

/* Test that 'off_t' is defined. */
static void
test_off_t_defined (void)
{
  off_t value ATTRIBUTE_UNUSED;
}

/* Test that 'pid_t' is defined. */
static void
test_pid_t_defined (void)
{
  pid_t value ATTRIBUTE_UNUSED;
}

/* Test that the 'O_*' macros are defined. */
static void
test_O_macros_defined (void)
{
  int value ATTRIBUTE_UNUSED;

  value = (O_CLOEXEC | O_CREAT | O_DIRECTORY | O_EXCL | O_NOCTTY | O_NOFOLLOW
           | O_TRUNC | O_TTY_INIT | O_APPEND | O_DSYNC | O_NONBLOCK | O_RSYNC
           | O_SYNC | O_ACCMODE | O_EXEC | O_RDONLY | O_RDWR | O_SEARCH
           | O_WRONLY | O_TEXT | O_BINARY);
}
