
include_guard(GLOBAL)

# Generate <assert.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_ASSERT_H "1" CACHE INTERNAL "")

check_include_file("assert.h" HAVE_ASSERT_H)

# Check for C23 static_assert or macro in assert.h
check_c_source_compiles("

#include <assert.h>

int
main (void)
{
  static_assert (5 * 5 == 25, \"Checking for C23 static assert.\");
  static_assert (5 * 5 == 25);
  return 0;
}
" HAVE_C23_STATIC_ASSERT)

# Check for C11 _Static_assert.
check_c_source_compiles("

int
main (void)
{
  _Static_assert (5 * 5 == 25, \"Checking for C11 static assert.\");
  _Static_assert (5 * 5 == 25);
  return 0;
}
" HAVE_C11_STATIC_ASSERT)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-assert-h.cmake)
endif ()

