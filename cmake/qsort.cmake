
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("qsort" "stdlib.h" HAVE_QSORT)
endif ()

set(LIBCFUNK_DECLARE_QSORT "1" CACHE STRING "")

if (NOT HAVE_QSORT OR LIBCFUNK_REPLACE_QSORT)
  include($CACHE{LIBCFUNK_MODULE_DIR}/qsort_r.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/qsort.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-qsort.cmake)
endif ()

