
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("rewind" "stdio.h" HAVE_REWIND)
endif ()

set(LIBCFUNK_DECLARE_REWIND "1" CACHE STRING "")

if (NOT HAVE_REWIND OR LIBCFUNK_REPLACE_REWIND)
  include($CACHE{LIBCFUNK_MODULE_DIR}/fseeko.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/rewind.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-rewind.cmake)
endif ()

