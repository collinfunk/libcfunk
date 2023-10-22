
include_guard(GLOBAL)

# Generate <string.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_MATH_H "1" CACHE INTERNAL "")

check_include_file("math.h" HAVE_MATH_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-math-h.cmake)
endif ()

