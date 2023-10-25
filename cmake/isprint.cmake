
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/ctype-h.cmake)

if (HAVE_CTYPE_H)
  check_symbol_exists("isprint" "ctype.h" HAVE_ISPRINT)
else ()
  set(HAVE_ISPRINT "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_ISPRINT "1" CACHE INTERNAL "")

if (NOT HAVE_ISPRINT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isprint.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

