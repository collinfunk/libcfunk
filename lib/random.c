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

#include <stdint.h>
#include <stdlib.h>

/* initstate (1, (char *) random_table, 128); */
static int32_t random_table[32]
    = { INT32_C (3),           INT32_C (-1726662223), INT32_C (379960547),
        INT32_C (1735697613),  INT32_C (1040273694),  INT32_C (1313901226),
        INT32_C (1627687941),  INT32_C (-179304937),  INT32_C (-2073333483),
        INT32_C (1780058412),  INT32_C (-1989503057), INT32_C (-615974602),
        INT32_C (344556628),   INT32_C (939512070),   INT32_C (-1249116260),
        INT32_C (1507946756),  INT32_C (-812545463),  INT32_C (154635395),
        INT32_C (1388815473),  INT32_C (-1926676823), INT32_C (525320961),
        INT32_C (-1009028674), INT32_C (968117788),   INT32_C (-123449607),
        INT32_C (1284210865),  INT32_C (435012392),   INT32_C (-2017506339),
        INT32_C (-911064859),  INT32_C (-370259173),  INT32_C (1132637927),
        INT32_C (1398500161),  INT32_C (-205601318) };

static struct random_data internal_state = { .fptr = &random_table[4],
                                             .rptr = &random_table[1],
                                             .state = &random_table[1],
                                             .rand_type = 3,
                                             .rand_deg = 31,
                                             .rand_sep = 3,
                                             .end_ptr = &random_table[32] };

/* FIXME: Doesn't conform to POSIX requirements for the 'random' function. */
long int
random (void)
#undef random
{
  int32_t result;

  (void) random_r (&internal_state, &result);
  return (long int) result;
}
