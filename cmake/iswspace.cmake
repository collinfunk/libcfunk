
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wctype-h.cmake)

if (HAVE_WCTYPE_H)
  check_symbol_exists("iswspace" "wctype.h" HAVE_ISWSPACE)
else ()
  set(HAVE_ISWSPACE "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_ISWSPACE "1" CACHE INTERNAL "")

if (NOT HAVE_ISWSPACE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/iswspace.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

