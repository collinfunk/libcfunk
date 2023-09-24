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

#ifndef GNUC_PREREQ_H
#define GNUC_PREREQ_H

#undef GNUC_PREREQ

/* Check that the current compiler is GCC and that it's version is greater than
   or equal to the given version. This can be used in preprocessor statements.
   If you want to check if the current compiler is GCC 12.2.1 or higher, you
   would use GNUC_PREREQ (12, 2, 1). This would return true if the current
   compiler is >= GCC version 12.2.1. This alone is usually not adequate to
   check wether a feature is supported or not. For example PCC 1.2.0 reports
   that it is version 4.3.1 but does not report the __sync family of atomics
   available in GCC 4.1.0. To check for Clang versions, CLANG_PREREQ should be
   used. Clang 18.0.0 reports that it is 4.2.1 but supports most of the later
   GCC features. */
#if defined(__GNUC__) && defined(__GNUC_MINOR__)
#  if defined(__GNUC_PATCHLEVEL__)
#    define GNUC_PREREQ(major, minor, patch)                                  \
      ((__GNUC__ > (major))                                                   \
       || ((__GNUC__ == (major))                                              \
           && ((__GNUC_MINOR__ > (minor))                                     \
               || ((__GNUC_MINOR__ == (minor))                                \
                   && (__GNUC_PATCHLEVEL__ >= (patch))))))
#  else
#    define GNUC_PREREQ(major, minor, patch)                                  \
      ((__GNUC__ > (major))                                                   \
       || ((__GNUC__ == (major))                                              \
           && ((__GNUC_MINOR__ > (minor))                                     \
               || ((__GNUC_MINOR__ == (minor)) && ((patch) == 0)))))
#  endif
#else
#  define GNUC_PREREQ(major, minor, patch) 0
#endif

#endif /* GNUC_PREREQ_H */
