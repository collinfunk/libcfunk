include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("strdup" "string.h")

set(LIBCFUNK_DECLARE_STRDUP "1" CACHE INTERNAL "")

if (NOT HAVE_STRDUP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strdup.c
  )
endif ()
