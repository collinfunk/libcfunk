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

#include "sha256.h"
#include "test-help.h"

struct sha224_testcase
{
  const char *message;
  const char *digest;
};

static const struct sha224_testcase testcases[] = {
  { "", "\xd1\x4a\x02\x8c\x2a\x3a\x2b\xc9\x47\x61\x02\xbb\x28\x82\x34\xc4\x15"
        "\xa2\xb0\x1f\x82\x8e\xa6\x2a\xc5\xb3\xe4\x2f" },
  { "a", "\xab\xd3\x75\x34\xc7\xd9\xa2\xef\xb9\x46\x5d\xe9\x31\xcd\x70\x55\xff"
         "\xdb\x88\x79\x56\x3a\xe9\x80\x78\xd6\xd6\xd5" },
  { "abc", "\x23\x09\x7d\x22\x34\x05\xd8\x22\x86\x42\xa4\x77\xbd\xa2\x55\xb3"
           "\x2a\xad\xbc\xe4\xbd\xa0\xb3\xf7\xe3\x6c\x9d\xa7" },
  { "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq",
    "\x75\x38\x8b\x16\x51\x27\x76\xcc\x5d\xba\x5d\xa1\xfd\x89\x01\x50\xb0\xc6"
    "\x45\x5c\xb4\xf5\x8b\x19\x52\x52\x25\x25" },
  { "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmn",
    "\xbd\xcc\x93\x2d\xc7\x37\xd4\x4c\x92\x4b\xc1\x52\x89\x83\x64\x55\x1b\xbe"
    "\xa6\xbd\x18\x84\x0b\xc4\x72\x56\x98\xe1" },
  { "hijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu",
    "\x96\x90\xa3\xc7\x08\x9e\xdc\xf0\x3f\xef\xd2\xb6\xd4\xb1\x04\xde\x5e\xed"
    "\x7d\x35\xa7\x2b\x42\x7c\xd7\xb5\x0f\xf2" },
  { "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopj"
    "klmnopqklmnopqrlmnopqrsmnopqrstnopqrstu",
    "\xc9\x7c\xa9\xa5\x59\x85\x0c\xe9\x7a\x04\xa9\x6d\xef\x6d\x99\xa9\xe0\xe0"
    "\xe2\xab\x14\xe6\xb8\xdf\x26\x5f\xc0\xb3" },
  { "01234567012345670123456701234567",
    "\x71\xb6\x56\x0b\x2f\x68\xd8\x24\x27\x61\xa0\x79\x63\x0e\xff\x8e\x94\xb8"
    "\x82\xc9\xc2\xb1\x6b\x58\x56\x72\xfb\xcd" },
  { "0123456701234567012345670123456701234567012345670123456701234567",
    "\x11\x52\xa5\x58\xc1\xdb\xcd\x02\x32\x22\xe3\x47\x2f\x2b\x9a\x2b\xdf\x89"
    "\x84\xe5\xd8\x21\x53\xe6\xb1\x26\xa2\x01" },
};

static void do_sha224_testcase (const struct sha224_testcase *test);
static void do_sha224_bigtest (void);

int
main (void)
{
  size_t i;

  for (i = 0; i < ARRAY_SIZE (testcases); ++i)
    do_sha224_testcase (&testcases[i]);

  do_sha224_bigtest ();
  return 0;
}

static void
do_sha224_testcase (const struct sha224_testcase *test)
{
  size_t i;
  struct sha256_ctx ctx;
  uint8_t digest[SHA224_DIGEST_SIZE];

  sha224_init (&ctx);
  sha256_update (&ctx, test->message, strlen (test->message));
  sha224_final (digest, &ctx);

  for (i = 0; i < sizeof (digest); ++i)
    printf ("%02x", digest[i]);
  printf ("\n");

  ASSERT (memcmp (digest, test->digest, sizeof (digest)) == 0);
}

static void
do_sha224_bigtest (void)
{
  size_t i;
  char *buffer;
  struct sha256_ctx ctx;
  uint8_t digest[SHA224_DIGEST_SIZE];
  const char *expect
      = "\x09\x07\xf5\xc4\x1a\xac\x4f\xaf\x84\x09\xea\xc4\x02\x2f\x8c\x5a\xe2"
        "\x03\x01\x81\x95\x0e\x0d\x3d\xf4\x9f\xc9\x50";

  buffer = malloc (1000000000);
  if (buffer == NULL)
    {
      fprintf (stderr, "malloc (): Out of memory.\n");
      abort ();
    }

  for (i = 0; i < 1000000000; ++i)
    buffer[i] = i & 0xff;

  sha224_init (&ctx);
  sha256_update (&ctx, buffer, 1000000000);
  sha224_final (digest, &ctx);

  for (i = 0; i < sizeof (digest); ++i)
    printf ("%02x", digest[i]);
  printf ("\n");

  free (buffer);

  ASSERT (memcmp (digest, expect, sizeof (digest)) == 0);
}
