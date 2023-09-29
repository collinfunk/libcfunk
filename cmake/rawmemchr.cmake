include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("rawmemchr" "string.h")

set(LIBCFUNK_DECLARE_RAWMEMCHR "1" CACHE INTERNAL "")

if (NOT HAVE_RAWMEMCHR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/rawmemchr.c
  )
endif ()
