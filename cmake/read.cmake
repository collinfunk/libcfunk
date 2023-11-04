
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("read" "unistd.h" HAVE_READ)
  check_symbol_exists("_read" "unistd.h" HAVE__READ)
endif ()

set(LIBCFUNK_DECLARE_READ "1" CACHE INTERNAL "")

if (NOT HAVE_READ)
  if (NOT HAVE__READ)
    message(FATAL_ERROR "No implementation of 'read' for your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/read.c
  )
endif ()

