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

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* TODO: Implement the mode GNU getopt defaults to. Permute ARGV so that
   nonoption elements are put at the end. */

struct option
{
  const char *name;
  int has_arg;
  int *flag;
  int val;
};

#define no_argument 0
#define required_argument 1
#define optional_argument 2

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

static int getopt_handle_long_options (int argc, char **argv,
                                       const char *short_options,
                                       const struct option *long_options,
                                       int *long_index, int long_options_only);
static int getopt_internal (int argc, char **argv, const char *short_options,
                            const struct option *long_options, int *long_index,
                            int long_options_only);

int getopt (int argc, char *const argv[], const char *short_options);
int getopt_long (int argc, char *const argv[], const char *short_options,
                 const struct option *long_options, int *long_index);
int getopt_long_only (int argc, char *const argv[], const char *short_options,
                      const struct option *long_options, int *long_index);

static int
getopt_handle_long_options (int argc, char **argv, const char *short_options,
                            const struct option *long_options, int *long_index,
                            int long_options_only)
{
  const char *option_name_start;
  const char *option_name_end;
  const struct option *match;
  size_t option_name_len, i;
  int has_equal;

  option_name_start = position;
  option_name_end = strchr (option_name_start, '=');

  /* Option has an argument after an '='. */
  if (option_name_end != NULL)
    {
      has_equal = 1;
      option_name_len = option_name_end - option_name_start;
    }
  else /* The full string is the option. */
    {
      has_equal = 0;
      option_name_len = strlen (option_name_start);
      option_name_end = option_name_start + option_name_len;
    }

  /* Find a matching option. Make sure both names are the same length so we
     don't mistake two options with the same prefix. */
  for (match = NULL, i = 0; long_options[i].name != NULL; ++i)
    {
      if (strncmp (option_name_start, long_options[i].name, option_name_len)
              == 0
          && strlen (long_options[i].name) == option_name_len)
        {
          match = &long_options[i];
          break;
        }
    }

  if (match == NULL)
    {
      if (opterr)
        fprintf (stderr, "%s: unrecognized option '--%s'\n", argv[0],
                 option_name_start);
      position = NULL;
      ++optind;
      optopt = 0;
      return '?';
    }

  ++optind;
  position = NULL;

  /* The option has an argument in the form "--option=argument". */
  if (has_equal)
    {
      if (match->has_arg == required_argument
          || match->has_arg == optional_argument)
        optarg = (char *) ++option_name_end;
      else
        {
          if (opterr)
            fprintf (stderr, "%s: option '--%s' doesn't allow an argument\n",
                     argv[0], match->name);
          optopt = match->val;
          return '?';
        }
    }
  else /* Argument may be the next index in ARGV. */
    {
      if (match->has_arg == required_argument)
        {
          if (optind < argc)
            optarg = argv[optind++];
          else
            {
              if (opterr)
                fprintf (stderr, "%s: option '--%s' requires an argument\n",
                         argv[0], match->name);
              optopt = match->val;
              return short_options[0] == ':' ? ':' : '?';
            }
        }
    }

  if (long_index != NULL)
    *long_index = (int) i;
  if (match->flag == NULL)
    return match->val;
  else
    {
      *match->flag = match->val;
      return 0;
    }
}

static int
getopt_internal (int argc, char **argv, const char *short_options,
                 const struct option *long_options, int *long_index,
                 int long_options_only)
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

      /* First non-option argument "--". */
      if (argv[optind][0] == '-' && argv[optind][1] == '-'
          && argv[optind][2] == '\0')
        return -1;

      /* Not an argument. */
      if (argv[optind][0] != '-' || argv[optind][0] == '\0')
        return -1;

      if (long_options != NULL)
        {
          /* -- which is a long option. */
          if (argv[optind][1] == '-')
            {
              position = &argv[optind][2];
              return getopt_handle_long_options (argc, argv, short_options,
                                                 long_options, long_index,
                                                 long_options_only);
            }
        }
      position = &argv[optind][1];
    }

  ch = *position++;
  curr_opt = strchr (short_options, ch);

  /* Goto the next element in ARGV. */
  if (*position == '\0')
    ++optind;

  /* Invalid option. */
  if (curr_opt == NULL || ch == ':' || ch == ';')
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
      else /* Required option. */
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
            }
          position = NULL;
        }
    }
  return ch;
}

int
getopt (int argc, char *const argv[], const char *short_options)
{
  return getopt_internal (argc, (char **) argv, short_options, NULL, NULL, 0);
}

int
getopt_long (int argc, char *const argv[], const char *short_options,
             const struct option *long_options, int *long_index)
{
  return getopt_internal (argc, (char **) argv, short_options, long_options,
                          long_index, 0);
}

int
getopt_long_only (int argc, char *const argv[], const char *short_options,
                  const struct option *long_options, int *long_index)
{
  return getopt_internal (argc, (char **) argv, short_options, long_options,
                          long_index, 1);
}

#if 0
int
main (int argc, char **argv)
{
  int count = 0;
  int option_index = 1;
  static int verbose_flag = 0;
  int ch;

  static struct option long_options[]
      = { { "verbose", no_argument, &verbose_flag, 1 },
          { "quiet", no_argument, &verbose_flag, 0 },
          { "list", no_argument, NULL, 'l' },
          { "create", required_argument, NULL, 'c' },
          { "delete", required_argument, NULL, 'd' },
          { NULL, 0, NULL, 0 } };

  for (;;)
    {
      ch = getopt_long (argc, argv, "lc:d:", long_options, &option_index);
      if (ch == -1)
        break;

      switch (ch)
        {
        case 0:
          break;
        case 'l':
          printf ("option -l (--list)\n");
          break;
        case 'c':
          printf ("option -c (--create): \"%s\"\n", optarg);
          break;
        case 'd':
          printf ("option -d (--delete): \"%s\"\n", optarg);
          break;
        case '?':
        default:
          abort ();
        }
    }

  if (verbose_flag)
    printf ("Verbose option set.\n");
  else
    printf ("Verbose option not set.\n");

  return 0;
}
#endif
