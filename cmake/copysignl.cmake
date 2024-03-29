
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/math-h.cmake)

if (HAVE_MATH_H)
  check_symbol_exists("copysignl" "math.h" HAVE_COPYSIGNL)
endif ()

set(LIBCFUNK_DECLARE_COPYSIGNL "1" CACHE STRING "")

if (NOT HAVE_COPYSIGNL OR LIBCFUNK_REPLACE_COPYSIGNL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/copysignl.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-copysignl.cmake)
endif ()

