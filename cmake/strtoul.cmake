
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("strtoul" "stdlib.h" HAVE_STRTOUL)
endif ()

set(LIBCFUNK_DECLARE_STRTOUL "1" CACHE STRING "")

# Very few libc implementations support C23 binary strings.
set(LIBCFUNK_REPLACE_STRTOUL "1" CACHE STRING "")

if (NOT HAVE_STRTOUL OR LIBCFUNK_REPLACE_STRTOUL)
  include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/isdigit.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/isalpha.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strtoul.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strtoul.cmake)
endif ()
