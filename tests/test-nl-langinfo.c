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

#include <langinfo.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

static void validate_nonnull_items (void);
static void print_all_items (void);

int
main (void)
{
  validate_nonnull_items ();
  print_all_items ();
  return 0;
}

/* Check that each item returns a string. The returned string may be empty
   but not a NULL pointer. */
static void
validate_nonnull_items (void)
{
  ASSERT (nl_langinfo (CODESET) != NULL);
  ASSERT (nl_langinfo (D_T_FMT) != NULL);
  ASSERT (nl_langinfo (D_FMT) != NULL);
  ASSERT (nl_langinfo (T_FMT) != NULL);
  ASSERT (nl_langinfo (T_FMT_AMPM) != NULL);
  ASSERT (nl_langinfo (AM_STR) != NULL);
  ASSERT (nl_langinfo (PM_STR) != NULL);
  ASSERT (nl_langinfo (DAY_1) != NULL);
  ASSERT (nl_langinfo (DAY_2) != NULL);
  ASSERT (nl_langinfo (DAY_3) != NULL);
  ASSERT (nl_langinfo (DAY_4) != NULL);
  ASSERT (nl_langinfo (DAY_5) != NULL);
  ASSERT (nl_langinfo (DAY_6) != NULL);
  ASSERT (nl_langinfo (DAY_7) != NULL);
  ASSERT (nl_langinfo (ABDAY_1) != NULL);
  ASSERT (nl_langinfo (ABDAY_2) != NULL);
  ASSERT (nl_langinfo (ABDAY_3) != NULL);
  ASSERT (nl_langinfo (ABDAY_4) != NULL);
  ASSERT (nl_langinfo (ABDAY_5) != NULL);
  ASSERT (nl_langinfo (ABDAY_6) != NULL);
  ASSERT (nl_langinfo (ABDAY_7) != NULL);
  ASSERT (nl_langinfo (MON_1) != NULL);
  ASSERT (nl_langinfo (MON_2) != NULL);
  ASSERT (nl_langinfo (MON_3) != NULL);
  ASSERT (nl_langinfo (MON_4) != NULL);
  ASSERT (nl_langinfo (MON_5) != NULL);
  ASSERT (nl_langinfo (MON_6) != NULL);
  ASSERT (nl_langinfo (MON_7) != NULL);
  ASSERT (nl_langinfo (MON_8) != NULL);
  ASSERT (nl_langinfo (MON_9) != NULL);
  ASSERT (nl_langinfo (MON_10) != NULL);
  ASSERT (nl_langinfo (MON_11) != NULL);
  ASSERT (nl_langinfo (MON_12) != NULL);
  ASSERT (nl_langinfo (ABMON_1) != NULL);
  ASSERT (nl_langinfo (ABMON_2) != NULL);
  ASSERT (nl_langinfo (ABMON_3) != NULL);
  ASSERT (nl_langinfo (ABMON_4) != NULL);
  ASSERT (nl_langinfo (ABMON_5) != NULL);
  ASSERT (nl_langinfo (ABMON_6) != NULL);
  ASSERT (nl_langinfo (ABMON_7) != NULL);
  ASSERT (nl_langinfo (ABMON_8) != NULL);
  ASSERT (nl_langinfo (ABMON_9) != NULL);
  ASSERT (nl_langinfo (ABMON_10) != NULL);
  ASSERT (nl_langinfo (ABMON_11) != NULL);
  ASSERT (nl_langinfo (ABMON_12) != NULL);
  ASSERT (nl_langinfo (ERA) != NULL);
  ASSERT (nl_langinfo (ERA_D_FMT) != NULL);
  ASSERT (nl_langinfo (ERA_D_T_FMT) != NULL);
  ASSERT (nl_langinfo (ERA_T_FMT) != NULL);
  ASSERT (nl_langinfo (ALT_DIGITS) != NULL);
  ASSERT (nl_langinfo (RADIXCHAR) != NULL);
  ASSERT (nl_langinfo (THOUSEP) != NULL);
  ASSERT (nl_langinfo (YESEXPR) != NULL);
  ASSERT (nl_langinfo (NOEXPR) != NULL);
  ASSERT (nl_langinfo (CRNCYSTR) != NULL);
}

