
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wctype-h.cmake)

if (HAVE_WCTYPE_H)
  check_symbol_exists("iswdigit" "wctype.h" HAVE_ISWDIGIT)
else ()
  set(HAVE_ISWDIGIT "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_ISWDIGIT "1" CACHE INTERNAL "")

if (NOT HAVE_ISWDIGIT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/iswdigit.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-iswdigit.cmake)
endif ()

