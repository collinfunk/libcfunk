
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("qsort_r" "stdlib.h" HAVE_QSORT_R)
endif ()

set(LIBCFUNK_DECLARE_QSORT_R "1" CACHE STRING "")

if (NOT HAVE_QSORT_R OR LIBCFUNK_REPLACE_QSORT_R)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/qsort_r.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-qsort_r.cmake)
endif ()

