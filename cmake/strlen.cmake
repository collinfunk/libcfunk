include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

check_c_symbol("strlen" "string.h")

set(LIBCFUNK_DECLARE_STRLEN "1" CACHE INTERNAL "")

if (NOT HAVE_STRLEN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strlen.c
  )
endif ()
