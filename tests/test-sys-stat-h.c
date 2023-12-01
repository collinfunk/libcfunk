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

#include "attributes.h"

static_assert (S_IXOTH == 00001);
static_assert (S_IWOTH == 00002);
static_assert (S_IROTH == 00004);
static_assert (S_IRWXO == 00007);
static_assert (S_IXGRP == 00010);
static_assert (S_IWGRP == 00020);
static_assert (S_IRGRP == 00040);
static_assert (S_IRWXG == 00070);
static_assert (S_IWUSR == 00200);
static_assert (S_IRUSR == 00400);
static_assert (S_IRWXU == 00700);
static_assert (S_IXUSR == 00100);
static_assert (S_ISVTX == 01000);
static_assert (S_ISGID == 02000);
static_assert (S_ISUID == 04000);

static void test_struct_stat_defined (void);

int
main (void)
{
  test_struct_stat_defined ();
  return 0;
}

static void
test_struct_stat_defined (void)
{
  struct stat value ATTRIBUTE_UNUSED;
}
