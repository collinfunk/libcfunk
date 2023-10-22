
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdlib-h.cmake)

if (HAVE_STDLIB_H)
  check_symbol_exists("lldiv" "stdlib.h" HAVE_LLDIV)
else ()
  set(HAVE_LLDIV "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_LLDIV "1" CACHE INTERNAL "")

if (NOT HAVE_LLDIV)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/lldiv.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-lldiv.cmake)
endif ()

