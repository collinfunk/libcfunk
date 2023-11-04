
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("stpcpy" "string.h" HAVE_STPCPY)
endif ()

set(LIBCFUNK_DECLARE_STPCPY "1" CACHE STRING "")

if (NOT HAVE_STPCPY)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/stpcpy.c
  )
endif ()
