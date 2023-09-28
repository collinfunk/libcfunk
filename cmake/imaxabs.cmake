
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/inttypes-h.cmake)

if (HAVE_INTTYPES_H)
  check_symbol_exists("imaxabs" "inttypes.h" HAVE_IMAXABS)
else ()
  set(HAVE_IMAXABS "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_IMAXABS "1" CACHE INTERNAL "")

if (NOT HAVE_IMAXABS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/imaxabs.c
  )
endif ()
