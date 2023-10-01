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

#include "sha1.h"
#include "test-help.h"

struct sha1_testcase
{
  const char *message;
  const char *digest;
};

static const struct sha1_testcase testcases[]
    = { { "", "\xda\x39\xa3\xee\x5e\x6b\x4b\x0d\x32\x55\xbf\xef\x95\x60\x18"
              "\x90\xaf\xd8\x07\x09" },
        { "a", "\x86\xf7\xe4\x37\xfa\xa5\xa7\xfc\xe1\x5d\x1d\xdc\xb9\xea\xea"
               "\xea\x37\x76\x67\xb8" },
        { "abc", "\xa9\x99\x3e\x36\x47\x06\x81\x6a\xba\x3e\x25\x71\x78\x50\xc2"
                 "\x6c\x9c\xd0\xd8\x9d" },
        { "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq",
          "\x84\x98\x3e\x44\x1c\x3b\xd2\x6e\xba\xae\x4a\xa1\xf9\x51\x29\xe5"
          "\xe5\x46\x70\xf1" },
        { "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmn",
          "\xc0\x1f\xbf\xbc\x82\x20\x46\xb0\x3c\x59\x8e\x28\xd4\x3d\x56\xa4"
          "\x90\x6e\x22\xad" },
        { "hijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu",
          "\x3a\xe8\xa7\xe1\x64\x86\x78\x73\x4b\xa5\xf3\xf5\x70\x70\xb1\xb3"
          "\xa5\x1f\x9b\x42" },
        { "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijk"
          "lmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu",
          "\xa4\x9b\x24\x46\xa0\x2c\x64\x5b\xf4\x19\xf9\x95\xb6\x70\x91\x25"
          "\x3a\x04\xa2\x59" },
        { "01234567012345670123456701234567",
          "\xc7\x29\xc8\x99\x6e\xe0\xa6\xf7\x4f\x4f\x32\x48\xe8\x95\x7e\xdf"
          "\x70\x4f\xb6\x24" },
        { "0123456701234567012345670123456701234567012345670123456701234567",
          "\xe0\xc0\x94\xe8\x67\xef\x46\xc3\x50\xef\x54\xa7\xf5\x9d\xd6\x0b"
          "\xed\x92\xae\x83" } };

static void do_sha1_testcase (const struct sha1_testcase *test);
static void do_sha1_bigtest (void);

int
main (void)
{
  size_t i;

  for (i = 0; i < ARRAY_SIZE (testcases); ++i)
    do_sha1_testcase (&testcases[i]);

  do_sha1_bigtest ();
  return 0;
}

static void
do_sha1_testcase (const struct sha1_testcase *test)
{
  size_t i;
  struct sha1_ctx ctx;
  uint8_t digest[SHA1_DIGEST_SIZE];

  sha1_init (&ctx);
  sha1_update (&ctx, test->message, strlen (test->message));
  sha1_final (digest, &ctx);

  for (i = 0; i < sizeof (digest); ++i)
    printf ("%02x", digest[i]);
  printf ("\n");

  ASSERT (memcmp (digest, test->digest, sizeof (digest)) == 0);
}

static void
do_sha1_bigtest (void)
{
  size_t i;
  char *buffer;
  struct sha1_ctx ctx;
  uint8_t digest[SHA1_DIGEST_SIZE];
  const char *expect = "\xba\xa2\x24\x74\xa9\xc4\x70\x39\xe2\x0c\xda\x7e\xf1"
                       "\x5d\xac\x39\x52\xdd\xc5\x19";

  buffer = malloc (1000000000);
  if (buffer == NULL)
    {
      fprintf (stderr, "malloc (): Out of memory.\n");
      abort ();
    }

  for (i = 0; i < 1000000000; ++i)
    buffer[i] = i & 0xff;

  sha1_init (&ctx);
  sha1_update (&ctx, buffer, 1000000000);
  sha1_final (digest, &ctx);

  for (i = 0; i < sizeof (digest); ++i)
    printf ("%02x", digest[i]);
  printf ("\n");

  free (buffer);

  ASSERT (memcmp (digest, expect, sizeof (digest)) == 0);
}
