include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("strncmp" "string.h")

set(LIBCFUNK_DECLARE_STRNCMP "1" CACHE INTERNAL "")

if (NOT HAVE_STRNCMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strncmp.c
  )
endif ()
