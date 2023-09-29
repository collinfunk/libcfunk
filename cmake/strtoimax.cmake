
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/inttypes-h.cmake)

check_c_symbol("strtoimax" "inttypes.h")

set(LIBCFUNK_DECLARE_STRTOIMAX "1" CACHE INTERNAL "")

if (NOT HAVE_STRTOIMAX)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strtoimax.c
  )
endif ()
