
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("reallocarray" "stdlib.h" HAVE_REALLOCARRAY)
else ()
  set (HAVE_REALLOCARRAY "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_REALLOCARRAY "1" CACHE INTERNAL "")

if (NOT HAVE_REALLOCARRAY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/reallocarray.c
  )
endif ()

