
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/math-h.cmake)

if (HAVE_MATH_H)
  check_symbol_exists("floorf" "math.h" HAVE_FLOORF)
endif ()

# TODO
if (NOT HAVE_FLOORF)
  message(FATAL_ERROR "No implementation of 'floorf' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-floorf.cmake)
endif ()

