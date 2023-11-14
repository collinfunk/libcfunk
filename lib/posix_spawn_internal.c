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

#include <sys/types.h>

#include <errno.h>
#include <sched.h>
#include <signal.h>
#include <spawn.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "posix_spawn_internal.h"

int
posix_spawn_internal (pid_t *pid, const char *file,
                      const posix_spawn_file_actions_t *file_actions,
                      const posix_spawnattr_t *attrp, char *const argv[],
                      char *const envp[], int use_env_path)
{
  int child_pid;
  short int attr_flags;

  /* Be nice and return an error while this is not implemented. */
  if (file_actions != NULL)
    return ENOSYS;

  /* Create a new process. */
  child_pid = fork ();
  switch (child_pid)
    {
    case -1: /* Error. */
      return errno;
    case 0: /* Child. */
      break;
    default: /* Parent. */
      /* Store the child's process id in PID. */
      if (pid != NULL)
        *pid = child_pid;
      return 0;
    }

  /* Check if we have attribute flags. */
  if (attrp != NULL)
    attr_flags = attrp->flags;
  else
    attr_flags = 0;

  /* Set the process group. */
  if (attr_flags & POSIX_SPAWN_SETPGROUP)
    {
      if (setpgid (0, attrp->pgroup) != 0)
        _Exit (127);
    }
  if ((attr_flags & (POSIX_SPAWN_SETSCHEDPARAM | POSIX_SPAWN_SETSCHEDULER))
      == POSIX_SPAWN_SETSCHEDPARAM)
    {
      /* Set the scheduling parameters. */
      if (sched_setparam (0, &attrp->schedparam) != 0)
        _Exit (127);
    }
  else if (attr_flags & POSIX_SPAWN_SETSCHEDULER)
    {
      /* Set the scheduling policy. */
      if (attr_flags & POSIX_SPAWN_SETSCHEDPARAM)
        {
          if (sched_setscheduler (0, attrp->schedpolicy, &attrp->schedparam)
              != 0)
            _Exit (127);
        }
      else
        {
          if (sched_setscheduler (0, attrp->schedpolicy, NULL) != 0)
            _Exit (127);
        }
    }
  /* Reset the effective user and group IDs. */
  if (attr_flags & POSIX_SPAWN_RESETIDS)
    {
      if (seteuid (getuid ()) != 0 || setegid (getgid ()) != 0)
        _Exit (127);
    }
  /* Set the signal mask of the process. */
  if (attr_flags & POSIX_SPAWN_SETSIGMASK)
    {
      if (sigprocmask (SIG_SETMASK, &attrp->sigmask, NULL) != 0)
        _Exit (127);
    }
  /* Set the signals defined in the given set to their default actions. */
  if (attr_flags & POSIX_SPAWN_SETSIGDEF)
    {
      int i;
      struct sigaction sa;

      memset (&sa, '\0', sizeof (struct sigaction));
      sa.sa_handler = SIG_DFL;
      for (i = 0; i <= NSIG; ++i)
        {
          if (sigismember (&attrp->sigdefault, i))
            {
              if (sigaction (i, &sa, NULL) != 0)
                _Exit (127);
            }
        }
    }

  /* TODO: File actions... */

  if (!use_env_path)
    execve (file, (char *const *) argv, (char *const *) envp);
  else
    execvpe (file, (char *const *) argv, (char *const *) envp);

  _Exit (127);
}
