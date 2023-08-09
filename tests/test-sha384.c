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

#include "sha512.h"
#include "test-help.h"

struct sha384_testcase
{
  const char *message;
  const char *digest;
};

static const struct sha384_testcase testcases[] = {
  { "", "\x38\xb0\x60\xa7\x51\xac\x96\x38\x4c\xd9\x32\x7e\xb1\xb1\xe3\x6a\x21"
        "\xfd\xb7\x11\x14\xbe\x07\x43\x4c\x0c\xc7\xbf\x63\xf6\xe1\xda\x27\x4e"
        "\xde\xbf\xe7\x6f\x65\xfb\xd5\x1a\xd2\xf1\x48\x98\xb9\x5b" },
  { "a", "\x54\xa5\x9b\x9f\x22\xb0\xb8\x08\x80\xd8\x42\x7e\x54\x8b\x7c\x23\xab"
         "\xd8\x73\x48\x6e\x1f\x03\x5d\xce\x9c\xd6\x97\xe8\x51\x75\x03\x3c\xaa"
         "\x88\xe6\xd5\x7b\xc3\x5e\xfa\xe0\xb5\xaf\xd3\x14\x5f\x31" },
  { "abc",
    "\xcb\x00\x75\x3f\x45\xa3\x5e\x8b\xb5\xa0\x3d\x69\x9a\xc6\x50\x07\x27\x2c"
    "\x32\xab\x0e\xde\xd1\x63\x1a\x8b\x60\x5a\x43\xff\x5b\xed\x80\x86\x07\x2b"
    "\xa1\xe7\xcc\x23\x58\xba\xec\xa1\x34\xc8\x25\xa7" },
  { "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq",
    "\x33\x91\xfd\xdd\xfc\x8d\xc7\x39\x37\x07\xa6\x5b\x1b\x47\x09\x39\x7c\xf8"
    "\xb1\xd1\x62\xaf\x05\xab\xfe\x8f\x45\x0d\xe5\xf3\x6b\xc6\xb0\x45\x5a\x85"
    "\x20\xbc\x4e\x6f\x5f\xe9\x5b\x1f\xe3\xc8\x45\x2b" },
  { "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmn",
    "\xc5\xf9\xc3\xda\xba\xbe\xdf\xd4\xf6\x69\x96\x09\x50\x7c\x3b\x67\x1d\xe8"
    "\x56\x5c\x42\xac\x33\x74\xa2\x80\x3f\xea\x72\x29\x86\xb8\xf7\x19\xe3\xaa"
    "\xb6\x08\x6d\x01\x40\x5e\xa4\xaa\xf7\x6a\x84\xad" },
  { "hijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu",
    "\xb3\x16\x56\x62\xdc\xbb\x43\x1c\x01\x6a\x83\xcc\xcc\x93\xc4\x49\xda\xef"
    "\x62\xd2\xf6\x5a\x8d\x5b\x0c\xa9\xa6\xe5\xa6\x9c\x25\x15\x1c\x36\xa9\x13"
    "\xc7\x1d\x4d\x7d\x26\x1b\xbf\x6a\xa0\x4a\x6c\xa9" },
  { "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopj"
    "klmnopqklmnopqrlmnopqrsmnopqrstnopqrstu",
    "\x09\x33\x0c\x33\xf7\x11\x47\xe8\x3d\x19\x2f\xc7\x82\xcd\x1b\x47\x53\x11"
    "\x1b\x17\x3b\x3b\x05\xd2\x2f\xa0\x80\x86\xe3\xb0\xf7\x12\xfc\xc7\xc7\x1a"
    "\x55\x7e\x2d\xb9\x66\xc3\xe9\xfa\x91\x74\x60\x39" },
  { "01234567012345670123456701234567",
    "\x15\x06\x58\x55\xb8\xe2\xdf\xfa\xc1\xd5\x6d\x06\x61\xb7\x67\x3e\x0d\xf6"
    "\x84\x09\x6d\x81\xb3\xca\x2f\x1e\x7c\x25\x87\x2a\x0a\x64\x88\xd7\xd0\x29"
    "\xa4\xbe\x14\x73\x03\x29\x34\x70\x7f\x41\x21\x27" },
  { "0123456701234567012345670123456701234567012345670123456701234567",
    "\x72\xf5\x89\x33\x31\xc2\x49\x31\x2d\x3c\x2b\x7a\x97\x09\xa7\xb9\x69\x08"
    "\xb7\x76\x91\x79\xdd\x98\x24\xed\x57\x86\x69\xfc\xc1\xf1\xc2\xde\x02\xc0"
    "\x3b\x3d\x35\xa4\x67\xaa\x0b\x47\x2c\x1b\xb3\xd1" }
};

static void do_sha384_testcase (const struct sha384_testcase *test);
static void do_sha384_bigtest (void);

int
main (void)
{
  size_t i;

  for (i = 0; i < ARRAY_SIZE (testcases); ++i)
    do_sha384_testcase (&testcases[i]);

  do_sha384_bigtest ();
  return 0;
}

static void
do_sha384_testcase (const struct sha384_testcase *test)
{
  size_t i;
  struct sha512_ctx ctx;
  uint8_t digest[SHA384_DIGEST_SIZE];

  sha384_init (&ctx);
  sha512_update (&ctx, test->message, strlen (test->message));
  sha384_final (digest, &ctx);

  for (i = 0; i < sizeof (digest); ++i)
    printf ("%02x", digest[i]);
  printf ("\n");

  ASSERT (memcmp (digest, test->digest, sizeof (digest)) == 0);
}

static void
do_sha384_bigtest (void)
{
  size_t i;
  char *buffer;
  struct sha512_ctx ctx;
  uint8_t digest[SHA384_DIGEST_SIZE];
  const char *expect
      = "\x8e\xc0\x98\xac\xbb\x20\xe6\x3f\xcf\x93\x28\xf2\x74\xae\xb4\xb9\xd4"
        "\xd5\x6d\x67\xd7\x48\xf5\xcd\xc2\xee\x03\xe6\xae\x4a\x15\x5c\x87\xf7"
        "\x6a\xa4\x64\x18\xdb\xdd\xcd\x22\xa5\xb2\x46\x66\x12\xd2";

  buffer = malloc (1000000000);
  if (buffer == NULL)
    {
      fprintf (stderr, "malloc (): Out of memory.\n");
      abort ();
    }

  for (i = 0; i < 1000000000; ++i)
    buffer[i] = i & 0xff;

  sha384_init (&ctx);
  sha512_update (&ctx, buffer, 1000000000);
  sha384_final (digest, &ctx);

  for (i = 0; i < sizeof (digest); ++i)
    printf ("%02x", digest[i]);
  printf ("\n");

  free (buffer);

  ASSERT (memcmp (digest, expect, sizeof (digest)) == 0);
}
