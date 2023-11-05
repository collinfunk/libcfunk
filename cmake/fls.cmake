
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_file("intrin.h" HAVE_INTRIN_H)

if (HAVE_STRING_H OR HAVE_STRINGS_H)
  set(FLS_INCLUDES "")
  if (HAVE_STRING_H)
    list(APPEND FLS_INCLUDES "string.h")
  endif ()
  if (HAVE_STRINGS_H)
    list(APPEND FLS_INCLUDES "strings.h")
  endif ()
  check_symbol_exists("fls" "${FLS_INCLUDES}" HAVE_FLS)
  unset(FLS_INCLUDES)
endif ()

set(LIBCFUNK_DECLARE_FLS "1" CACHE STRING "")

if (NOT HAVE_FLS OR LIBCFUNK_REPLACE_FLS)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/fls.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fls.cmake)
endif ()

