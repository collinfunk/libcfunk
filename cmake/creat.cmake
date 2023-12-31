
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/fcntl-h.cmake)

if (HAVE_FCNTL_H)
  check_symbol_exists("creat" "fcntl.h" HAVE_CREAT)
endif ()

set(LIBCFUNK_DECLARE_CREAT "1" CACHE STRING "")

if (NOT HAVE_CREAT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/creat.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-creat.cmake)
endif ()

