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

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "circular-shift.h"
#include "test-help.h"

/* This file should not abort with -fsanitize=undefined. */

static void test_rotl8 (void);
static void test_rotl16 (void);
static void test_rotl32 (void);
static void test_rotl64 (void);
static void test_rotr8 (void);
static void test_rotr16 (void);
static void test_rotr32 (void);
static void test_rotr64 (void);

int
main (void)
{
  test_rotl8 ();
  test_rotl16 ();
  test_rotl32 ();
  test_rotl64 ();
  test_rotr8 ();
  test_rotr16 ();
  test_rotr32 ();
  test_rotr64 ();
  return 0;
}

static void
test_rotl8 (void)
{
  ASSERT (rotl8 (0x96, 0) == 0x96);
  ASSERT (rotl8 (0x96, 1) == 0x2d);
  ASSERT (rotl8 (0x96, 2) == 0x5a);
  ASSERT (rotl8 (0x96, 3) == 0xb4);
  ASSERT (rotl8 (0x96, 4) == 0x69);
  ASSERT (rotl8 (0x96, 5) == 0xd2);
  ASSERT (rotl8 (0x96, 6) == 0xa5);
  ASSERT (rotl8 (0x96, 7) == 0x4b);
  ASSERT (rotl8 (0x96, 8) == 0x96);
  ASSERT (rotl8 (0x96, 9) == 0x2d);
  ASSERT (rotl8 (0x96, 10) == 0x5a);
  ASSERT (rotl8 (0x96, 11) == 0xb4);
  ASSERT (rotl8 (0x96, 12) == 0x69);
  ASSERT (rotl8 (0x96, 13) == 0xd2);
  ASSERT (rotl8 (0x96, 14) == 0xa5);
  ASSERT (rotl8 (0x96, 15) == 0x4b);
  ASSERT (rotl8 (0x96, 16) == 0x96);
}

static void
test_rotl16 (void)
{
  ASSERT (rotl16 (0x5e1aU, 0) == 0x5e1aU);
  ASSERT (rotl16 (0x5e1aU, 1) == 0xbc34U);
  ASSERT (rotl16 (0x5e1aU, 2) == 0x7869U);
  ASSERT (rotl16 (0x5e1aU, 3) == 0xf0d2U);
  ASSERT (rotl16 (0x5e1aU, 4) == 0xe1a5U);
  ASSERT (rotl16 (0x5e1aU, 5) == 0xc34bU);
  ASSERT (rotl16 (0x5e1aU, 6) == 0x8697U);
  ASSERT (rotl16 (0x5e1aU, 7) == 0x0d2fU);
  ASSERT (rotl16 (0x5e1aU, 8) == 0x1a5eU);
  ASSERT (rotl16 (0x5e1aU, 9) == 0x34bcU);
  ASSERT (rotl16 (0x5e1aU, 10) == 0x6978U);
  ASSERT (rotl16 (0x5e1aU, 11) == 0xd2f0U);
  ASSERT (rotl16 (0x5e1aU, 12) == 0xa5e1U);
  ASSERT (rotl16 (0x5e1aU, 13) == 0x4bc3U);
  ASSERT (rotl16 (0x5e1aU, 14) == 0x9786U);
  ASSERT (rotl16 (0x5e1aU, 15) == 0x2f0dU);
  ASSERT (rotl16 (0x5e1aU, 16) == 0x5e1aU);
  ASSERT (rotl16 (0x5e1aU, 17) == 0xbc34U);
  ASSERT (rotl16 (0x5e1aU, 18) == 0x7869U);
  ASSERT (rotl16 (0x5e1aU, 19) == 0xf0d2U);
  ASSERT (rotl16 (0x5e1aU, 20) == 0xe1a5U);
  ASSERT (rotl16 (0x5e1aU, 21) == 0xc34bU);
  ASSERT (rotl16 (0x5e1aU, 22) == 0x8697U);
  ASSERT (rotl16 (0x5e1aU, 23) == 0x0d2fU);
  ASSERT (rotl16 (0x5e1aU, 24) == 0x1a5eU);
  ASSERT (rotl16 (0x5e1aU, 25) == 0x34bcU);
  ASSERT (rotl16 (0x5e1aU, 26) == 0x6978U);
  ASSERT (rotl16 (0x5e1aU, 27) == 0xd2f0U);
  ASSERT (rotl16 (0x5e1aU, 28) == 0xa5e1U);
  ASSERT (rotl16 (0x5e1aU, 29) == 0x4bc3U);
  ASSERT (rotl16 (0x5e1aU, 30) == 0x9786U);
  ASSERT (rotl16 (0x5e1aU, 31) == 0x2f0dU);
  ASSERT (rotl16 (0x5e1aU, 32) == 0x5e1aU);
}

