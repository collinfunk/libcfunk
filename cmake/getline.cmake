
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("getline" "stdio.h" HAVE_GETLINE)
endif ()

set(LIBCFUNK_DECLARE_GETLINE "1" CACHE STRING "")

if (NOT HAVE_GETLINE OR LIBCFUNK_REPLACE_GETLINE)
  include($CACHE{LIBCFUNK_MODULE_DIR}/getdelim.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getline.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getline.cmake)
endif ()

