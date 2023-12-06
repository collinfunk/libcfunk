
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("popen" "stdio.h" HAVE_POPEN)
  check_symbol_exists("_popen" "stdio.h" HAVE__POPEN)
endif ()

set(LIBCFUNK_DECLARE_POPEN "1" CACHE STRING "")

if (NOT HAVE_POPEN)
  if (NOT HAVE__POPEN)
    message(FATAL_ERROR "No implementation of 'popen' avaliable on your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/popen.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-popen.cmake)
endif ()

