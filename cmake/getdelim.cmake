
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unlocked-stdio.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("getdelim" "stdio.h" HAVE_GETDELIM)
endif ()

set(LIBCFUNK_DECLARE_GETDELIM "1" CACHE INTERNAL "")

if (NOT HAVE_GETDELIM)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getdelim.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getdelim.cmake)
endif ()

