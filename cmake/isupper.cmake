
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/ctype-h.cmake)

if (HAVE_CTYPE_H)
  check_symbol_exists("isupper" "ctype.h" HAVE_ISUPPER)
else ()
  set(HAVE_ISUPPER "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_ISUPPER "1" CACHE INTERNAL "")

if (NOT HAVE_ISUPPER)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isupper.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-isupper.cmake)
endif ()

