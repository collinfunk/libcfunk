
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/math-h.cmake)

if (HAVE_MATH_H)
  check_symbol_exists("copysignf" "math.h" HAVE_COPYSIGNF)
endif ()

set(LIBCFUNK_DECLARE_COPYSIGNF "1" CACHE STRING "")

if (NOT HAVE_COPYSIGNF OR LIBCFUNK_REPLACE_COPYSIGNF)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/copysignf.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-copysignf.cmake)
endif ()

