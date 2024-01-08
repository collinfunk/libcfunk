
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stdint-h.cmake)

# Generate <unistd.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_UNISTD_H "1" CACHE STRING "")

check_include_file("unistd.h" HAVE_UNISTD_H)
check_include_file("io.h" HAVE_IO_H)
check_include_file("direct.h" HAVE_DIRECT_H)

if (HAVE_UNISTD_H)
  find_file(UNISTD_H_PATH NAMES "unistd.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "unistd.h")
endif ()
if (HAVE_IO_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "io.h")
endif()
if (HAVE_DIRECT_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "direct.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-unistd-h.cmake)
endif ()

