
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("strtoll" "stdlib.h" HAVE_STRTOLL)
else ()
  set (HAVE_STRTOLL "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_STRTOLL "1" CACHE INTERNAL "")

if (NOT HAVE_STRTOLL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strtoll.c
  )
endif ()

