
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_file("intrin.h" HAVE_INTRIN_H)

if (HAVE_STRING_H OR HAVE_STRINGS_H)
  set(FLSLL_INCLUDES "")
  if (HAVE_STRING_H)
    list(APPEND FLSLL_INCLUDES "string.h")
  endif ()
  if (HAVE_STRINGS_H)
    list(APPEND FLSLL_INCLUDES "strings.h")
  endif ()
  check_symbol_exists("flsll" "${FLSLL_INCLUDES}" HAVE_FLSLL)
  unset(FLSLL_INCLUDES)
endif ()

set(LIBCFUNK_DECLARE_FLSLL "1" CACHE STRING "")

if (NOT HAVE_FLSLL OR LIBCFUNK_REPLACE_FLSLL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/flsll.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-flsll.cmake)
endif ()

