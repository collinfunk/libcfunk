
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wctype-h.cmake)

if (HAVE_WCTYPE_H)
  check_symbol_exists("iswupper" "wctype.h" HAVE_ISWUPPER)
else ()
  set(HAVE_ISWUPPER "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_ISWUPPER "1" CACHE INTERNAL "")

if (NOT HAVE_ISWUPPER)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/iswupper.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

