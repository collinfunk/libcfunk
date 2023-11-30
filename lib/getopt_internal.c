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
#include <string.h>

#include "getopt_internal.h"

#if !HAVE_OPTARG
char *optarg = NULL;
#endif

#if !HAVE_OPTERR
int opterr = 1;
#endif

#if !HAVE_OPTIND
int optind = 1;
#endif

#if !HAVE_OPTOPT
int optopt = '?';
#endif

static char *position = NULL;

static int getopt_initialized = 0;

static int getopt_handle_long_options (int argc, char **argv,
                                       const char *optstring,
                                       const struct option *longopts,
                                       int *longindex, int long_only);

int
getopt_internal (int argc, char **argv, const char *optstring,
                 const struct option *longopts, int *longindex, int long_only)
{
  char ch;
  const char *curr_opt;

  optarg = NULL;
  if (argc < 1)
    return -1;
  if (!getopt_initialized)
    {
      optarg = NULL;
      opterr = 1;
      optind = 1;
      optopt = '?';
      position = NULL;
      getopt_initialized = 1;
    }
  if (optstring[0] == ':')
    opterr = 0;
  if (position == NULL || position[0] == '\0')
    {
      if (optind >= argc)
        return -1;
      if (argv[optind][0] == '-' && argv[optind][1] == '-'
          && argv[optind][2] == '\0')
        return -1;
      if (argv[optind][0] != '-' || argv[optind][1] == '\0')
        return -1;
      if (longopts != NULL)
        {
          position = &argv[optind][2];
          return getopt_handle_long_options (argc, argv, optstring, longopts,
                                             longindex, long_only);
        }
      position = &argv[optind][1];
    }
  ch = *position++;
  curr_opt = (const char *) strchr (optstring, ch);
  if (position[0] == '\0')
    optind++;
  if (curr_opt == NULL || ch == ':' || ch == ';')
    {
      if (opterr)
        fprintf (stderr, "%s: illegal option -- %c\n", argv[0], ch);
      optopt = ch;
      return '?';
    }
  if (curr_opt[1] == ':')
    {
      if (curr_opt[2] == ':')
        {
          if (position[0] == ':')
            {
              optarg = position++;
              optind++;
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
      else
        {
          if (position[0] != '\0')
            {
              optarg = position++;
              optind++;
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
                  ch = optstring[0] == ':' ? ':' : '?';
                }
            }
          position = NULL;
        }
    }
  return ch;
}

static int
getopt_handle_long_options (int argc, char **argv, const char *optstring,
                            const struct option *longopts, int *longindex,
                            int long_only)
{
  const char *option_name_start;
  const char *option_name_end;
  const struct option *match;
  size_t option_name_len;
  size_t i;
  int has_equal;

  option_name_start = (const char *) position;
  option_name_end = (const char *) strchr (option_name_start, '=');
  if (option_name_end != NULL)
    {
      has_equal = 1;
      option_name_len = option_name_end - option_name_start;
    }
  else
    {
      has_equal = 0;
      option_name_len = strlen (option_name_start);
      option_name_end = option_name_start + option_name_len;
    }
  for (match = NULL, i = 0; longopts[i].name != NULL; ++i)
    {
      if (strncmp (option_name_start, longopts[i].name, option_name_len) == 0
          && strlen (longopts[i].name) == option_name_len)
        {
          match = &longopts[i];
          break;
        }
    }
  if (match == NULL)
    {
      if (opterr)
        fprintf (stderr, "%s: unrecognized option '--%s'\n", argv[0],
                 option_name_start);
      position = NULL;
      optind++;
      optopt = 0;
      return '?';
    }
  optind++;
  position = NULL;
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
  else
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
              return optstring[0] == ':' ? ':' : '?';
            }
        }
    }
  if (longindex != NULL)
    *longindex = (int) i;
  if (match->flag == NULL)
    return match->val;
  else
    {
      *match->flag = match->val;
      return 0;
    }
}
