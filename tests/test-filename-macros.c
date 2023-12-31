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

#include <stdio.h>
#include <stdlib.h>

#include "filename.h"
#include "test-help.h"

static void test_filename_is_dirsep (void);
static void test_filename_is_listsep (void);
static void test_filename_has_drive_prefix (void);
static void test_filename_is_absolute (void);
static void test_filename_is_relative (void);

int
main (void)
{
  test_filename_is_dirsep ();
  test_filename_is_listsep ();
  test_filename_has_drive_prefix ();
  test_filename_is_absolute ();
  test_filename_is_relative ();
  return 0;
}

static void
test_filename_is_dirsep (void)
{
#if defined(_WIN32)
  ASSERT (FILENAME_IS_DIRSEP ('/'));
  ASSERT (FILENAME_IS_DIRSEP ('\\'));
#else
  ASSERT (FILENAME_IS_DIRSEP ('/'));
  ASSERT (!FILENAME_IS_DIRSEP ('\\'));
#endif
}

static void
test_filename_is_listsep (void)
{
#if defined(_WIN32)
  ASSERT (!FILENAME_IS_LISTSEP (':'));
  ASSERT (FILENAME_IS_LISTSEP (';'));
#else
  ASSERT (FILENAME_IS_LISTSEP (':'));
  ASSERT (!FILENAME_IS_LISTSEP (';'));
#endif
}

static void
test_filename_has_drive_prefix (void)
{
#if defined(_WIN32)
  ASSERT (FILENAME_HAS_DRIVE_PREFIX ("c:/dir1/dir2/"));
  ASSERT (FILENAME_HAS_DRIVE_PREFIX ("C:/dir1/dir2/"));
  ASSERT (FILENAME_HAS_DRIVE_PREFIX ("c:\\dir1\\dir2\\"));
  ASSERT (FILENAME_HAS_DRIVE_PREFIX ("C:\\dir1\\dir2\\"));
  ASSERT (!FILENAME_HAS_DRIVE_PREFIX ("c/dir1/dir2/"));
  ASSERT (!FILENAME_HAS_DRIVE_PREFIX ("C/dir1/dir2/"));
  ASSERT (!FILENAME_HAS_DRIVE_PREFIX ("c\\dir1\\dir2\\"));
  ASSERT (!FILENAME_HAS_DRIVE_PREFIX ("C\\dir1\\dir2\\"));
#else
  ASSERT (!FILENAME_HAS_DRIVE_PREFIX ("c:/dir1/dir2/"));
  ASSERT (!FILENAME_HAS_DRIVE_PREFIX ("C:/dir1/dir2/"));
  ASSERT (!FILENAME_HAS_DRIVE_PREFIX ("c:\\dir1\\dir2\\"));
  ASSERT (!FILENAME_HAS_DRIVE_PREFIX ("C:\\dir1\\dir2\\"));
  ASSERT (!FILENAME_HAS_DRIVE_PREFIX ("c/dir1/dir2/"));
  ASSERT (!FILENAME_HAS_DRIVE_PREFIX ("C/dir1/dir2/"));
  ASSERT (!FILENAME_HAS_DRIVE_PREFIX ("c\\dir1\\dir2\\"));
  ASSERT (!FILENAME_HAS_DRIVE_PREFIX ("C\\dir1\\dir2\\"));
#endif
}

