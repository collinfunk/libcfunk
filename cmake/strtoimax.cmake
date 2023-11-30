
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/inttypes-h.cmake)

if (HAVE_INTTYPES_H)
  check_symbol_exists("strtoimax" "inttypes.h" HAVE_STRTOIMAX)
endif ()

set(LIBCFUNK_DECLARE_STRTOIMAX "1" CACHE STRING "")

# Very few libc implementations support C23 binary strings.
set(LIBCFUNK_REPLACE_STRTOIMAX "1" CACHE STRING "")

if (NOT HAVE_STRTOIMAX OR LIBCFUNK_REPLACE_STRTOIMAX)
  include($CACHE{LIBCFUNK_MODULE_DIR}/isdigit.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/isalpha.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strtoimax.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strtoimax.cmake)
endif ()