static void
print_all_items (void)
{
  printf ("CODESET: %s\n", nl_langinfo (CODESET));
  printf ("D_T_FMT: %s\n", nl_langinfo (D_T_FMT));
  printf ("D_FMT: %s\n", nl_langinfo (D_FMT));
  printf ("T_FMT: %s\n", nl_langinfo (T_FMT));
  printf ("T_FMT_AMPM: %s\n", nl_langinfo (T_FMT_AMPM));
  printf ("AM_STR: %s\n", nl_langinfo (AM_STR));
  printf ("PM_STR: %s\n", nl_langinfo (PM_STR));
  printf ("DAY_1: %s\n", nl_langinfo (DAY_1));
  printf ("DAY_2: %s\n", nl_langinfo (DAY_2));
  printf ("DAY_3: %s\n", nl_langinfo (DAY_3));
  printf ("DAY_4: %s\n", nl_langinfo (DAY_4));
  printf ("DAY_5: %s\n", nl_langinfo (DAY_5));
  printf ("DAY_6: %s\n", nl_langinfo (DAY_6));
  printf ("DAY_7: %s\n", nl_langinfo (DAY_7));
  printf ("ABDAY_1: %s\n", nl_langinfo (ABDAY_1));
  printf ("ABDAY_2: %s\n", nl_langinfo (ABDAY_2));
  printf ("ABDAY_3: %s\n", nl_langinfo (ABDAY_3));
  printf ("ABDAY_4: %s\n", nl_langinfo (ABDAY_4));
  printf ("ABDAY_5: %s\n", nl_langinfo (ABDAY_5));
  printf ("ABDAY_6: %s\n", nl_langinfo (ABDAY_6));
  printf ("ABDAY_7: %s\n", nl_langinfo (ABDAY_7));
  printf ("MON_1: %s\n", nl_langinfo (MON_1));
  printf ("MON_2: %s\n", nl_langinfo (MON_2));
  printf ("MON_3: %s\n", nl_langinfo (MON_3));
  printf ("MON_4: %s\n", nl_langinfo (MON_4));
  printf ("MON_5: %s\n", nl_langinfo (MON_5));
  printf ("MON_6: %s\n", nl_langinfo (MON_6));
  printf ("MON_7: %s\n", nl_langinfo (MON_7));
  printf ("MON_8: %s\n", nl_langinfo (MON_8));
  printf ("MON_9: %s\n", nl_langinfo (MON_9));
  printf ("MON_10: %s\n", nl_langinfo (MON_10));
  printf ("MON_11: %s\n", nl_langinfo (MON_11));
  printf ("MON_12: %s\n", nl_langinfo (MON_12));
  printf ("ABMON_1: %s\n", nl_langinfo (ABMON_1));
  printf ("ABMON_2: %s\n", nl_langinfo (ABMON_2));
  printf ("ABMON_3: %s\n", nl_langinfo (ABMON_3));
  printf ("ABMON_4: %s\n", nl_langinfo (ABMON_4));
  printf ("ABMON_5: %s\n", nl_langinfo (ABMON_5));
  printf ("ABMON_6: %s\n", nl_langinfo (ABMON_6));
  printf ("ABMON_7: %s\n", nl_langinfo (ABMON_7));
  printf ("ABMON_8: %s\n", nl_langinfo (ABMON_8));
  printf ("ABMON_9: %s\n", nl_langinfo (ABMON_9));
  printf ("ABMON_10: %s\n", nl_langinfo (ABMON_10));
  printf ("ABMON_11: %s\n", nl_langinfo (ABMON_11));
  printf ("ABMON_12: %s\n", nl_langinfo (ABMON_12));
  printf ("ERA: %s\n", nl_langinfo (ERA));
  printf ("ERA_D_FMT: %s\n", nl_langinfo (ERA_D_FMT));
  printf ("ERA_D_T_FMT: %s\n", nl_langinfo (ERA_D_T_FMT));
  printf ("ERA_T_FMT: %s\n", nl_langinfo (ERA_T_FMT));
  printf ("ALT_DIGITS: %s\n", nl_langinfo (ALT_DIGITS));
  printf ("RADIXCHAR: %s\n", nl_langinfo (RADIXCHAR));
  printf ("THOUSEP: %s\n", nl_langinfo (THOUSEP));
  printf ("YESEXPR: %s\n", nl_langinfo (YESEXPR));
  printf ("NOEXPR: %s\n", nl_langinfo (NOEXPR));
  printf ("CRNCYSTR: %s\n", nl_langinfo (CRNCYSTR));
}
