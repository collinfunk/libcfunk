
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

# BSD, GNU libc, etc.
check_include_file("sys/param.h" HAVE_SYS_PARAM_H)

# XSI extension.
check_struct_has_member("struct stat" "st_blksize" "sys/stat.h" HAVE_STRUCT_STAT_ST_BLKSIZE)
check_struct_has_member("struct stat" "st_blocks" "sys/stat.h" HAVE_STRUCT_STAT_ST_BLOCKS)

target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
  $CACHE{LIBCFUNK_SOURCE_DIR}/block-size.h
)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-block-size.cmake)
endif ()

