
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/ctype-h.cmake)

if (HAVE_CTYPE_H)
  check_symbol_exists("islower" "ctype.h" HAVE_ISLOWER)
else ()
  set(HAVE_ISLOWER "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_ISLOWER "1" CACHE INTERNAL "")

if (NOT HAVE_ISLOWER)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/islower.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-islower.cmake)
endif ()

