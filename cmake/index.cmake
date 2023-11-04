
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

if (HAVE_STRINGS_H)
  check_symbol_exists("index" "strings.h" HAVE_INDEX)
endif ()

set(LIBCFUNK_DECLARE_INDEX "1" CACHE STRING "")

if (NOT HAVE_INDEX OR LIBCFUNK_REPLACE_INDEX)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/index.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-index.cmake)
endif ()

