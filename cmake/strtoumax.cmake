
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/inttypes-h.cmake)

check_c_symbol("strtoumax" "inttypes.h")

set(LIBCFUNK_DECLARE_STRTOUMAX "1" CACHE INTERNAL "")

if (NOT HAVE_STRTOUMAX)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strtoumax.c
  )
endif ()
