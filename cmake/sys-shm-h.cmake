
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <sys/shm.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_SHM_H "1" CACHE STRING "")

check_include_file("sys/shm.h" HAVE_SYS_SHM_H)

if (HAVE_SYS_SHM_H)
  find_file(SYS_SHM_H_PATH NAMES "sys/shm.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/shm.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-shm-h.cmake)
endif ()

