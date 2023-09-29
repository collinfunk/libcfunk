
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

check_c_symbol("index" "strings.h")

set(LIBCFUNK_DECLARE_INDEX "1" CACHE INTERNAL "")

if (NOT HAVE_INDEX)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/index.c
  )
endif ()

