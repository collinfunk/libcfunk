
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/ctype-h.cmake)

if (HAVE_CTYPE_H)
  check_symbol_exists("isxdigit" "ctype.h" HAVE_ISXDIGIT)
endif ()

set(LIBCFUNK_DECLARE_ISXDIGIT "1" CACHE INTERNAL "")

if (NOT HAVE_ISXDIGIT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isxdigit.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-isxdigit.cmake)
endif ()

