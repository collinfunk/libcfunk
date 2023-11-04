
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/math-h.cmake)

if (HAVE_MATH_H)
  check_symbol_exists("fabs" "math.h" HAVE_FABS)
endif ()

set(LIBCFUNK_DECLARE_FABS "1" CACHE INTERNAL "")

if (NOT HAVE_FABS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/fabs.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fabs.cmake)
endif ()

