
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wctype-h.cmake)

if (HAVE_WCTYPE_H)
  check_symbol_exists("wctype" "wctype.h" HAVE_WCTYPE)
else ()
  set(HAVE_WCTYPE "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WCTYPE "1" CACHE INTERNAL "")

if (NOT HAVE_WCTYPE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wctype.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

