
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)

# Generate <stdint.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDINT_H "1" CACHE STRING "")

check_include_file("stdint.h" HAVE_STDINT_H)
check_include_file("inttypes.h" HAVE_INTTYPES_H)
check_include_file("wchar.h" HAVE_WCHAR_H)

if (HAVE_INTTYPES_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "inttypes.h")
endif ()

if (HAVE_WCHAR_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "wchar.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

# Signed exact-width integer types.
check_type_size("int8_t" INT8_T)
check_type_size("int16_t" INT16_T)
check_type_size("int32_t" INT32_T)
check_type_size("int64_t" INT64_T)

# Unsigned exact-width integer types.
check_type_size("uint8_t" UINT8_T)
check_type_size("uint16_t" UINT16_T)
check_type_size("uint32_t" UINT32_T)
check_type_size("uint64_t" UINT64_T)

# Signed minimum-width integer types.
check_type_size("int_least8_t" INT_LEAST8_T)
check_type_size("int_least16_t" INT_LEAST16_T)
check_type_size("int_least32_t" INT_LEAST32_T)
check_type_size("int_least64_t" INT_LEAST64_T)

# Unsigned minimum-width integer types.
check_type_size("uint_least8_t" UINT_LEAST8_T)
check_type_size("uint_least16_t" UINT_LEAST16_T)
check_type_size("uint_least32_t" UINT_LEAST32_T)
check_type_size("uint_least64_t" UINT_LEAST64_T)

# Signed fastest-width integer types.
check_type_size("int_fast8_t" INT_FAST8_T)
check_type_size("int_fast16_t" INT_FAST16_T)
check_type_size("int_fast32_t" INT_FAST32_T)
check_type_size("int_fast64_t" INT_FAST64_T)

# Unsigned fastest-width integer types.
check_type_size("uint_fast8_t" UINT_FAST8_T)
check_type_size("uint_fast16_t" UINT_FAST16_T)
check_type_size("uint_fast32_t" UINT_FAST32_T)
check_type_size("uint_fast64_t" UINT_FAST64_T)

# Integer types capable of holding object pointers.
check_type_size("intptr_t" INTPTR_T)
check_type_size("uintptr_t" UINTPTR_T)

# Greatest-width integer types.
check_type_size("intmax_t" INTMAX_T)
check_type_size("uintmax_t" UINTMAX_T)

# Other types which have macros in 'stdint.h'.
check_type_size("size_t" SIZE_T)
check_type_size("ptrdiff_t" PTRDIFF_T)
check_type_size("wchar_t" WCHAR_T)
check_type_size("wint_t" WINT_T)

# Width of fixed-width signed types.
set(INT8_WIDTH "8" CACHE STRING "")
set(INT16_WIDTH "16" CACHE STRING "")
set(INT32_WIDTH "32" CACHE STRING "")
set(INT64_WIDTH "64" CACHE STRING "")

# Width of fixed-width unsigned types.
set(UINT8_WIDTH "${INT8_WIDTH}" CACHE STRING "")
set(UINT16_WIDTH "${INT16_WIDTH}" CACHE STRING "")
set(UINT32_WIDTH "${INT32_WIDTH}" CACHE STRING "")
set(UINT64_WIDTH "${INT64_WIDTH}" CACHE STRING "")

if (HAVE_INT_LEAST8_T)
  math(EXPR INT_LEAST8_WIDTH "${INT_LEAST8_T} * ${CHAR_BIT}")
  set(INT_LEAST8_WIDTH "${INT_LEAST8_WIDTH}" CACHE STRING "")
  unset(INT_LEAST8_WIDTH)
else ()
  set(INT_LEAST8_WIDTH "${INT8_WIDTH}" CACHE STRING "")
endif ()

if (HAVE_INT_LEAST16_T)
  math(EXPR INT_LEAST16_WIDTH "${INT_LEAST16_T} * ${CHAR_BIT}")
  set(INT_LEAST16_WIDTH "${INT_LEAST16_WIDTH}" CACHE STRING "")
  unset(INT_LEAST16_WIDTH)
else ()
  set(INT_LEAST16_WIDTH "${INT16_WIDTH}" CACHE STRING "")
endif ()

if (HAVE_INT_LEAST32_T)
  math(EXPR INT_LEAST32_WIDTH "${INT_LEAST32_T} * ${CHAR_BIT}")
  set(INT_LEAST32_WIDTH "${INT_LEAST32_WIDTH}" CACHE STRING "")
  unset(INT_LEAST32_WIDTH)
else ()
  set(INT_LEAST32_WIDTH "${INT32_WIDTH}" CACHE STRING "")
endif ()

if (HAVE_INT_LEAST64_T)
  math(EXPR INT_LEAST64_WIDTH "${INT_LEAST64_T} * ${CHAR_BIT}")
  set(INT_LEAST64_WIDTH "${INT_LEAST64_WIDTH}" CACHE STRING "")
  unset(INT_LEAST64_WIDTH)
else ()
  set(INT_LEAST64_WIDTH "${INT64_WIDTH}" CACHE STRING "")
endif ()

if (HAVE_UINT_LEAST8_T)
  math(EXPR UINT_LEAST8_WIDTH "${UINT_LEAST8_T} * ${CHAR_BIT}")
  set(UINT_LEAST8_WIDTH "${UINT_LEAST8_WIDTH}" CACHE STRING "")
  unset(UINT_LEAST8_WIDTH)
else ()
  set(UINT_LEAST8_WIDTH "${INT_LEAST8_WIDTH}" CACHE STRING "")
endif ()

if (HAVE_UINT_LEAST16_T)
  math(EXPR UINT_LEAST16_WIDTH "${UINT_LEAST16_T} * ${CHAR_BIT}")
  set(UINT_LEAST16_WIDTH "${UINT_LEAST16_WIDTH}" CACHE STRING "")
  unset(UINT_LEAST16_WIDTH)
else ()
  set(UINT_LEAST16_WIDTH "${INT_LEAST16_WIDTH}" CACHE STRING "")
endif ()

if (HAVE_UINT_LEAST32_T)
  math(EXPR UINT_LEAST32_WIDTH "${UINT_LEAST32_T} * ${CHAR_BIT}")
  set(UINT_LEAST32_WIDTH "${UINT_LEAST32_WIDTH}" CACHE STRING "")
  unset(UINT_LEAST32_WIDTH)
else ()
  set(UINT_LEAST32_WIDTH "${INT_LEAST32_WIDTH}" CACHE STRING "")
endif ()

if (HAVE_UINT_LEAST64_T)
  math(EXPR UINT_LEAST64_WIDTH "${UINT_LEAST64_T} * ${CHAR_BIT}")
  set(UINT_LEAST64_WIDTH "${UINT_LEAST64_WIDTH}" CACHE STRING "")
  unset(UINT_LEAST64_WIDTH)
else ()
  set(UINT_LEAST64_WIDTH "${INT_LEAST64_WIDTH}" CACHE STRING "")
endif ()

if (HAVE_INT_FAST8_T)
  math(EXPR INT_FAST8_WIDTH "${INT_FAST8_T} * ${CHAR_BIT}")
  set(INT_FAST8_WIDTH "${INT_FAST8_WIDTH}" CACHE STRING "")
  unset(INT_FAST8_WIDTH)
else ()
  set(INT_FAST8_WIDTH "${INT8_WIDTH}" CACHE STRING "")
endif ()

if (HAVE_INT_FAST16_T)
  math(EXPR INT_FAST16_WIDTH "${INT_FAST16_T} * ${CHAR_BIT}")
  set(INT_FAST16_WIDTH "${INT_FAST16_WIDTH}" CACHE STRING "")
  unset(INT_FAST16_WIDTH)
else ()
  # Assume systems with 64-bit pointers have faster 64-bit integers.
  if (${CMAKE_SIZEOF_VOID_P} EQUAL 8)
    set(INT_FAST16_WIDTH "${INT64_WIDTH}" CACHE STRING "")
  else ()
    set(INT_FAST16_WIDTH "${INT32_WIDTH}" CACHE STRING "")
  endif ()
endif ()

if (HAVE_INT_FAST32_T)
  math(EXPR INT_FAST32_WIDTH "${INT_FAST32_T} * ${CHAR_BIT}")
  set(INT_FAST32_WIDTH "${INT_FAST32_WIDTH}" CACHE STRING "")
  unset(INT_FAST32_WIDTH)
else ()
  # Assume systems with 64-bit pointers have faster 64-bit integers.
  if (${CMAKE_SIZEOF_VOID_P} EQUAL 8)
    set(INT_FAST32_WIDTH "${INT64_WIDTH}" CACHE STRING "")
  else ()
    set(INT_FAST32_WIDTH "${INT32_WIDTH}" CACHE STRING "")
  endif ()
endif ()

if (HAVE_INT_FAST64_T)
  math(EXPR INT_FAST64_WIDTH "${INT_FAST64_T} * ${CHAR_BIT}")
  set(INT_FAST64_WIDTH "${INT_FAST64_WIDTH}" CACHE STRING "")
  unset(INT_FAST64_WIDTH)
else ()
  set(INT_FAST64_WIDTH "${INT64_WIDTH}" CACHE STRING "")
endif ()

if (HAVE_UINT_FAST8_T)
  math(EXPR UINT_FAST8_WIDTH "${UINT_FAST8_T} * ${CHAR_BIT}")
  set(UINT_FAST8_WIDTH "${UINT_FAST8_WIDTH}" CACHE STRING "")
  unset(UINT_FAST8_WIDTH)
else ()
  set(UINT_FAST8_WIDTH "${INT_FAST8_WIDTH}" CACHE STRING "")
endif ()

if (HAVE_UINT_FAST16_T)
  math(EXPR UINT_FAST16_WIDTH "${UINT_FAST16_T} * ${CHAR_BIT}")
  set(UINT_FAST16_WIDTH "${UINT_FAST16_WIDTH}" CACHE STRING "")
  unset(UINT_FAST16_WIDTH)
else ()
  set(UINT_FAST16_WIDTH "${INT_FAST16_WIDTH}" CACHE STRING "")
endif ()

if (HAVE_UINT_FAST32_T)
  math(EXPR UINT_FAST32_WIDTH "${UINT_FAST32_T} * ${CHAR_BIT}")
  set(UINT_FAST32_WIDTH "${UINT_FAST32_WIDTH}" CACHE STRING "")
  unset(UINT_FAST32_WIDTH)
else ()
  set(UINT_FAST32_WIDTH "${INT_FAST32_WIDTH}" CACHE STRING "")
endif ()

if (HAVE_UINT_FAST64_T)
  math(EXPR UINT_FAST64_WIDTH "${UINT_FAST64_T} * ${CHAR_BIT}")
  set(UINT_FAST64_WIDTH "${UINT_FAST64_WIDTH}" CACHE STRING "")
  unset(UINT_FAST64_WIDTH)
else ()
  set(UINT_FAST64_WIDTH "${INT_FAST64_WIDTH}" CACHE STRING "")
endif ()

if (HAVE_INTPTR_T)
  math(EXPR INTPTR_WIDTH "${INTPTR_T} * ${CHAR_BIT}")
  set(INTPTR_WIDTH "${INTPTR_WIDTH}" CACHE STRING "")
  unset(INTPTR_WIDTH)
else ()
  # Use the size of 'void *' instead.
  math(EXPR INTPTR_WIDTH "${CMAKE_SIZEOF_VOID_P} * ${CHAR_BIT}")
  set(INTPTR_WIDTH "${INTPTR_WIDTH}" CACHE STRING "")
  unset(INTPTR_WIDTH)
endif ()

if (HAVE_UINTPTR_T)
  math(EXPR UINTPTR_WIDTH "${UINTPTR_T} * ${CHAR_BIT}")
  set(UINTPTR_WIDTH "${UINTPTR_WIDTH}" CACHE STRING "")
  unset(UINTPTR_WIDTH)
else ()
  set(UINTPTR_WIDTH "${INTPTR_WIDTH}" CACHE STRING "")
endif ()

if (HAVE_INTMAX_T)
  math(EXPR INTMAX_WIDTH "${INTMAX_T} * ${CHAR_BIT}")
  set(INTMAX_WIDTH "${INTMAX_WIDTH}" CACHE STRING "")
  unset(INTMAX_WIDTH)
else ()
  # Assume that 64-bit integers are supported.
  set(INTMAX_WIDTH "${INT64_WIDTH}" CACHE STRING "")
endif ()

if (HAVE_UINTMAX_T)
  math(EXPR UINTMAX_WIDTH "${UINTMAX_T} * ${CHAR_BIT}")
  set(UINTMAX_WIDTH "${UINTMAX_WIDTH}" CACHE STRING "")
  unset(UINTMAX_WIDTH)
else ()
  set(UINTMAX_WIDTH "${INTMAX_WIDTH}" CACHE STRING "")
endif ()

if (HAVE_SIZE_T)
  math(EXPR SIZE_WIDTH "${SIZE_T} * ${CHAR_BIT}")
  set(SIZE_WIDTH "${SIZE_WIDTH}" CACHE STRING "")
  unset(SIZE_WIDTH)
else ()
  # TODO
endif ()

if (HAVE_PTRDIFF_T)
  math(EXPR PTRDIFF_WIDTH "${PTRDIFF_T} * ${CHAR_BIT}")
  set(PTRDIFF_WIDTH "${PTRDIFF_WIDTH}" CACHE STRING "")
  unset(PTRDIFF_WIDTH)
else ()
  # TODO
endif ()

foreach (int_type "INT8" "INT16" "INT32" "INT64"
    "INT_FAST8" "INT_FAST16" "INT_FAST32" "INT_FAST64"
    "INT_LEAST8" "INT_LEAST16" "INT_LEAST32" "INT_LEAST64"
    "INTPTR"
    "INTMAX"
    "PTRDIFF")
  if ("${${int_type}_WIDTH}" STREQUAL "${SCHAR_WIDTH}")
    set(${int_type}_MAX "${SCHAR_MAX}" CACHE STRING "")
    set(${int_type}_MIN "${SCHAR_MIN}" CACHE STRING "")
    set(${int_type}_TYPE "signed char" CACHE STRING "")
  elseif ("${${int_type}_WIDTH}" STREQUAL "${SHRT_WIDTH}")
    set(${int_type}_MAX "${SHRT_MAX}" CACHE STRING "")
    set(${int_type}_MIN "${SHRT_MIN}" CACHE STRING "")
    set(${int_type}_TYPE "short int" CACHE STRING "")
  elseif ("${${int_type}_WIDTH}" STREQUAL "${INT_WIDTH}")
    set(${int_type}_MAX "${INT_MAX}" CACHE STRING "")
    set(${int_type}_MIN "${INT_MIN}" CACHE STRING "")
    set(${int_type}_TYPE "int" CACHE STRING "")
  elseif ("${${int_type}_WIDTH}" STREQUAL "${LONG_WIDTH}")
    set(${int_type}_MAX "${LONG_MAX}" CACHE STRING "")
    set(${int_type}_MIN "${LONG_MIN}" CACHE STRING "")
    set(${int_type}_TYPE "long int" CACHE STRING "")
  elseif ("${${int_type}_WIDTH}" STREQUAL "${LLONG_WIDTH}")
    set(${int_type}_MAX "${LLONG_MAX}" CACHE STRING "")
    set(${int_type}_MIN "${LLONG_MIN}" CACHE STRING "")
    set(${int_type}_TYPE "long long int" CACHE STRING "")
  else ()
    message(FATAL_ERROR "Unknown type used for '${int_type} (${${int_type}_WIDTH} bits).")
  endif ()
endforeach ()

foreach (int_type "UINT8" "UINT16" "UINT32" "UINT64"
    "UINT_FAST8" "UINT_FAST16" "UINT_FAST32" "UINT_FAST64"
    "UINT_LEAST8" "UINT_LEAST16" "UINT_LEAST32" "UINT_LEAST64"
    "UINTPTR"
    "UINTMAX"
    "SIZE")
  if ("${${int_type}_WIDTH}" STREQUAL "${UCHAR_WIDTH}")
    set(${int_type}_MAX "${UCHAR_MAX}" CACHE STRING "")
    set(${int_type}_MIN "${UCHAR_MIN}" CACHE STRING "")
    set(${int_type}_TYPE "unsigned char" CACHE STRING "")
  elseif ("${${int_type}_WIDTH}" STREQUAL "${USHRT_WIDTH}")
    set(${int_type}_MAX "${USHRT_MAX}" CACHE STRING "")
    set(${int_type}_MIN "${USHRT_MIN}" CACHE STRING "")
    set(${int_type}_TYPE "unsigned short int" CACHE STRING "")
  elseif ("${${int_type}_WIDTH}" STREQUAL "${UINT_WIDTH}")
    set(${int_type}_MAX "${UINT_MAX}" CACHE STRING "")
    set(${int_type}_MIN "${UINT_MIN}" CACHE STRING "")
    set(${int_type}_TYPE "unsigned int" CACHE STRING "")
  elseif ("${${int_type}_WIDTH}" STREQUAL "${ULONG_WIDTH}")
    set(${int_type}_MAX "${ULONG_MAX}" CACHE STRING "")
    set(${int_type}_MIN "${ULONG_MIN}" CACHE STRING "")
    set(${int_type}_TYPE "unsigned long int" CACHE STRING "")
  elseif ("${${int_type}_WIDTH}" STREQUAL "${ULLONG_WIDTH}")
    set(${int_type}_MAX "${ULLONG_MAX}" CACHE STRING "")
    set(${int_type}_MIN "${ULLONG_MIN}" CACHE STRING "")
    set(${int_type}_TYPE "unsigned long long int" CACHE STRING "")
  else ()
    message(FATAL_ERROR "Unknown type used for '${int_type} (${${int_type}_WIDTH} bits).")
  endif ()
endforeach ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdint-h.cmake)
endif ()
