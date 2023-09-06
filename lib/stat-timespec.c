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
#include <sys/time.h>
#include <sys/types.h>

#include <time.h>

struct timespec
stat_get_atime_timespec (struct stat *st)
{
#if HAVE_STRUCT_STAT_ST_ATIM_TIMESPEC_TV_NSEC
  return st->st_atim;
#elif HAVE_STRUCT_STAT_ST_ATIMESPEC
  return st->st_atimespec;
#else
  struct timespec ts;
  ts.tv_sec = st->st_atime;
  ts.tv_nsec = 0;
  return ts;
#endif
}

struct timespec
stat_get_ctime_timespec (struct stat *st)
{
#if HAVE_STRUCT_STAT_ST_CTIM_TIMESPEC_TV_NSEC
  return st->st_ctim;
#elif HAVE_STRUCT_STAT_ST_CTIMESPEC
  return st->st_ctimespec;
#else
  struct timespec ts;
  ts.tv_sec = st->st_ctime;
  ts.tv_nsec = 0;
  return ts;
#endif
}

struct timespec
stat_get_mtime_timespec (struct stat *st)
{
#if HAVE_STRUCT_STAT_ST_MTIM_TIMESPEC_TV_NSEC
  return st->st_mtim;
#elif HAVE_STRUCT_STAT_ST_MTIMESPEC
  return st->st_mtimespec;
#else
  struct timespec ts;
  ts.tv_sec = st->st_mtime;
  ts.tv_nsec = 0;
  return ts;
#endif
}
