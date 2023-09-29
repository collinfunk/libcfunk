include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("strndup" "string.h")

set(LIBCFUNK_DECLARE_STRNDUP "1" CACHE INTERNAL "")

if (NOT HAVE_STRNDUP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strndup.c
  )
endif ()
