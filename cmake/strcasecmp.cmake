
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

check_c_symbol("strcasecmp" "strings.h")

set(LIBCFUNK_DECLARE_STRCASECMP "1" CACHE INTERNAL "")

if (NOT HAVE_STRCASECMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strcasecmp.c
  )
endif ()

