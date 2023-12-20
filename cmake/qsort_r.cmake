
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("qsort_r" "stdlib.h" HAVE_QSORT_R)
endif ()

if (NOT HAVE_QSORT_R)
  message(FATAL_ERROR "No implementation of 'qsort_r' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-qsort_r.cmake)
endif ()

