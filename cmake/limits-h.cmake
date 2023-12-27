
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

check_type_size("ssize_t" SIZEOF_SSIZE_T)

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

if (CHAR_IS_UNSIGNED)
  set(CHAR_WIDTH "${UCHAR_WIDTH}" CACHE STRING "")
else ()
  set(CHAR_WIDTH "${SCHAR_WIDTH}" CACHE STRING "")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-limits-h.cmake)
endif ()

