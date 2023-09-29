include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("strrchr" "string.h")

set(LIBCFUNK_DECLARE_STRRCHR "1" CACHE INTERNAL "")

if (NOT HAVE_STRRCHR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strrchr.c
  )
endif ()
