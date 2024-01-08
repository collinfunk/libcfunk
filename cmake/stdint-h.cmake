
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stddef-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/signal-h.cmake)

# Generate <stdint.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDINT_H "1" CACHE STRING "")

check_include_file("stdint.h" HAVE_STDINT_H)
check_include_file("inttypes.h" HAVE_INTTYPES_H)
check_include_file("wchar.h" HAVE_WCHAR_H)

if (HAVE_STDINT_H)
  find_file(STDINT_H_PATH NAMES "stdint.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

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

foreach (type INTPTR UINTPTR PTRDIFF)
  if (HAVE_${type}_T)
    math(EXPR type_WIDTH "${${type}_T} * ${CHAR_BIT}")
  else ()
    math(EXPR type_WIDTH "${CMAKE_SIZEOF_VOID_P} * ${CHAR_BIT}")
  endif ()
  set(${type}_WIDTH "${type_WIDTH}" CACHE STRING "")
  unset(type_WIDTH)
endforeach ()

foreach (type INTMAX UINTMAX SIZE)
  if (HAVE_${type}_T)
    math(EXPR type_WIDTH "${${type}_T} * ${CHAR_BIT}")
  else ()
    math(EXPR type_WIDTH "8 * ${CHAR_BIT}")
  endif ()
  set(${type}_WIDTH "${type_WIDTH}" CACHE STRING "")
  unset(type_WIDTH)
endforeach ()

foreach (type INT8 INT16 INT32 INT64 UINT8 UINT16 UINT32 UINT64)
  if (HAVE_${type}_T)
    math(EXPR ${type}_WIDTH "${${type}_T} * ${CHAR_BIT}")
    set(${type}_WIDTH "${${type}_WIDTH}" CACHE STRING "")
    unset(${type}_WIDTH)
  else ()
    string(REGEX MATCH "U?INT([0-9]*)" type_WIDTH "${type}")
    set(${type}_WIDTH "${CMAKE_MATCH_1}" CACHE STRING "")
    unset(type_WIDTH)
  endif ()
endforeach ()

foreach (type INT_LEAST8 INT_LEAST16 INT_LEAST32 INT_LEAST64
    UINT_LEAST8 UINT_LEAST16 UINT_LEAST32 UINT_LEAST64)
  if (HAVE_${type}_T)
    math(EXPR ${type}_WIDTH "${${type}_T} * ${CHAR_BIT}")
    set(${type}_WIDTH "${${type}_WIDTH}" CACHE STRING "")
    unset(${type}_WIDTH)
  else ()
    string(REGEX MATCH "U?INT_LEAST([0-9]*)" type_WIDTH "${type}")
    set(${type}_WIDTH "${CMAKE_MATCH_1}" CACHE STRING "")
    unset(type_WIDTH)
  endif ()
endforeach ()

foreach (type INT_FAST8 INT_FAST16 INT_FAST32 INT_FAST64
    UINT_FAST8 UINT_FAST16 UINT_FAST32 UINT_FAST64)
  if (HAVE_${type}_T)
    math(EXPR ${type}_WIDTH "${${type}_T} * ${CHAR_BIT}")
    set(${type}_WIDTH "${${type}_WIDTH}" CACHE STRING "")
    unset(${type}_WIDTH)
  else ()
    string(REGEX MATCH "U?INT_FAST([0-9]*)" type_WIDTH "${type}")
    if ("${CMAKE_MATCH_1}" STREQUAL "8")
      set(${type}_WIDTH "${CMAKE_MATCH_1}" CACHE STRING "")
    elseif ("${INTPTR_WIDTH}" GREATER_EQUAL "${CMAKE_MATCH_1}")
      set(${type}_WIDTH "${INTPTR_WIDTH}" CACHE STRING "")
    else ()
      set(${type}_WIDTH "${CMAKE_MATCH_1}" CACHE STRING "")
    endif ()
    unset(type_WIDTH)
  endif ()
endforeach ()

foreach (type INT8 INT16 INT32 INT64
    INT_LEAST8 INT_LEAST16 INT_LEAST32 INT_LEAST64
    INT_FAST8 INT_FAST16 INT_FAST32 INT_FAST64
    INTPTR INTMAX PTRDIFF)
  if ("${${type}_WIDTH}" STREQUAL "${SCHAR_WIDTH}")
    set(${type}_MAX "${SCHAR_MAX}" CACHE STRING "")
    set(${type}_MIN "${SCHAR_MIN}" CACHE STRING "")
    set(${type}_TYPE "signed char" CACHE STRING "")
  elseif ("${${type}_WIDTH}" STREQUAL "${SHRT_WIDTH}")
    set(${type}_MAX "${SHRT_MAX}" CACHE STRING "")
    set(${type}_MIN "${SHRT_MIN}" CACHE STRING "")
    set(${type}_TYPE "short int" CACHE STRING "")
  elseif ("${${type}_WIDTH}" STREQUAL "${INT_WIDTH}")
    set(${type}_MAX "${INT_MAX}" CACHE STRING "")
    set(${type}_MIN "${INT_MIN}" CACHE STRING "")
    set(${type}_TYPE "int" CACHE STRING "")
  elseif ("${${type}_WIDTH}" STREQUAL "${LONG_WIDTH}")
    set(${type}_MAX "${LONG_MAX}" CACHE STRING "")
    set(${type}_MIN "${LONG_MIN}" CACHE STRING "")
    set(${type}_TYPE "long int" CACHE STRING "")
  elseif ("${${type}_WIDTH}" STREQUAL "${LLONG_WIDTH}")
    set(${type}_MAX "${LLONG_MAX}" CACHE STRING "")
    set(${type}_MIN "${LLONG_MIN}" CACHE STRING "")
    set(${type}_TYPE "long long int" CACHE STRING "")
  else ()
    message(FATAL_ERROR "Unknown value for '${type}_WIDTH'.")
  endif ()
endforeach ()

foreach (type UINT8 UINT16 UINT32 UINT64
    UINT_LEAST8 UINT_LEAST16 UINT_LEAST32 UINT_LEAST64
    UINT_FAST8 UINT_FAST16 UINT_FAST32 UINT_FAST64
    UINTPTR UINTMAX SIZE)
  if ("${${type}_WIDTH}" STREQUAL "${UCHAR_WIDTH}")
    set(${type}_MAX "${UCHAR_MAX}" CACHE STRING "")
    set(${type}_TYPE "unsigned char" CACHE STRING "")
  elseif ("${${type}_WIDTH}" STREQUAL "${USHRT_WIDTH}")
    set(${type}_MAX "${USHRT_MAX}" CACHE STRING "")
    set(${type}_TYPE "unsigned short int" CACHE STRING "")
  elseif ("${${type}_WIDTH}" STREQUAL "${UINT_WIDTH}")
    set(${type}_MAX "${UINT_MAX}" CACHE STRING "")
    set(${type}_TYPE "unsigned int" CACHE STRING "")
  elseif ("${${type}_WIDTH}" STREQUAL "${ULONG_WIDTH}")
    set(${type}_MAX "${ULONG_MAX}" CACHE STRING "")
    set(${type}_TYPE "unsigned long int" CACHE STRING "")
  elseif ("${${type}_WIDTH}" STREQUAL "${ULLONG_WIDTH}")
    set(${type}_MAX "${ULLONG_MAX}" CACHE STRING "")
    set(${type}_TYPE "unsigned long long int" CACHE STRING "")
  else ()
    message(FATAL_ERROR "Unknown value for '${type}_WIDTH'.")
  endif ()
endforeach ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdint-h.cmake)
endif ()
