
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-ext-h.cmake)

if (HAVE_STDIO_EXT_H)
  check_symbol_exists("__fwriting" "stdio_ext.h" HAVE___FWRITING)
endif ()

set(LIBCFUNK_DECLARE___FWRITING "1" CACHE STRING "")

if (NOT HAVE___FWRITING)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/__fwriting.c
  )
endif ()

if (LIBCFUNK_MODULE_DIR)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-__fwriting.cmake)
endif ()

