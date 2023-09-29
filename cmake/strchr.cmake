include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("strchr" "string.h")

set(LIBCFUNK_DECLARE_STRCHR "1" CACHE INTERNAL "")

if (NOT HAVE_STRCHR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strchr.c
  )
endif ()
