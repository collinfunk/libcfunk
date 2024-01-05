/*-
 * Copyright (c) 2024, Collin Funk
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

#include "attributes.h"
#include "test-help.h"

/* Signals required by C99. */
static const int supported_signals[] = {
#ifdef SIGABRT
  SIGABRT,
#endif
#ifdef SIGFPE
  SIGFPE,
#endif
#ifdef SIGILL
  SIGILL,
#endif
#ifdef SIGINT
  SIGINT,
#endif
#ifdef SIGSEGV
  SIGSEGV,
#endif
#ifdef SIGTERM
  SIGTERM,
#endif
};

/* Incremented inside of the signal handler. */
static int signals_received = 0;

static void signal_handler (int signal_number);
static void test_sigaction_no_flags (void);

int
main (void)
{
  test_sigaction_no_flags ();
  return 0;
}

static void
signal_handler (int signal_number ATTRIBUTE_UNUSED)
{
  signals_received++;
}

static void
test_sigaction_no_flags (void)
{
  size_t i;
  struct sigaction sa;

  /* Setup the sigaction structure. */
  sa.sa_flags = 0;
  sa.sa_handler = signal_handler;
  ASSERT (sigemptyset (&sa.sa_mask) == 0);

  /* Setup the signals. */
  for (i = 0; i < ARRAY_SIZE (supported_signals); ++i)
    ASSERT (sigaction (supported_signals[i], &sa, NULL) == 0);

  /* Raise each of the signals. */
  for (i = 0; i < ARRAY_SIZE (supported_signals); ++i)
    ASSERT (raise (supported_signals[i]) == 0);

  ASSERT ((size_t) signals_received == ARRAY_SIZE (supported_signals));
}
