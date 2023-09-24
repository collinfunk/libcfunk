
include_guard(GLOBAL)

# Generate <limits.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_LIMITS_H "1" CACHE INTERNAL "")

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
check_type_size("signed char" SIZEOF_CHAR)
check_type_size("short" SIZEOF_SHORT)
check_type_size("int" SIZEOF_INT)
check_type_size("long" SIZEOF_LONG)
check_type_size("long long" SIZEOF_LONG_LONG)

check_type_size("size_t" SIZEOF_SIZE_T)
check_type_size("ssize_t" SIZEOF_SSIZE_T)

math(EXPR CHAR_WIDTH "${SIZEOF_CHAR} * 8")
math(EXPR SHRT_WIDTH "${SIZEOF_SHORT} * 8")
math(EXPR INT_WIDTH "${SIZEOF_INT} * 8")
math(EXPR LONG_WIDTH "${SIZEOF_LONG} * 8")
math(EXPR LONG_LONG_WIDTH "${SIZEOF_LONG_LONG} * 8")
math(EXPR SIZE_WIDTH "${SIZEOF_SIZE_T} * 8")
math(EXPR SSIZE_WIDTH "${SIZEOF_SSIZE_T} * 8")

set(SCHAR_WIDTH "${CHAR_WIDTH}" CACHE INTERNAL "")
set(SHRT_WIDTH "${SHRT_WIDTH}" CACHE INTERNAL "")
set(INT_WIDTH "${INT_WIDTH}" CACHE INTERNAL "")
set(LONG_WIDTH "${LONG_WIDTH}" CACHE INTERNAL "")
set(LONG_LONG_WIDTH "${LONG_LONG_WIDTH}" CACHE INTERNAL "")
set(SIZE_WIDTH "${SIZE_WIDTH}" CACHE INTERNAL "")
set(SSIZE_WIDTH "${SSIZE_WIDTH}" CACHE INTERNAL "")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-limits-h.cmake)
endif ()
