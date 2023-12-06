
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/inttypes-h.cmake)

if (HAVE_INTTYPES_H)
  check_symbol_exists("imaxabs" "inttypes.h" HAVE_IMAXABS)
endif ()

set(LIBCFUNK_DECLARE_IMAXABS "1" CACHE STRING "")

if (NOT HAVE_IMAXABS OR LIBCFUNK_REPLACE_IMAXABS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/imaxabs.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-imaxabs.cmake)
endif ()

