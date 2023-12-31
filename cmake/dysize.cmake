
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

if (HAVE_TIME_H)
  check_symbol_exists("dysize" "time.h" HAVE_DYSIZE)
endif ()

set(LIBCFUNK_DECLARE_DYSIZE "1" CACHE STRING "")

if (NOT HAVE_DYSIZE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/dysize.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-dysize.cmake)
endif ()

