
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stddef-h.cmake)

# Generate <limits.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_LIMITS_H "1" CACHE STRING "")

check_include_file("limits.h" HAVE_LIMITS_H)
check_include_file("sys/param.h" HAVE_SYS_PARAM_H)

# Check if `char' is signed or unsigned.
check_c_source_compiles("
int
main (void)
{
  int array[1 - 2 * (((char) -1) < 0)];
  array[0] = 0;
  return array[0];
}" CHAR_IS_UNSIGNED)

# Signed integer types.
check_type_size("char" SIZEOF_CHAR)
check_type_size("short" SIZEOF_SHORT)
check_type_size("int" SIZEOF_INT)
check_type_size("long" SIZEOF_LONG)
check_type_size("long long" SIZEOF_LONG_LONG)

check_type_size("ssize_t" SSIZE_T)

# This assumption is checked in 'libcfunk-init.cmake'.
set(CHAR_BIT "8" CACHE STRING "")

math(EXPR SCHAR_WIDTH "${SIZEOF_CHAR} * ${CHAR_BIT}")
math(EXPR SHRT_WIDTH "${SIZEOF_SHORT} * ${CHAR_BIT}")
math(EXPR INT_WIDTH "${SIZEOF_INT} * ${CHAR_BIT}")
math(EXPR LONG_WIDTH "${SIZEOF_LONG} * ${CHAR_BIT}")
math(EXPR LLONG_WIDTH "${SIZEOF_LONG_LONG}* ${CHAR_BIT}")

# C23 signed type width macros.
set(SCHAR_WIDTH "${SCHAR_WIDTH}" CACHE STRING "")
set(SHRT_WIDTH "${SHRT_WIDTH}" CACHE STRING "")
set(INT_WIDTH "${INT_WIDTH}" CACHE STRING "")
set(LONG_WIDTH "${LONG_WIDTH}" CACHE STRING "")
set(LLONG_WIDTH "${LLONG_WIDTH}" CACHE STRING "")

# Clear the non-cache variables.
unset(SCHAR_WIDTH)
unset(SHRT_WIDTH)
unset(INT_WIDTH)
unset(LONG_WIDTH)
unset(LLONG_WIDTH)

# C23 unsigned type width macros.
set(UCHAR_WIDTH "${SCHAR_WIDTH}" CACHE STRING "")
set(USHRT_WIDTH "${SHRT_WIDTH}" CACHE STRING "")
set(UINT_WIDTH "${INT_WIDTH}" CACHE STRING "")
set(ULLONG_WIDTH "${LLONG_WIDTH}" CACHE STRING "")
set(ULONG_WIDTH "${LONG_WIDTH}" CACHE STRING "")

# POSIX type widths.
set(CHAR_BIT "${SCHAR_WIDTH}" CACHE STRING "")
set(WORD_BIT "${INT_WIDTH}" CACHE STRING "")
set(LONG_BIT "${LONG_WIDTH}" CACHE STRING "")

#  Set the '*_MAX' and '*_MIN' macros for signed types.
foreach (type SCHAR SHRT INT LONG LLONG)
  set(type_SUFFIX "")
  if ("${${type}_WIDTH}" STREQUAL "8")
    set(${type}_MAX "127")
  elseif ("${${type}_WIDTH}" STREQUAL "16")
    set(${type}_MAX "32767")
  elseif ("${${type}_WIDTH}" STREQUAL "32")
    set(${type}_MAX "2147483647")
  elseif ("${${type}_WIDTH}" STREQUAL "64")
    set(${type}_MAX "9223372036854775807")
  else ()
    message(FATAL_ERROR "Unknown value for '${type}_WIDTH'.")
  endif ()
  if ("${type}" STREQUAL "LONG")
    set(type_SUFFIX "L")
  elseif ("${type}" STREQUAL "LLONG")
    set(type_SUFFIX "LL")
  endif ()
  set(${type}_MAX "${${type}_MAX}${type_SUFFIX}" CACHE STRING "")
  unset(${type}_MAX)
  set(${type}_MIN "(-$CACHE{${type}_MAX} - 1${type_SUFFIX})" CACHE STRING "")
  unset(type_SUFFIX)
endforeach ()

#  Set the '*_MAX' macros for unsigned types.
foreach (type UCHAR USHRT UINT ULONG ULLONG)
  set(type_SUFFIX "")
  if ("${${type}_WIDTH}" STREQUAL "8")
    set(${type}_MAX "255")
  elseif ("${${type}_WIDTH}" STREQUAL "16")
    set(${type}_MAX "65535")
  elseif ("${${type}_WIDTH}" STREQUAL "32")
    set(${type}_MAX "4294967295")
  elseif ("${${type}_WIDTH}" STREQUAL "64")
    set(${type}_MAX "18446744073709551615")
  else ()
    message(FATAL_ERROR "Unknown value for '${type}_WIDTH'.")
  endif ()
  if ("${type}" STREQUAL "ULONG")
    set(type_SUFFIX "UL")
  elseif ("${type}" STREQUAL "ULLONG")
    set(type_SUFFIX "ULL")
  elseif ("${type}" STREQUAL "UINT")
    set(type_SUFFIX "U")
  elseif ("${${type}_WIDTH}" STREQUAL "${UINT_WIDTH}")
    set(type_SUFFIX "U")
  endif ()
  set(${type}_MAX "${${type}_MAX}${type_SUFFIX}" CACHE STRING "")
  unset(${type}_MAX)
  unset(type_SUFFIX)
endforeach ()

if (CHAR_IS_UNSIGNED)
  set(CHAR_WIDTH "${UCHAR_WIDTH}" CACHE STRING "")
else ()
  set(CHAR_WIDTH "${SCHAR_WIDTH}" CACHE STRING "")
  set(CHAR_MAX "${SCHAR_MAX}" CACHE STRING "")
  set(CHAR_MIN "${SCHAR_MIN}" CACHE STRING "")
endif ()

# GNU libc macros from before the other names were standardized.
set(LONG_LONG_MAX "${LLONG_MAX}" CACHE STRING "")
set(ULONG_LONG_MAX "${ULLONG_MAX}" CACHE STRING "")
set(LONG_LONG_MIN "${LLONG_MIN}" CACHE STRING "")

# Try to find the underlying type of 'ssize_t' for the maximum.
if (HAVE_SSIZE_T)
  math(EXPR SSIZE_WIDTH "${SSIZE_T}* ${CHAR_BIT}")
  foreach (type SCHAR SHRT INT LONG LLONG)
    if ("${SSIZE_WIDTH}" STREQUAL "${${type}_WIDTH}")
      set(SSIZE_MAX "${${type}_MAX}" CACHE STRING "")
      break ()
    endif ()
  endforeach ()
  unset(SSIZE_WIDTH)
else ()
  # TODO: Define to long int or something else?
  message(FATAL_ERROR "Your system does not define 'ssize_t'.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-limits-h.cmake)
endif ()

