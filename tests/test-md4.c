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

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "md4.h"
#include "test-help.h"

struct md4_testcase
{
  const char *message;
  const char *digest;
};

static const struct md4_testcase testcases[] = {
  { "", "\x31\xd6\xcf\xe0\xd1\x6a\xe9\x31\xb7\x3c\x59\xd7\xe0\xc0\x89\xc0" },
  { "a", "\xbd\xe5\x2c\xb3\x1d\xe3\x3e\x46\x24\x5e\x05\xfb\xdb\xd6\xfb\x24" },
  { "abc",
    "\xa4\x48\x01\x7a\xaf\x21\xd8\x52\x5f\xc1\x0a\xe8\x7a\xa6\x72\x9d" },
  { "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq",
    "\x46\x91\xa9\xec\x81\xb1\xa6\xbd\x1a\xb8\x55\x72\x40\xb2\x45\xc5" },
  { "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmn",
    "\xde\x7c\xfe\x90\x59\xc6\x12\xb3\xec\x3b\xeb\x7d\x60\x20\x68\xf0" },
  { "hijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu",
    "\x93\x2c\xf8\x72\x6f\x67\xec\x87\x9b\xf2\x5a\xe2\xd4\x4b\x06\x84" },
  { "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopj"
    "klmnopqklmnopqrlmnopqrsmnopqrstnopqrstu",
    "\x21\x02\xd1\xd9\x4b\xd5\x8e\xbf\x5a\xa2\x5c\x30\x5b\xb7\x83\xad" },
  { "01234567012345670123456701234567",
    "\x65\x05\x25\xfd\x92\x48\x13\x08\x91\xd3\xc0\x5b\xc2\x5b\xe3\xdc" },
  { "0123456701234567012345670123456701234567012345670123456701234567",
    "\x8e\x01\x59\xd4\x87\x58\xbc\xd8\x75\xe9\xa0\xbe\xf4\x2d\x3d\x92" },
};

static void do_md4_testcase (const struct md4_testcase *test);
static void do_md4_bigtest (void);

int
main (void)
{
  size_t i;

  for (i = 0; i < ARRAY_SIZE (testcases); ++i)
    do_md4_testcase (&testcases[i]);

  do_md4_bigtest ();
  return 0;
}

static void
do_md4_testcase (const struct md4_testcase *test)
{
  size_t i;
  struct md4_ctx ctx;
  uint8_t digest[MD4_DIGEST_SIZE];

  md4_init (&ctx);
  md4_update (&ctx, test->message, strlen (test->message));
  md4_final (digest, &ctx);

  for (i = 0; i < sizeof (digest); ++i)
    printf ("%02x", digest[i]);
  printf ("\n");

  ASSERT (memcmp (digest, test->digest, sizeof (digest)) == 0);
}

static void
do_md4_bigtest (void)
{
  size_t i;
  char *buffer;
  struct md4_ctx ctx;
  uint8_t digest[MD4_DIGEST_SIZE];
  const char *expect
      = "\xee\x1c\x30\xfb\xe1\x0f\xfb\x0c\xe9\xb8\x8c\x52\xda\x4f\xad\x9f";

  buffer = malloc (1000000000);
  if (buffer == NULL)
    {
      fprintf (stderr, "malloc (): Out of memory.\n");
      abort ();
    }

  for (i = 0; i < 1000000000; ++i)
    buffer[i] = i & 0xff;

  md4_init (&ctx);
  md4_update (&ctx, buffer, 1000000000);
  md4_final (digest, &ctx);

  for (i = 0; i < sizeof (digest); ++i)
    printf ("%02x", digest[i]);
  printf ("\n");

  free (buffer);

  ASSERT (memcmp (digest, expect, sizeof (digest)) == 0);
}
