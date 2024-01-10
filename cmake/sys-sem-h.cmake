
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <sys/sem.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_SEM_H "1" CACHE STRING "")

check_include_file("sys/sem.h" HAVE_SYS_SEM_H)

if (HAVE_SYS_SEM_H)
  find_file(SYS_SEM_H_PATH NAMES "sys/sem.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/sem.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-sem-h.cmake)
endif ()

