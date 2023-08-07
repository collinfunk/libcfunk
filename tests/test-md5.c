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

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"
#include "test-help.h"

struct md5_testcase
{
  const char *message;
  const char *digest;
};

static const struct md5_testcase testcases[] = {
  { "", "\xd4\x1d\x8c\xd9\x8f\x00\xb2\x04\xe9\x80\x09\x98\xec\xf8\x42\x7e" },
  { "a", "\x0c\xc1\x75\xb9\xc0\xf1\xb6\xa8\x31\xc3\x99\xe2\x69\x77\x26\x61" },
  { "abc",
    "\x90\x01\x50\x98\x3c\xd2\x4f\xb0\xd6\x96\x3f\x7d\x28\xe1\x7f\x72" },
  { "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq",
    "\x82\x15\xef\x07\x96\xa2\x0b\xca\xaa\xe1\x16\xd3\x87\x6c\x66\x4a" },
  { "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmn",
    "\x2a\x74\x5e\x5e\x84\x2e\x56\x4a\x44\x3a\x71\x71\x11\x99\x1c\x3a" },
  { "hijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu",
    "\x02\x38\x14\xa2\x6d\xe8\xa3\xdc\xe5\xed\x4a\x01\xbe\xbc\x37\xde" },
  { "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopj"
    "klmnopqklmnopqrlmnopqrsmnopqrstnopqrstu",
    "\x03\xdd\x88\x07\xa9\x31\x75\xfb\x06\x2d\xfb\x55\xdc\x7d\x35\x9c" },
  { "01234567012345670123456701234567",
    "\x04\x79\x4f\xed\xa8\x4b\x1c\x14\xf1\x55\x91\x87\x91\x10\xb2\xe1" },
  { "0123456701234567012345670123456701234567012345670123456701234567",
    "\x52\x06\x20\xde\x89\xe2\x20\xf9\xb5\x85\x0c\xc9\x7c\xbf\xf4\x6c" }
};

static void do_md5_testcase (const struct md5_testcase *test);
static void do_md5_bigtest (void);

int
main (void)
{
  size_t i;

  for (i = 0; i < ARRAY_SIZE (testcases); ++i)
    do_md5_testcase (&testcases[i]);

  do_md5_bigtest ();
  return 0;
}

static void
do_md5_testcase (const struct md5_testcase *test)
{
  size_t i;
  struct md5_ctx ctx;
  uint8_t digest[MD5_DIGEST_SIZE];

  md5_init (&ctx);
  md5_update (&ctx, test->message, strlen (test->message));
  md5_final (digest, &ctx);

  for (i = 0; i < sizeof (digest); ++i)
    printf ("%02x", digest[i]);
  printf ("\n");

  ASSERT (memcmp (digest, test->digest, sizeof (digest)) == 0);
}

static void
do_md5_bigtest (void)
{
  size_t i;
  char *buffer;
  struct md5_ctx ctx;
  uint8_t digest[MD5_DIGEST_SIZE];
  const char *expect
      = "\x66\xb6\x4e\xd9\x83\x71\xd3\x0f\x6a\x48\xc0\xa9\xb0\xb8\xb6\xcd";

  buffer = malloc (1000000000);
  if (buffer == NULL)
    {
      fprintf (stderr, "malloc (): Out of memory.\n");
      abort ();
    }

  for (i = 0; i < 1000000000; ++i)
    buffer[i] = i & 0xff;

  md5_init (&ctx);
  md5_update (&ctx, buffer, 1000000000);
  md5_final (digest, &ctx);

  for (i = 0; i < sizeof (digest); ++i)
    printf ("%02x", digest[i]);
  printf ("\n");

  free (buffer);

  ASSERT (memcmp (digest, expect, sizeof (digest)) == 0);
}
