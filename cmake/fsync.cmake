
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("fsync" "unistd.h" HAVE_FSYNC)
else ()
  set(HAVE_FSYNC "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_FSYNC "1" CACHE INTERNAL "")

if (NOT HAVE_FSYNC)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/fsync.c
  )
endif ()
