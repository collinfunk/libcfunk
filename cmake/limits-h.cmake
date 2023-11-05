
include_guard(GLOBAL)

# Generate <limits.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_LIMITS_H "1" CACHE STRING "")

check_include_file("limits.h" HAVE_LIMITS_H)

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

check_type_size("ssize_t" SIZEOF_SSIZE_T)

# This is checked by 'libcfunk-init.cmake'.
set(CHAR_BIT "8" CACHE STRING "")

# Calculate the widths of each type.
math(EXPR CHAR_WIDTH "${SIZEOF_CHAR} * ${CHAR_BIT}")
math(EXPR SHRT_WIDTH "${SIZEOF_SHORT} * ${CHAR_BIT}")
math(EXPR INT_WIDTH "${SIZEOF_INT} * ${CHAR_BIT}")
math(EXPR LONG_WIDTH "${SIZEOF_LONG} * ${CHAR_BIT}")
math(EXPR LLONG_WIDTH "${SIZEOF_LONG_LONG} * ${CHAR_BIT}")
math(EXPR SSIZE_WIDTH "${SIZEOF_SSIZE_T} * ${CHAR_BIT}")

# These macros are defined by POSIX and may be missing on some systems.
set(CHAR_BIT "8" CACHE STRING "")
set(WORD_BIT "${INT_WIDTH}" CACHE STRING "")
set(LONG_BIT "${LONG_WIDTH}" CACHE STRING "")

# C23 signed type width macros (and plain char).
set(CHAR_WIDTH "${CHAR_WIDTH}" CACHE STRING "")
set(SCHAR_WIDTH "${CHAR_WIDTH}" CACHE STRING "")
set(SHRT_WIDTH "${SHRT_WIDTH}" CACHE STRING "")
set(INT_WIDTH "${INT_WIDTH}" CACHE STRING "")
set(LONG_WIDTH "${LONG_WIDTH}" CACHE STRING "")
set(LLONG_WIDTH "${LLONG_WIDTH}" CACHE STRING "")

# C23 unsigned type width macros.
set(UCHAR_WIDTH "${CHAR_WIDTH}" CACHE STRING "")
set(USHRT_WIDTH "${SHRT_WIDTH}" CACHE STRING "")
set(UINT_WIDTH "${INT_WIDTH}" CACHE STRING "")
set(ULONG_WIDTH "${LONG_WIDTH}" CACHE STRING "")
set(ULLONG_WIDTH "${LLONG_WIDTH}" CACHE STRING "")

# Temporary variables to store the maximum value of signed types.
set(SCHAR_MAX "")
set(SHRT_MAX "")
set(INT_MAX "")
set(LONG_MAX "")
set(LLONG_MAX "")

# Get the maximum from the width. It is assumed all integers are two's
# complement and contain no padding bits.
foreach (int_type "SCHAR" "SHRT" "INT" "LONG" "LLONG")
  if (${${int_type}_WIDTH} EQUAL 8)
    set(${int_type}_MAX "0x7f")
  elseif (${${int_type}_WIDTH} EQUAL 16)
    set(${int_type}_MAX "0x7fff")
  elseif (${${int_type}_WIDTH} EQUAL 32)
    set(${int_type}_MAX "0x7fffffff")
  elseif (${${int_type}_WIDTH} EQUAL 64)
    set(${int_type}_MAX "0x7fffffffffffffff")
  else ()
    message(FATAL_ERROR "Unsupported width '${${int_type}_WIDTH}' for '${int_type}'.")
  endif ()
endforeach ()

# Set the signed maxiumum values in the cache.
set(SCHAR_MAX "${SCHAR_MAX}" CACHE STRING "")
set(SHRT_MAX "${SHRT_MAX}" CACHE STRING "")
set(INT_MAX "${INT_MAX}" CACHE STRING "")
set(LONG_MAX "${LONG_MAX}L" CACHE STRING "")
set(LLONG_MAX "${LLONG_MAX}LL" CACHE STRING "")

# Set the signed minimum values in the cache.
set(SCHAR_MIN "(-${SCHAR_MAX} - 1)" CACHE STRING "")
set(SHRT_MIN "(-${SHRT_MAX} - 1)" CACHE STRING "")
set(INT_MIN "(-${INT_MAX} - 1)" CACHE STRING "")
set(LONG_MIN "(-${LONG_MAX}L - 1L)" CACHE STRING "")
set(LLONG_MIN "(-${LLONG_MAX}LL - 1LL)" CACHE STRING "")

