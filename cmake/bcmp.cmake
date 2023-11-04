
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

if (HAVE_STRINGS_H)
  check_symbol_exists("bcmp" "strings.h" HAVE_BCMP)
endif ()

set(LIBCFUNK_DECLARE_BCMP "1" CACHE STRING "")

if (NOT HAVE_BCMP OR LIBCFUNK_REPLACE_BCMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/bcmp.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-bcmp.cmake)
endif ()

