
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/ctype-h.cmake)

if (HAVE_CTYPE_H)
  check_symbol_exists("toupper" "ctype.h" HAVE_TOUPPER)
endif ()

set(LIBCFUNK_DECLARE_TOUPPER "1" CACHE STRING "")

if (NOT HAVE_TOUPPER)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/toupper.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-toupper.cmake)
endif ()

