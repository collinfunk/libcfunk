
include_guard(GLOBAL)

# Generate <error.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_ERROR_H "1" CACHE STRING "")

check_include_file("error.h" HAVE_ERROR_H)

if (HAVE_ERROR_H)
  find_file(ERROR_H_PATH NAMES "error.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-error-h.cmake)
endif ()

