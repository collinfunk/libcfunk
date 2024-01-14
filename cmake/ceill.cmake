
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/math-h.cmake)

if (HAVE_MATH_H)
  check_symbol_exists("ceill" "math.h" HAVE_CEILL)
endif ()

# TODO
if (NOT HAVE_CEILL)
  message(FATAL_ERROR "No implementation of 'ceill' for your system.")
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ceill.cmake)
endif ()

