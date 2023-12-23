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

#include "test-help.h"

static void test_a64l_1 (void);
static void test_a64l_2 (void);
static void test_a64l_3 (void);

int
main (void)
{
  test_a64l_1 ();
  test_a64l_2 ();
  test_a64l_3 ();
  return 0;
}

static void
test_a64l_1 (void)
{
  ASSERT (a64l (".") == 0L);
  ASSERT (a64l ("/") == 1L);
  ASSERT (a64l ("0") == 2L);
  ASSERT (a64l ("1") == 3L);
  ASSERT (a64l ("2") == 4L);
  ASSERT (a64l ("3") == 5L);
  ASSERT (a64l ("4") == 6L);
  ASSERT (a64l ("5") == 7L);
  ASSERT (a64l ("6") == 8L);
  ASSERT (a64l ("7") == 9L);
  ASSERT (a64l ("8") == 10L);
  ASSERT (a64l ("9") == 11L);
  ASSERT (a64l ("A") == 12L);
  ASSERT (a64l ("B") == 13L);
  ASSERT (a64l ("C") == 14L);
  ASSERT (a64l ("D") == 15L);
  ASSERT (a64l ("E") == 16L);
  ASSERT (a64l ("F") == 17L);
  ASSERT (a64l ("G") == 18L);
  ASSERT (a64l ("H") == 19L);
  ASSERT (a64l ("I") == 20L);
  ASSERT (a64l ("J") == 21L);
  ASSERT (a64l ("K") == 22L);
  ASSERT (a64l ("L") == 23L);
  ASSERT (a64l ("M") == 24L);
  ASSERT (a64l ("N") == 25L);
  ASSERT (a64l ("O") == 26L);
  ASSERT (a64l ("P") == 27L);
  ASSERT (a64l ("Q") == 28L);
  ASSERT (a64l ("R") == 29L);
  ASSERT (a64l ("S") == 30L);
  ASSERT (a64l ("T") == 31L);
  ASSERT (a64l ("U") == 32L);
  ASSERT (a64l ("V") == 33L);
  ASSERT (a64l ("W") == 34L);
  ASSERT (a64l ("X") == 35L);
  ASSERT (a64l ("Y") == 36L);
  ASSERT (a64l ("Z") == 37L);
  ASSERT (a64l ("a") == 38L);
  ASSERT (a64l ("b") == 39L);
  ASSERT (a64l ("c") == 40L);
  ASSERT (a64l ("d") == 41L);
  ASSERT (a64l ("e") == 42L);
  ASSERT (a64l ("f") == 43L);
  ASSERT (a64l ("g") == 44L);
  ASSERT (a64l ("h") == 45L);
  ASSERT (a64l ("i") == 46L);
  ASSERT (a64l ("j") == 47L);
  ASSERT (a64l ("k") == 48L);
  ASSERT (a64l ("l") == 49L);
  ASSERT (a64l ("m") == 50L);
  ASSERT (a64l ("n") == 51L);
  ASSERT (a64l ("o") == 52L);
  ASSERT (a64l ("p") == 53L);
  ASSERT (a64l ("q") == 54L);
  ASSERT (a64l ("r") == 55L);
  ASSERT (a64l ("s") == 56L);
  ASSERT (a64l ("t") == 57L);
  ASSERT (a64l ("u") == 58L);
  ASSERT (a64l ("v") == 59L);
  ASSERT (a64l ("w") == 60L);
  ASSERT (a64l ("x") == 61L);
  ASSERT (a64l ("y") == 62L);
  ASSERT (a64l ("z") == 63L);
}

static void
test_a64l_2 (void)
{
  ASSERT (a64l ("..") == 0L);
  ASSERT (a64l ("//") == 65L);
  ASSERT (a64l ("00") == 130L);
  ASSERT (a64l ("11") == 195L);
  ASSERT (a64l ("22") == 260L);
  ASSERT (a64l ("33") == 325L);
  ASSERT (a64l ("44") == 390L);
  ASSERT (a64l ("55") == 455L);
  ASSERT (a64l ("66") == 520L);
  ASSERT (a64l ("77") == 585L);
  ASSERT (a64l ("88") == 650L);
  ASSERT (a64l ("99") == 715L);
  ASSERT (a64l ("AA") == 780L);
  ASSERT (a64l ("BB") == 845L);
  ASSERT (a64l ("CC") == 910L);
  ASSERT (a64l ("DD") == 975L);
  ASSERT (a64l ("EE") == 1040L);
  ASSERT (a64l ("FF") == 1105L);
  ASSERT (a64l ("GG") == 1170L);
  ASSERT (a64l ("HH") == 1235L);
  ASSERT (a64l ("II") == 1300L);
  ASSERT (a64l ("JJ") == 1365L);
  ASSERT (a64l ("KK") == 1430L);
  ASSERT (a64l ("LL") == 1495L);
  ASSERT (a64l ("MM") == 1560L);
  ASSERT (a64l ("NN") == 1625L);
  ASSERT (a64l ("OO") == 1690L);
  ASSERT (a64l ("PP") == 1755L);
  ASSERT (a64l ("QQ") == 1820L);
  ASSERT (a64l ("RR") == 1885L);
  ASSERT (a64l ("SS") == 1950L);
  ASSERT (a64l ("TT") == 2015L);
  ASSERT (a64l ("UU") == 2080L);
  ASSERT (a64l ("VV") == 2145L);
  ASSERT (a64l ("WW") == 2210L);
  ASSERT (a64l ("XX") == 2275L);
  ASSERT (a64l ("YY") == 2340L);
  ASSERT (a64l ("ZZ") == 2405L);
  ASSERT (a64l ("aa") == 2470L);
  ASSERT (a64l ("bb") == 2535L);
  ASSERT (a64l ("cc") == 2600L);
  ASSERT (a64l ("dd") == 2665L);
  ASSERT (a64l ("ee") == 2730L);
  ASSERT (a64l ("ff") == 2795L);
  ASSERT (a64l ("gg") == 2860L);
  ASSERT (a64l ("hh") == 2925L);
  ASSERT (a64l ("ii") == 2990L);
  ASSERT (a64l ("jj") == 3055L);
  ASSERT (a64l ("kk") == 3120L);
  ASSERT (a64l ("ll") == 3185L);
  ASSERT (a64l ("mm") == 3250L);
  ASSERT (a64l ("nn") == 3315L);
  ASSERT (a64l ("oo") == 3380L);
  ASSERT (a64l ("pp") == 3445L);
  ASSERT (a64l ("qq") == 3510L);
  ASSERT (a64l ("rr") == 3575L);
  ASSERT (a64l ("ss") == 3640L);
  ASSERT (a64l ("tt") == 3705L);
  ASSERT (a64l ("uu") == 3770L);
  ASSERT (a64l ("vv") == 3835L);
  ASSERT (a64l ("ww") == 3900L);
  ASSERT (a64l ("xx") == 3965L);
  ASSERT (a64l ("yy") == 4030L);
  ASSERT (a64l ("zz") == 4095L);
}

