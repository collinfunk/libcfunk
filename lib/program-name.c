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

#ifdef _WIN32
#  include <windows.h>
#endif

#include <sys/types.h>

#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "program-name.h"

#ifndef PATH_MAX
#  define PATH_MAX 255
#endif

#ifndef LINE_MAX
#  define LINE_MAX 512
#endif

/* Could just extern this in the header but it seems like it might cause
   collisions. */
const char *program_name = NULL;

/* Default filename to return for systems where getprogname(3) and
   getexecname(3) have not been implemented. */
static const char default_program_name[8] = "unknown";

#if !HAVE_PROGRAM_INVOCATION_NAME && !HAVE_GETEXECNAME && !HAVE___ARGV        \
    && !HAVE__PROGNAME && !HAVE__GETPROGNAME
static int exec_name_initialized = 0;
static char exec_name[PATH_MAX];
#endif

#if !HAVE_PROGRAM_INVOCATION_SHORT_NAME && !HAVE_PROGRAM_INVOCATION_NAME      \
    && !HAVE___PROGNAME && !HAVE_GETPROGNAME && !HAVE_GETEXECNAME             \
    && !HAVE___ARGV
static int prog_name_initialized = 0;
static char prog_name[PATH_MAX];
#endif

/* BSD */
#if HAVE__PROGNAME
extern char *__progname;
#endif

/* glibc and musl */
#if HAVE_PROGRAM_INVOCATION_NAME
extern char *program_invocation_name;
#endif

/* glibc and musl */
#if HAVE_PROGRAM_INVOCATION_SHORT_NAME
extern char *program_invocation_short_name;
#endif

void
set_program_name (const char *file_name)
{
  const char *fixed_name = strrchr (file_name, '/');
  program_name = fixed_name != NULL ? fixed_name + 1 : file_name;
}

const char *
get_program_name (void)
{
  return program_name;
}

/* This function is based on the BSD function with the same name. */
#if !HAVE_GETPROGNAME
const char *
getprogname (void)
{
#  if HAVE_PROGRAM_INVOCATION_SHORT_NAME
  return (const char *) program_invocation_short_name;
#  elif __HAVE_PROGNAME
  return (const char *) __progname;
#  elif HAVE_GETEXECNAME
  const char *exec_name = getexecname ();
  if (exec_name != NULL)
    {
      const char *fixed_name = strrchr (exec_name, '/');
      return fixed_name != NULL ? fixed_name + 1 : exec_name;
    }
#  elif HAVE_PROGRAM_INVOCATION_NAME
  const char *fixed_name = strrchr (program_invocation_name, '/');
  return program_invocation_name != NULL ? fixed_name + 1
                                         : program_invocation_name;
#  elif HAVE___ARGV
  const char *fixed_name = strrchr (__argv[0], '/');
  fixed_name = fixed_name != NULL ? fixed_name + 1 : __argv[0];
  fixed_name = strrchr (__argv[0], '\\');
  fixed_name = fixed_name != NULL ? fixed_name + 1 : __argv[0];
  return fixed_name;
#  elif defined(_WIN32)
  /* https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamea */
  if (prog_name_initialized)
    return (const char *) prog_name;
  else
    {
      if (GetModuleFileName (NULL, prog_name, sizeof (prog_name)))
        {
          /* FIXME: \\ :/ */
          const char *fixed_name = strrchr (prog_name, '/');
          fixed_name = fixed_name != NULL ? fixed_name + 1 : prog_name;
          fixed_name = strrchr (prog_name, '\\');
          fixed_name = fixed_name != NULL ? fixed_name + 1 : prog_name;
          prog_name_initialized = 1;
          return (const char *) memmove (prog_name, fixed_name,
                                         strlen (fixed_name) + 1);
        }
    }
#  elif !defined(_WIN32) /* Check for procfs file before returning a
                            generic string. */
  pid_t current_pid = getpid ();
  int fd;
  char proc_file[PATH_MAX];
  char buffer[LINE_MAX];

  snprintf (proc_file, sizeof (proc_file), "/proc/%d/cmdline",
            (int) current_pid);
  fd = open (proc_file, O_RDONLY | O_CLOEXEC);

  if (prog_name_initialized)
    return prog_name;
  else
    {
      if (fd >= 0)
        {
          size_t total_read = 0;
          const char *p;

          while (total_read < sizeof (buffer))
            {
              ssize_t current_read = read (fd, buffer + total_read,
                                           sizeof (buffer) - total_read);
              if (current_read <= 0)
                break;
              total_read += current_read;
            }
          buffer[total_read] = '\0';
          p = strrchr (buffer, '/');
          p = p != NULL ? p + 1 : (const char *) buffer;

          memcpy (prog_name, p, strlen (p) + 1);
          close (fd);
          prog_name_initialized = 1;
          return prog_name;
        }
    }
#  endif
  return default_program_name;
}
#endif

/* This function is based on the Solaris function with the same name. */
#if !HAVE_GETEXECNAME
const char *
getexecname (void)
{
#  if HAVE_PROGRAM_INVOCATION_NAME
  return (const char *) program_invocation_name;
#  elif HAVE___ARGV
  return (const char *) __argv[0];
#  elif defined(_WIN32)
  /* https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamea */
  if (exec_name_initialized)
    return (const char *) exec_name;
  else
    {
      if (GetModuleFileName (NULL, exec_name, sizeof (exec_name)))
        {
          exec_name_initialized = 1;
          return (const char *) exec_name;
        }
    }
#  elif HAVE_PROGRAM_INVOCATION_SHORT_NAME
  return (const char *) program_invocation_short_name;
#  elif __HAVE_PROGNAME
  return (const char *) __progname;
#  elif !defined(_WIN32) /* Check for procfs file before returning a
                            generic string. */

  pid_t current_pid = getpid ();
  int fd;
  char proc_file[PATH_MAX];
  char buffer[LINE_MAX];

  if (exec_name_initialized)
    return (const char *) exec_name;
  else
    {
      snprintf (proc_file, sizeof (proc_file), "/proc/%d/cmdline",
                (int) current_pid);
      fd = open (proc_file, O_RDONLY | O_CLOEXEC);
      if (fd >= 0)
        {
          size_t total_read = 0;

          while (total_read < sizeof (buffer))
            {
              ssize_t current_read = read (fd, buffer + total_read,
                                           sizeof (buffer) - total_read);
              if (current_read <= 0)
                break;
              total_read += current_read;
            }

          buffer[total_read] = '\0';

          memcpy (exec_name, buffer, strlen (buffer) + 1);
          close (fd);
          exec_name_initialized = 1;
          return exec_name;
        }
    }
#  endif
  /* TODO: Return program_name here? */
  return default_program_name;
}
#endif

#if 0
int
main (int argc, char **argv)
{
  /* Silence warnings :) */
  if (argc == 0)
    return 1;
  set_program_name (argv[0]);
  printf ("program_name: %s\n", program_name);
  printf ("getprogname (): %s\n", getprogname ());
  printf ("getexecname (): %s\n", getexecname ());
  return 0;
}
#endif
