
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("wmemset" "wchar.h" HAVE_WMEMSET)
else ()
  set(HAVE_WMEMSET "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_WMEMSET "1" CACHE INTERNAL "")

if (NOT HAVE_WMEMSET)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/wmemset.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-wmemset.cmake)
endif ()

