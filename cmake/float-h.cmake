
include_guard(GLOBAL)

# Generate <float.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_FLOAT_H "1" CACHE STRING "")

check_include_file("float.h" HAVE_FLOAT_H)

if (HAVE_FLOAT_H)
  find_file(FLOAT_H_PATH NAMES "float.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-float-h.cmake)
endif ()

