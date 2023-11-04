
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-ext-h.cmake)

if (HAVE_STDIO_EXT_H)
  check_symbol_exists("__freadable" "stdio_ext.h" HAVE___FREADABLE)
endif ()

set(LIBCFUNK_DECLARE___FREADABLE "1" CACHE INTERNAL "")

if (NOT HAVE___FREADABLE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/__freadable.c
  )
endif ()

if (LIBCFUNK_MODULE_DIR)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-__freadable.cmake)
endif ()

