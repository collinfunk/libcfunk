
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <sys/msg.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_MSG_H "1" CACHE STRING "")

check_include_file("sys/msg.h" HAVE_SYS_MSG_H)

if (HAVE_SYS_MSG_H)
  find_file(SYS_MSG_H_PATH NAMES "sys/msg.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/msg.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-msg-h.cmake)
endif ()

