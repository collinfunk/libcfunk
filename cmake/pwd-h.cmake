
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stddef-h.cmake)

# Generate <pwd.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_PWD_H "1" CACHE STRING "")

check_include_file("pwd.h" HAVE_PWD_H)

if (HAVE_PWD_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "pwd.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("struct passwd" STRUCT_PASSWD)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-pwd-h.cmake)
endif ()