static void
test_a64l_3 (void)
{
  ASSERT (a64l ("...") == 0L);
  ASSERT (a64l ("///") == 4161L);
  ASSERT (a64l ("000") == 8322L);
  ASSERT (a64l ("111") == 12483L);
  ASSERT (a64l ("222") == 16644L);
  ASSERT (a64l ("333") == 20805L);
  ASSERT (a64l ("444") == 24966L);
  ASSERT (a64l ("555") == 29127L);
  ASSERT (a64l ("666") == 33288L);
  ASSERT (a64l ("777") == 37449L);
  ASSERT (a64l ("888") == 41610L);
  ASSERT (a64l ("999") == 45771L);
  ASSERT (a64l ("AAA") == 49932L);
  ASSERT (a64l ("BBB") == 54093L);
  ASSERT (a64l ("CCC") == 58254L);
  ASSERT (a64l ("DDD") == 62415L);
  ASSERT (a64l ("EEE") == 66576L);
  ASSERT (a64l ("FFF") == 70737L);
  ASSERT (a64l ("GGG") == 74898L);
  ASSERT (a64l ("HHH") == 79059L);
  ASSERT (a64l ("III") == 83220L);
  ASSERT (a64l ("JJJ") == 87381L);
  ASSERT (a64l ("KKK") == 91542L);
  ASSERT (a64l ("LLL") == 95703L);
  ASSERT (a64l ("MMM") == 99864L);
  ASSERT (a64l ("NNN") == 104025L);
  ASSERT (a64l ("OOO") == 108186L);
  ASSERT (a64l ("PPP") == 112347L);
  ASSERT (a64l ("QQQ") == 116508L);
  ASSERT (a64l ("RRR") == 120669L);
  ASSERT (a64l ("SSS") == 124830L);
  ASSERT (a64l ("TTT") == 128991L);
  ASSERT (a64l ("UUU") == 133152L);
  ASSERT (a64l ("VVV") == 137313L);
  ASSERT (a64l ("WWW") == 141474L);
  ASSERT (a64l ("XXX") == 145635L);
  ASSERT (a64l ("YYY") == 149796L);
  ASSERT (a64l ("ZZZ") == 153957L);
  ASSERT (a64l ("aaa") == 158118L);
  ASSERT (a64l ("bbb") == 162279L);
  ASSERT (a64l ("ccc") == 166440L);
  ASSERT (a64l ("ddd") == 170601L);
  ASSERT (a64l ("eee") == 174762L);
  ASSERT (a64l ("fff") == 178923L);
  ASSERT (a64l ("ggg") == 183084L);
  ASSERT (a64l ("hhh") == 187245L);
  ASSERT (a64l ("iii") == 191406L);
  ASSERT (a64l ("jjj") == 195567L);
  ASSERT (a64l ("kkk") == 199728L);
  ASSERT (a64l ("lll") == 203889L);
  ASSERT (a64l ("mmm") == 208050L);
  ASSERT (a64l ("nnn") == 212211L);
  ASSERT (a64l ("ooo") == 216372L);
  ASSERT (a64l ("ppp") == 220533L);
  ASSERT (a64l ("qqq") == 224694L);
  ASSERT (a64l ("rrr") == 228855L);
  ASSERT (a64l ("sss") == 233016L);
  ASSERT (a64l ("ttt") == 237177L);
  ASSERT (a64l ("uuu") == 241338L);
  ASSERT (a64l ("vvv") == 245499L);
  ASSERT (a64l ("www") == 249660L);
  ASSERT (a64l ("xxx") == 253821L);
  ASSERT (a64l ("yyy") == 257982L);
  ASSERT (a64l ("zzz") == 262143L);
}
