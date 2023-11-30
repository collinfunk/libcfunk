
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("atoi" "stdlib.h" HAVE_ATOI)
endif ()

set(LIBCFUNK_DECLARE_ATOI "1" CACHE STRING "")

if (NOT HAVE_ATOI)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strtol.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/atoi.c
  )
endif ()
