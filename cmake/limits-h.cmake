
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)

# Generate <limits.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_LIMITS_H "1" CACHE INTERNAL "")

check_c_system_headers("limits.h")

# Check if `char' is signed or unsigned.
check_c_compiles("
int
main (void)
{
  int array[1 - 2 * (((char) -1) < 0)];
  array[0] = 0;
  return array[0];
}" CHAR_IS_UNSIGNED)

# Signed integer types.
check_c_type_exists("signed char")
check_c_type_exists("short")
check_c_type_exists("int")
check_c_type_exists("long")
check_c_type_exists("long long")

check_c_type_exists("size_t")
check_c_type_exists("ssize_t")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-limits-h.cmake)
endif ()
