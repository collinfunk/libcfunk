
include_guard(GLOBAL)

# Generate <stdalign.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDALIGN_H "1" CACHE STRING "")

check_include_file("stdalign.h" HAVE_STDALIGN_H)

if (HAVE_STDALIGN_H)
  find_file(STDALIGN_H_PATH NAMES "stdalign.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdalign-h.cmake)
endif ()

