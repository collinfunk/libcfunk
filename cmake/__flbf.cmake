
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-ext-h.cmake)

if (HAVE_STDIO_EXT_H)
  check_symbol_exists("__flbf" "stdio_ext.h" HAVE___FLBF)
endif ()

set(LIBCFUNK_DECLARE___FLBF "1" CACHE INTERNAL "")

if (NOT HAVE___FLBF)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/__flbf.c
  )
endif ()

if (LIBCFUNK_MODULE_DIR)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-__flbf.cmake)
endif ()

