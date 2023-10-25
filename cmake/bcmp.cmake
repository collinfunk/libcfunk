
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

if (HAVE_STRINGS_H)
  check_symbol_exists("bcmp" "strings.h" HAVE_BCMP)
else ()
  set (HAVE_BCMP "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_BCMP "1" CACHE INTERNAL "")

if (NOT HAVE_BCMP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/bcmp.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-bcmp.cmake)
endif ()

