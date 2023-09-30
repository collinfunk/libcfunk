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

#ifndef BLOCK_SIZE_H
#define BLOCK_SIZE_H

#include <config.h>

#undef DEV_BSIZE
#undef ST_BLKSIZE
#undef ST_BLOCKS

/* BSD, GNU libc, etc. */
#if HAVE_SYS_PARAM_H
#  include <sys/param.h>
#endif

#include <sys/stat.h>

/* Find a definition for DEV_BSIZE. If it can't be found just guess 512. */
#ifndef DEV_BSIZE
#  ifdef BSIZE
#    define DEV_BSIZE BSIZE
#  else
#    define DEV_BSIZE 512
#  endif
#endif

/* Define S_BLKSIZE if it is not defined. This is the number of bytes
   in the 'st_blocks' member of 'struct stat' if it is available. */
#ifndef S_BLKSIZE
#  define S_BLKSIZE 512
#endif

/* This macro allows for access of the 'st_blksize' member of 'struct stat'.
   Since this is an XSI extension it is not supported everywhere. If it is not
   supported then just return DEV_BSIZE. */
#if HAVE_STRUCT_STAT_ST_BLKSIZE
#  define ST_BLKSIZE(st) ((st).st_blksize)
#else
#  define ST_BLKSIZE(st) DEV_BSIZE
#endif

/* This macro allows for access of the 'st_blocks' member of 'struct stat'.
   If it is not supported then the file size and S_BLKSIZE macro is used to
   calculate the number of blocks used. */
#if HAVE_STRUCT_STAT_ST_BLOCKS
#  define ST_BLOCKS(st) ((st).st_blocks)
#else
#  define ST_BLOCKS(st)                                                       \
    (((st).st_size / S_BLKSIZE) + (((st).st_size % S_BLKSIZE) != 0))
#endif

#endif /* BLOCK_SIZE_H */
