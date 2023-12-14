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

#include <pty.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include "test-help.h"

static void test_openpty (void);

int
main (void)
{
  test_openpty ();
  return 0;
}

static void
test_openpty (void)
{
  int master;
  int slave;
  int result;
  struct termios attr;

  /* Open a pseudo-terminal pair. */
  result = openpty (&master, &slave, NULL, NULL, NULL);
  if (result == -1)
    {
      fprintf (stderr, "openpty () failed.\n");
      exit (1);
    }

  /* Get the terminal attributes. */
  if (tcgetattr (slave, &attr) == -1)
    {
      fprintf (stderr, "tcgetattr () failed.\n");
      exit (1);
    }

  /* Turn on echo and canonical input. */
  attr.c_lflag |= ECHO | ECHOE | ICANON;
  attr.c_cc[VERASE] = '\b';

  /* Set the terminal attributes. */
  if (tcsetattr (slave, TCSANOW, &attr) == -1)
    {
      fprintf (stderr, "tcsetattr () failed.\n");
      exit (1);
    }

  {
    const char message[] = "Test string\b\b\b\b\b\bmessage\n";
    const char expect[] = "Test message\n";
    char buffer[64];

    /* Write the string to the master file descriptor */
    result = (int) write (master, message, sizeof (message) - 1);
    if (result != (int) (sizeof (message) - 1))
      {
        fprintf (stderr, "write () failed.\n");
        exit (1);
      }

    /* Read from the slave file descriptor. */
    result = (int) read (slave, buffer, sizeof (buffer));
    if (result != (int) (sizeof (expect) - 1))
      {
        fprintf (stderr, "read () failed.\n");
        exit (1);
      }

    /* Check the string that was read. */
    if (memcmp (buffer, expect, sizeof (expect) - 1) != 0)
      {
        fprintf (stderr, "Read incorrect string.\n");
        exit (1);
      }
  }

  (void) close (master);
  (void) close (slave);
}
