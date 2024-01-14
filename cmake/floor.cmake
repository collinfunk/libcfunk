
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/math-h.cmake)

if (HAVE_MATH_H)
  check_symbol_exists("floor" "math.h" HAVE_FLOOR)
endif ()

# TODO
if (NOT HAVE_FLOOR)
  message(FATAL_ERROR "No implementation of 'floor' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-floor.cmake)
endif ()

