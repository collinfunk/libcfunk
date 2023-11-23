
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("ftello" "stdio.h" HAVE_FTELLO)
  check_symbol_exists("ftell" "stdio.h" HAVE_FTELL)
endif ()

check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_WINDOWS_H)
  set(LIBCFUNK_REPLACE_FTELLO "1" CACHE STRING "")
  check_symbol_exists("_ftelli64" "stdio.h" HAVE__FTELLI64)
  # Reject pipes.
  include($CACHE{LIBCFUNK_MODULE_DIR}/lseek.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/fileno.cmake)
endif ()

set(LIBCFUNK_DECLARE_FTELLO "1" CACHE STRING "")

if (NOT HAVE_FTELLO OR LIBCFUNK_REPLACE_FTELLO)
  if (NOT HAVE__FTELLI64)
    message(WARNING "Using ftell as a replacement for ftello. This may \
cause unexpected behavior on large files.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/ftello.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ftello.cmake)
endif ()

