
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wctype-h.cmake)

if (HAVE_WCTYPE_H)
  check_symbol_exists("towlower" "wctype.h" HAVE_TOWLOWER)
endif ()

set(LIBCFUNK_DECLARE_TOWLOWER "1" CACHE INTERNAL "")

if (NOT HAVE_TOWLOWER)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/towlower.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-towlower.cmake)
endif ()

