
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_file("intrin.h" HAVE_INTRIN_H)

if (HAVE_STRING_H OR HAVE_STRINGS_H)
  set(POPCOUNTL_INCLUDES "")
  if (HAVE_STRING_H)
    list(APPEND POPCOUNTL_INCLUDES "string.h")
  endif ()
  if (HAVE_STRINGS_H)
    list(APPEND POPCOUNTL_INCLUDES "strings.h")
  endif ()
  check_symbol_exists("popcountl" "${POPCOUNTL_INCLUDES}" HAVE_POPCOUNTL)
  unset(POPCOUNTL_INCLUDES)
endif ()

set(LIBCFUNK_DECLARE_POPCOUNTL "1" CACHE INTERNAL "")

if (NOT HAVE_POPCOUNTL)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/popcountl.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-popcountl.cmake)
endif ()

