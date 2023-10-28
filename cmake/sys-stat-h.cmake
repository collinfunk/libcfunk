
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

# Generate <sys/stat.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_SYS_STAT_H "1" CACHE INTERNAL "")

check_include_file("sys/stat.h" HAVE_SYS_STAT_H)
check_include_file("windows.h" HAVE_WINDOWS_H)

set(LIBCFUNK_DECLARE_CHMOD "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_FSTAT "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_LSTAT "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_MKDIR "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_MKFIFO "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_MKNOD "0" CACHE INTERNAL "")
set(LIBCFUNK_DECLARE_STAT "0" CACHE INTERNAL "")

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sys-stat-h.cmake)
endif ()

