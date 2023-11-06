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

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "attributes.h"
#include "test-help.h"

static void test_struct_stat_defined (void);

int
main (void)
{
  /* Other. */
  printf ("S_IXOTH: %04o\n", (unsigned int) S_IXOTH);
  printf ("S_IWOTH: %04o\n", (unsigned int) S_IWOTH);
  printf ("S_IROTH: %04o\n", (unsigned int) S_IROTH);
  printf ("S_IRWXO: %04o\n", (unsigned int) S_IRWXO);

  /* Group. */
  printf ("S_IXGRP: %04o\n", (unsigned int) S_IXGRP);
  printf ("S_IWGRP: %04o\n", (unsigned int) S_IWGRP);
  printf ("S_IRGRP: %04o\n", (unsigned int) S_IRGRP);
  printf ("S_IRWXG: %04o\n", (unsigned int) S_IRWXG);

  /* User. */
  printf ("S_IXUSR: %04o\n", (unsigned int) S_IXUSR);
  printf ("S_IWUSR: %04o\n", (unsigned int) S_IWUSR);
  printf ("S_IRUSR: %04o\n", (unsigned int) S_IRUSR);
  printf ("S_IRWXU: %04o\n", (unsigned int) S_IRWXU);

  /* Other. */
  printf ("S_ISVTX: %04o\n", (unsigned int) S_ISVTX);
  printf ("S_ISGID: %04o\n", (unsigned int) S_ISGID);
  printf ("S_ISUID: %04o\n", (unsigned int) S_ISUID);

  test_struct_stat_defined ();

  return 0;
}

static void
test_struct_stat_defined (void)
{
  struct stat value ATTRIBUTE_UNUSED;
}