# Cleanup the temporary variables.
unset(SCHAR_MAX)
unset(SHRT_MAX)
unset(INT_MAX)
unset(LONG_MAX)
unset(LLONG_MAX)

# Temporary variables to store the maximum value of unsigned types.
set(UCHAR_MAX "")
set(USHRT_MAX "")
set(UINT_MAX "")
set(ULONG_MAX "")
set(ULLONG_MAX "")

# Get the maximum from the width.
foreach (int_type "UCHAR" "USHRT" "UINT" "ULONG" "ULLONG")
  if (${${int_type}_WIDTH} EQUAL 8)
    set(${int_type}_MAX "0xff")
  elseif (${${int_type}_WIDTH} EQUAL 16)
    set(${int_type}_MAX "0xffff")
  elseif (${${int_type}_WIDTH} EQUAL 32)
    set(${int_type}_MAX "0xffffffff")
  elseif (${${int_type}_WIDTH} EQUAL 64)
    set(${int_type}_MAX "0xffffffffffffffff")
  else ()
    message(FATAL_ERROR "Unsupported width '${${int_type}_WIDTH}' for '${int_type}'.")
  endif ()
endforeach ()

# Set the maximum value for 'unsigned char'.
if (${SCHAR_MAX} STREQUAL ${INT_MAX})
  set(UCHAR_MAX "${UCHAR_MAX}U" CACHE STRING "")
else ()
  set(UCHAR_MAX "${UCHAR_MAX}" CACHE STRING "")
endif ()

# Set the maximum value for 'unsigned short int'.
if (${SHRT_MAX} STREQUAL ${INT_MAX})
  set(USHRT_MAX "${USHRT_MAX}U" CACHE STRING "")
else ()
  set(USHRT_MAX "${USHRT_MAX}" CACHE STRING "")
endif ()

# Set the rest of the unsigned maximum values.
set(UINT_MAX "${UINT_MAX}U" CACHE STRING "")
set(ULONG_MAX "${ULONG_MAX}UL" CACHE STRING "")
set(ULLONG_MAX "${ULLONG_MAX}ULL" CACHE STRING "")

# Cleanup the temporary variables.
unset(UCHAR_MAX)
unset(USHRT_MAX)
unset(UINT_MAX)
unset(ULONG_MAX)
unset(ULLONG_MAX)

# The plain 'char' type may be signed or unsigned. Set its minimum and maximum
# values accordingly.
if (NOT CHAR_IS_UNSIGNED)
  set(CHAR_MIN "${SCHAR_MIN}" CACHE STRING "")
  set(CHAR_MAX "${SCHAR_MAX}" CACHE STRING "")
else ()
  set(CHAR_MAX "${UCHAR_MAX}" CACHE STRING "")
  if (${SCHAR_MAX} STREQUAL ${INT_MAX})
    set(CHAR_MIN "0U" CACHE STRING "")
  else ()
    set(CHAR_MIN "0" CACHE STRING "")
  endif ()
endif ()

# Figure out what 'ssize_t' is typedef'd as.
if (${SSIZE_WIDTH} EQUAL ${SCHAR_WIDTH})
  set(SSIZE_MAX "${SCHAR_MAX}" CACHE STRING "")
elseif (${SSIZE_WIDTH} EQUAL ${SHRT_WIDTH})
  set(SSIZE_MAX "${SHRT_MAX}" CACHE STRING "")
elseif (${SSIZE_WIDTH} EQUAL ${INT_WIDTH})
  set(SSIZE_MAX "${INT_MAX}" CACHE STRING "")
elseif (${SSIZE_WIDTH} EQUAL ${LONG_WIDTH})
  set(SSIZE_MAX "${LONG_MAX}" CACHE STRING "")
elseif (${SSIZE_WIDTH} EQUAL ${LLONG_WIDTH})
  set(SSIZE_MAX "${LLONG_MAX}" CACHE STRING "")
else ()
  message(FATAL_ERROR "Can't figure out what 'ssize_t' is typedef'd as.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-limits-h.cmake)
endif ()
