
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("labs" "stdlib.h" HAVE_LABS)
endif ()

set(LIBCFUNK_DECLARE_LABS "1" CACHE STRING "")

if (NOT HAVE_LABS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/labs.c
  )
endif ()
