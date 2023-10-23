
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wchar-h.cmake)

if (HAVE_WCHAR_H)
  check_symbol_exists("btowc" "wchar.h" HAVE_BTOWC)
else ()
  set(HAVE_BTOWC "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_BTOWC "1" CACHE INTERNAL "")

if (NOT HAVE_BTOWC)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/btowc.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-btowc.cmake)
endif ()

