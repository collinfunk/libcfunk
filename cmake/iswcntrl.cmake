
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wctype-h.cmake)

if (HAVE_WCTYPE_H)
  check_symbol_exists("iswcntrl" "wctype.h" HAVE_ISWCNTRL)
endif ()

set(LIBCFUNK_DECLARE_ISWCNTRL "1" CACHE STRING "")

if (NOT HAVE_ISWCNTRL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/iswcntrl.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

