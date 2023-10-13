
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/fsync.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("fdatasync" "unistd.h" HAVE_FDATASYNC)
else ()
  set(HAVE_FDATASYNC "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_FDATASYNC "1" CACHE INTERNAL "")

if (NOT HAVE_FDATASYNC)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/fdatasync.c
  )
endif ()
