
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("posix_memalign" "stdlib.h" HAVE_POSIX_MEMALIGN)
endif ()

# TODO
if (NOT HAVE_POSIX_MEMALIGN)
  message(FATAL_ERROR "No implementation of 'posix_memalign' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-posix_memalign.cmake)
endif ()

