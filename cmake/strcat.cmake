include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("strcat" "string.h")

set(LIBCFUNK_DECLARE_STRCAT "1" CACHE INTERNAL "")

if (NOT HAVE_STRCAT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strcat.c
  )
endif ()
