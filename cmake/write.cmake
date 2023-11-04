
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

if (HAVE_UNISTD_H)
  check_symbol_exists("write" "unistd.h" HAVE_WRITE)
  check_symbol_exists("_write" "unistd.h" HAVE__WRITE)
endif ()

set(LIBCFUNK_DECLARE_WRITE "1" CACHE STRING "")

if (NOT HAVE_WRITE)
  if (NOT HAVE__WRITE)
    message(FATAL_ERROR "No implementation of 'write' for your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/write.c
  )
endif ()

