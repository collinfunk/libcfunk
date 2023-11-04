
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-ext-h.cmake)

if (HAVE_STDIO_EXT_H)
  check_symbol_exists("__fpurge" "stdio_ext.h" HAVE___FPURGE)
endif ()

set(LIBCFUNK_DECLARE___FPURGE "1" CACHE STRING "")

if (NOT HAVE___FPURGE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/__fpurge.c
  )
endif ()

if (LIBCFUNK_MODULE_DIR)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-__fpurge.cmake)
endif ()

