
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-ext-h.cmake)

if (HAVE_STDIO_EXT_H)
  check_symbol_exists("__fwritable" "stdio_ext.h" HAVE___FWRITABLE)
endif ()

set(LIBCFUNK_DECLARE___FWRITABLE "1" CACHE INTERNAL "")

if (NOT HAVE___FWRITABLE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/__fwritable.c
  )
endif ()

if (LIBCFUNK_MODULE_DIR)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-__fwritable.cmake)
endif ()

