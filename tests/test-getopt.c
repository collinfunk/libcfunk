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

/* Simple test program for 'getopt'. */
int
main (int argc, char **argv)
{
  int ch;
  int seen_options = 0;

  while ((ch = getopt (argc, argv, ":abf:o:")) != -1)
    {
      switch (ch)
        {
        case 'a':
          printf ("%d: Saw option a.\n", seen_options);
          ++seen_options;
          break;
        case 'b':
          printf ("%d: Saw option b.\n", seen_options);
          ++seen_options;
          break;
        case 'f':
          ASSERT (optarg != NULL);
          printf ("%d: Saw option f with argument '%s'.\n", seen_options,
                  optarg);
          ++seen_options;
          break;
        case 'o':
          ASSERT (optarg != NULL);
          printf ("%d: Saw option o with argument '%s'.\n", seen_options,
                  optarg);
          ++seen_options;
          break;
        case ':':
          fprintf (stderr, "%d: Missing argument for %c.\n", seen_options, ch);
          ++seen_options;
          break;
        case '?':
        default:
          fprintf (stderr, "%d: Invalid option %c.\n", seen_options, optopt);
          ++seen_options;
          break;
        }
    }

  printf ("Total options seen: %d\n", seen_options);

  return 0;
}
