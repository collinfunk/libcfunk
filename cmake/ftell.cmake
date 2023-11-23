
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

set(LIBCFUNK_DECLARE_FTELL "1" CACHE STRING "")
set(LIBCFUNK_REPLACE_FTELL "1" CACHE STRING "")

if (LIBCFUNK_REPLACE_FTELL)
  include($CACHE{LIBCFUNK_MODULE_DIR}/ftello.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/limits-h.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/ftell.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ftell.cmake)
endif ()

