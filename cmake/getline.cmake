
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/getdelim.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("getline" "stdio.h" HAVE_GETLINE)
else ()
  set(HAVE_GETLINE "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_GETLINE "1" CACHE INTERNAL "")

if (NOT HAVE_GETLINE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getline.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getline.cmake)
endif ()

