
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/math-h.cmake)

if (HAVE_MATH_H)
  check_symbol_exists("copysignf" "math.h" HAVE_COPYSIGNF)
else ()
  set(HAVE_COPYSIGNF "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_COPYSIGNF "1" CACHE INTERNAL "")

if (NOT HAVE_COPYSIGNF)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/copysignf.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-copysignf.cmake)
endif ()

