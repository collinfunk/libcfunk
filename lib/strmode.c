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

#include <sys/stat.h>
#include <sys/types.h>

#include <string.h>

/* Directory restricted deletion flag. Not required by POSIX. */
#ifndef S_ISVTX
#  define S_ISVTX 01000
#endif

/* Macro to check for whiteout files. Defined on 4.4BSD and its descendants.
   Not defined by glibc. */
#ifndef S_ISWHT
#  define S_ISWHT(mode) 0
#endif

#ifndef S_ISLNK
#  define S_ISLNK(mode) 0
#endif

#ifndef S_ISSOCK
#  define S_ISSOCK(mode) 0
#endif

#ifndef S_ISUID
#  define S_ISUID 0
#endif

#ifndef S_ISGID
#  define S_ISGID 0
#endif

/* strmode(3) function based on 4.4BSD.
   Converts a file mode into a symbolic string.
   STR should be atleast 12 characters and the resulting string will always end
   with a space followed by a NUL byte. */
void
strmode (mode_t mode, char *str)
{
  if (S_ISREG (mode))
    str[0] = '-';
  else if (S_ISBLK (mode))
    str[0] = 'b';
  else if (S_ISCHR (mode))
    str[0] = 'c';
  else if (S_ISDIR (mode))
    str[0] = 'd';
  else if (S_ISLNK (mode))
    str[0] = 'l';
  else if (S_ISFIFO (mode))
    str[0] = 'p';
  else if (S_ISSOCK (mode))
    str[0] = 's';
  else if (S_ISWHT (mode))
    str[0] = 'w';
  else
    str[0] = '?';

  /* Owner permissions. */
  str[1] = (mode & S_IRUSR) ? 'r' : '-';
  str[2] = (mode & S_IWUSR) ? 'w' : '-';
  if (mode & S_ISUID)
    str[3] = (mode & S_IXUSR) ? 's' : 'S';
  else
    str[3] = (mode & S_IXUSR) ? 'x' : '-';

  /* Group permissions. */
  str[4] = (mode & S_IRGRP) ? 'r' : '-';
  str[5] = (mode & S_IWGRP) ? 'w' : '-';
  if (mode & S_ISGID)
    str[6] = (mode & S_IXGRP) ? 's' : 'S';
  else
    str[6] = (mode & S_IXGRP) ? 'x' : '-';

  /* Others permissions. */
  str[7] = (mode & S_IROTH) ? 'r' : '-';
  str[8] = (mode & S_IWOTH) ? 'w' : '-';
  if (mode & S_ISVTX)
    str[9] = (mode & S_IXOTH) ? 't' : 'T';
  else
    str[9] = (mode & S_IXOTH) ? 'x' : '-';

  str[10] = ' ';
  str[11] = '\0';
}
