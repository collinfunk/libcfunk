
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/math-h.cmake)

if (HAVE_MATH_H)
  check_symbol_exists("copysign" "math.h" HAVE_COPYSIGN)
endif ()

set(LIBCFUNK_DECLARE_COPYSIGN "1" CACHE STRING "")

if (NOT HAVE_COPYSIGN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/copysign.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-copysign.cmake)
endif ()

