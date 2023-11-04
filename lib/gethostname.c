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

#include <limits.h>
#include <string.h>
#include <unistd.h>

#if HAVE_SYS_UTSNAME_H
#  include <sys/utsname.h>
#endif

#if LIBCFUNK_REPLACE_GETHOSTNAME

int
gethostname (char *name, size_t name_len)
  #undef gethostname
{
  /* Windows uses int and not size_t. */
  if (name_len > INT_MAX)
    {
      errno = EINVAL;
      return -1;
    }

  return gethostname (name, (int) name_len);
}

#elif HAVE_UNAME

int
gethostname (char *name, size_t name_len)
{
  struct utsname buffer;

  if (name_len < 0 || uname (&buffer) < 0)
    return -1;

  if (name_len > sizeof (buffer.nodename))
    strcpy (name, buffer.nodename);
  else
    {
      size_t nodename_len = strlen (buffer.nodename);
      if (nodename_len + 1 <= name_len)
        memcpy (name, buffer.nodename, nodename_len + 1);
      else
        {
          memcpy (name, buffer.nodename, name_len);
          name[name_len - 1] = '\0';
          return -1;
        }
    }

  return 0;
}

#else /* Unlucky */

int
gethostname (char *name, size_t name_len)
{
  if (name != NULL)
    *name = '\0';
  errno = ENOSYS;
  return -1;
}

#endif
