
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/signal-h.cmake)

# Generate <sys/wait.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_WAIT_H "1" CACHE STRING "")

check_include_file("sys/wait.h" HAVE_SYS_WAIT_H)
check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_SYS_WAIT_H)
  find_file(SYS_WAIT_H_PATH NAMES "sys/wait.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/wait.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("idtype_t" IDTYPE_T)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-wait-h.cmake)
endif ()

