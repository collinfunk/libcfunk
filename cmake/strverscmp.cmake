include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/string-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/ctype.cmake)

if (HAVE_STRING_H)
  check_symbol_exists("strverscmp" "string.h" HAVE_STRVERSCMP)
else ()
  set(HAVE_STRVERSCMP "" CACHE INTERNAL "")
endif()

set(LIBCFUNK_DECLARE_STRVERSCMP "1" CACHE INTERNAL "")

if (NOT HAVE_STRVERSCMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/strverscmp.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-strverscmp.cmake)
endif ()