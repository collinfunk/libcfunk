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

#include <inttypes.h>

#include "attributes.h"

static void test_signed_signed_int_fprintf_macros (void);
static void test_signed_unsigned_int_fprintf_macros (void);
static void test_signed_signed_int_scanf_macros (void);
static void test_signed_unsigned_int_scanf_macros (void);

/* Test that 'inttypes.h' can be included correctly. */
int
main (void)
{
  test_signed_signed_int_fprintf_macros ();
  test_signed_unsigned_int_fprintf_macros ();
  test_signed_signed_int_scanf_macros ();
  test_signed_unsigned_int_scanf_macros ();
  return 0;
}

static void
test_signed_signed_int_fprintf_macros (void)
{
  const char *ptr ATTRIBUTE_UNUSED;

  ptr = PRId8 PRId16 PRId32 PRId64 PRIdLEAST8 PRIdLEAST16 PRIdLEAST32
      PRIdLEAST64 PRIdFAST8 PRIdFAST16 PRIdFAST32 PRIdFAST64 PRIdMAX PRIdPTR
          PRIi8 PRIi16 PRIi32 PRIi64 PRIiLEAST8 PRIiLEAST16 PRIiLEAST32
              PRIiLEAST64 PRIiFAST8 PRIiFAST16 PRIiFAST32 PRIiFAST64 PRIiMAX
                  PRIiPTR;
}

static void
test_signed_unsigned_int_fprintf_macros (void)
{
  const char *ptr ATTRIBUTE_UNUSED;

  ptr = PRIo8 PRIo16 PRIo32 PRIo64 PRIoLEAST8 PRIoLEAST16 PRIoLEAST32
      PRIoLEAST64 PRIoFAST8 PRIoFAST16 PRIoFAST32 PRIoFAST64 PRIoMAX PRIoPTR
          PRIu8 PRIu16 PRIu32 PRIu64 PRIuLEAST8 PRIuLEAST16 PRIuLEAST32
              PRIuLEAST64 PRIuFAST8 PRIuFAST16 PRIuFAST32 PRIuFAST64 PRIuMAX
                  PRIuPTR PRIx8 PRIx16 PRIx32 PRIx64 PRIxLEAST8 PRIxLEAST16
                      PRIxLEAST32 PRIxLEAST64 PRIxFAST8 PRIxFAST16 PRIxFAST32
                          PRIxFAST64 PRIxMAX PRIxPTR PRIX8 PRIX16 PRIX32 PRIX64
                              PRIXLEAST8 PRIXLEAST16 PRIXLEAST32 PRIXLEAST64
                                  PRIXFAST8 PRIXFAST16 PRIXFAST32 PRIXFAST64
                                      PRIXMAX PRIXPTR;
}

static void
test_signed_signed_int_scanf_macros (void)
{
  const char *ptr ATTRIBUTE_UNUSED;

  ptr = SCNd8 SCNd16 SCNd32 SCNd64 SCNdLEAST8 SCNdLEAST16 SCNdLEAST32
      SCNdLEAST64 SCNdFAST8 SCNdFAST16 SCNdFAST32 SCNdFAST64 SCNdMAX SCNdPTR
          SCNi8 SCNi16 SCNi32 SCNi64 SCNiLEAST8 SCNiLEAST16 SCNiLEAST32
              SCNiLEAST64 SCNiFAST8 SCNiFAST16 SCNiFAST32 SCNiFAST64 SCNiMAX
                  SCNiPTR;
}

static void
test_signed_unsigned_int_scanf_macros (void)
{
  const char *ptr ATTRIBUTE_UNUSED;

  ptr = SCNo8 SCNo16 SCNo32 SCNo64 SCNoLEAST8 SCNoLEAST16 SCNoLEAST32
      SCNoLEAST64 SCNoFAST8 SCNoFAST16 SCNoFAST32 SCNoFAST64 SCNoMAX SCNoPTR
          SCNu8 SCNu16 SCNu32 SCNu64 SCNuLEAST8 SCNuLEAST16 SCNuLEAST32
              SCNuLEAST64 SCNuFAST8 SCNuFAST16 SCNuFAST32 SCNuFAST64 SCNuMAX
                  SCNuPTR SCNx8 SCNx16 SCNx32 SCNx64 SCNxLEAST8 SCNxLEAST16
                      SCNxLEAST32 SCNxLEAST64 SCNxFAST8 SCNxFAST16 SCNxFAST32
                          SCNxFAST64 SCNxMAX SCNxPTR;
}
