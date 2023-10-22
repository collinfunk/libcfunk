
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/math-h.cmake)

if (HAVE_MATH_H)
  check_symbol_exists("fabsl" "math.h" HAVE_FABSL)
else ()
  set(HAVE_FABSL "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_FABSL "1" CACHE INTERNAL "")

if (NOT HAVE_FABSL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/fabsl.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fabsl.cmake)
endif ()

