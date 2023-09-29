include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("memset" "string.h")

set(LIBCFUNK_DECLARE_MEMSET "1" CACHE INTERNAL "")

if (NOT HAVE_MEMSET)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/memset.c
  )
endif ()
