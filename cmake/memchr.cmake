include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("memchr" "string.h")

set(LIBCFUNK_DECLARE_MEMCHR "1" CACHE INTERNAL "")

if (NOT HAVE_MEMCHR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/memchr.c
  )
endif ()
