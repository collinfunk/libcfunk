
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wctype-h.cmake)

if (HAVE_WCTYPE_H)
  check_symbol_exists("towupper" "wctype.h" HAVE_TOWUPPER)
endif ()

set(LIBCFUNK_DECLARE_TOWUPPER "1" CACHE INTERNAL "")

if (NOT HAVE_TOWUPPER)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/towupper.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-towupper.cmake)
endif ()

