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
char *optarg = NULL;

/* If the application does not set OPTERR to 0 and the first character of the
   option string is not a colon, getopt(3) should print diagnostic messages to
   stderr. */
int opterr = 1;

/* Index of the next element in ARGV to be processed. Must be initialized
   to 1. */
int optind = 1;

/* The option character that caused the error. */
int optopt = '?';

/* Our current position in ARGV. */
static char *position = NULL;

int
getopt (int argc, char *const argv[], const char *short_options)
{
  char ch;
  const char *curr_opt;

  optarg = NULL;

  if (argc < 1)
    return -1;

  if (*short_options == ':')
    opterr = 0;

  if (position == NULL || *position == '\0')
    {
      if (optind >= argc)
        return -1;
      if (argv[optind][0] == '-' && argv[optind][1] != '\0'
          && argv[optind][1] != '-')
        position = &argv[optind][1];
      else
        return -1;
    }

  ch = *position++;
  curr_opt = strchr (short_options, ch);

  /* Goto the next element in ARGV. */
  if (*position == '\0')
    ++optind;

  /* Invalid option. */
  if (curr_opt == NULL)
    {
      if (opterr)
        fprintf (stderr, "%s: illegal option -- %c\n", argv[0], ch);
      optopt = ch;
      return '?';
    }

  if (curr_opt[1] == ':')
    {
      /* Optional argument. */
      if (curr_opt[2] == ':')
        {
          if (*position != '\0')
            {
              optarg = position++;
              ++optind;
            }
          else
            {
              if (optind < argc && argv[optind][0] != '-')
                optarg = argv[optind++];
              else
                optarg = NULL;
            }
          position = NULL;
        }
      else /* Required argument. */
        {
          if (*position != '\0')
            {
              optarg = position++;
              ++optind;
            }
          else
            {
              if (optind < argc)
                optarg = argv[optind++];
              else
                {
                  if (opterr)
                    fprintf (stderr, "%s: option requires an argument -- %c\n",
                             argv[0], ch);
                  optopt = ch;
                  ch = short_options[0] == ':' ? ':' : '?';
                }
              position = NULL;
            }
        }
    }

  return ch;
}

#if 0
int
main (int argc, char **argv)
{
  int count = 0;
  int ch;

  while ((ch = getopt (argc, argv, "abc::d:")) != -1)
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
          printf ("ARG %d: c, \"%s\"\n", count, optarg ? optarg : "[none]");
          break;
        case 'd':
          printf ("ARG %d: d, \"%s\"\n", count, optarg);
          break;
        case '?':
        default:
          exit (1);
        }
      count++;
    }

  return 0;
}
#endif
