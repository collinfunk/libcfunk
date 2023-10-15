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
#include <stdio.h>

#include "attributes.h"

/* If the switch statement in 'ensure_unique' causes compilation errors then
   you should define this to 0 and look at the output of 'print_constants'. */
#ifndef ENSURE_UNIQUE
#  define ENSURE_UNIQUE 1
#endif

static void print_constants (void);
static void ensure_unique (void);

int
main (void)
{
  nl_item item ATTRIBUTE_UNUSED;
  print_constants ();
  ensure_unique ();
  return 0;
}

/* Print all constants defined in langinfo.h. */
static void
print_constants (void)
{
  printf ("CODESET:     %d\n", CODESET);
  printf ("D_T_FMT:     %d\n", D_T_FMT);
  printf ("D_FMT:       %d\n", D_FMT);
  printf ("T_FMT:       %d\n", T_FMT);
  printf ("T_FMT_AMPM:  %d\n", T_FMT_AMPM);
  printf ("AM_STR:      %d\n", AM_STR);
  printf ("PM_STR:      %d\n", PM_STR);
  printf ("DAY_1:       %d\n", DAY_1);
  printf ("DAY_2:       %d\n", DAY_2);
  printf ("DAY_3:       %d\n", DAY_3);
  printf ("DAY_4:       %d\n", DAY_4);
  printf ("DAY_5:       %d\n", DAY_5);
  printf ("DAY_6:       %d\n", DAY_6);
  printf ("DAY_7:       %d\n", DAY_7);
  printf ("MON_1:       %d\n", MON_1);
  printf ("MON_2:       %d\n", MON_2);
  printf ("MON_3:       %d\n", MON_3);
  printf ("MON_4:       %d\n", MON_4);
  printf ("MON_5:       %d\n", MON_5);
  printf ("MON_6:       %d\n", MON_6);
  printf ("MON_7:       %d\n", MON_7);
  printf ("MON_8:       %d\n", MON_8);
  printf ("MON_9:       %d\n", MON_9);
  printf ("MON_10:      %d\n", MON_10);
  printf ("MON_11:      %d\n", MON_11);
  printf ("MON_12:      %d\n", MON_12);
  printf ("ABMON_1:     %d\n", ABMON_1);
  printf ("ABMON_2:     %d\n", ABMON_2);
  printf ("ABMON_3:     %d\n", ABMON_3);
  printf ("ABMON_4:     %d\n", ABMON_4);
  printf ("ABMON_5:     %d\n", ABMON_5);
  printf ("ABMON_6:     %d\n", ABMON_6);
  printf ("ABMON_7:     %d\n", ABMON_7);
  printf ("ABMON_8:     %d\n", ABMON_8);
  printf ("ABMON_9:     %d\n", ABMON_9);
  printf ("ABMON_10:    %d\n", ABMON_10);
  printf ("ABMON_11:    %d\n", ABMON_11);
  printf ("ABMON_12:    %d\n", ABMON_12);
  printf ("ERA:         %d\n", ERA);
  printf ("ERA_D_FMT:   %d\n", ERA_D_FMT);
  printf ("ERA_D_T_FMT: %d\n", ERA_D_T_FMT);
  printf ("ERA_T_FMT:   %d\n", ERA_T_FMT);
  printf ("ALT_DIGITS:  %d\n", ALT_DIGITS);
  printf ("RADIXCHAR:   %d\n", RADIXCHAR);
  printf ("THOUSEP:     %d\n", THOUSEP);
  printf ("YESEXPR:     %d\n", YESEXPR);
  printf ("NOEXPR:      %d\n", NOEXPR);
  printf ("CRNCYSTR:    %d\n", CRNCYSTR);
}

/* If this program fails to compile. Uncomment this and fix the non-unique
   values. */
/* #undef ENSURE_UNIQUE */

static void
ensure_unique (void)
{
#if ENSURE_UNIQUE
  switch (0)
    {
    case CODESET:
    case D_T_FMT:
    case D_FMT:
    case T_FMT:
    case T_FMT_AMPM:
    case AM_STR:
    case PM_STR:
    case DAY_1:
    case DAY_2:
    case DAY_3:
    case DAY_4:
    case DAY_5:
    case DAY_6:
    case DAY_7:
    case ABDAY_1:
    case ABDAY_2:
    case ABDAY_3:
    case ABDAY_4:
    case ABDAY_5:
    case ABDAY_6:
    case ABDAY_7:
    case MON_1:
    case MON_2:
    case MON_3:
    case MON_4:
    case MON_5:
    case MON_6:
    case MON_7:
    case MON_8:
    case MON_9:
    case MON_10:
    case MON_11:
    case MON_12:
    case ABMON_1:
    case ABMON_2:
    case ABMON_3:
    case ABMON_4:
    case ABMON_5:
    case ABMON_6:
    case ABMON_7:
    case ABMON_8:
    case ABMON_9:
    case ABMON_10:
    case ABMON_11:
    case ABMON_12:
    case ERA:
    case ERA_D_FMT:
    case ERA_D_T_FMT:
    case ERA_T_FMT:
    case ALT_DIGITS:
    case RADIXCHAR:
    case THOUSEP:
    case YESEXPR:
    case NOEXPR:
    case CRNCYSTR:
    default:
      break;
    }
#endif
}
