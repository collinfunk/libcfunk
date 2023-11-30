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

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "test-help.h"

static int verbose_flag = 0;

/* Simple test program for 'getopt_long_only'. */
int
main (int argc, char **argv)
{
  int ch;
  int option_index = 0;
  int seen_options = 0;

  static const struct option long_options[] = {
    { "verbose", no_argument, &verbose_flag, 1 },
    { "quiet", no_argument, &verbose_flag, 0 },
    { "create", required_argument, NULL, 'c' },
    { "delete", required_argument, NULL, 'd' },
    { NULL, 0, NULL, 0 },
  };

  for (;;)
    {
      ch = getopt_long_only (argc, argv, "c:d:", long_options, &option_index);

      if (ch == -1)
        break;

      switch (ch)
        {
        case 0:
          seen_options++;
          break;
        case 'c':
          printf ("Option %d: --create %s\n", seen_options, optarg);
          seen_options++;
          break;
        case 'd':
          printf ("Option %d: --delete %s\n", seen_options, optarg);
          seen_options++;
          break;
        case '?':
          break;
        default:
          exit (1);
        }
    }

  return 0;
}
