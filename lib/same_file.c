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
#include <sys/types.h>

#if HAVE_WINDOWS_H
#  include <windows.h>
#endif

#include "same_file.h"
#include "same_inode.h"

/* https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilea */
/* https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfileinformationbyhandle */
/* https://learn.microsoft.com/en-us/windows/win32/api/fileapi/ns-fileapi-by_handle_file_information */
bool
same_file (const char *file1, const char *file2)
{
#if !HAVE_WINDOWS_H
  {
    struct stat stat_buffer1, stat_buffer2;

    if (stat (file1, &stat_buffer1) < 0 || stat (file2, &stat_buffer2) < 0)
      return false;

    return SAME_INODE (stat_buffer1, stat_buffer2);
  }
#else
  {
    HANDLE file_handle1, file_handle2;
    BY_HANDLE_FILE_INFORMATION file_info1, file_info2;

    file_handle1
        = CreateFile (file1, FILE_READ_ATTRIBUTES,
                      FILE_SHARE_DELETE | FILE_SHARE_READ | FILE_SHARE_WRITE,
                      NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
    if (file_handle1 == INVALID_HANDLE_VALUE)
      return false;

    file_handle2
        = CreateFile (file2, FILE_READ_ATTRIBUTES,
                      FILE_SHARE_DELETE | FILE_SHARE_READ | FILE_SHARE_WRITE,
                      NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
    if (file_handle2 == INVALID_HANDLE_VALUE)
      return false;

    if (!GetFileInformationByHandle (file_handle1, &file_info1)
        || !GetFileInformationByHandle (file_handle2, &file_info2))
      return false;

    return file_info1.dwFileAttributes == file_info2.dwFileAttributes
           && file_info1.ftCreationTime.dwLowDateTime
                  == file_info2.ftCreationTime.dwLowDateTime
           && file_info1.ftCreationTime.dwHighDateTime
                  == file_info2.ftCreationTime.dwHighDateTime
           && file_info1.ftLastAccessTime.dwLowDateTime
                  == file_info2.ftLastAccessTime.dwLowDateTime
           && file_info1.ftLastAccessTime.dwHighDateTime
                  == file_info2.ftLastAccessTime.dwHighDateTime
           && file_info1.ftLastWriteTime.dwLowDateTime
                  == file_info2.ftLastWriteTime.dwLowDateTime
           && file_info1.ftLastWriteTime.dwHighDateTime
                  == file_info2.ftLastWriteTime.dwHighDateTime
           && file_info1.dwVolumeSerialNumber
                  == file_info2.dwVolumeSerialNumber
           && file_info1.nFileSizeLow == file_info2.nFileSizeLow
           && file_info1.nFileSizeHigh == file_info2.nFileSizeHigh
           && file_info1.nNumberOfLinks == file_info2.nNumberOfLinks
           && file_info1.nFileIndexLow == file_info2.nFileIndexLow
           && file_info1.nFileIndexHigh == file_info2.nFileIndexHigh;
  }
#endif
}
