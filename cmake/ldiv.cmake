
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("ldiv" "stdlib.h" HAVE_LDIV)
endif ()

set(LIBCFUNK_DECLARE_LDIV "1" CACHE STRING "")

if (NOT HAVE_LDIV OR LIBCFUNK_REPLACE_LDIV)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/ldiv.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ldiv.cmake)
endif ()

