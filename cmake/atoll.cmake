
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/strtoll.cmake)

check_c_symbol("atoll" "stdlib.h")

set(LIBCFUNK_DECLARE_ATOLL "1" CACHE INTERNAL "")

if (NOT HAVE_ATOLL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/atoll.c
  )
endif ()
