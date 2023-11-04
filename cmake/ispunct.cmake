
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/ctype-h.cmake)

if (HAVE_CTYPE_H)
  check_symbol_exists("ispunct" "ctype.h" HAVE_ISPUNCT)
endif ()

set(LIBCFUNK_DECLARE_ISPUNCT "1" CACHE INTERNAL "")

if (NOT HAVE_ISPUNCT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/ispunct.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

