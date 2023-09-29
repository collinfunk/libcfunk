
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

check_c_symbol("strtoull" "stdlib.h")

set(LIBCFUNK_DECLARE_STRTOULL "1" CACHE INTERNAL "")

if (NOT HAVE_STRTOULL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strtoull.c
  )
endif ()

