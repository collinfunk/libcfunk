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

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test-help.h"

struct signal_string
{
  int value;
  const char *str;
};

/* Signals required by C99. */
static const struct signal_string supported_signals[] = {
#ifdef SIGABRT
/* May also be "Abort trap". Just ignore this one. */
/* { SIGABRT, "Aborted" }, */
#endif
#ifdef SIGFPE
  { SIGFPE, "Floating point exception" },
#endif
#ifdef SIGILL
  { SIGILL, "Illegal instruction" },
#endif
#ifdef SIGINT
  { SIGINT, "Interrupt" },
#endif
#ifdef SIGSEGV
  { SIGSEGV, "Segmentation fault" },
#endif
#ifdef SIGTERM
  { SIGTERM, "Terminated" },
#endif
};

static void test_strsignal_invalid (void);
static void test_strsignal_valid (void);

int
main (void)
{
  test_strsignal_invalid ();
  test_strsignal_valid ();
  return 0;
}

/* POSIX allows this function to return NULL if the signal number is invalid.
   Try to make sure it acts like BSD and GNU libc where are descriptive string
   is returned. */
static void
test_strsignal_invalid (void)
{
  const char *result;

  /* Make sure we get a non-empty string. */
  result = strsignal (-1);
  ASSERT (result != NULL);
  ASSERT (result[0] != '\0');
}

/* Test strsignal with some valid signal numbers. */
static void
test_strsignal_valid (void)
{
  size_t i;

  for (i = 0; i < ARRAY_SIZE (supported_signals); ++i)
    {
      const char *result = strsignal (supported_signals[i].value);

      ASSERT (result != NULL);
      ASSERT (strcmp (result, supported_signals[i].str) == 0);
    }
}
