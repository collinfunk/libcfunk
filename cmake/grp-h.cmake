
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stddef-h.cmake)

# Generate <grp.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_GRP_H "1" CACHE STRING "")

check_include_file("grp.h" HAVE_GRP_H)

if (HAVE_GRP_H)
  find_file(GRP_H_PATH NAMES "grp.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "grp.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("struct group" STRUCT_GROUP)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-grp-h.cmake)
endif ()

