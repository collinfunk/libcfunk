
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wctype-h.cmake)

if (HAVE_WCTYPE_H)
  check_symbol_exists("iswxdigit" "wctype.h" HAVE_ISWXDIGIT)
endif ()

set(LIBCFUNK_DECLARE_ISWXDIGIT "1" CACHE STRING "")

if (NOT HAVE_ISWXDIGIT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/iswxdigit.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-iswxdigit.cmake)
endif ()

