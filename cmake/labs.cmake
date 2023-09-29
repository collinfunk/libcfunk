
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

check_c_symbol("labs" "stdlib.h")

set(LIBCFUNK_DECLARE_LABS "1" CACHE INTERNAL "")

if (NOT HAVE_LABS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/labs.c
  )
endif ()
