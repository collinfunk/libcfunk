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

#include <sys/types.h>

#include "attributes.h"

static void test_blkcnt_t_defined (void);
static void test_blksize_t_defined (void);
static void test_dev_t_defined (void);
static void test_gid_t_defined (void);
static void test_ino_t_defined (void);
static void test_mode_t_defined (void);
static void test_nlink_t_defined (void);
static void test_off_t_defined (void);
static void test_pid_t_defined (void);
static void test_size_t_defined (void);
static void test_ssize_t_defined (void);
static void test_suseconds_t_defined (void);
static void test_uid_t_defined (void);
static void test_useconds_t_defined (void);

/* Make sure that 'sys/types.h' can be included. */
int
main (void)
{
  test_blkcnt_t_defined ();
  test_blksize_t_defined ();
  test_dev_t_defined ();
  test_gid_t_defined ();
  test_ino_t_defined ();
  test_mode_t_defined ();
  test_nlink_t_defined ();
  test_off_t_defined ();
  test_pid_t_defined ();
  test_size_t_defined ();
  test_ssize_t_defined ();
  test_suseconds_t_defined ();
  test_uid_t_defined ();
  test_useconds_t_defined ();
  return 0;
}

static void
test_blkcnt_t_defined (void)
{
  blkcnt_t value ATTRIBUTE_UNUSED;
}

static void
test_blksize_t_defined (void)
{
  blksize_t value ATTRIBUTE_UNUSED;
}

static void
test_dev_t_defined (void)
{
  dev_t value ATTRIBUTE_UNUSED;
}

static void
test_gid_t_defined (void)
{
  gid_t value ATTRIBUTE_UNUSED;
}

static void
test_ino_t_defined (void)
{
  ino_t value ATTRIBUTE_UNUSED;
}

static void
test_mode_t_defined (void)
{
  mode_t value ATTRIBUTE_UNUSED;
}

static void
test_nlink_t_defined (void)
{
  nlink_t value ATTRIBUTE_UNUSED;
}

static void
test_off_t_defined (void)
{
  off_t value ATTRIBUTE_UNUSED;
}

static void
test_pid_t_defined (void)
{
  pid_t value ATTRIBUTE_UNUSED;
}

static void
test_size_t_defined (void)
{
  size_t value ATTRIBUTE_UNUSED;
}

static void
test_ssize_t_defined (void)
{
  ssize_t value ATTRIBUTE_UNUSED;
}

static void
test_suseconds_t_defined (void)
{
  suseconds_t value ATTRIBUTE_UNUSED;
}

static void
test_uid_t_defined (void)
{
  uid_t value ATTRIBUTE_UNUSED;
}

static void
test_useconds_t_defined (void)
{
  useconds_t value ATTRIBUTE_UNUSED;
}
