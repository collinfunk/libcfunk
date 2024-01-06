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
static void test_signal (void);
static void test_signal_is_bsd_or_sysv (void);

int
main (void)
{
  test_signal ();
  test_signal_is_bsd_or_sysv ();
  return 0;
}

static void
signal_handler (int signal_number ATTRIBUTE_UNUSED)
{
  signals_received++;
}

static void
test_signal (void)
{
  size_t i;

  /* Setup the signals. */
  for (i = 0; i < ARRAY_SIZE (supported_signals); ++i)
    ASSERT (signal (supported_signals[i], signal_handler) != SIG_ERR);

  for (i = 0; i < ARRAY_SIZE (supported_signals); ++i)
    ASSERT (raise (supported_signals[i]) == 0);

  ASSERT ((size_t) signals_received == ARRAY_SIZE (supported_signals));
}

static void
test_signal_is_bsd_or_sysv (void)
{
  size_t i;
  bool is_bsd;

  for (i = 0; i < ARRAY_SIZE (supported_signals); ++i)
    {
      if (i == 0)
        is_bsd = signal (supported_signals[i], SIG_DFL) == signal_handler;
      else if (is_bsd)
        ASSERT (signal (supported_signals[i], SIG_DFL) == signal_handler);
      else
        ASSERT (signal (supported_signals[i], SIG_DFL) != signal_handler);
    }

  if (is_bsd)
    printf ("Your system uses BSD-like signals.\n");
  else
    printf ("Your system uses System V-like signals.\n");
}