static void
test_rotl32 (void)
{
  ASSERT (rotl32 (0x51af3678UL, 0) == 0x51af3678UL);
  ASSERT (rotl32 (0x51af3678UL, 1) == 0xa35e6cf0UL);
  ASSERT (rotl32 (0x51af3678UL, 2) == 0x46bcd9e1UL);
  ASSERT (rotl32 (0x51af3678UL, 3) == 0x8d79b3c2UL);
  ASSERT (rotl32 (0x51af3678UL, 4) == 0x1af36785UL);
  ASSERT (rotl32 (0x51af3678UL, 5) == 0x35e6cf0aUL);
  ASSERT (rotl32 (0x51af3678UL, 6) == 0x6bcd9e14UL);
  ASSERT (rotl32 (0x51af3678UL, 7) == 0xd79b3c28UL);
  ASSERT (rotl32 (0x51af3678UL, 8) == 0xaf367851UL);
  ASSERT (rotl32 (0x51af3678UL, 9) == 0x5e6cf0a3UL);
  ASSERT (rotl32 (0x51af3678UL, 10) == 0xbcd9e146UL);
  ASSERT (rotl32 (0x51af3678UL, 11) == 0x79b3c28dUL);
  ASSERT (rotl32 (0x51af3678UL, 12) == 0xf367851aUL);
  ASSERT (rotl32 (0x51af3678UL, 13) == 0xe6cf0a35UL);
  ASSERT (rotl32 (0x51af3678UL, 14) == 0xcd9e146bUL);
  ASSERT (rotl32 (0x51af3678UL, 15) == 0x9b3c28d7UL);
  ASSERT (rotl32 (0x51af3678UL, 16) == 0x367851afUL);
  ASSERT (rotl32 (0x51af3678UL, 17) == 0x6cf0a35eUL);
  ASSERT (rotl32 (0x51af3678UL, 18) == 0xd9e146bcUL);
  ASSERT (rotl32 (0x51af3678UL, 19) == 0xb3c28d79UL);
  ASSERT (rotl32 (0x51af3678UL, 20) == 0x67851af3UL);
  ASSERT (rotl32 (0x51af3678UL, 21) == 0xcf0a35e6UL);
  ASSERT (rotl32 (0x51af3678UL, 22) == 0x9e146bcdUL);
  ASSERT (rotl32 (0x51af3678UL, 23) == 0x3c28d79bUL);
  ASSERT (rotl32 (0x51af3678UL, 24) == 0x7851af36UL);
  ASSERT (rotl32 (0x51af3678UL, 25) == 0xf0a35e6cUL);
  ASSERT (rotl32 (0x51af3678UL, 26) == 0xe146bcd9UL);
  ASSERT (rotl32 (0x51af3678UL, 27) == 0xc28d79b3UL);
  ASSERT (rotl32 (0x51af3678UL, 28) == 0x851af367UL);
  ASSERT (rotl32 (0x51af3678UL, 29) == 0x0a35e6cfUL);
  ASSERT (rotl32 (0x51af3678UL, 30) == 0x146bcd9eUL);
  ASSERT (rotl32 (0x51af3678UL, 31) == 0x28d79b3cUL);
  ASSERT (rotl32 (0x51af3678UL, 32) == 0x51af3678UL);
  ASSERT (rotl32 (0x51af3678UL, 33) == 0xa35e6cf0UL);
  ASSERT (rotl32 (0x51af3678UL, 34) == 0x46bcd9e1UL);
  ASSERT (rotl32 (0x51af3678UL, 35) == 0x8d79b3c2UL);
  ASSERT (rotl32 (0x51af3678UL, 36) == 0x1af36785UL);
  ASSERT (rotl32 (0x51af3678UL, 37) == 0x35e6cf0aUL);
  ASSERT (rotl32 (0x51af3678UL, 38) == 0x6bcd9e14UL);
  ASSERT (rotl32 (0x51af3678UL, 39) == 0xd79b3c28UL);
  ASSERT (rotl32 (0x51af3678UL, 40) == 0xaf367851UL);
  ASSERT (rotl32 (0x51af3678UL, 41) == 0x5e6cf0a3UL);
  ASSERT (rotl32 (0x51af3678UL, 42) == 0xbcd9e146UL);
  ASSERT (rotl32 (0x51af3678UL, 43) == 0x79b3c28dUL);
  ASSERT (rotl32 (0x51af3678UL, 44) == 0xf367851aUL);
  ASSERT (rotl32 (0x51af3678UL, 45) == 0xe6cf0a35UL);
  ASSERT (rotl32 (0x51af3678UL, 46) == 0xcd9e146bUL);
  ASSERT (rotl32 (0x51af3678UL, 47) == 0x9b3c28d7UL);
  ASSERT (rotl32 (0x51af3678UL, 48) == 0x367851afUL);
  ASSERT (rotl32 (0x51af3678UL, 49) == 0x6cf0a35eUL);
  ASSERT (rotl32 (0x51af3678UL, 50) == 0xd9e146bcUL);
  ASSERT (rotl32 (0x51af3678UL, 51) == 0xb3c28d79UL);
  ASSERT (rotl32 (0x51af3678UL, 52) == 0x67851af3UL);
  ASSERT (rotl32 (0x51af3678UL, 53) == 0xcf0a35e6UL);
  ASSERT (rotl32 (0x51af3678UL, 54) == 0x9e146bcdUL);
  ASSERT (rotl32 (0x51af3678UL, 55) == 0x3c28d79bUL);
  ASSERT (rotl32 (0x51af3678UL, 56) == 0x7851af36UL);
  ASSERT (rotl32 (0x51af3678UL, 57) == 0xf0a35e6cUL);
  ASSERT (rotl32 (0x51af3678UL, 58) == 0xe146bcd9UL);
  ASSERT (rotl32 (0x51af3678UL, 59) == 0xc28d79b3UL);
  ASSERT (rotl32 (0x51af3678UL, 60) == 0x851af367UL);
  ASSERT (rotl32 (0x51af3678UL, 61) == 0x0a35e6cfUL);
  ASSERT (rotl32 (0x51af3678UL, 62) == 0x146bcd9eUL);
  ASSERT (rotl32 (0x51af3678UL, 63) == 0x28d79b3cUL);
  ASSERT (rotl32 (0x51af3678UL, 64) == 0x51af3678UL);
}

