
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-ext-h.cmake)

if (HAVE_STDIO_EXT_H)
  check_symbol_exists("__freading" "stdio_ext.h" HAVE___FREADING)
endif ()

set(LIBCFUNK_DECLARE___FREADING "1" CACHE INTERNAL "")

if (NOT HAVE___FREADING)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/__freading.c
  )
endif ()

if (LIBCFUNK_MODULE_DIR)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-__freading.cmake)
endif ()

