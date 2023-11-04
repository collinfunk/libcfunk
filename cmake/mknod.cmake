
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

if (HAVE_SYS_STAT_H)
  check_symbol_exists("mknod" "sys/stat.h" HAVE_MKNOD)
endif ()

check_include_file("windows.h" HAVE_WINDOWS_H)

set(LIBCFUNK_DECLARE_MKNOD "1" CACHE INTERNAL "")

if (NOT HAVE_MKNOD)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/mknod.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-mknod.cmake)
endif ()

