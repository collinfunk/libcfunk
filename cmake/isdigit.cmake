
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/ctype-h.cmake)

if (HAVE_CTYPE_H)
  check_symbol_exists("isdigit" "ctype.h" HAVE_ISDIGIT)
endif ()

set(LIBCFUNK_DECLARE_ISDIGIT "1" CACHE INTERNAL "")

if (NOT HAVE_ISDIGIT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isdigit.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-isdigit.cmake)
endif ()

