include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strcmp" "string.h" HAVE_STRCMP)
else ()
  set(HAVE_STRCMP "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_STRCMP "1" CACHE INTERNAL "")

if (NOT HAVE_STRCMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strcmp.c
  )
endif ()