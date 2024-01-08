
include_guard(GLOBAL)

# Assume we have this.
set(LIBCFUNK_GENERATE_STDBOOL_H "0" CACHE STRING "")

check_include_file("stdbool.h" HAVE_STDBOOL_H)

if (HAVE_STDBOOL_H)
  find_file(STDBOOL_H_PATH NAMES "stdbool.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdbool-h.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdbool-c23.cmake)
endif ()

