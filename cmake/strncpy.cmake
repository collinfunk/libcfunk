include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("strncpy" "string.h")

set(LIBCFUNK_DECLARE_STRNCPY "1" CACHE INTERNAL "")

if (NOT HAVE_STRNCPY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strncpy.c
  )
endif ()
