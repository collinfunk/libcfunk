
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

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-limits-h.cmake)
endif ()

