
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("fdatasync" "unistd.h" HAVE_FDATASYNC)
endif ()

set(LIBCFUNK_DECLARE_FDATASYNC "1" CACHE STRING "")

if (NOT HAVE_FDATASYNC)
  include($CACHE{LIBCFUNK_MODULE_DIR}/fsync.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/fdatasync.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fdatasync.cmake)
endif ()

