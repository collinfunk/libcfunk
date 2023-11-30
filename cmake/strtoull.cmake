
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("strtoull" "stdlib.h" HAVE_STRTOULL)
endif ()

set(LIBCFUNK_DECLARE_STRTOULL "1" CACHE STRING "")

# Very few libc implementations support C23 binary strings.
set(LIBCFUNK_REPLACE_STRTOULL "1" CACHE STRING "")

if (NOT HAVE_STRTOULL OR LIBCFUNK_REPLACE_STRTOULL)
  include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/isdigit.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/isalpha.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strtoull.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strtoull.cmake)
endif ()
