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

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The pointer to the option argument. */
char *optarg;

/* Index of the next element in ARGV to be processed. Must be initialized
   to 1. */
int optind = 1;

/* If the application does not set OPTERR to 0 and the first character of the
   option string is not a colon, getopt(3) should print diagnostic messages to
   stderr. */
int opterr = 1;

/* The option character that caused the error. */
int optopt = 0;

int
getopt (int argc, char *const argv[], const char *optstring)
{
  const char *curr_arg;
  const char *curr_opt;

  if (optind >= argc)
    return -1;

  curr_arg = argv[optind];

  /* argv[optind] is a NULL pointer. */
  if (curr_arg == NULL)
    return -1;
  /* *argv[optind] is not the character '-'. */
  if (curr_arg[0] != '-')
    return -1;
  /* argv[optind] points to the string "--". */
  if (curr_arg[1] == '-' && curr_arg[2] == '\0')
    {
      optind++;
      optopt = curr_arg[1];
      return -1;
    }
  /* argv[optind] points to the string "-". */
  if (curr_arg[1] == '\0')
    return -1;

  curr_opt = strchr (optstring, curr_arg[1]);

  /* Invalid argument. */
  if (curr_opt == NULL)
    {
      optind++;
      optopt = curr_arg[1];
      if (opterr && optstring[0] != ':')
        fprintf (stderr, "%s: illegal option -- %c\n", argv[0], curr_arg[1]);
      return '?';
    }

  /* No extra argument. */
  if (curr_opt[1] != ':')
    {
      optarg = NULL;
      optind++;
    }
  else /* Argument expected. */
    {
      if (argc > optind + 1 && argv[optind + 1] != NULL)
        {
          optarg = argv[optind + 1];
          optopt = curr_arg[1];
          optind++;
        }
      else /* No argument given. */
        {
          optopt = curr_arg[1];
          if (*optstring == ':')
            return ':';
          if (opterr)
            fprintf (stderr, "%s: option requires an argument -- %c\n",
                     argv[0], curr_arg[1]);
          return '?';
        }
      optind += 2;
    }

  return curr_arg[1];
}

#if 0
int
main (int argc, char **argv)
{
  int count = 0;
  int ch;

  while ((ch = getopt (argc, argv, ":abc:")) != -1)
    {
      switch (ch)
        {
        case 'a':
          printf ("ARG %d: a\n", count);
          break;
        case 'b':
          printf ("ARG %d: b\n", count);
          break;
        case 'c':
          printf ("ARG %d: c, \"%s\"\n", count, optarg);
          break;
        case '?':
        default:
          printf ("Invalid option: %c\n", optopt);
          break;
        }
      count++;
    }

  return 0;
}
#endif
