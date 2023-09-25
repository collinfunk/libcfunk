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

#ifndef FILENAME_H
#define FILENAME_H

/* Macros and functions for dealing with filenames. */

/* Windows file path format documentation:
   https://learn.microsoft.com/en-us/windows/win32/fileio/naming-a-file
   https://learn.microsoft.com/en-us/dotnet/standard/io/file-path-formats */

#include <stdbool.h>

/* Macros:
   int FILENAME_NATIVE_DIRSEP
     This is the most natural directory separator for the current platform.
     For Windows this means '\' instead of '/' which everything else uses.
     This macro should not be used for comparison. See FILENAME_IS_DIRSEP.
   bool FILENAME_IS_DIRSEP(ch)
     Returns true if CH is a character that joins pathname components.
   bool FILENAME_IS_LISTSEP(ch)
     Returns true if CH is a character used to separate a list of files such
     as $PATH.
   bool FILENAME_HAS_DRIVE_PREFIX(str)
     Returns true if STR has a DOS style volume prefix. Valid volume prefixes
     are A: to Z: case insensitive. It is possible on some versions of
     DOS/Windows to use other prefixes but it is not supported.
   bool FILENAME_IS_ABSOLUTE(str)
     Returns true if STR is an absolute file path. For Windows, this returns
     true if STR is an absolute path (c:/folder/file.txt) or if it is a path
     relative to the current drive letter (/folder/file.txt).
   bool FILENAME_IS_RELATIVE(str)
     Returns true if STR is a relative file path. For Windows, this returns
     true if STR is a path relative to the current working directory
     (folder/file.txt) or if it is a relative path to the current directory
     of a drive letter (c:folder/file.txt).
 */
#if defined(_WIN32)
#  define FILENAME_NATIVE_DIRSEP '\\'
#  define FILENAME_IS_DIRSEP(ch) ((ch) == '/' || (ch) == '\\')
#  define FILENAME_IS_LISTSEP(ch) ((ch) == ';')
#  define FILENAME_HAS_DRIVE_PREFIX(str)                                      \
    ((((str)[0] >= 'A' && (str)[0] <= 'Z')                                    \
      || ((str)[0] >= 'a' && (str)[0] <= 'z'))                                \
     && ((str)[1] == ':'))
#  define FILENAME_IS_ABSOLUTE(str)                                           \
    FILENAME_IS_DIRSEP ((str)[FILENAME_HAS_DRIVE_PREFIX (str) ? 2 : 0])
#  define FILENAME_IS_RELATIVE(str)                                           \
    ((!FILENAME_HAS_DRIVE_PREFIX (str)) && (!FILENAME_IS_DIRSEP ((str)[0])))
#else
#  define FILENAME_NATIVE_DIRSEP '/'
#  define FILENAME_IS_DIRSEP(ch) ((ch) == '/')
#  define FILENAME_IS_LISTSEP(ch) ((ch) == ':')
#  define FILENAME_HAS_DRIVE_PREFIX(str) (0)
#  define FILENAME_IS_ABSOLUTE(str) FILENAME_IS_DIRSEP ((str)[0])
#  define FILENAME_IS_RELATIVE(str) (!FILENAME_IS_DIRSEP ((str)[0]))
#endif

/* Truncates filename at the last '.' character which is not part of a directory
   component of FILE_NAME. Returns true if a '\0' was placed over '.'. */
extern bool filename_strip_extension (char *file_name);

/* Strip trailing slashes in FILE_NAME and return the number removed. */
extern int filename_strip_slashes (char *file_name);

/* Returns a pointer to the last directory component of FILE_NAME. The input
   string is not modified. */
extern const char *filename_last_component (const char *file_name);

/* Allocate a string containing the FILE_NAME with extension added to
   the end. If EXTENSION is a NULL pointer or an empty string, this function
   has the same behavior as strdup (FILE_NAME). */
extern char *filename_join_extension (const char *file_name,
                                      const char *extension);

/* Allocate a string containing the FILE_NAME with the DIRECTORY added as a
   prefix. If DIRECTORY is a NULL pointer, empty string, or "." this function
   has the same behavior as strdup (FILE_NAME). If the given directory does
   not have a trailing slash then one is added. In other words, these two
   calls are equivalent:

     filename_join_directory ("/bin/", "sh") -> "/bin/sh"
     filename_join_directory ("/bin", "sh") -> "/bin/sh"

   The exception to this rule is Windows drive prefixes. On Windows, the
   file name "C:dir\file" is a relative path from the current working
   directory of the C drive. However, the file name "C:\dir\file" is
   an absolute path from the root of the C drive. This function respects
   this difference as shown in these calls:

     filename_join_directory ("C:", "dir")        -> "C:dir"
     filename_join_directory ("C:\\", "dir")      -> "C:\dir"
     filename_join_directory ("C:\\dir", "file"   -> "C:\dir\file"
     filename_join_directory ("C:\\dir\\", "file" -> "C:\dir\file"
 */
extern char *filename_join_directory (const char *directory,
                                      const char *file_name);

#endif /* FILENAME_H */
