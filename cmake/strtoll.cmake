
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("strtoll" "stdlib.h" HAVE_STRTOLL)
endif ()

set(LIBCFUNK_DECLARE_STRTOLL "1" CACHE STRING "")

# Very few libc implementations support C23 binary strings.
set(LIBCFUNK_REPLACE_STRTOLL "1" CACHE STRING "")

if (NOT HAVE_STRTOLL OR LIBCFUNK_REPLACE_STRTOLL)
  include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/isdigit.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/isalpha.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strtoll.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strtoll.cmake)
endif ()
