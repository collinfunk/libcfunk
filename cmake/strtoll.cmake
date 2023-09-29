
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

check_c_symbol("strtoll" "stdlib.h")

set(LIBCFUNK_DECLARE_STRTOLL "1" CACHE INTERNAL "")

if (NOT HAVE_STRTOLL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strtoll.c
  )
endif ()

