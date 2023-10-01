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

#include <sys/stat.h>
#include <sys/types.h>

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* The path to the systems shell database file. */
#ifndef SHELL_DATABASE
#  define SHELL_DATABASE "/etc/shells"
#endif

/* The path to the systems shell. */
#ifndef SH_PATH
#  define SH_PATH "/bin/sh"
#endif

/* The path to the systems C shell. */
#ifndef CSH_PATH
#  define CSH_PATH "/bin/csh"
#endif

/* This array contains the default shells that are returned if SHELL_DATABASE
   does not exist or cannot be opened. They are chosen for compatibility with
   the original BSD function. You can replace choices for your operating system
   as long as the last element is NULL. */
static const char *default_shells[3] = { SH_PATH, CSH_PATH, NULL };

/* The data read from the file or NULL. */
static char *shell_data = NULL;

/* The number of bytes in shell_data. */
static size_t shell_data_size = 0;

/* Current position into the shell_data buffer. */
static size_t shell_data_index = 0;

/* Set to 0 if the default shells are not being used. If it is not 0 it is
   being used to index the default shells. */
static size_t default_index = 0;

static int load_shell_database (void);
static char *get_next_shell (void);

/* Get the next shell or return NULL if there is none. */
char *
getusershell (void)
{
  /* Return data from the file if it is avaliable. */
  if (shell_data != NULL)
    return get_next_shell ();
  else
    {
      /* Try to load the file. If it doesnt work return a default shell. */
      if (!(load_shell_database () < 0))
        return get_next_shell ();
      else
        {
          if (default_shells[default_index] != NULL)
            return (char *) default_shells[default_index++];
          else
            return NULL;
        }
    }
}

/* Rewind the shell database. */
void
setusershell (void)
{
  shell_data_index = 0;
  default_index = 0;
}

/* Free all used memory. */
void
endusershell (void)
{
  free (shell_data);
  shell_data = NULL;
  shell_data_size = 0;
  shell_data_index = 0;
  default_index = 0;
}

/* Load the shell file into memory. */
static int
load_shell_database (void)
{
  FILE *fp;
  struct stat st;

  /* Make sure SHELL_DATABASE isn't a empty file. */
  if (stat (SHELL_DATABASE, &st) < 0 || !S_ISREG (st.st_mode)
      || st.st_size <= 0)
    return -1;

  fp = fopen (SHELL_DATABASE, "r");
  if (fp == NULL)
    return -1;

  shell_data = (char *) malloc (st.st_size);
  if (shell_data == NULL)
    {
      fclose (fp);
      return -1;
    }

  if (fread (shell_data, st.st_size, 1, fp) != 1)
    {
      fclose (fp);
      free (shell_data);
      shell_data = NULL;
      return -1;
    }

  shell_data_index = 0;
  shell_data_size = st.st_size;
  fclose (fp);
  return 0;
}

/* Return the next shell from the shell database. If there is no more left then
   NULL is returned. */
static char *
get_next_shell (void)
{
  unsigned char *p;
  const unsigned char *end;

  if (shell_data == NULL || shell_data_index >= shell_data_size)
    return NULL;

  p = (unsigned char *) shell_data + shell_data_index;
  end = (const unsigned char *) shell_data + shell_data_size;

  for (;;)
    {
      /* Base case. End of line. */
      if (*p == '\n' || *p == '\0')
        {
          *p++ = '\0';
          if (p >= end)
            return NULL;
        }
      /* Single line comments. */
      else if (*p == '#')
        {
          do
            ++p;
          while (*p != '\n' && *p != '\0');
        }
      /* Found an absolute file path. */
      else if (*p == '/')
        {
          char *save = (char *) p;
          do
            ++p;
          while (*p != '\0' && !isspace (*p));
          *p++ = '\0';
          shell_data_index = p - (unsigned char *) shell_data;
          return save;
        }
      /* Unknown. Go to next line. */
      else
        {
          do
            ++p;
          while (*p != '\n' || *p != '\0');
        }
    }

  return NULL;
}

/* Simple test defined here so you can change SHELL_DATABASE to point to a
   different file. You may not have one in "/etc/shells" or it might be small
   depending on how many shells you have installed.  */
#if 0
int
main (void)
{
  char *ptr;

  endusershell ();
  printf ("Pass one of %s:\n", SHELL_DATABASE);

  for (;;)
    {
      ptr = getusershell ();
      if (ptr == NULL)
        break;
      printf ("%s\n", ptr);
    }

  /* Rewind. */
  setusershell ();
  printf ("Pass two of %s:\n", SHELL_DATABASE);

  for (;;)
    {
      ptr = getusershell ();
      if (ptr == NULL)
        break;
      printf ("%s\n", ptr);
    }

  /* Close and reopen. */
  endusershell ();
  printf ("Pass three of %s:\n", SHELL_DATABASE);
  for (;;)
    {
      ptr = getusershell ();
      if (ptr == NULL)
        break;
      printf ("%s\n", ptr);
    }
  endusershell ();

  return 0;
}
#endif
