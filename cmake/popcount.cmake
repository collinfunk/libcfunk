
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/strings-h.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)
check_include_file("intrin.h" HAVE_INTRIN_H)

if (HAVE_STRING_H OR HAVE_STRINGS_H)
  set(POPCOUNT_INCLUDES "")
  if (HAVE_STRING_H)
    list(APPEND POPCOUNT_INCLUDES "string.h")
  endif ()
  if (HAVE_STRINGS_H)
    list(APPEND POPCOUNT_INCLUDES "strings.h")
  endif ()
  check_symbol_exists("popcount" "${POPCOUNT_INCLUDES}" HAVE_POPCOUNT)
  unset(POPCOUNT_INCLUDES)
endif ()

set(LIBCFUNK_DECLARE_POPCOUNT "1" CACHE STRING "")

if (NOT HAVE_POPCOUNT)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/popcount.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-popcount.cmake)
endif ()