static void
test_rotl64 (void)
{
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 0) == 0x59ae28915a84db37ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 1) == 0xb35c5122b509b66eULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 2) == 0x66b8a2456a136cddULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 3) == 0xcd71448ad426d9baULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 4) == 0x9ae28915a84db375ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 5) == 0x35c5122b509b66ebULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 6) == 0x6b8a2456a136cdd6ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 7) == 0xd71448ad426d9bacULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 8) == 0xae28915a84db3759ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 9) == 0x5c5122b509b66eb3ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 10) == 0xb8a2456a136cdd66ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 11) == 0x71448ad426d9bacdULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 12) == 0xe28915a84db3759aULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 13) == 0xc5122b509b66eb35ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 14) == 0x8a2456a136cdd66bULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 15) == 0x1448ad426d9bacd7ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 16) == 0x28915a84db3759aeULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 17) == 0x5122b509b66eb35cULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 18) == 0xa2456a136cdd66b8ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 19) == 0x448ad426d9bacd71ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 20) == 0x8915a84db3759ae2ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 21) == 0x122b509b66eb35c5ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 22) == 0x2456a136cdd66b8aULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 23) == 0x48ad426d9bacd714ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 24) == 0x915a84db3759ae28ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 25) == 0x22b509b66eb35c51ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 26) == 0x456a136cdd66b8a2ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 27) == 0x8ad426d9bacd7144ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 28) == 0x15a84db3759ae289ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 29) == 0x2b509b66eb35c512ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 30) == 0x56a136cdd66b8a24ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 31) == 0xad426d9bacd71448ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 32) == 0x5a84db3759ae2891ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 33) == 0xb509b66eb35c5122ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 34) == 0x6a136cdd66b8a245ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 35) == 0xd426d9bacd71448aULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 36) == 0xa84db3759ae28915ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 37) == 0x509b66eb35c5122bULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 38) == 0xa136cdd66b8a2456ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 39) == 0x426d9bacd71448adULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 40) == 0x84db3759ae28915aULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 41) == 0x09b66eb35c5122b5ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 42) == 0x136cdd66b8a2456aULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 43) == 0x26d9bacd71448ad4ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 44) == 0x4db3759ae28915a8ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 45) == 0x9b66eb35c5122b50ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 46) == 0x36cdd66b8a2456a1ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 47) == 0x6d9bacd71448ad42ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 48) == 0xdb3759ae28915a84ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 49) == 0xb66eb35c5122b509ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 50) == 0x6cdd66b8a2456a13ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 51) == 0xd9bacd71448ad426ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 52) == 0xb3759ae28915a84dULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 53) == 0x66eb35c5122b509bULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 54) == 0xcdd66b8a2456a136ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 55) == 0x9bacd71448ad426dULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 56) == 0x3759ae28915a84dbULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 57) == 0x6eb35c5122b509b6ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 58) == 0xdd66b8a2456a136cULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 59) == 0xbacd71448ad426d9ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 60) == 0x759ae28915a84db3ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 61) == 0xeb35c5122b509b66ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 62) == 0xd66b8a2456a136cdULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 63) == 0xacd71448ad426d9bULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 64) == 0x59ae28915a84db37ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 65) == 0xb35c5122b509b66eULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 66) == 0x66b8a2456a136cddULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 67) == 0xcd71448ad426d9baULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 68) == 0x9ae28915a84db375ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 69) == 0x35c5122b509b66ebULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 70) == 0x6b8a2456a136cdd6ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 71) == 0xd71448ad426d9bacULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 72) == 0xae28915a84db3759ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 73) == 0x5c5122b509b66eb3ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 74) == 0xb8a2456a136cdd66ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 75) == 0x71448ad426d9bacdULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 76) == 0xe28915a84db3759aULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 77) == 0xc5122b509b66eb35ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 78) == 0x8a2456a136cdd66bULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 79) == 0x1448ad426d9bacd7ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 80) == 0x28915a84db3759aeULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 81) == 0x5122b509b66eb35cULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 82) == 0xa2456a136cdd66b8ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 83) == 0x448ad426d9bacd71ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 84) == 0x8915a84db3759ae2ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 85) == 0x122b509b66eb35c5ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 86) == 0x2456a136cdd66b8aULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 87) == 0x48ad426d9bacd714ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 88) == 0x915a84db3759ae28ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 89) == 0x22b509b66eb35c51ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 90) == 0x456a136cdd66b8a2ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 91) == 0x8ad426d9bacd7144ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 92) == 0x15a84db3759ae289ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 93) == 0x2b509b66eb35c512ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 94) == 0x56a136cdd66b8a24ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 95) == 0xad426d9bacd71448ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 96) == 0x5a84db3759ae2891ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 97) == 0xb509b66eb35c5122ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 98) == 0x6a136cdd66b8a245ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 99) == 0xd426d9bacd71448aULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 100) == 0xa84db3759ae28915ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 101) == 0x509b66eb35c5122bULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 102) == 0xa136cdd66b8a2456ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 103) == 0x426d9bacd71448adULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 104) == 0x84db3759ae28915aULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 105) == 0x09b66eb35c5122b5ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 106) == 0x136cdd66b8a2456aULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 107) == 0x26d9bacd71448ad4ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 108) == 0x4db3759ae28915a8ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 109) == 0x9b66eb35c5122b50ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 110) == 0x36cdd66b8a2456a1ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 111) == 0x6d9bacd71448ad42ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 112) == 0xdb3759ae28915a84ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 113) == 0xb66eb35c5122b509ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 114) == 0x6cdd66b8a2456a13ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 115) == 0xd9bacd71448ad426ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 116) == 0xb3759ae28915a84dULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 117) == 0x66eb35c5122b509bULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 118) == 0xcdd66b8a2456a136ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 119) == 0x9bacd71448ad426dULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 120) == 0x3759ae28915a84dbULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 121) == 0x6eb35c5122b509b6ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 122) == 0xdd66b8a2456a136cULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 123) == 0xbacd71448ad426d9ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 124) == 0x759ae28915a84db3ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 125) == 0xeb35c5122b509b66ULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 126) == 0xd66b8a2456a136cdULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 127) == 0xacd71448ad426d9bULL);
  ASSERT (rotl64 (0x59ae28915a84db37ULL, 128) == 0x59ae28915a84db37ULL);
}

