
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

check_c_symbol("bsearch" "stdlib.h")

set(LIBCFUNK_DECLARE_BSEARCH "1" CACHE INTERNAL "")

if (NOT HAVE_BSEARCH)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/bsearch.c
  )
endif ()

