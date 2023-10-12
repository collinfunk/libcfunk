
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-ext-h.cmake)

if (HAVE_STDIO_EXT_H)
  check_symbol_exists("__fbufsize" "stdio_ext.h" HAVE___FBUFSIZE)
else ()
  set(HAVE___FBUFSIZE "0" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE___FBUFSIZE "1" CACHE INTERNAL "")

if (NOT HAVE___FBUFSIZE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/__fbufsize.c
  )
endif ()

if (LIBCFUNK_MODULE_DIR)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-__fbufsize.cmake)
endif ()

