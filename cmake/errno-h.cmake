
include_guard(GLOBAL)

# Generate <errno.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_ERRNO_H "1" CACHE STRING "")

check_include_file("errno.h" HAVE_ERRNO_H)

if (HAVE_ERRNO_H)
  find_file(ERRNO_H_PATH NAMES "errno.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "errno.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("error_t" ERROR_T)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-errno-h.cmake)
endif ()

