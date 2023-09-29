
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

check_c_symbol("strncasecmp" "strings.h")

set(LIBCFUNK_DECLARE_STRNCASECMP "1" CACHE INTERNAL "")

if (NOT HAVE_STRNCASECMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strncasecmp.c
  )
endif ()

