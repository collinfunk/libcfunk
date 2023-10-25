
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/ctype-h.cmake)

if (HAVE_CTYPE_H)
  check_symbol_exists("tolower" "ctype.h" HAVE_TOLOWER)
else ()
  set(HAVE_TOLOWER "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_TOLOWER "1" CACHE INTERNAL "")

if (NOT HAVE_TOLOWER)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/tolower.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-tolower.cmake)
endif ()

