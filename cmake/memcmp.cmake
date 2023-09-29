include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("memcmp" "string.h")

set(LIBCFUNK_DECLARE_MEMCMP "1" CACHE INTERNAL "")

if (NOT HAVE_MEMCMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/memcmp.c
  )
endif ()
