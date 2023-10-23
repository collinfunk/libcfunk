
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wctype-h.cmake)

if (HAVE_WCTYPE_H)
  check_symbol_exists("iswlower" "wctype.h" HAVE_ISWLOWER)
else ()
  set(HAVE_ISWLOWER "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_ISWLOWER "1" CACHE INTERNAL "")

if (NOT HAVE_ISWLOWER)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/iswlower.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-iswlower.cmake)
endif ()

