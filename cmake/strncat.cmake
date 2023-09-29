include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("strncat" "string.h")

set(LIBCFUNK_DECLARE_STRNCAT "1" CACHE INTERNAL "")

if (NOT HAVE_STRNCAT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strncat.c
  )
endif ()
