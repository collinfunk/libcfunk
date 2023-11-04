
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("rawmemchr" "string.h" HAVE_RAWMEMCHR)
endif ()

set(LIBCFUNK_DECLARE_RAWMEMCHR "1" CACHE STRING "")

if (NOT HAVE_RAWMEMCHR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/rawmemchr.c
  )
endif ()
