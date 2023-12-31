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

#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

/* Compiler attributes. */

#include "__has_attribute.h"
#include "__has_declspec_attribute.h"

/* Keep sorted. */
#undef ATTRIBUTE_ALIGNED
#undef ATTRIBUTE_ALLOC_SIZE
#undef ATTRIBUTE_ALWAYS_INLINE
#undef ATTRIBUTE_ARTIFICIAL
#undef ATTRIBUTE_COLD
#undef ATTRIBUTE_CONST
#undef ATTRIBUTE_FALLTHROUGH
#undef ATTRIBUTE_GNU_INLINE
#undef ATTRIBUTE_HOT
#undef ATTRIBUTE_MALLOC
#undef ATTRIBUTE_NOINLINE
#undef ATTRIBUTE_NONNULL
#undef ATTRIBUTE_NONSTRING
#undef ATTRIBUTE_NOTHROW
#undef ATTRIBUTE_PACKED
#undef ATTRIBUTE_PURE
#undef ATTRIBUTE_RETURNS_NONNULL
#undef ATTRIBUTE_RETURNS_TWICE
#undef ATTRIBUTE_SENTINEL
#undef ATTRIBUTE_UNUSED
#undef ATTRIBUTE_USED
#undef ATTRIBUTE_WARN_UNUSED_RESULT

/* Define __attribute__ to do nothing on compilers that don't support
   GNU style attributes. */
#if !defined(__GNUC__) && !defined(__clang__) && !defined(__attribute__)
#  define __attribute__(x)
#endif

/* Specifies the minimum alignment for a variable, structure, or member. */
#if __has_attribute(__aligned__)
#  define ATTRIBUTE_ALIGNED(x) __attribute__ ((__aligned__ (x)))
#else
#  define ATTRIBUTE_ALIGNED
#endif

/* Indicates that a function returns memory allocated with a size given by the
   Xth parameter. */
#if __has_attribute(__alloc_size__)
#  define ATTRIBUTE_ALLOC_SIZE(x) __attribute__ ((__alloc_size__ (x)))
#else
#  define ATTRIBUTE_ALLOC_SIZE(x)
#endif

/* Tell the compiler that a function should always be inlined despite
   restrictions that apply to the inline keyword. */
#if __has_attribute(__always_inline__)
#  define ATTRIBUTE_ALWAYS_INLINE __attribute__ ((__always_inline__))
#else
#  define ATTRIBUTE_ALWAYS_INLINE
#endif

/* Used for small inlined functions which should be associated with the caller
   for debug information output. */
#if __has_attribute(__artificial__)
#  define ATTRIBUTE_ARTIFICIAL __attribute__ ((__artificial__))
#else
#  define ATTRIBUTE_ARTIFICIAL
#endif

/* Inform the compiler that a function is not likely to be executed. */
#if __has_attribute(__cold__)
#  define ATTRIBUTE_COLD __attribute__ ((__cold__))
#else
#  define ATTRIBUTE_COLD
#endif

/* Similar to ATTRIBUTE_PURE except that is even more strict. Functions marked
   with ATTRIBUTE_CONST may not read from objects that affect its return value
   between invocations. */
#if __has_attribute(__const__)
#  define ATTRIBUTE_CONST __attribute__ ((__const__))
#else
#  define ATTRIBUTE_CONST
#endif

/* ATTRIBUTE_FALLTHROUGH is used to indicate that switch case intentionally
   falls through. This silences -Wimplicit-fallthrough warnings with GCC and
   Clang. */
#if __has_attribute(__fallthrough__)
#  define ATTRIBUTE_FALLTHROUGH __attribute__ ((__fallthrough__))
#else
#  define ATTRIBUTE_FALLTHROUGH
#endif

/* ATTRIBUTE_GNU_INLINE should be used on functions also declared with the
   inline keyword. This tells GCC to treat the function as if it were defined
   in gnu90 mode even when compiling in a different mode. In GNU C90, function
   definitions with both the extern and inline keyword will only be used for
   inlining. References to the address of function will be treated as an
   external reference. */
#if __has_attribute(__gnu_inline__)
#  define ATTRIBUTE_GNU_INLINE __attribute__ ((__gnu_inline__))
#else
#  define ATTRIBUTE_GNU_INLINE
#endif

