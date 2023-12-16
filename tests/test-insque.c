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

#include <search.h>
#include <stdio.h>
#include <stdlib.h>

#include "test-help.h"

static void test_insque_noncircular (void);

int
main (void)
{
  test_insque_noncircular ();
  return 0;
}

static void
test_insque_noncircular (void)
{
  struct qelem nodes[64];
  size_t i;

  ASSERT (ARRAY_SIZE (nodes) > 1);

  insque (&nodes[0], NULL);
  for (i = 1; i < ARRAY_SIZE (nodes); ++i)
    insque (&nodes[i], &nodes[i - 1]);

  for (i = 0; i < ARRAY_SIZE (nodes) - 1; ++i)
    {
      ASSERT (nodes[i].q_forw == &nodes[i + 1]);
      if (i == 0)
        ASSERT (nodes[i].q_back == NULL);
      else
        ASSERT (nodes[i].q_back == &nodes[i - 1]);
    }
}
