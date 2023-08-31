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

#include "filename.h"
#include "program-name.h"

#ifndef PATH_MAX
#  define PATH_MAX 255
#endif

#ifndef LINE_MAX
#  define LINE_MAX 512
#endif

/* Could just extern this in the header but it seems like it might cause
   collisions. */
static const char *program_name = NULL;

/* Default filename to return for systems where getprogname(3) and
   getexecname(3) have not been implemented. */
static const char default_program_name[8] = "unknown";

/* Some implementations of getprogname and getexecname use pointers to
   allocated memory. Since the real implementation's of these functions are
   not malloc'ed, free(3) will not be called on these pointers. Since the
   allocations are done once and they are only the size of a filename, it
   shouldn't be a big deal.
 */
#if !HAVE_PROGRAM_INVOCATION_NAME && !HAVE_PROGRAM_INVOCATION_SHORT_NAME      \
    && !HAVE_GET_GETEXECNAME && !HAVE__PROGNAME && !HAVE___ARGV
static int exec_name_initialized = 0;
static char *exec_name = NULL;
#endif

#if !HAVE_PROGRAM_INVOCATION_NAME && !HAVE_PROGRAM_INVOCATION_SHORT_NAME      \
    && !HAVE_GET_GETEXECNAME && !HAVE__PROGNAME && !HAVE___ARGV
static int prog_name_initialized = 0;
static char *prog_name = NULL;
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
  program_name = filename_last_component (file_name);
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
  const char *gexec_name = getexecname ();
  if (gexec_name != NULL)
    return filename_last_component (gexec_name);
#  elif HAVE_PROGRAM_INVOCATION_NAME
  return filename_last_component (program_invocation_name);
#  elif HAVE___ARGV
  /* TODO: malloc and strip the .exe extension? */
  return filename_last_component (__argv[0]);
#  elif defined(_WIN32)
  char buffer[PATH_MAX];
  /* https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamea */
  if (prog_name_initialized)
    return (const char *) prog_name;
  else
    {
      if (GetModuleFileName (NULL, buffer, sizeof (buffer)))
        {
          char *last = (char *) filename_last_component (buffer);
          size_t last_len;
          filename_strip_extension (last);
          last_len = strlen (last);
          prog_name = (char *) malloc (last_len + 1);
          if (prog_name != NULL)
            {
              prog_name_initialized = 1;
              return (const char *) memcpy (prog_name, last, last_len + 1);
            }
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
          size_t len;
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

          p = filename_last_component (buffer);
          len = strlen (p);

          prog_name = (char *) malloc (len + 1);
          if (prog_name != NULL)
            {
              memcpy (prog_name, p, len + 1);
              close (fd);
              prog_name_initialized = 1;
              return prog_name;
            }
          else
            close (fd);
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
  char buffer[PATH_MAX];
  /* https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamea */
  if (exec_name_initialized)
    return (const char *) exec_name;
  else
    {
      if (GetModuleFileName (NULL, buffer, sizeof (buffer)))
        {
          size_t exec_name_len = strlen (buffer);
          exec_name = (char *) malloc (exec_name_len + 1);
          if (exec_name != NULL)
            {
              exec_name_initialized = 1;
              return (const char *) memcpy (exec_name, buffer,
                                            exec_name_len + 1);
            }
        }
    }
#  elif 0 && HAVE_PROGRAM_INVOCATION_SHORT_NAME
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
          size_t len;

          while (total_read < sizeof (buffer))
            {
              ssize_t current_read = read (fd, buffer + total_read,
                                           sizeof (buffer) - total_read);
              if (current_read <= 0)
                break;
              total_read += current_read;
            }

          buffer[total_read] = '\0';
          len = strlen (buffer);

          exec_name = (char *) malloc (len + 1);
          if (exec_name != NULL)
            {
              memcpy (exec_name, buffer, len + 1);
              close (fd);
              exec_name_initialized = 1;
              return exec_name;
            }
          else
            close (fd);
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
