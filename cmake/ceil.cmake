
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/math-h.cmake)

if (HAVE_MATH_H)
  check_symbol_exists("ceil" "math.h" HAVE_CEIL)
endif ()

# TODO
if (NOT HAVE_CEIL)
  message(FATAL_ERROR "No implementation of 'ceil' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ceil.cmake)
endif ()

