
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/math-h.cmake)

if (HAVE_MATH_H)
  check_symbol_exists("fabsf" "math.h" HAVE_FABSF)
endif ()

set(LIBCFUNK_DECLARE_FABSF "1" CACHE INTERNAL "")

if (NOT HAVE_FABSF)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/fabsf.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fabsf.cmake)
endif ()

