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
#include <string.h>

#include "test-help.h"

static void test_l64a_r_1 (void);
static void test_l64a_r_2 (void);
static void test_l64a_r_3 (void);

int
main (void)
{
  test_l64a_r_1 ();
  test_l64a_r_2 ();
  test_l64a_r_3 ();
  return 0;
}

static void
test_l64a_r_1 (void)
{
  char buffer[2];

  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (1L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "/") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (2L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "0") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (3L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "1") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (4L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "2") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (5L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "3") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (6L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "4") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (7L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "5") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (8L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "6") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (9L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "7") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (10L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "8") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (11L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "9") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (12L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "A") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (13L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "B") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (14L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "C") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (15L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "D") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (16L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "E") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (17L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "F") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (18L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "G") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (19L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "H") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (20L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "I") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (21L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "J") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (22L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "K") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (23L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "L") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (24L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "M") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (25L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "N") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (26L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "O") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (27L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "P") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (28L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "Q") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (29L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "R") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (30L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "S") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (31L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "T") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (32L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "U") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (33L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "V") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (34L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "W") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (35L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "X") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (36L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "Y") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (37L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "Z") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (38L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "a") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (39L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "b") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (40L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "c") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (41L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "d") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (42L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "e") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (43L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "f") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (44L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "g") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (45L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "h") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (46L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "i") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (47L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "j") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (48L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "k") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (49L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "l") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (50L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "m") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (51L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "n") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (52L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "o") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (53L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "p") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (54L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "q") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (55L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "r") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (56L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "s") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (57L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "t") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (58L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "u") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (59L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "v") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (60L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "w") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (61L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "x") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (62L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "y") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    ASSERT (l64a_r (63L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "z") == 0);
  }
}

static void
test_l64a_r_2 (void)
{
  char buffer[3];

  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (65L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "//") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (130L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "00") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (195L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "11") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (260L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "22") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (325L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "33") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (390L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "44") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (455L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "55") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (520L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "66") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (585L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "77") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (650L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "88") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (715L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "99") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (780L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "AA") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (845L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "BB") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (910L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "CC") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (975L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "DD") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (1040L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "EE") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (1105L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "FF") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (1170L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "GG") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (1235L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "HH") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (1300L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "II") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (1365L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "JJ") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (1430L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "KK") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (1495L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "LL") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (1560L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "MM") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (1625L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "NN") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (1690L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "OO") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (1755L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "PP") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (1820L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "QQ") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (1885L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "RR") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (1950L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "SS") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (2015L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "TT") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (2080L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "UU") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (2145L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "VV") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (2210L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "WW") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (2275L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "XX") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (2340L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "YY") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (2405L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "ZZ") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (2470L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "aa") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (2535L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "bb") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (2600L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "cc") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (2665L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "dd") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (2730L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "ee") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (2795L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "ff") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (2860L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "gg") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (2925L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "hh") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (2990L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "ii") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (3055L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "jj") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (3120L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "kk") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (3185L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "ll") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (3250L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "mm") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (3315L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "nn") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (3380L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "oo") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (3445L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "pp") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (3510L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "qq") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (3575L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "rr") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (3640L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "ss") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (3705L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "tt") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (3770L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "uu") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (3835L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "vv") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (3900L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "ww") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (3965L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "xx") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (4030L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "yy") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    ASSERT (l64a_r (4095L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "zz") == 0);
  }
}

static void
test_l64a_r_3 (void)
{
  char buffer[4];

  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (4161L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "///") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (8322L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "000") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (12483L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "111") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (16644L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "222") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (20805L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "333") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (24966L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "444") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (29127L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "555") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (33288L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "666") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (37449L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "777") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (41610L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "888") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (45771L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "999") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (49932L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "AAA") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (54093L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "BBB") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (58254L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "CCC") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (62415L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "DDD") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (66576L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "EEE") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (70737L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "FFF") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (74898L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "GGG") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (79059L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "HHH") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (83220L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "III") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (87381L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "JJJ") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (91542L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "KKK") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (95703L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "LLL") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (99864L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "MMM") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (104025L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "NNN") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (108186L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "OOO") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (112347L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "PPP") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (116508L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "QQQ") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (120669L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "RRR") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (124830L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "SSS") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (128991L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "TTT") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (133152L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "UUU") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (137313L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "VVV") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (141474L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "WWW") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (145635L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "XXX") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (149796L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "YYY") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (153957L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "ZZZ") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (158118L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "aaa") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (162279L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "bbb") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (166440L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "ccc") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (170601L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "ddd") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (174762L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "eee") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (178923L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "fff") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (183084L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "ggg") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (187245L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "hhh") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (191406L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "iii") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (195567L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "jjj") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (199728L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "kkk") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (203889L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "lll") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (208050L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "mmm") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (212211L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "nnn") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (216372L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "ooo") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (220533L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "ppp") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (224694L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "qqq") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (228855L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "rrr") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (233016L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "sss") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (237177L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "ttt") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (241338L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "uuu") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (245499L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "vvv") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (249660L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "www") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (253821L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "xxx") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (257982L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "yyy") == 0);
  }
  {
    buffer[0] = -1;
    buffer[1] = -1;
    buffer[2] = -1;
    buffer[3] = -1;
    ASSERT (l64a_r (262143L, buffer, sizeof (buffer)) == 0);
    ASSERT (strcmp (buffer, "zzz") == 0);
  }
}
