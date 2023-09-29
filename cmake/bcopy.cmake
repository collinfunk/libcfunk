
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

check_c_symbol("bcopy" "strings.h")

set(LIBCFUNK_DECLARE_BCOPY "1" CACHE INTERNAL "")

if (NOT HAVE_BCOPY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/bcopy.c
  )
endif ()