static void
test_rotr8 (void)
{
  ASSERT (rotr8 (0x96, 0) == 0x96);
  ASSERT (rotr8 (0x96, 1) == 0x4b);
  ASSERT (rotr8 (0x96, 2) == 0xa5);
  ASSERT (rotr8 (0x96, 3) == 0xd2);
  ASSERT (rotr8 (0x96, 4) == 0x69);
  ASSERT (rotr8 (0x96, 5) == 0xb4);
  ASSERT (rotr8 (0x96, 6) == 0x5a);
  ASSERT (rotr8 (0x96, 7) == 0x2d);
  ASSERT (rotr8 (0x96, 8) == 0x96);
  ASSERT (rotr8 (0x96, 9) == 0x4b);
  ASSERT (rotr8 (0x96, 10) == 0xa5);
  ASSERT (rotr8 (0x96, 11) == 0xd2);
  ASSERT (rotr8 (0x96, 12) == 0x69);
  ASSERT (rotr8 (0x96, 13) == 0xb4);
  ASSERT (rotr8 (0x96, 14) == 0x5a);
  ASSERT (rotr8 (0x96, 15) == 0x2d);
  ASSERT (rotr8 (0x96, 16) == 0x96);
}

static void
test_rotr16 (void)
{
  ASSERT (rotr16 (0x5e1aU, 0) == 0x5e1aU);
  ASSERT (rotr16 (0x5e1aU, 1) == 0x2f0dU);
  ASSERT (rotr16 (0x5e1aU, 2) == 0x9786U);
  ASSERT (rotr16 (0x5e1aU, 3) == 0x4bc3U);
  ASSERT (rotr16 (0x5e1aU, 4) == 0xa5e1U);
  ASSERT (rotr16 (0x5e1aU, 5) == 0xd2f0U);
  ASSERT (rotr16 (0x5e1aU, 6) == 0x6978U);
  ASSERT (rotr16 (0x5e1aU, 7) == 0x34bcU);
  ASSERT (rotr16 (0x5e1aU, 8) == 0x1a5eU);
  ASSERT (rotr16 (0x5e1aU, 9) == 0x0d2fU);
  ASSERT (rotr16 (0x5e1aU, 10) == 0x8697U);
  ASSERT (rotr16 (0x5e1aU, 11) == 0xc34bU);
  ASSERT (rotr16 (0x5e1aU, 12) == 0xe1a5U);
  ASSERT (rotr16 (0x5e1aU, 13) == 0xf0d2U);
  ASSERT (rotr16 (0x5e1aU, 14) == 0x7869U);
  ASSERT (rotr16 (0x5e1aU, 15) == 0xbc34U);
  ASSERT (rotr16 (0x5e1aU, 16) == 0x5e1aU);
  ASSERT (rotr16 (0x5e1aU, 17) == 0x2f0dU);
  ASSERT (rotr16 (0x5e1aU, 18) == 0x9786U);
  ASSERT (rotr16 (0x5e1aU, 19) == 0x4bc3U);
  ASSERT (rotr16 (0x5e1aU, 20) == 0xa5e1U);
  ASSERT (rotr16 (0x5e1aU, 21) == 0xd2f0U);
  ASSERT (rotr16 (0x5e1aU, 22) == 0x6978U);
  ASSERT (rotr16 (0x5e1aU, 23) == 0x34bcU);
  ASSERT (rotr16 (0x5e1aU, 24) == 0x1a5eU);
  ASSERT (rotr16 (0x5e1aU, 25) == 0x0d2fU);
  ASSERT (rotr16 (0x5e1aU, 26) == 0x8697U);
  ASSERT (rotr16 (0x5e1aU, 27) == 0xc34bU);
  ASSERT (rotr16 (0x5e1aU, 28) == 0xe1a5U);
  ASSERT (rotr16 (0x5e1aU, 29) == 0xf0d2U);
  ASSERT (rotr16 (0x5e1aU, 30) == 0x7869U);
  ASSERT (rotr16 (0x5e1aU, 31) == 0xbc34U);
  ASSERT (rotr16 (0x5e1aU, 32) == 0x5e1aU);
}

