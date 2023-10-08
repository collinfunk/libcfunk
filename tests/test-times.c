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

#include <sys/times.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "test-help.h"

int
main (void)
{
  struct tms start_tms, end_tms;
  clock_t start_time, end_time;
  long long int real_time, user_time, system_time;
  long int i, j;

  start_time = times (&start_tms);
  ASSERT (start_time != (clock_t) -1);

  for (i = 0; i < 100000; ++i)
    for (j = 0; j < 10000; ++j)
      ;

  end_time = times (&end_tms);

  real_time = (long long int) (end_time - start_time);
  user_time = (long long int) (end_tms.tms_utime - start_tms.tms_utime);
  system_time = (long long int) (end_tms.tms_stime - start_tms.tms_stime);

  printf ("Real time:   %lld\n", real_time);
  printf ("User time:   %lld\n", user_time);
  printf ("System time: %lld\n", system_time);

  return 0;
}
