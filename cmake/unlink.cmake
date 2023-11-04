
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

check_include_file("io.h" HAVE_IO_H)
check_include_file("stdio.h" HAVE_STDIO_H)

if (HAVE_UNISTD_H OR HAVE_IO_H OR HAVE_STDIO_H)
  set(UNLINK_INCLUDES "")
  if (HAVE_UNISTD_H)
    list(APPEND UNLINK_INCLUDES "unistd.h")
  endif ()
  if (HAVE_IO_H)
    list(APPEND UNLINK_INCLUDES "io.h")
  endif ()
  if (HAVE_STDIO_H)
    list(APPEND UNLINK_INCLUDES "stdio.h")
  endif ()
  check_symbol_exists("unlink" "${UNLINK_INCLUDES}" HAVE_UNLINK)
  check_symbol_exists("_unlink" "${UNLINK_INCLUDES}" HAVE__UNLINK)
  unset(UNLINK_INCLUDES)
endif ()

set(LIBCFUNK_DECLARE_UNLINK "1" CACHE STRING "")

if (NOT HAVE_UNLINK)
  if (NOT HAVE__UNLINK)
    message(FATAL_ERROR "No implementation of unlink on your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/unlink.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-unlink.cmake)
endif ()
