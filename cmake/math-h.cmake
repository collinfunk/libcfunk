
include_guard(GLOBAL)

# Generate <string.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_MATH_H "1" CACHE INTERNAL "")

check_include_file("math.h" HAVE_MATH_H)
check_include_file("tgmath.h" HAVE_TGMATH_H)

# FIXME: Safe to assume this exists?
target_link_libraries("$CACHE{LIBCFUNK_LIBRARY_NAME}" PUBLIC "m")
list(APPEND CMAKE_REQUIRED_LIBRARIES "m")

set(LIBCFUNK_DECLARE_COPYSIGN "" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_COPYSIGNF "" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_COPYSIGNL "" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_FABS "" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_FABSF "" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_FABSL "" CACHE INTERNAL "")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-math-h.cmake)
endif ()

