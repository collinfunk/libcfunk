
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strlen" "string.h" HAVE_STRLEN)
endif ()

set(LIBCFUNK_DECLARE_STRLEN "1" CACHE STRING "")

if (NOT HAVE_STRLEN OR LIBCFUNK_REPLACE_STRLEN)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strlen.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strlen.cmake)
endif ()

