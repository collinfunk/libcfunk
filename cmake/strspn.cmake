include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("strspn" "string.h")

set(LIBCFUNK_DECLARE_STRSPN "1" CACHE INTERNAL "")

if (NOT HAVE_STRSPN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strspn.c
  )
endif ()
