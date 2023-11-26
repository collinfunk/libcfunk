
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("bsearch" "stdlib.h" HAVE_BSEARCH)
endif ()

set(LIBCFUNK_DECLARE_BSEARCH "1" CACHE STRING "")

if (NOT HAVE_BSEARCH OR LIBCFUNK_REPLACE_BSEARCH)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/bsearch.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-bsearch.cmake)
endif ()

