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
#include <sys/types.h>

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "binary-mode.h"
#include "test-help.h"

static const char message[] = "Message\n";
static size_t message_len = sizeof (message) - 1;

int
main (void)
{
  int fd1, fd2;
  struct stat st1, st2;
  FILE *fp1;
  FILE *fp2;
  int sane_newlines;

  /* Test opening a file in binary mode. */
  fd1 = open ("test-open-binary.tmp",
              O_CLOEXEC | O_RDWR | O_CREAT | O_TRUNC | O_BINARY, 0600);
  ASSERT (fd1 >= 0);
  ASSERT (write (fd1, message, message_len) == (ssize_t) message_len);
  ASSERT (close (fd1) == 0);

  /* Test opening a file in text mode. */
  fd2 = open ("test-open-text.tmp",
              O_CLOEXEC | O_RDWR | O_CREAT | O_TRUNC | O_TEXT, 0600);
  ASSERT (fd2 >= 0);
  ASSERT (write (fd2, message, message_len) == (ssize_t) message_len);
  ASSERT (close (fd2) == 0);

  ASSERT (stat ("test-open-binary.tmp", &st1) == 0);
  ASSERT (stat ("test-open-text.tmp", &st2) == 0);

  /* We don't actually read the file to check CRLF vs LF. Since O_TEXT and
     O_BINARY effect the data we read, just check the size from stat ().
     On systems where the distinction between the modes matter, the resulting
     file size shouldn't be equal. */
  sane_newlines = st1.st_size == st2.st_size;

  /* Test fset_binary_mode. */
  fp1 = fopen ("test-fwrite-binary.tmp", "w");
  ASSERT (fp1 != NULL);
  ASSERT (fset_binary_mode (fp1) != -1);
  ASSERT (fwrite (message, message_len, 1, fp1) == 1);
  ASSERT (fclose (fp1) == 0);

  /* Test fset_text_mode. */
  fp2 = fopen ("test-fwrite-text.tmp", "w");
  ASSERT (fp2 != NULL);
  ASSERT (fset_text_mode (fp2) != -1);
  ASSERT (fwrite (message, message_len, 1, fp2) == 1);
  ASSERT (fclose (fp2) == 0);

  ASSERT (stat ("test-fwrite-binary.tmp", &st1) == 0);
  ASSERT (stat ("test-fwrite-text.tmp", &st2) == 0);

  if (sane_newlines)
    ASSERT (st1.st_size == st2.st_size);
  else
    ASSERT (st1.st_size != st2.st_size);

  /* Test set_binary_mode. Use O_TEXT to open so the mode actually changes. */
  fd1 = open ("test-write-binary.tmp",
              O_CLOEXEC | O_RDWR | O_CREAT | O_TRUNC | O_TEXT, 0600);
  ASSERT (fd1 >= 0);
  ASSERT (set_binary_mode (fd1) != -1);
  ASSERT (write (fd1, message, message_len) == (ssize_t) message_len);
  ASSERT (close (fd1) == 0);

  /* Test set_text_mode. Use O_BINARY to open so the mode actually changes. */
  fd2 = open ("test-write-text.tmp",
              O_CLOEXEC | O_RDWR | O_CREAT | O_TRUNC | O_BINARY, 0600);
  ASSERT (fd2 >= 0);
  ASSERT (set_text_mode (fd1) != -1);
  ASSERT (write (fd2, message, message_len) == (ssize_t) message_len);
  ASSERT (close (fd2) == 0);

  ASSERT (stat ("test-write-binary.tmp", &st1) == 0);
  ASSERT (stat ("test-write-text.tmp", &st2) == 0);

  if (sane_newlines)
    ASSERT (st1.st_size == st2.st_size);
  else
    ASSERT (st1.st_size != st2.st_size);

  return 0;
}
