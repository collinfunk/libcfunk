
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strpbrk" "string.h" HAVE_STRPBRK)
endif ()

set(LIBCFUNK_DECLARE_STRPBRK "1" CACHE STRING "")

if (NOT HAVE_STRPBRK OR LIBCFUNK_REPLACE_STRPBRK)
  include($CACHE{LIBCFUNK_MODULE_DIR}/strcspn.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strpbrk.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strpbrk.cmake)
endif ()

