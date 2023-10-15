
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("fileno" "stdio.h" HAVE_FILENO)
  check_symbol_exists("_fileno" "stdio.h" HAVE__FILENO)
else ()
  set(HAVE_FILENO "" CACHE INTERNAL "")
  set(HAVE__FILENO "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_FILENO "1" CACHE INTERNAL "")

if (NOT HAVE_FILENO)
  if (NOT HAVE__FILENO)
    message(FATAL_ERROR "No implementation of 'fileno' for your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/fileno.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fileno.cmake)
endif ()
