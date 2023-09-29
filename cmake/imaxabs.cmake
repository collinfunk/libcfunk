
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/inttypes-h.cmake)

check_c_symbol("imaxabs" "inttypes.h")

set(LIBCFUNK_DECLARE_IMAXABS "1" CACHE INTERNAL "")

if (NOT HAVE_IMAXABS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/imaxabs.c
  )
endif ()