static void
test_rotr32 (void)
{
  ASSERT (rotr32 (0x51af3678UL, 0) == 0x51af3678UL);
  ASSERT (rotr32 (0x51af3678UL, 1) == 0x28d79b3cUL);
  ASSERT (rotr32 (0x51af3678UL, 2) == 0x146bcd9eUL);
  ASSERT (rotr32 (0x51af3678UL, 3) == 0x0a35e6cfUL);
  ASSERT (rotr32 (0x51af3678UL, 4) == 0x851af367UL);
  ASSERT (rotr32 (0x51af3678UL, 5) == 0xc28d79b3UL);
  ASSERT (rotr32 (0x51af3678UL, 6) == 0xe146bcd9UL);
  ASSERT (rotr32 (0x51af3678UL, 7) == 0xf0a35e6cUL);
  ASSERT (rotr32 (0x51af3678UL, 8) == 0x7851af36UL);
  ASSERT (rotr32 (0x51af3678UL, 9) == 0x3c28d79bUL);
  ASSERT (rotr32 (0x51af3678UL, 10) == 0x9e146bcdUL);
  ASSERT (rotr32 (0x51af3678UL, 11) == 0xcf0a35e6UL);
  ASSERT (rotr32 (0x51af3678UL, 12) == 0x67851af3UL);
  ASSERT (rotr32 (0x51af3678UL, 13) == 0xb3c28d79UL);
  ASSERT (rotr32 (0x51af3678UL, 14) == 0xd9e146bcUL);
  ASSERT (rotr32 (0x51af3678UL, 15) == 0x6cf0a35eUL);
  ASSERT (rotr32 (0x51af3678UL, 16) == 0x367851afUL);
  ASSERT (rotr32 (0x51af3678UL, 17) == 0x9b3c28d7UL);
  ASSERT (rotr32 (0x51af3678UL, 18) == 0xcd9e146bUL);
  ASSERT (rotr32 (0x51af3678UL, 19) == 0xe6cf0a35UL);
  ASSERT (rotr32 (0x51af3678UL, 20) == 0xf367851aUL);
  ASSERT (rotr32 (0x51af3678UL, 21) == 0x79b3c28dUL);
  ASSERT (rotr32 (0x51af3678UL, 22) == 0xbcd9e146UL);
  ASSERT (rotr32 (0x51af3678UL, 23) == 0x5e6cf0a3UL);
  ASSERT (rotr32 (0x51af3678UL, 24) == 0xaf367851UL);
  ASSERT (rotr32 (0x51af3678UL, 25) == 0xd79b3c28UL);
  ASSERT (rotr32 (0x51af3678UL, 26) == 0x6bcd9e14UL);
  ASSERT (rotr32 (0x51af3678UL, 27) == 0x35e6cf0aUL);
  ASSERT (rotr32 (0x51af3678UL, 28) == 0x1af36785UL);
  ASSERT (rotr32 (0x51af3678UL, 29) == 0x8d79b3c2UL);
  ASSERT (rotr32 (0x51af3678UL, 30) == 0x46bcd9e1UL);
  ASSERT (rotr32 (0x51af3678UL, 31) == 0xa35e6cf0UL);
  ASSERT (rotr32 (0x51af3678UL, 32) == 0x51af3678UL);
  ASSERT (rotr32 (0x51af3678UL, 33) == 0x28d79b3cUL);
  ASSERT (rotr32 (0x51af3678UL, 34) == 0x146bcd9eUL);
  ASSERT (rotr32 (0x51af3678UL, 35) == 0x0a35e6cfUL);
  ASSERT (rotr32 (0x51af3678UL, 36) == 0x851af367UL);
  ASSERT (rotr32 (0x51af3678UL, 37) == 0xc28d79b3UL);
  ASSERT (rotr32 (0x51af3678UL, 38) == 0xe146bcd9UL);
  ASSERT (rotr32 (0x51af3678UL, 39) == 0xf0a35e6cUL);
  ASSERT (rotr32 (0x51af3678UL, 40) == 0x7851af36UL);
  ASSERT (rotr32 (0x51af3678UL, 41) == 0x3c28d79bUL);
  ASSERT (rotr32 (0x51af3678UL, 42) == 0x9e146bcdUL);
  ASSERT (rotr32 (0x51af3678UL, 43) == 0xcf0a35e6UL);
  ASSERT (rotr32 (0x51af3678UL, 44) == 0x67851af3UL);
  ASSERT (rotr32 (0x51af3678UL, 45) == 0xb3c28d79UL);
  ASSERT (rotr32 (0x51af3678UL, 46) == 0xd9e146bcUL);
  ASSERT (rotr32 (0x51af3678UL, 47) == 0x6cf0a35eUL);
  ASSERT (rotr32 (0x51af3678UL, 48) == 0x367851afUL);
  ASSERT (rotr32 (0x51af3678UL, 49) == 0x9b3c28d7UL);
  ASSERT (rotr32 (0x51af3678UL, 50) == 0xcd9e146bUL);
  ASSERT (rotr32 (0x51af3678UL, 51) == 0xe6cf0a35UL);
  ASSERT (rotr32 (0x51af3678UL, 52) == 0xf367851aUL);
  ASSERT (rotr32 (0x51af3678UL, 53) == 0x79b3c28dUL);
  ASSERT (rotr32 (0x51af3678UL, 54) == 0xbcd9e146UL);
  ASSERT (rotr32 (0x51af3678UL, 55) == 0x5e6cf0a3UL);
  ASSERT (rotr32 (0x51af3678UL, 56) == 0xaf367851UL);
  ASSERT (rotr32 (0x51af3678UL, 57) == 0xd79b3c28UL);
  ASSERT (rotr32 (0x51af3678UL, 58) == 0x6bcd9e14UL);
  ASSERT (rotr32 (0x51af3678UL, 59) == 0x35e6cf0aUL);
  ASSERT (rotr32 (0x51af3678UL, 60) == 0x1af36785UL);
  ASSERT (rotr32 (0x51af3678UL, 61) == 0x8d79b3c2UL);
  ASSERT (rotr32 (0x51af3678UL, 62) == 0x46bcd9e1UL);
  ASSERT (rotr32 (0x51af3678UL, 63) == 0xa35e6cf0UL);
  ASSERT (rotr32 (0x51af3678UL, 64) == 0x51af3678UL);
}

