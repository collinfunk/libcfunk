
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/ctype-h.cmake)

if (HAVE_CTYPE_H)
  check_symbol_exists("isalnum" "ctype.h" HAVE_ISALNUM)
else ()
  set(HAVE_ISALNUM "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_ISALNUM "1" CACHE INTERNAL "")

if (NOT HAVE_ISALNUM)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isalnum.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

