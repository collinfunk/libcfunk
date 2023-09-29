include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("memmove" "string.h")

set(LIBCFUNK_DECLARE_MEMMOVE "1" CACHE INTERNAL "")

if (NOT HAVE_MEMMOVE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/memmove.c
  )
endif ()
