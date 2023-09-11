
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/inttypes-h.cmake)

if (HAVE_INTTYPES_H)
  check_symbol_exists("strtoumax" "inttypes.h" HAVE_STRTOUMAX)
else ()
  set(HAVE_STRTOUMAX "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_STRTOUMAX "1" CACHE INTERNAL "")

if (NOT HAVE_STRTOUMAX)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strtoumax.c
  )
endif ()
