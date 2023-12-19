
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("qsort" "stdlib.h" HAVE_QSORT)
endif ()

if (NOT HAVE_QSORT)
  message(FATAL_ERROR "No implementation of 'qsort' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-qsort.cmake)
endif ()

