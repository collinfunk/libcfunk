
include_guard(GLOBAL)

# Generate <tar.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_TAR_H "1" CACHE STRING "")

check_include_file("tar.h" HAVE_TAR_H)

if (HAVE_TAR_H)
  find_file(TAR_H_PATH NAMES "tar.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-tar-h.cmake)
endif ()

