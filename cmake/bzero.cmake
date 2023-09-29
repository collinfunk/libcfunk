
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

check_c_symbol("bzero" "strings.h")

set(LIBCFUNK_DECLARE_BZERO "1" CACHE INTERNAL "")

if (NOT HAVE_BZERO)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/bzero.c
  )
endif ()

