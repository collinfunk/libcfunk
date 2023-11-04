
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

if (HAVE_STRINGS_H)
  check_symbol_exists("bzero" "strings.h" HAVE_BZERO)
endif ()

set(LIBCFUNK_DECLARE_BZERO "1" CACHE INTERNAL "")

if (NOT HAVE_BZERO)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/bzero.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-bzero.cmake)
endif ()

