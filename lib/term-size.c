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

#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#if HAVE_SYS_IOCTL_H
#  include <sys/ioctl.h>
#endif

#if HAVE_TERMIOS_H
#  include <termios.h>
#endif

#include "term-size.h"

/* https://learn.microsoft.com/en-us/windows/console/getconsolescreenbufferinfo */
/* https://learn.microsoft.com/en-us/windows/console/console-screen-buffer-info-str */
#ifdef _WIN32
int
term_get_height (void)
{
  HANDLE console_output;
  CONSOLE_SCREEN_BUFFER_INFO buffer_info;

  console_output = GetStdHandle (STD_OUTPUT_HANDLE);
  if (console_output == INVALID_HANDLE_VALUE)
    return -1;
  else
    {
      if (GetConsoleScreenBufferInfo (console_output, &buffer_info))
        return (int) buffer_info.dwSize.Y;
      else
        return -1;
    }
}

int
term_get_width (void)
{
  HANDLE console_output;
  CONSOLE_SCREEN_BUFFER_INFO buffer_info;

  console_output = GetStdHandle (STD_OUTPUT_HANDLE);
  if (console_output == INVALID_HANDLE_VALUE)
    return -1;
  else
    {
      if (GetConsoleScreenBufferInfo (console_output, &buffer_info))
        return (int) buffer_info.dwSize.X;
      else
        return -1;
    }
}

int
term_get_size (int *height, int *width)
{
  HANDLE console_output;
  CONSOLE_SCREEN_BUFFER_INFO buffer_info;

  console_output = GetStdHandle (STD_OUTPUT_HANDLE);
  if (console_output == INVALID_HANDLE_VALUE)
    return -1;
  else
    {
      if (!GetConsoleScreenBufferInfo (console_output, &buffer_info))
        return -1;
      else
        {
          if (height != NULL)
            *height = (int) buffer_info.dwSize.Y;
          if (width != NULL)
            *width = (int) buffer_info.dwSize.X;
        }
    }
  return 0;
}
#else
int
term_get_height (void)
{
  for (;;)
    {
      struct winsize sz;
      int result = ioctl (STDIN_FILENO, TIOCGWINSZ, &sz);

      if (result < 0)
        {
          if (errno == EINTR)
            continue;
          else
            return -1;
        }
      return (int) sz.ws_row;
    }
}

int
term_get_width (void)
{
  for (;;)
    {
      struct winsize sz;
      int result = ioctl (STDIN_FILENO, TIOCGWINSZ, &sz);

      if (result < 0)
        {
          if (errno == EINTR)
            continue;
          else
            return -1;
        }
      return (int) sz.ws_col;
    }
}

int
term_get_size (int *height, int *width)
{
  for (;;)
    {
      struct winsize sz;
      int result = ioctl (STDIN_FILENO, TIOCGWINSZ, &sz);

      if (result < 0)
        {
          if (errno == EINTR)
            continue;
          else
            return -1;
        }

      if (height != NULL)
        *height = (int) sz.ws_row;
      if (width != NULL)
        *width = (int) sz.ws_col;
      return 0;
    }
}
#endif
