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
sigabbrev_np (int signal_number)
{
  switch (signal_number)
    {
#if defined(SIGABRT)
    case SIGABRT:
      return "ABRT";
#endif
#if defined(SIGALRM)
    case SIGALRM:
      return "ALRM";
#endif
#if defined(SIGBUS)
    case SIGBUS:
      return "BUS";
#endif
#if defined(SIGCHLD)
    case SIGCHLD:
      return "CHLD";
#endif
#if defined(SIGCONT)
    case SIGCONT:
      return "CONT";
#endif
#if defined(SIGFPE)
    case SIGFPE:
      return "FPE";
#endif
#if defined(SIGHUP)
    case SIGHUP:
      return "HUP";
#endif
#if defined(SIGILL)
    case SIGILL:
      return "ILL";
#endif
#if defined(SIGINT)
    case SIGINT:
      return "INT";
#endif
#if defined(SIGKILL)
    case SIGKILL:
      return "KILL";
#endif
#if defined(SIGPIPE)
    case SIGPIPE:
      return "PIPE";
#endif
#if defined(SIGQUIT)
    case SIGQUIT:
      return "QUIT";
#endif
#if defined(SIGSEGV)
    case SIGSEGV:
      return "SEGV";
#endif
#if defined(SIGSTOP)
    case SIGSTOP:
      return "STOP";
#endif
#if defined(SIGTERM)
    case SIGTERM:
      return "TERM";
#endif
#if defined(SIGTSTP)
    case SIGTSTP:
      return "TSTP";
#endif
#if defined(SIGTTIN)
    case SIGTTIN:
      return "TTIN";
#endif
#if defined(SIGTTOU)
    case SIGTTOU:
      return "TTOU";
#endif
#if defined(SIGUSR1)
    case SIGUSR1:
      return "USR1";
#endif
#if defined(SIGUSR2)
    case SIGUSR2:
      return "USR2";
#endif
#if defined(SIGPOLL)
    case SIGPOLL:
      return "POLL";
#endif
#if defined(SIGPROF)
    case SIGPROF:
      return "PROF";
#endif
#if defined(SIGSYS)
    case SIGSYS:
      return "SYS";
#endif
#if defined(SIGTRAP)
    case SIGTRAP:
      return "TRAP";
#endif
#if defined(SIGURG)
    case SIGURG:
      return "URG";
#endif
#if defined(SIGVTALRM)
    case SIGVTALRM:
      return "VTALRM";
#endif
#if defined(SIGXCPU)
    case SIGXCPU:
      return "XCPU";
#endif
#if defined(SIGXFSZ)
    case SIGXFSZ:
      return "XFSZ";
#endif
    }
  return NULL;
}
