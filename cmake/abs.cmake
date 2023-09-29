
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

check_c_symbol("abs" "stdlib.h")

set(LIBCFUNK_DECLARE_ABS "1" CACHE INTERNAL "")

if (NOT HAVE_ABS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/abs.c
  )
endif ()
