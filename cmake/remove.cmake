
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_IO_H OR HAVE_STDIO_H)
  set(REMOVE_INCLUDES "")
  if (HAVE_IO_H)
    list(APPEND REMOVE_INCLUDES "io.h")
  endif ()
  if (HAVE_STDIO_H)
    list(APPEND REMOVE_INCLUDES "stdio.h")
  endif ()
  check_symbol_exists("remove" "${REMOVE_INCLUDES}" HAVE_REMOVE)
  check_symbol_exists("_remove" "${REMOVE_INCLUDES}" HAVE__REMOVE)
  unset(REMOVE_INCLUDES)
endif ()

# Windows does not remove empty directories.
check_include_file("windows.h" HAVE_WINDOWS_H)
if (HAVE_WINDOWS_H)
  set(LIBCFUNK_REPLACE_REMOVE "1" CACHE STRING "")
endif ()

set(LIBCFUNK_DECLARE_REMOVE "1" CACHE STRING "")

if (NOT HAVE_REMOVE OR LIBCFUNK_REPLACE_REMOVE)
  if (NOT HAVE_REMOVE AND NOT HAVE__REMOVE)
    message(FATAL_ERROR "No implementation of remove on your system.")
  endif ()
  include($CACHE{LIBCFUNK_MODULE_DIR}/rmdir.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/unlink.cmake)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/remove.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-remove.cmake)
endif ()

