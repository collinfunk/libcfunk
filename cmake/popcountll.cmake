
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_file("intrin.h" HAVE_INTRIN_H)

if (HAVE_STRING_H OR HAVE_STRINGS_H)
  set(POPCOUNTLL_INCLUDES "")
  if (HAVE_STRING_H)
    list(APPEND POPCOUNTLL_INCLUDES "string.h")
  endif ()
  if (HAVE_STRINGS_H)
    list(APPEND POPCOUNTLL_INCLUDES "strings.h")
  endif ()
  check_symbol_exists("popcountll" "${POPCOUNTLL_INCLUDES}" HAVE_POPCOUNTLL)
  unset(POPCOUNTLL_INCLUDES)
endif ()

set(LIBCFUNK_DECLARE_POPCOUNTLL "1" CACHE INTERNAL "")

if (NOT HAVE_POPCOUNTLL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/popcountll.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-popcountll.cmake)
endif ()

