
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/math-h.cmake)

if (HAVE_MATH_H)
  check_symbol_exists("floorl" "math.h" HAVE_FLOORL)
endif ()

# TODO
if (NOT HAVE_FLOORL)
  message(FATAL_ERROR "No implementation of 'floorl' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-floorl.cmake)
endif ()

