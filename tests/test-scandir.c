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

#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "test-help.h"

#undef TEST_DIRECTORY_NAME
#define TEST_DIRECTORY_NAME "test-scandir.tmp"

/* File names sorted alphabetically. */
static const char *const file_names[]
    = { TEST_DIRECTORY_NAME "/test-scandir1.tmp",
        TEST_DIRECTORY_NAME "/test-scandir2.tmp",
        TEST_DIRECTORY_NAME "/test-scandir3.tmp",
        TEST_DIRECTORY_NAME "/test-scandir4.tmp",
        TEST_DIRECTORY_NAME "/test-scandir5.tmp" };

static int ignore_dot_directories (const struct dirent *ptr);
static void test_scandir (void);

int
main (void)
{
  size_t i;

  /* Make sure all files and directories are removed. */
  for (i = 0; i < ARRAY_SIZE (file_names); ++i)
    (void) remove (file_names[i]);
  (void) remove (TEST_DIRECTORY_NAME);

  test_scandir ();

  /* Make sure all files and directories are removed. */
  for (i = 0; i < ARRAY_SIZE (file_names); ++i)
    (void) remove (file_names[i]);
  (void) remove (TEST_DIRECTORY_NAME);

  return 0;
}

/* Ignore the "." and ".." directory entries. */
static int
ignore_dot_directories (const struct dirent *ptr)
{
  if (ptr->d_name[0] != '.')
    return 1;
  else
    {
      if (ptr->d_name[1] == '\0')
        return 0;
      else if (ptr->d_name[1] == '.' && ptr->d_name[2] == '\0')
        return 0;
      else
        return 1;
    }
}

/* Perform a basic test on the 'scandir' function. */
static void
test_scandir (void)
{
  struct dirent **name_list;
  int result;
  size_t i;

  /* Create a directory and some files. */
  ASSERT (mkdir (TEST_DIRECTORY_NAME, 0700) == 0);
  for (i = 0; i < ARRAY_SIZE (file_names); ++i)
    {
      int fd = creat (file_names[i], 0600);
      ASSERT (fd >= 0);
      ASSERT (close (fd) == 0);
    }

  /* Get the file names from the directory. */
  result = scandir (TEST_DIRECTORY_NAME, &name_list, ignore_dot_directories,
                    alphasort);
  ASSERT (result >= 0);
  ASSERT ((size_t) result == ARRAY_SIZE (file_names));

  /* Check the resulting array. */
  for (i = 0; i < (size_t) result; ++i)
    {
      ASSERT (strcmp (name_list[i]->d_name, file_names[i] + 17) == 0);
      free (name_list[i]);
    }
  free (name_list);

  /* Cleanup the file system. */
  for (i = 0; i < ARRAY_SIZE (file_names); ++i)
    ASSERT (remove (file_names[i]) == 0);
  ASSERT (remove (TEST_DIRECTORY_NAME) == 0);
}
