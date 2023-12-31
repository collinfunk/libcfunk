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

#include "sha256.h"
#include "test-help.h"

struct sha256_testcase
{
  const char *message;
  const char *digest;
};

static const struct sha256_testcase testcases[] = {
  { "", "\xe3\xb0\xc4\x42\x98\xfc\x1c\x14\x9a\xfb\xf4\xc8\x99\x6f\xb9\x24\x27"
        "\xae\x41\xe4\x64\x9b\x93\x4c\xa4\x95\x99\x1b\x78\x52\xb8\x55" },
  { "a", "\xca\x97\x81\x12\xca\x1b\xbd\xca\xfa\xc2\x31\xb3\x9a\x23\xdc\x4d\xa7"
         "\x86\xef\xf8\x14\x7c\x4e\x72\xb9\x80\x77\x85\xaf\xee\x48\xbb" },
  { "abc",
    "\xba\x78\x16\xbf\x8f\x01\xcf\xea\x41\x41\x40\xde\x5d\xae\x22\x23\xb0\x03"
    "\x61\xa3\x96\x17\x7a\x9c\xb4\x10\xff\x61\xf2\x00\x15\xad" },
  { "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq",
    "\x24\x8d\x6a\x61\xd2\x06\x38\xb8\xe5\xc0\x26\x93\x0c\x3e\x60\x39\xa3\x3c"
    "\xe4\x59\x64\xff\x21\x67\xf6\xec\xed\xd4\x19\xdb\x06\xc1" },
  { "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmn",
    "\x07\x8c\x0d\xfc\x32\x78\xfd\x77\x59\x92\x0f\x5c\xca\x94\xc6\xd5\x5d\xb2"
    "\xc6\x94\x51\x0f\x6e\x26\xa8\xfe\x5c\x5b\x50\xa4\xf4\x17" },
  { "hijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu",
    "\x2f\x04\x49\x74\x57\x21\xe3\x48\xda\xfd\x26\xac\x9f\xc1\xd7\xec\x5a\x7c"
    "\x6c\xc5\x82\x21\xc3\xf6\x67\xe9\x4e\xc4\xe2\xae\x65\x62" },
  { "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopj"
    "klmnopqklmnopqrlmnopqrsmnopqrstnopqrstu",
    "\xcf\x5b\x16\xa7\x78\xaf\x83\x80\x03\x6c\xe5\x9e\x7b\x04\x92\x37\x0b\x24"
    "\x9b\x11\xe8\xf0\x7a\x51\xaf\xac\x45\x03\x7a\xfe\xe9\xd1" },
  { "01234567012345670123456701234567",
    "\xdd\x01\x45\x16\x94\x40\xe7\xe5\xc0\x34\x7a\xb0\xc1\xb4\xf8\xc9\x70\xe6"
    "\xad\x3f\xf6\x25\xa2\xed\xfc\x52\x87\x8f\x38\x4e\x76\x81" },
  { "0123456701234567012345670123456701234567012345670123456701234567",
    "\x81\x82\xca\xdb\x21\xaf\x0e\x37\xc0\x64\x14\xec\xe0\x8e\x19\xc6\x5b\xdb"
    "\x22\xc3\x96\xd4\x8b\xa7\x34\x10\x12\xee\xa9\xff\xdf\xdd" },
};

static void do_sha256_testcase (const struct sha256_testcase *test);
static void do_sha256_bigtest (void);

int
main (void)
{
  size_t i;

  for (i = 0; i < ARRAY_SIZE (testcases); ++i)
    do_sha256_testcase (&testcases[i]);

  do_sha256_bigtest ();
  return 0;
}

static void
do_sha256_testcase (const struct sha256_testcase *test)
{
  size_t i;
  struct sha256_ctx ctx;
  uint8_t digest[SHA256_DIGEST_SIZE];

  sha256_init (&ctx);
  sha256_update (&ctx, test->message, strlen (test->message));
  sha256_final (digest, &ctx);

  for (i = 0; i < sizeof (digest); ++i)
    printf ("%02x", digest[i]);
  printf ("\n");

  ASSERT (memcmp (digest, test->digest, sizeof (digest)) == 0);
}

static void
do_sha256_bigtest (void)
{
  size_t i;
  char *buffer;
  struct sha256_ctx ctx;
  uint8_t digest[SHA256_DIGEST_SIZE];
  const char *expect
      = "\x3c\xca\xf2\x67\xe1\xdc\xae\x06\x52\x9a\x76\xa4\xd5\x86\xe7\xa4\xf6"
        "\x16\xb1\x9b\x2c\x4d\xa9\xe8\xab\xad\x6a\x2d\x6a\x6a\xd1\x3a";

  buffer = malloc (1000000000);
  if (buffer == NULL)
    {
      fprintf (stderr, "malloc (): Out of memory.\n");
      abort ();
    }

  for (i = 0; i < 1000000000; ++i)
    buffer[i] = i & 0xff;

  sha256_init (&ctx);
  sha256_update (&ctx, buffer, 1000000000);
  sha256_final (digest, &ctx);

  for (i = 0; i < sizeof (digest); ++i)
    printf ("%02x", digest[i]);
  printf ("\n");

  free (buffer);

  ASSERT (memcmp (digest, expect, sizeof (digest)) == 0);
}
