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

#include <errno.h>
#include <stdint.h>
#include <stdlib.h>

int
random_r (struct random_data *restrict buf, int32_t *restrict result)
{
  if (buf == NULL || result == NULL)
    {
      errno = EINVAL;
      return -1;
    }
  if (buf->rand_type == 0)
    {
      int32_t value
          = (int32_t) ((((uint32_t) *buf->state * UINT32_C (1103515245))
                        + UINT32_C (12345))
                       & INT32_MAX);
      *buf->state = value;
      *result = value;
    }
  else
    {
      uint32_t value = (uint32_t) *buf->fptr + (uint32_t) *buf->rptr;
      *buf->fptr = (int32_t) value;
      *result = (int32_t) ((value >> 1) & INT32_MAX);
      if (++buf->fptr >= buf->end_ptr)
        {
          buf->fptr = buf->state;
          buf->rptr++;
        }
      else if (++buf->rptr >= buf->end_ptr)
        buf->rptr = buf->state;
    }
  return 0;
}