/* Inform the compiler that a function is likely to be executed frequently. */
#if __has_attribute(__hot__)
#  define ATTRIBUTE_HOT __attribute__ ((__hot__))
#else
#  define ATTRIBUTE_HOT __attribute__ ((__hot__))
#endif

/* Indicates that a function returns a pointer to newly allocated memory. */
#if __has_attribute(__malloc__)
#  define ATTRIBUTE_MALLOC __attribute__ ((__malloc__))
#else
#  define ATTRIBUTE_MALLOC
#endif

/* Tell the compiler that a function should not be considered for inlining. */
#if __has_attribute(__noinline__)
#  define ATTRIBUTE_NOINLINE __attribute__ ((__noinline__))
#elif __has_declspec_attribute(noinline)
#  define ATTRIBUTE_NOINLINE __declspec (noinline)
#else
#  define ATTRIBUTE_NOINLINE
#endif

/* Indicates that the given arguments in a function prototype should be
   NULL pointers. */
#if __has_attribute(__nonnull__)
#  define ATTRIBUTE_NONNULL(x) __attribute__ ((__nonnull__ (x)))
#else
#  define ATTRIBUTE_NONNULL(x)
#endif

/* Indicates that a char (signed or unsigned) variable or member declaration
   is not intended to be a NUL terminated string. */
#if __has_attribute(__non_string__)
#  define ATTRIBUTE_NONSTRING __attribute__ ((__nonstring__))
#else
#  define ATTRIBUTE_NONSTRING
#endif

/* Indicates that a function cannot throw an exception. */
#if __has_attribute(__nothrow__)
#  define ATTRIBUTE_NOTHROW __attribute__ ((__nothrow__))
#elif __has_declspec_attribute(nothrow)
#  define ATTRIBUTE_NOTHROW __declspec (nothrow)
#else
#  define ATTRIBUTE_NOTHROW
#endif

/* Tell the compiler that a structure or member should have the smallest
   possible alignment. */
#if __has_attribute(__packed__)
#  define ATTRIBUTE_PACKED __attribute__ ((__packed__))
#else
#  define ATTRIBUTE_PACKED
#endif

/* Indicates that calls to a function have no changes to the state of the
   program other than return value. Functions marked with ATTRIBUTE_PURE
   may access memory which changes in between invocations. */
#if __has_attribute(__pure__)
#  define ATTRIBUTE_PURE __attribute__ ((__pure__))
#else
#  define ATTRIBUTE_PURE
#endif

/* Tell the compiler that the return value of a function will never be NULL. */
#if __has_attribute(__returns_nonnull__)
#  define ATTRIBUTE_RETURNS_NONNULL __attribute__ ((__returns_nonnull__))
#else
#  define ATTRIBUTE_RETURNS_NONNULL
#endif

/* Tells the compiler that a function may return more than once. */
#if __has_attribute(__returns_twice__)
#  define ATTRIBUTE_RETURNS_TWICE __attribute__ ((__returns_twice__))
#else
#  define ATTRIBUTE_RETURNS_TWICE
#endif

/* Tell the compiler that a variadic function expects the last argument
   to be NULL. */
#if __has_attribute(__sentinel__)
#  define ATTRIBUTE_SENTINEL(x) __attribute__ ((__sentinel__ (x)))
#else
#  define ATTRIBUTE_SENTINEL
#endif

/* Marks a variable or function as unused so that it does not cause any
   warnings to be emitted by the compiler. */
#if __has_attribute(__unused__)
#  define ATTRIBUTE_UNUSED __attribute__ ((__unused__))
#else
#  define ATTRIBUTE_UNUSED
#endif

/* Mark a variable or function as used so that the compiler does not optimize
   it out even if it appears to be unreferenced. */
#if __has_attribute(__used__)
#  define ATTRIBUTE_USED __attribute__ ((__used__))
#else
#  define ATTRIBUTE_USED
#endif

/* Tell the compiler it should emit a warning if the return value of a function
   call is not used. */
#if __has_attribute(__warn_unused_result__)
#  define ATTRIBUTE_WARN_UNUSED_RESULT __attribute__ ((__warn_unused_result__))
#else
#  define ATTRIBUTE_WARN_UNUSED_RESULT
#endif

#endif /* ATTRIBUTES_H */
