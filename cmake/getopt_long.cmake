
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/getopt-h.cmake)

if (HAVE_STDLIB_H OR HAVE_UNISTD_H OR HAVE_GETOPT_H)
  set(GETOPT_INCLUDES "")
  if (HAVE_STDLIB_H)
    list(APPEND GETOPT_INCLUDES "stdlib.h")
  endif ()
  if (HAVE_UNISTD_H)
    list(APPEND GETOPT_INCLUDES "unistd.h")
  endif ()
  if (HAVE_GETOPT_H)
    list(APPEND GETOPT_INCLUDES "getopt.h")
  endif ()
  check_symbol_exists("getopt_long" "${GETOPT_INCLUDES}" HAVE_GETOPT_LONG)
  unset(GETOPT_INCLUDES)
endif ()

set(LIBCFUNK_DECLARE_GETOPT_LONG "1" CACHE STRING "")

if (NOT HAVE_GETOPT_LONG OR LIBCFUNK_REPLACE_GETOPT_LONG)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/getopt_long.c
    $CACHE{LIBCFUNK_SOURCE_DIR}/getopt_internal.c
    $CACHE{LIBCFUNK_SOURCE_DIR}/getopt_internal.h
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-getopt_long.cmake)
endif ()

