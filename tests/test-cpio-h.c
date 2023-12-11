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

#include <cpio.h>

static_assert (C_IRUSR == 0000400);
static_assert (C_IWUSR == 0000200);
static_assert (C_IXUSR == 0000100);
static_assert (C_IRGRP == 0000040);
static_assert (C_IWGRP == 0000020);
static_assert (C_IXGRP == 0000010);
static_assert (C_IROTH == 0000004);
static_assert (C_IWOTH == 0000002);
static_assert (C_IXOTH == 0000001);
static_assert (C_ISUID == 0004000);
static_assert (C_ISGID == 0002000);
static_assert (C_ISVTX == 0001000);
static_assert (C_ISDIR == 0040000);
static_assert (C_ISFIFO == 0010000);
static_assert (C_ISREG == 0100000);
static_assert (C_ISBLK == 0060000);
static_assert (C_ISCHR == 0020000);
static_assert (C_ISCTG == 0110000);
static_assert (C_ISLNK == 0120000);
static_assert (C_ISSOCK == 0140000);

int
main (void)
{
  char magic[] = MAGIC;

  if ((magic[0] != '0') || (magic[1] != '7') || (magic[2] != '0')
      || (magic[3] != '7') || (magic[4] != '0') || (magic[5] != '7')
      || (magic[6] != '\0'))
    return 0;

  return 0;
}
