
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/strtol.cmake)

check_c_symbol("atoi" "stdlib.h")

set(LIBCFUNK_DECLARE_ATOI "1" CACHE INTERNAL "")

if (NOT HAVE_ATOI)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/atoi.c
  )
endif ()
