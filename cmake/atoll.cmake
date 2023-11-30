
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("atoll" "stdlib.h" HAVE_ATOLL)
endif ()

set(LIBCFUNK_DECLARE_ATOLL "1" CACHE STRING "")

if (NOT HAVE_ATOLL)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strtoll.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/atoll.c
  )
endif ()
