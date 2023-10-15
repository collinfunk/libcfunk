
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-ext-h.cmake)

if (HAVE_STDIO_EXT_H)
  check_symbol_exists("__fseterr" "stdio_ext.h" HAVE___FSETERR)
else ()
  set(HAVE___FSETERR "0" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE___FSETERR "1" CACHE INTERNAL "")

if (NOT HAVE___FSETERR)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/__fseterr.c
  )
endif ()

if (LIBCFUNK_MODULE_DIR)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-__fseterr.cmake)
endif ()
