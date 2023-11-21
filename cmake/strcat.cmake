
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strcat" "string.h" HAVE_STRCAT)
endif ()

set(LIBCFUNK_DECLARE_STRCAT "1" CACHE STRING "")

if (NOT HAVE_STRCAT OR LIBCFUNK_REPLACE_STRCAT)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strcpy.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strlen.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strcat.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strcat.cmake)
endif ()

