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

#include <signal.h>
#include <stddef.h>
#include <string.h>

/* This function may return NULL on OS-specific signals. */
const char *
sigdescr_np (int signal_number)
{
  switch (signal_number)
    {
#if defined(SIGABRT)
    case SIGABRT:
      return "Aborted";
#endif
#if defined(SIGALRM)
    case SIGALRM:
      return "Alarm clock";
#endif
#if defined(SIGBUS)
    case SIGBUS:
      return "Bus error";
#endif
#if defined(SIGCHLD)
    case SIGCHLD:
      return "Child exited";
#endif
#if defined(SIGCONT)
    case SIGCONT:
      return "Continued";
#endif
#if defined(SIGFPE)
    case SIGFPE:
      return "Floating point exception";
#endif
#if defined(SIGHUP)
    case SIGHUP:
      return "Hangup";
#endif
#if defined(SIGILL)
    case SIGILL:
      return "Illegal instruction";
#endif
#if defined(SIGINT)
    case SIGINT:
      return "Interrupt";
#endif
#if defined(SIGKILL)
    case SIGKILL:
      return "Killed";
#endif
#if defined(SIGPIPE)
    case SIGPIPE:
      return "Broken pipe";
#endif
#if defined(SIGQUIT)
    case SIGQUIT:
      return "Quit";
#endif
#if defined(SIGSEGV)
    case SIGSEGV:
      return "Segmentation fault";
#endif
#if defined(SIGSTOP)
    case SIGSTOP:
      return "Stopped (signal)";
#endif
#if defined(SIGTERM)
    case SIGTERM:
      return "Terminated";
#endif
#if defined(SIGTSTP)
    case SIGTSTP:
      return "Stopped";
#endif
#if defined(SIGTTIN)
    case SIGTTIN:
      return "Stopped (tty input)";
#endif
#if defined(SIGTTOU)
    case SIGTTOU:
      return "Stopped (tty output)";
#endif
#if defined(SIGUSR1)
    case SIGUSR1:
      return "User defined signal 1";
#endif
#if defined(SIGUSR2)
    case SIGUSR2:
      return "User defined signal 2";
#endif
#if defined(SIGPOLL)
    case SIGPOLL:
      return "I/O possible";
#endif
#if defined(SIGPROF)
    case SIGPROF:
      return "Profiling timer expired";
#endif
#if defined(SIGSYS)
    case SIGSYS:
      return "Bad system call";
#endif
#if defined(SIGTRAP)
    case SIGTRAP:
      return "Trace/breakpoint trap";
#endif
#if defined(SIGURG)
    case SIGURG:
      return "Urgent I/O condition";
#endif
#if defined(SIGVTALRM)
    case SIGVTALRM:
      return "Virtual timer expired";
#endif
#if defined(SIGXCPU)
    case SIGXCPU:
      return "CPU time limit exceeded";
#endif
#if defined(SIGXFSZ)
    case SIGXFSZ:
      return "File size limit exceeded";
#endif
    }
  return NULL;
}
