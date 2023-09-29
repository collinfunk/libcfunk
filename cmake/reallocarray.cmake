
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

check_c_symbol("reallocarray" "stdlib.h")

set(LIBCFUNK_DECLARE_REALLOCARRAY "1" CACHE INTERNAL "")

if (NOT HAVE_REALLOCARRAY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/reallocarray.c
  )
endif ()

