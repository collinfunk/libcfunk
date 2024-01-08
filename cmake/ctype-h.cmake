
include_guard(GLOBAL)

# Generate <ctype.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_CTYPE_H "1" CACHE STRING "")

check_include_file("ctype.h" HAVE_CTYPE_H)

if (HAVE_CTYPE_H)
  find_file(CTYPE_H_PATH NAMES "ctype.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ctype-h.cmake)
endif ()

