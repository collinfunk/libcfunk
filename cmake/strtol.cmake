
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("strtol" "stdlib.h" HAVE_STRTOL)
endif ()

set(LIBCFUNK_DECLARE_STRTOL "1" CACHE STRING "")

# Very few libc implementations support C23 binary strings.
set(LIBCFUNK_REPLACE_STRTOL "1" CACHE STRING "")

if (NOT HAVE_STRTOL OR LIBCFUNK_REPLACE_STRTOL)
  include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/isdigit.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/isalpha.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strtol.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strtol.cmake)
endif ()

