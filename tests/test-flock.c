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

#include <sys/file.h>

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "test-help.h"

#undef TEST_FILE_NAME

#define TEST_FILE_NAME "test-flock.tmp"

static void test_shared_lock (void);
static void test_exclusive_lock (void);

int
main (void)
{
  test_shared_lock ();
  test_exclusive_lock ();
  remove (TEST_FILE_NAME);
  return 0;
}

static void
test_shared_lock (void)
{
  int fd1, fd2;

  fd1 = open (TEST_FILE_NAME, O_RDWR | O_CREAT | O_TRUNC, 0600);
  ASSERT (fd1 >= 0);
  ASSERT (flock (fd1, LOCK_SH) == 0);

  fd2 = open (TEST_FILE_NAME, O_RDWR | O_CREAT | O_TRUNC, 0600);
  ASSERT (fd2 >= 0);
  ASSERT (flock (fd2, LOCK_SH | LOCK_NB) == 0);

  ASSERT (flock (fd1, LOCK_UN) == 0);
  ASSERT (flock (fd2, LOCK_UN) == 0);
  ASSERT (close (fd1) == 0);
  ASSERT (close (fd2) == 0);
}

static void
test_exclusive_lock (void)
{
  int fd1, fd2;

  fd1 = open (TEST_FILE_NAME, O_RDWR | O_CREAT | O_TRUNC, 0600);
  ASSERT (fd1 >= 0);
  ASSERT (flock (fd1, LOCK_EX) == 0);

  fd2 = open (TEST_FILE_NAME, O_RDWR | O_CREAT | O_TRUNC, 0600);
  ASSERT (fd2 >= 0);
  ASSERT (flock (fd2, LOCK_EX | LOCK_UN) == -1);

  ASSERT (flock (fd1, LOCK_UN) == 0);
  ASSERT (close (fd1) == 0);
  ASSERT (close (fd2) == 0);
}
