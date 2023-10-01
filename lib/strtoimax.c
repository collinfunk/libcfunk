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

#define STRTOL_FUNC_NAME strtoimax
#define STRTOL_INT_TYPE intmax_t
#define STRTOL_SIGNED_INT_TYPE intmax_t
#define STRTOL_UNSIGNED_INT_TYPE uintmax_t
#define STRTOL_INT_MAX INTMAX_MAX
#define STRTOL_INT_MIN INTMAX_MIN
#define STRTOL_SIGNED_INT_MAX INTMAX_MAX
#define STRTOL_SIGNED_INT_MIN INTMAX_MIN
#define STRTOL_UNSIGNED_INT_MAX UINTMAX_MAX
#define STRTOL_UNSIGNED_INT_MIN 0ULL
#define STRTOL_RETURN_UNSIGNED 0
#define STRTOL_SUPPORT_C23 1

#include "strtol.c"