static void
test_filename_is_absolute (void)
{
#if defined(_WIN32)
  ASSERT (FILENAME_IS_ABSOLUTE ("/"));
  ASSERT (FILENAME_IS_ABSOLUTE ("/a"));
  ASSERT (FILENAME_IS_ABSOLUTE ("/a/"));
  ASSERT (FILENAME_IS_ABSOLUTE ("/a/b"));
  ASSERT (FILENAME_IS_ABSOLUTE ("/a/b/c"));
  ASSERT (FILENAME_IS_ABSOLUTE ("\\"));
  ASSERT (FILENAME_IS_ABSOLUTE ("\\a"));
  ASSERT (FILENAME_IS_ABSOLUTE ("\\a/"));
  ASSERT (FILENAME_IS_ABSOLUTE ("\\a/b"));
  ASSERT (FILENAME_IS_ABSOLUTE ("\\a/b/c"));
  ASSERT (FILENAME_IS_ABSOLUTE ("d:/"));
  ASSERT (FILENAME_IS_ABSOLUTE ("d:/a"));
  ASSERT (FILENAME_IS_ABSOLUTE ("d:/a/"));
  ASSERT (FILENAME_IS_ABSOLUTE ("d:/a/b"));
  ASSERT (FILENAME_IS_ABSOLUTE ("d:/a/b/c"));
  ASSERT (FILENAME_IS_ABSOLUTE ("c:\\"));
  ASSERT (FILENAME_IS_ABSOLUTE ("c:\\a"));
  ASSERT (FILENAME_IS_ABSOLUTE ("C:\\a/"));
  ASSERT (FILENAME_IS_ABSOLUTE ("C:\\a/b"));
  ASSERT (FILENAME_IS_ABSOLUTE ("C:\\a/b/c"));
  ASSERT (!FILENAME_IS_ABSOLUTE (""));
  ASSERT (!FILENAME_IS_ABSOLUTE ("a"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("a/"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("a/b"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("a/b/c"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("d:"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("d:a"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("d:a/"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("c:a/b"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("c:a/b/c"));
#else
  ASSERT (FILENAME_IS_ABSOLUTE ("/"));
  ASSERT (FILENAME_IS_ABSOLUTE ("/a"));
  ASSERT (FILENAME_IS_ABSOLUTE ("/a/"));
  ASSERT (FILENAME_IS_ABSOLUTE ("/a/b"));
  ASSERT (FILENAME_IS_ABSOLUTE ("/a/b/c"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("\\"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("\\a"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("\\a/"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("\\a/b"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("\\a/b/c"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("d:/"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("d:/a"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("d:/a/"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("d:/a/b"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("d:/a/b/c"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("c:\\"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("c:\\a"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("C:\\a/"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("C:\\a/b"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("C:\\a/b/c"));
  ASSERT (!FILENAME_IS_ABSOLUTE (""));
  ASSERT (!FILENAME_IS_ABSOLUTE ("a"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("a/"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("a/b"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("a/b/c"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("d:"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("d:a"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("d:a/"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("c:a/b"));
  ASSERT (!FILENAME_IS_ABSOLUTE ("c:a/b/c"));
#endif
}

static void
test_filename_is_relative (void)
{
#if defined(_WIN32)
  ASSERT (!FILENAME_IS_RELATIVE ("/"));
  ASSERT (!FILENAME_IS_RELATIVE ("/a"));
  ASSERT (!FILENAME_IS_RELATIVE ("/a/"));
  ASSERT (!FILENAME_IS_RELATIVE ("/a/b"));
  ASSERT (!FILENAME_IS_RELATIVE ("/a/b/c"));
  ASSERT (!FILENAME_IS_RELATIVE ("\\"));
  ASSERT (!FILENAME_IS_RELATIVE ("\\a"));
  ASSERT (!FILENAME_IS_RELATIVE ("\\a/"));
  ASSERT (!FILENAME_IS_RELATIVE ("\\a/b"));
  ASSERT (!FILENAME_IS_RELATIVE ("\\a/b/c"));
  ASSERT (!FILENAME_IS_RELATIVE ("c:/"));
  ASSERT (!FILENAME_IS_RELATIVE ("c:/a"));
  ASSERT (!FILENAME_IS_RELATIVE ("c:/a/"));
  ASSERT (!FILENAME_IS_RELATIVE ("C:/a/b"));
  ASSERT (!FILENAME_IS_RELATIVE ("C:/a/b/c"));
  ASSERT (!FILENAME_IS_RELATIVE ("C:\\"));
  ASSERT (!FILENAME_IS_RELATIVE ("d:\\a"));
  ASSERT (!FILENAME_IS_RELATIVE ("d:\\a/"));
  ASSERT (!FILENAME_IS_RELATIVE ("d:\\a/b"));
  ASSERT (!FILENAME_IS_RELATIVE ("d:\\a/b/c"));
  ASSERT (!FILENAME_IS_RELATIVE ("c:"));
  ASSERT (!FILENAME_IS_RELATIVE ("c:a"));
  ASSERT (!FILENAME_IS_RELATIVE ("c:a/"));
  ASSERT (!FILENAME_IS_RELATIVE ("C:a/b"));
  ASSERT (!FILENAME_IS_RELATIVE ("C:a/b/c"));
  ASSERT (!FILENAME_IS_RELATIVE ("C:"));
  ASSERT (!FILENAME_IS_RELATIVE ("d:a"));
  ASSERT (!FILENAME_IS_RELATIVE ("d:a/"));
  ASSERT (!FILENAME_IS_RELATIVE ("d:a/b"));
  ASSERT (!FILENAME_IS_RELATIVE ("d:a/b/c"));
  ASSERT (FILENAME_IS_RELATIVE (""));
  ASSERT (FILENAME_IS_RELATIVE ("a"));
  ASSERT (FILENAME_IS_RELATIVE ("a/"));
  ASSERT (FILENAME_IS_RELATIVE ("a/b"));
  ASSERT (FILENAME_IS_RELATIVE ("a/b/c"));
#else
  ASSERT (!FILENAME_IS_RELATIVE ("/"));
  ASSERT (!FILENAME_IS_RELATIVE ("/a"));
  ASSERT (!FILENAME_IS_RELATIVE ("/a/"));
  ASSERT (!FILENAME_IS_RELATIVE ("/a/b"));
  ASSERT (!FILENAME_IS_RELATIVE ("/a/b/c"));
  ASSERT (FILENAME_IS_RELATIVE ("\\"));
  ASSERT (FILENAME_IS_RELATIVE ("\\a"));
  ASSERT (FILENAME_IS_RELATIVE ("\\a/"));
  ASSERT (FILENAME_IS_RELATIVE ("\\a/b"));
  ASSERT (FILENAME_IS_RELATIVE ("\\a/b/c"));
  ASSERT (FILENAME_IS_RELATIVE ("c:/"));
  ASSERT (FILENAME_IS_RELATIVE ("c:/a"));
  ASSERT (FILENAME_IS_RELATIVE ("c:/a/"));
  ASSERT (FILENAME_IS_RELATIVE ("C:/a/b"));
  ASSERT (FILENAME_IS_RELATIVE ("C:/a/b/c"));
  ASSERT (FILENAME_IS_RELATIVE ("C:\\"));
  ASSERT (FILENAME_IS_RELATIVE ("d:\\a"));
  ASSERT (FILENAME_IS_RELATIVE ("d:\\a/"));
  ASSERT (FILENAME_IS_RELATIVE ("d:\\a/b"));
  ASSERT (FILENAME_IS_RELATIVE ("d:\\a/b/c"));
  ASSERT (FILENAME_IS_RELATIVE ("c:"));
  ASSERT (FILENAME_IS_RELATIVE ("c:a"));
  ASSERT (FILENAME_IS_RELATIVE ("c:a/"));
  ASSERT (FILENAME_IS_RELATIVE ("C:a/b"));
  ASSERT (FILENAME_IS_RELATIVE ("C:a/b/c"));
  ASSERT (FILENAME_IS_RELATIVE ("C:"));
  ASSERT (FILENAME_IS_RELATIVE ("d:a"));
  ASSERT (FILENAME_IS_RELATIVE ("d:a/"));
  ASSERT (FILENAME_IS_RELATIVE ("d:a/b"));
  ASSERT (FILENAME_IS_RELATIVE ("d:a/b/c"));
  ASSERT (FILENAME_IS_RELATIVE (""));
  ASSERT (FILENAME_IS_RELATIVE ("a"));
  ASSERT (FILENAME_IS_RELATIVE ("a/"));
  ASSERT (FILENAME_IS_RELATIVE ("a/b"));
  ASSERT (FILENAME_IS_RELATIVE ("a/b/c"));
#endif
}
