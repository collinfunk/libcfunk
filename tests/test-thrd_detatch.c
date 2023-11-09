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

#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

#include "attributes.h"
#include "test-help.h"

static int worker_func (void *arg);

int
main (void)
{
  thrd_t worker_thread;
  struct timespec ts = { .tv_sec = 1, .tv_nsec = 0 };

  /* Create a thread. */
  ASSERT (thrd_create (&worker_thread, worker_func, NULL) == thrd_success);

  /* Sleep for a second so WORKER_THREAD has time to finish. */
  ASSERT (thrd_sleep (&ts, NULL) == thrd_success);

  /* Make sure thrd_join fails. */
  ASSERT (thrd_join (worker_thread, NULL) == thrd_error);

  return 0;
}

/* The worker thread which calls thrd_detatch on itself. After this
   thread returns, the subsequent call to thrd_join should fail. */
static int
worker_func (void *arg ATTRIBUTE_UNUSED)
{
  ASSERT (thrd_detach (thrd_current ()) == thrd_success);
  return 0;
}
