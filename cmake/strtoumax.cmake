
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/inttypes-h.cmake)

if (HAVE_INTTYPES_H)
  check_symbol_exists("strtoumax" "inttypes.h" HAVE_STRTOUMAX)
endif ()

set(LIBCFUNK_DECLARE_STRTOUMAX "1" CACHE STRING "")

# Very few libc implementations support C23 binary strings.
set(LIBCFUNK_REPLACE_STRTOUMAX "1" CACHE STRING "")

if (NOT HAVE_STRTOUMAX OR LIBCFUNK_REPLACE_STRTOUMAX)
  include($CACHE{LIBCFUNK_MODULE_DIR}/isdigit.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/isalpha.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strtoumax.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strtoumax.cmake)
endif ()

