include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("strcmp" "string.h")

set(LIBCFUNK_DECLARE_STRCMP "1" CACHE INTERNAL "")

if (NOT HAVE_STRCMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strcmp.c
  )
endif ()
