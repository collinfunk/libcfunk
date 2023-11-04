
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-stat-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/fcntl-h.cmake)

if (HAVE_FCNTL_H)
  check_symbol_exists("open" "fcntl.h" HAVE_OPEN)
  check_symbol_exists("_open" "fcntl.h" HAVE__OPEN)
endif ()

set(LIBCFUNK_DECLARE_OPEN "1" CACHE INTERNAL "")

if (NOT HAVE_OPEN)
  if (NOT HAVE__OPEN)
    message(FATAL_ERROR "No implementation for 'open' on your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/open.c
  )
endif ()

