include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("strsep" "string.h")

set(LIBCFUNK_DECLARE_STRSEP "1" CACHE INTERNAL "")

if (NOT HAVE_STRSEP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strsep.c
  )
endif ()
