
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <sys/mman.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_MMAN_H "1" CACHE STRING "")

check_include_file("sys/mman.h" HAVE_SYS_MMAN_H)

if (HAVE_SYS_MMAN_H)
  find_file(SYS_MMAN_H_PATH NAMES "sys/mman.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/mman.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-mman-h.cmake)
endif ()

