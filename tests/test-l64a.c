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

static void test_l64a_1 (void);
static void test_l64a_2 (void);
static void test_l64a_3 (void);

int
main (void)
{
  test_l64a_1 ();
  test_l64a_2 ();
  test_l64a_3 ();
  return 0;
}

static void
test_l64a_1 (void)
{
  ASSERT (strcmp (l64a (1L), "/") == 0);
  ASSERT (strcmp (l64a (2L), "0") == 0);
  ASSERT (strcmp (l64a (3L), "1") == 0);
  ASSERT (strcmp (l64a (4L), "2") == 0);
  ASSERT (strcmp (l64a (5L), "3") == 0);
  ASSERT (strcmp (l64a (6L), "4") == 0);
  ASSERT (strcmp (l64a (7L), "5") == 0);
  ASSERT (strcmp (l64a (8L), "6") == 0);
  ASSERT (strcmp (l64a (9L), "7") == 0);
  ASSERT (strcmp (l64a (10L), "8") == 0);
  ASSERT (strcmp (l64a (11L), "9") == 0);
  ASSERT (strcmp (l64a (12L), "A") == 0);
  ASSERT (strcmp (l64a (13L), "B") == 0);
  ASSERT (strcmp (l64a (14L), "C") == 0);
  ASSERT (strcmp (l64a (15L), "D") == 0);
  ASSERT (strcmp (l64a (16L), "E") == 0);
  ASSERT (strcmp (l64a (17L), "F") == 0);
  ASSERT (strcmp (l64a (18L), "G") == 0);
  ASSERT (strcmp (l64a (19L), "H") == 0);
  ASSERT (strcmp (l64a (20L), "I") == 0);
  ASSERT (strcmp (l64a (21L), "J") == 0);
  ASSERT (strcmp (l64a (22L), "K") == 0);
  ASSERT (strcmp (l64a (23L), "L") == 0);
  ASSERT (strcmp (l64a (24L), "M") == 0);
  ASSERT (strcmp (l64a (25L), "N") == 0);
  ASSERT (strcmp (l64a (26L), "O") == 0);
  ASSERT (strcmp (l64a (27L), "P") == 0);
  ASSERT (strcmp (l64a (28L), "Q") == 0);
  ASSERT (strcmp (l64a (29L), "R") == 0);
  ASSERT (strcmp (l64a (30L), "S") == 0);
  ASSERT (strcmp (l64a (31L), "T") == 0);
  ASSERT (strcmp (l64a (32L), "U") == 0);
  ASSERT (strcmp (l64a (33L), "V") == 0);
  ASSERT (strcmp (l64a (34L), "W") == 0);
  ASSERT (strcmp (l64a (35L), "X") == 0);
  ASSERT (strcmp (l64a (36L), "Y") == 0);
  ASSERT (strcmp (l64a (37L), "Z") == 0);
  ASSERT (strcmp (l64a (38L), "a") == 0);
  ASSERT (strcmp (l64a (39L), "b") == 0);
  ASSERT (strcmp (l64a (40L), "c") == 0);
  ASSERT (strcmp (l64a (41L), "d") == 0);
  ASSERT (strcmp (l64a (42L), "e") == 0);
  ASSERT (strcmp (l64a (43L), "f") == 0);
  ASSERT (strcmp (l64a (44L), "g") == 0);
  ASSERT (strcmp (l64a (45L), "h") == 0);
  ASSERT (strcmp (l64a (46L), "i") == 0);
  ASSERT (strcmp (l64a (47L), "j") == 0);
  ASSERT (strcmp (l64a (48L), "k") == 0);
  ASSERT (strcmp (l64a (49L), "l") == 0);
  ASSERT (strcmp (l64a (50L), "m") == 0);
  ASSERT (strcmp (l64a (51L), "n") == 0);
  ASSERT (strcmp (l64a (52L), "o") == 0);
  ASSERT (strcmp (l64a (53L), "p") == 0);
  ASSERT (strcmp (l64a (54L), "q") == 0);
  ASSERT (strcmp (l64a (55L), "r") == 0);
  ASSERT (strcmp (l64a (56L), "s") == 0);
  ASSERT (strcmp (l64a (57L), "t") == 0);
  ASSERT (strcmp (l64a (58L), "u") == 0);
  ASSERT (strcmp (l64a (59L), "v") == 0);
  ASSERT (strcmp (l64a (60L), "w") == 0);
  ASSERT (strcmp (l64a (61L), "x") == 0);
  ASSERT (strcmp (l64a (62L), "y") == 0);
  ASSERT (strcmp (l64a (63L), "z") == 0);
}

