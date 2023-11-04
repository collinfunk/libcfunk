
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("pclose" "stdio.h" HAVE_PCLOSE)
  check_symbol_exists("_pclose" "stdio.h" HAVE__PCLOSE)
endif ()

set(LIBCFUNK_DECLARE_PCLOSE "1" CACHE INTERNAL "")

if (NOT HAVE_PCLOSE)
  if (NOT HAVE__PCLOSE)
    message(FATAL_ERROR "No implementation of 'pclose' avaliable on your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/pclose.c
  )
endif ()

