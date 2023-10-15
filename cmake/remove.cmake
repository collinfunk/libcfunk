
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
else ()
  set(HAVE_REMOVE "" CACHE INTERNAL "")
  set(HAVE__REMOVE "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_REMOVE "1" CACHE INTERNAL "")

if (NOT HAVE_REMOVE)
  if (NOT HAVE__REMOVE)
    message(FATAL_ERROR "No implementation of remove on your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/remove.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-remove.cmake)
endif ()