static void
test_l64a_2 (void)
{
  ASSERT (strcmp (l64a (65L), "//") == 0);
  ASSERT (strcmp (l64a (130L), "00") == 0);
  ASSERT (strcmp (l64a (195L), "11") == 0);
  ASSERT (strcmp (l64a (260L), "22") == 0);
  ASSERT (strcmp (l64a (325L), "33") == 0);
  ASSERT (strcmp (l64a (390L), "44") == 0);
  ASSERT (strcmp (l64a (455L), "55") == 0);
  ASSERT (strcmp (l64a (520L), "66") == 0);
  ASSERT (strcmp (l64a (585L), "77") == 0);
  ASSERT (strcmp (l64a (650L), "88") == 0);
  ASSERT (strcmp (l64a (715L), "99") == 0);
  ASSERT (strcmp (l64a (780L), "AA") == 0);
  ASSERT (strcmp (l64a (845L), "BB") == 0);
  ASSERT (strcmp (l64a (910L), "CC") == 0);
  ASSERT (strcmp (l64a (975L), "DD") == 0);
  ASSERT (strcmp (l64a (1040L), "EE") == 0);
  ASSERT (strcmp (l64a (1105L), "FF") == 0);
  ASSERT (strcmp (l64a (1170L), "GG") == 0);
  ASSERT (strcmp (l64a (1235L), "HH") == 0);
  ASSERT (strcmp (l64a (1300L), "II") == 0);
  ASSERT (strcmp (l64a (1365L), "JJ") == 0);
  ASSERT (strcmp (l64a (1430L), "KK") == 0);
  ASSERT (strcmp (l64a (1495L), "LL") == 0);
  ASSERT (strcmp (l64a (1560L), "MM") == 0);
  ASSERT (strcmp (l64a (1625L), "NN") == 0);
  ASSERT (strcmp (l64a (1690L), "OO") == 0);
  ASSERT (strcmp (l64a (1755L), "PP") == 0);
  ASSERT (strcmp (l64a (1820L), "QQ") == 0);
  ASSERT (strcmp (l64a (1885L), "RR") == 0);
  ASSERT (strcmp (l64a (1950L), "SS") == 0);
  ASSERT (strcmp (l64a (2015L), "TT") == 0);
  ASSERT (strcmp (l64a (2080L), "UU") == 0);
  ASSERT (strcmp (l64a (2145L), "VV") == 0);
  ASSERT (strcmp (l64a (2210L), "WW") == 0);
  ASSERT (strcmp (l64a (2275L), "XX") == 0);
  ASSERT (strcmp (l64a (2340L), "YY") == 0);
  ASSERT (strcmp (l64a (2405L), "ZZ") == 0);
  ASSERT (strcmp (l64a (2470L), "aa") == 0);
  ASSERT (strcmp (l64a (2535L), "bb") == 0);
  ASSERT (strcmp (l64a (2600L), "cc") == 0);
  ASSERT (strcmp (l64a (2665L), "dd") == 0);
  ASSERT (strcmp (l64a (2730L), "ee") == 0);
  ASSERT (strcmp (l64a (2795L), "ff") == 0);
  ASSERT (strcmp (l64a (2860L), "gg") == 0);
  ASSERT (strcmp (l64a (2925L), "hh") == 0);
  ASSERT (strcmp (l64a (2990L), "ii") == 0);
  ASSERT (strcmp (l64a (3055L), "jj") == 0);
  ASSERT (strcmp (l64a (3120L), "kk") == 0);
  ASSERT (strcmp (l64a (3185L), "ll") == 0);
  ASSERT (strcmp (l64a (3250L), "mm") == 0);
  ASSERT (strcmp (l64a (3315L), "nn") == 0);
  ASSERT (strcmp (l64a (3380L), "oo") == 0);
  ASSERT (strcmp (l64a (3445L), "pp") == 0);
  ASSERT (strcmp (l64a (3510L), "qq") == 0);
  ASSERT (strcmp (l64a (3575L), "rr") == 0);
  ASSERT (strcmp (l64a (3640L), "ss") == 0);
  ASSERT (strcmp (l64a (3705L), "tt") == 0);
  ASSERT (strcmp (l64a (3770L), "uu") == 0);
  ASSERT (strcmp (l64a (3835L), "vv") == 0);
  ASSERT (strcmp (l64a (3900L), "ww") == 0);
  ASSERT (strcmp (l64a (3965L), "xx") == 0);
  ASSERT (strcmp (l64a (4030L), "yy") == 0);
  ASSERT (strcmp (l64a (4095L), "zz") == 0);
}

