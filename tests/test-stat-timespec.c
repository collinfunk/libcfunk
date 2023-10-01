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

#include <errno.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stat-timespec.h"
#include "test-help.h"

/* This should be true on most systems. */
#ifndef STAT_HAS_NANOSECONDS
#  define STAT_HAS_NANOSECONDS 1
#endif

#ifndef FILE_TO_STAT
#  define FILE_TO_STAT __FILE__
#endif

static void check_timespec (struct timespec *ts, const char *str);

int
main (void)
{
  struct stat st;
  struct timespec ts;

  if (stat (FILE_TO_STAT, &st) < 0)
    {
      fprintf (stderr, "Failed to stat %s: %s\n", FILE_TO_STAT,
               strerror (errno));
      abort ();
    }

  ts = stat_get_atime_timespec (&st);
  check_timespec (&ts, "atime");
  ts = stat_get_ctime_timespec (&st);
  check_timespec (&ts, "ctime");
  ts = stat_get_mtime_timespec (&st);
  check_timespec (&ts, "mtime");

  return 0;
}

static void
check_timespec (struct timespec *ts, const char *str)
{
  printf ("%s\n", str);
  printf ("  seconds:     %jd\n", (intmax_t) ts->tv_sec);
  printf ("  nanoseconds: %ld\n", ts->tv_nsec);
#if STAT_HAS_NANOSECONDS
  /* Assume nanoseconds isn't zero and pray. */
  if (ts->tv_nsec == 0L)
    {
      abort ();
    }
#else
  if (ts->tv_nsec != 0)
    {
      abort ();
    }
#endif
}
