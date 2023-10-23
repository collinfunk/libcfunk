
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/wctype-h.cmake)

if (HAVE_WCTYPE_H)
  check_symbol_exists("iswctype" "wctype.h" HAVE_ISWCTYPE)
else ()
  set(HAVE_ISWCTYPE "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_ISWCTYPE "1" CACHE INTERNAL "")

if (NOT HAVE_ISWCTYPE)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/iswctype.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()

