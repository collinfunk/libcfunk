
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/ctype-h.cmake)

if (HAVE_CTYPE_H)
  check_symbol_exists("isgraph" "ctype.h" HAVE_ISGRAPH)
else ()
  set(HAVE_ISGRAPH "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_ISGRAPH "1" CACHE INTERNAL "")

if (NOT HAVE_ISGRAPH)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isgraph.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

