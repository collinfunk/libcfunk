
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/strtol.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("atol" "stdlib.h" HAVE_ATOL)
else ()
  set(HAVE_ATOL "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_ATOL "1" CACHE INTERNAL "")

if (NOT HAVE_ATOL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/atol.c
  )
endif ()
