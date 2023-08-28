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

#ifndef INT_OVERFLOW_H
#define INT_OVERFLOW_H

#include <limits.h>
#include <stdint.h>

#undef INT_ADD_RANGE_OVERFLOW
#undef INT_SUB_RANGE_OVERFLOW

/* bool INT_ADD_RANGE_OVERFLOW */
#define INT_ADD_RANGE_OVERFLOW(a, b, min, max)                                \
  ((min) < 0 ? (b) > 0 ? (a) > (max) - (b) : (a) < (min) - (b)                \
   : (a) < 0 ? (b) <= (a) + (b)                                               \
   : (b) < 0 ? (a) <= (a) + (b)                                               \
             : (b) > (a) + (b))

/* bool INT_SUB_RANGE_OVERFLOW */
#define INT_SUB_RANGE_OVERFLOW(a, b, min, max)                                \
  ((min) < 0 ? (b) > 0 ? (a) < (min) + (b) : (a) > (max) + (b)                \
   : (a) < 0 ? 1                                                              \
   : (b) < 0 ? (a) >= (a) - (b)                                               \
             : (a) < (b))

#endif /* INT_OVERFLOW_H */
