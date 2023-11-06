
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

# Generate <sys/stat.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_STAT_H "1" CACHE STRING "")

check_include_file("sys/stat.h" HAVE_SYS_STAT_H)
check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_SYS_STAT_H)
  list(APPEND CMAKE_EXTRA_INCLUDE_FILES "sys/stat.h")
endif ()

list(REMOVE_DUPLICATES CMAKE_EXTRA_INCLUDE_FILES)

check_type_size("struct stat" STRUCT_STAT)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-stat-h.cmake)
endif ()

