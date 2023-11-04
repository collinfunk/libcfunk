
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-ext-h.cmake)

if (HAVE_STDIO_EXT_H)
  check_symbol_exists("__fpending" "stdio_ext.h" HAVE___FPENDING)
endif ()

set(LIBCFUNK_DECLARE___FPENDING "1" CACHE INTERNAL "")

if (NOT HAVE___FPENDING)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/__fpending.c
  )
endif ()

if (LIBCFUNK_MODULE_DIR)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-__fpending.cmake)
endif ()

