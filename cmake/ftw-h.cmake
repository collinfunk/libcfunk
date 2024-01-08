
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

# Generate <ftw.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_FTW_H "1" CACHE STRING "")

check_include_file("ftw.h" HAVE_FTW_H)

if (HAVE_FTW_H)
  find_file(FTW_H_PATH NAMES "ftw.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "ftw.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("struct FTW" STRUCT_FTW)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ftw-h.cmake)
endif ()

