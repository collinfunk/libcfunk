
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

check_c_symbol("strtoul" "stdlib.h")

set(LIBCFUNK_DECLARE_STRTOUL "1" CACHE INTERNAL "")

if (NOT HAVE_STRTOUL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strtoul.c
  )
endif ()

