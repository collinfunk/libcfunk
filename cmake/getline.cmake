
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/getdelim.cmake)

check_c_symbol("getline" "stdio.h")

set(LIBCFUNK_DECLARE_GETLINE "1" CACHE INTERNAL "")

if (NOT HAVE_GETLINE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getline.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getline.cmake)
endif ()