static void
test_l64a_3 (void)
{
  ASSERT (strcmp (l64a (4161L), "///") == 0);
  ASSERT (strcmp (l64a (8322L), "000") == 0);
  ASSERT (strcmp (l64a (12483L), "111") == 0);
  ASSERT (strcmp (l64a (16644L), "222") == 0);
  ASSERT (strcmp (l64a (20805L), "333") == 0);
  ASSERT (strcmp (l64a (24966L), "444") == 0);
  ASSERT (strcmp (l64a (29127L), "555") == 0);
  ASSERT (strcmp (l64a (33288L), "666") == 0);
  ASSERT (strcmp (l64a (37449L), "777") == 0);
  ASSERT (strcmp (l64a (41610L), "888") == 0);
  ASSERT (strcmp (l64a (45771L), "999") == 0);
  ASSERT (strcmp (l64a (49932L), "AAA") == 0);
  ASSERT (strcmp (l64a (54093L), "BBB") == 0);
  ASSERT (strcmp (l64a (58254L), "CCC") == 0);
  ASSERT (strcmp (l64a (62415L), "DDD") == 0);
  ASSERT (strcmp (l64a (66576L), "EEE") == 0);
  ASSERT (strcmp (l64a (70737L), "FFF") == 0);
  ASSERT (strcmp (l64a (74898L), "GGG") == 0);
  ASSERT (strcmp (l64a (79059L), "HHH") == 0);
  ASSERT (strcmp (l64a (83220L), "III") == 0);
  ASSERT (strcmp (l64a (87381L), "JJJ") == 0);
  ASSERT (strcmp (l64a (91542L), "KKK") == 0);
  ASSERT (strcmp (l64a (95703L), "LLL") == 0);
  ASSERT (strcmp (l64a (99864L), "MMM") == 0);
  ASSERT (strcmp (l64a (104025L), "NNN") == 0);
  ASSERT (strcmp (l64a (108186L), "OOO") == 0);
  ASSERT (strcmp (l64a (112347L), "PPP") == 0);
  ASSERT (strcmp (l64a (116508L), "QQQ") == 0);
  ASSERT (strcmp (l64a (120669L), "RRR") == 0);
  ASSERT (strcmp (l64a (124830L), "SSS") == 0);
  ASSERT (strcmp (l64a (128991L), "TTT") == 0);
  ASSERT (strcmp (l64a (133152L), "UUU") == 0);
  ASSERT (strcmp (l64a (137313L), "VVV") == 0);
  ASSERT (strcmp (l64a (141474L), "WWW") == 0);
  ASSERT (strcmp (l64a (145635L), "XXX") == 0);
  ASSERT (strcmp (l64a (149796L), "YYY") == 0);
  ASSERT (strcmp (l64a (153957L), "ZZZ") == 0);
  ASSERT (strcmp (l64a (158118L), "aaa") == 0);
  ASSERT (strcmp (l64a (162279L), "bbb") == 0);
  ASSERT (strcmp (l64a (166440L), "ccc") == 0);
  ASSERT (strcmp (l64a (170601L), "ddd") == 0);
  ASSERT (strcmp (l64a (174762L), "eee") == 0);
  ASSERT (strcmp (l64a (178923L), "fff") == 0);
  ASSERT (strcmp (l64a (183084L), "ggg") == 0);
  ASSERT (strcmp (l64a (187245L), "hhh") == 0);
  ASSERT (strcmp (l64a (191406L), "iii") == 0);
  ASSERT (strcmp (l64a (195567L), "jjj") == 0);
  ASSERT (strcmp (l64a (199728L), "kkk") == 0);
  ASSERT (strcmp (l64a (203889L), "lll") == 0);
  ASSERT (strcmp (l64a (208050L), "mmm") == 0);
  ASSERT (strcmp (l64a (212211L), "nnn") == 0);
  ASSERT (strcmp (l64a (216372L), "ooo") == 0);
  ASSERT (strcmp (l64a (220533L), "ppp") == 0);
  ASSERT (strcmp (l64a (224694L), "qqq") == 0);
  ASSERT (strcmp (l64a (228855L), "rrr") == 0);
  ASSERT (strcmp (l64a (233016L), "sss") == 0);
  ASSERT (strcmp (l64a (237177L), "ttt") == 0);
  ASSERT (strcmp (l64a (241338L), "uuu") == 0);
  ASSERT (strcmp (l64a (245499L), "vvv") == 0);
  ASSERT (strcmp (l64a (249660L), "www") == 0);
  ASSERT (strcmp (l64a (253821L), "xxx") == 0);
  ASSERT (strcmp (l64a (257982L), "yyy") == 0);
  ASSERT (strcmp (l64a (262143L), "zzz") == 0);
}