static void
test_rotr64 (void)
{
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 0) == 0x59ae28915a84db37ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 1) == 0xacd71448ad426d9bULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 2) == 0xd66b8a2456a136cdULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 3) == 0xeb35c5122b509b66ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 4) == 0x759ae28915a84db3ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 5) == 0xbacd71448ad426d9ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 6) == 0xdd66b8a2456a136cULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 7) == 0x6eb35c5122b509b6ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 8) == 0x3759ae28915a84dbULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 9) == 0x9bacd71448ad426dULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 10) == 0xcdd66b8a2456a136ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 11) == 0x66eb35c5122b509bULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 12) == 0xb3759ae28915a84dULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 13) == 0xd9bacd71448ad426ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 14) == 0x6cdd66b8a2456a13ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 15) == 0xb66eb35c5122b509ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 16) == 0xdb3759ae28915a84ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 17) == 0x6d9bacd71448ad42ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 18) == 0x36cdd66b8a2456a1ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 19) == 0x9b66eb35c5122b50ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 20) == 0x4db3759ae28915a8ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 21) == 0x26d9bacd71448ad4ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 22) == 0x136cdd66b8a2456aULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 23) == 0x09b66eb35c5122b5ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 24) == 0x84db3759ae28915aULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 25) == 0x426d9bacd71448adULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 26) == 0xa136cdd66b8a2456ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 27) == 0x509b66eb35c5122bULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 28) == 0xa84db3759ae28915ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 29) == 0xd426d9bacd71448aULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 30) == 0x6a136cdd66b8a245ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 31) == 0xb509b66eb35c5122ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 32) == 0x5a84db3759ae2891ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 33) == 0xad426d9bacd71448ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 34) == 0x56a136cdd66b8a24ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 35) == 0x2b509b66eb35c512ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 36) == 0x15a84db3759ae289ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 37) == 0x8ad426d9bacd7144ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 38) == 0x456a136cdd66b8a2ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 39) == 0x22b509b66eb35c51ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 40) == 0x915a84db3759ae28ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 41) == 0x48ad426d9bacd714ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 42) == 0x2456a136cdd66b8aULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 43) == 0x122b509b66eb35c5ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 44) == 0x8915a84db3759ae2ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 45) == 0x448ad426d9bacd71ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 46) == 0xa2456a136cdd66b8ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 47) == 0x5122b509b66eb35cULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 48) == 0x28915a84db3759aeULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 49) == 0x1448ad426d9bacd7ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 50) == 0x8a2456a136cdd66bULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 51) == 0xc5122b509b66eb35ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 52) == 0xe28915a84db3759aULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 53) == 0x71448ad426d9bacdULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 54) == 0xb8a2456a136cdd66ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 55) == 0x5c5122b509b66eb3ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 56) == 0xae28915a84db3759ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 57) == 0xd71448ad426d9bacULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 58) == 0x6b8a2456a136cdd6ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 59) == 0x35c5122b509b66ebULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 60) == 0x9ae28915a84db375ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 61) == 0xcd71448ad426d9baULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 62) == 0x66b8a2456a136cddULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 63) == 0xb35c5122b509b66eULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 64) == 0x59ae28915a84db37ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 65) == 0xacd71448ad426d9bULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 66) == 0xd66b8a2456a136cdULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 67) == 0xeb35c5122b509b66ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 68) == 0x759ae28915a84db3ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 69) == 0xbacd71448ad426d9ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 70) == 0xdd66b8a2456a136cULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 71) == 0x6eb35c5122b509b6ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 72) == 0x3759ae28915a84dbULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 73) == 0x9bacd71448ad426dULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 74) == 0xcdd66b8a2456a136ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 75) == 0x66eb35c5122b509bULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 76) == 0xb3759ae28915a84dULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 77) == 0xd9bacd71448ad426ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 78) == 0x6cdd66b8a2456a13ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 79) == 0xb66eb35c5122b509ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 80) == 0xdb3759ae28915a84ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 81) == 0x6d9bacd71448ad42ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 82) == 0x36cdd66b8a2456a1ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 83) == 0x9b66eb35c5122b50ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 84) == 0x4db3759ae28915a8ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 85) == 0x26d9bacd71448ad4ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 86) == 0x136cdd66b8a2456aULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 87) == 0x09b66eb35c5122b5ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 88) == 0x84db3759ae28915aULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 89) == 0x426d9bacd71448adULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 90) == 0xa136cdd66b8a2456ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 91) == 0x509b66eb35c5122bULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 92) == 0xa84db3759ae28915ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 93) == 0xd426d9bacd71448aULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 94) == 0x6a136cdd66b8a245ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 95) == 0xb509b66eb35c5122ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 96) == 0x5a84db3759ae2891ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 97) == 0xad426d9bacd71448ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 98) == 0x56a136cdd66b8a24ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 99) == 0x2b509b66eb35c512ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 100) == 0x15a84db3759ae289ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 101) == 0x8ad426d9bacd7144ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 102) == 0x456a136cdd66b8a2ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 103) == 0x22b509b66eb35c51ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 104) == 0x915a84db3759ae28ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 105) == 0x48ad426d9bacd714ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 106) == 0x2456a136cdd66b8aULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 107) == 0x122b509b66eb35c5ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 108) == 0x8915a84db3759ae2ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 109) == 0x448ad426d9bacd71ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 110) == 0xa2456a136cdd66b8ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 111) == 0x5122b509b66eb35cULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 112) == 0x28915a84db3759aeULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 113) == 0x1448ad426d9bacd7ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 114) == 0x8a2456a136cdd66bULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 115) == 0xc5122b509b66eb35ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 116) == 0xe28915a84db3759aULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 117) == 0x71448ad426d9bacdULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 118) == 0xb8a2456a136cdd66ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 119) == 0x5c5122b509b66eb3ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 120) == 0xae28915a84db3759ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 121) == 0xd71448ad426d9bacULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 122) == 0x6b8a2456a136cdd6ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 123) == 0x35c5122b509b66ebULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 124) == 0x9ae28915a84db375ULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 125) == 0xcd71448ad426d9baULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 126) == 0x66b8a2456a136cddULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 127) == 0xb35c5122b509b66eULL);
  ASSERT (rotr64 (0x59ae28915a84db37ULL, 128) == 0x59ae28915a84db37ULL);
}
