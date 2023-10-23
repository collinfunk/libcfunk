
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wctype-h.cmake)

if (HAVE_WCTYPE_H)
  check_symbol_exists("iswprint" "wctype.h" HAVE_ISWPRINT)
else ()
  set(HAVE_ISWPRINT "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_ISWPRINT "1" CACHE INTERNAL "")

if (NOT HAVE_ISWPRINT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/iswprint.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

