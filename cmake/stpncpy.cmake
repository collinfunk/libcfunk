
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("stpncpy" "string.h" HAVE_STPNCPY)
endif ()

set(LIBCFUNK_DECLARE_STPNCPY "1" CACHE STRING "")

if (NOT HAVE_STPNCPY OR LIBCFUNK_REPLACE_STPNCPY)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strnlen.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/memcpy.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/memset.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/stpncpy.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stpncpy.cmake)
endif ()

