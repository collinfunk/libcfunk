
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

check_c_symbol("llabs" "stdlib.h")

set(LIBCFUNK_DECLARE_LLABS "1" CACHE INTERNAL "")

if (NOT HAVE_LLABS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/llabs.c
  )
endif ()
