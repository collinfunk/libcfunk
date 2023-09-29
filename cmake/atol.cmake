
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/strtol.cmake)

check_c_symbol("atol" "stdlib.h")

set(LIBCFUNK_DECLARE_ATOL "1" CACHE INTERNAL "")

if (NOT HAVE_ATOL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/atol.c
  )
endif ()
