
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("aligned_alloc" "stdlib.h" HAVE_ALIGNED_ALLOC)
endif ()

# TODO
if (NOT HAVE_ALIGNED_ALLOC)
  message(FATAL_ERROR "No implementation of 'aligned_alloc' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-aligned_alloc.cmake)
endif ()

