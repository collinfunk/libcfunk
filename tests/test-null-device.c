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

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "null-device.h"
#include "test-help.h"

int
main (void)
{
  int fd;
  char buffer[2048];
  size_t i;

  fd = open (NULL_DEVICE, O_RDONLY);

  /* If the NULL_DEVICE macro is set correctly. All reads should return 0. */
  ASSERT (fd >= 0);
  ASSERT (read (fd, buffer, sizeof (buffer)) == 0);
  ASSERT (close (fd) == 0);

  /* Silence any warnings about uninitialized memory. */
  for (i = 0; i < sizeof (buffer); ++i)
    buffer[i] = (char) i;

  fd = open (NULL_DEVICE, O_WRONLY);

  /* If the NULL_DEVICE macro is set correctly, it should accept whatever we
     attempt to write to it. */
  ASSERT (fd >= 0);
  ASSERT ((size_t) write (fd, buffer, sizeof (buffer)) == sizeof (buffer));
  ASSERT (close (fd) == 0);

  return 0;
}
