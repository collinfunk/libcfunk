
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/math-h.cmake)

if (HAVE_MATH_H)
  check_symbol_exists("ceilf" "math.h" HAVE_CEILF)
endif ()

# TODO
if (NOT HAVE_CEILF)
  message(FATAL_ERROR "No implementation of 'ceilf' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ceilf.cmake)
endif ()

