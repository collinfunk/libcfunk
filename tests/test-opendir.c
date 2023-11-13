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

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

static void test_opendir_not_exists (void);
static void test_opendir_current_dir (void);

int
main (void)
{
  test_opendir_not_exists ();
  test_opendir_current_dir ();
  return 0;
}

/* Test that calling 'opendir' on a directory doesn't exit results in a NULL
   pointer being returned. */
static void
test_opendir_not_exists (void)
{
  const char *dir_doesnt_exist = "this_directory_shouldnt_exist";
  DIR *dirp;

  dirp = opendir (dir_doesnt_exist);
  ASSERT (dirp == NULL);
}

/* Test that calling 'opendir' on the current directory doesn't return a NULL
   pointer. Make sure to call 'closedir' to make sanitizers and leak checks
   happy. */
static void
test_opendir_current_dir (void)
{
  const char *current_dir = ".";
  DIR *dirp;

  dirp = opendir (current_dir);
  ASSERT (dirp != NULL);

  ASSERT (closedir (dirp) == 0);
}
