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

#ifndef TEST_HELP_H
#define TEST_HELP_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#undef ARRAY_SIZE
#undef ASSERT

#define ARRAY_SIZE(array) (sizeof (array) / sizeof (array[0]))

/* assert () defined here for tests so test checks happen even if CMake
   defines NDBEUG. This should probably replaced with CMake and some test
   library but most of of the info online is C++. */
#define ASSERT(expression)                                                    \
  do                                                                          \
    {                                                                         \
      if (!(expression))                                                      \
        {                                                                     \
          fprintf (stderr, "Assertion failed on line %d of %s: %s.\n",        \
                   __LINE__, __FILE__, #expression);                          \
          abort ();                                                           \
        }                                                                     \
    }                                                                         \
  while (0)

#endif /* TEST_HELP_H */
