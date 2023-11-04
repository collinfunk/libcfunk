
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)

if (HAVE_SYS_STAT_H)
  check_symbol_exists("lstat" "sys/stat.h" HAVE_LSTAT)
endif ()

set(LIBCFUNK_DECLARE_LSTAT "1" CACHE INTERNAL "")

if (NOT HAVE_LSTAT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/lstat.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-lstat.cmake)
endif ()

