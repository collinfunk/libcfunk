
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <sys/statvfs.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_STATVFS_H "1" CACHE STRING "")

check_include_file("sys/statvfs.h" HAVE_SYS_STATVFS_H)

if (HAVE_SYS_STATVFS_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/statvfs.h")
  list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)
  check_type_size("struct statvfs" STRUCT_STATVFS)
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-statvfs-h.cmake)
endif ()

