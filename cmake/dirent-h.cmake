
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <dirent.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_DIRENT_H "1" CACHE STRING "")

check_include_file("dirent.h" HAVE_DIRENT_H)

if (HAVE_DIRENT_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "dirent.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

check_type_size("struct dirent" STRUCT_DIRENT)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-dirent-h.cmake)
endif ()

