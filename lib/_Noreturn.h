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

#ifndef C11__NORETURN_H
#define C11__NORETURN_H

#include <config.h>

#include "__has_attribute.h"
#include "__has_declspec_attribute.h"

/* _Noreturn is part of C11. This file requires `_Noreturn.cmake' is used to
   check if it is supported by the compiler or not. If it is not supported and
   HAVE_C11__NORETURN is set to 0, we define it to a builtin if avaliable. */
#ifndef _Noreturn
#  if !HAVE_C11__NORETURN
#    if __has_attribute(__noreturn__)
#      define _Noreturn __attribute__ ((__noreturn__))
#    elif __has_declspec_attribute(noreturn)
#      define _Noreturn __declspec (noreturn)
#    else /* No builtins. */
#      define _Noreturn
#    endif /* __has_attribute(__noreturn__) */
#  endif   /* !HAVE_C11__NORETURN */
#endif     /* _Noreturn */

#endif /* C11__NORETURN_H */
