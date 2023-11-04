
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_file("intrin.h" HAVE_INTRIN_H)

if (HAVE_STRING_H OR HAVE_STRINGS_H)
  set(FFSLL_INCLUDES "")
  if (HAVE_STRING_H)
    list(APPEND FFSLL_INCLUDES "string.h")
  endif ()
  if (HAVE_STRINGS_H)
    list(APPEND FFSLL_INCLUDES "strings.h")
  endif ()
  check_symbol_exists("ffsll" "${FFSLL_INCLUDES}" HAVE_FFSLL)
  unset(FFSLL_INCLUDES)
endif ()

set(LIBCFUNK_DECLARE_FFSLL "1" CACHE STRING "")

if (NOT HAVE_FFSLL OR LIBCFUNK_REPLACE_FFSLL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/ffsll.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ffsll.cmake)
endif ()

