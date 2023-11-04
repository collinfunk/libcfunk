
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wctype-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/iswctype.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/iswalnum.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/iswalpha.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/iswblank.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/iswcntrl.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/iswdigit.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/iswgraph.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/iswlower.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/iswprint.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/iswpunct.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/iswspace.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/iswupper.cmake)

if (HAVE_WCTYPE_H)
  check_symbol_exists("wctype" "wctype.h" HAVE_WCTYPE)
endif ()

set(LIBCFUNK_DECLARE_WCTYPE "1" CACHE INTERNAL "")

if (NOT HAVE_WCTYPE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wctype.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-wctype.cmake)
endif ()

