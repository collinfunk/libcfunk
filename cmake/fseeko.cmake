
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-h.cmake)

if (HAVE_STDIO_H)
  check_symbol_exists("fseeko" "stdio.h" HAVE_FSEEKO)
  check_symbol_exists("fseek" "stdio.h" HAVE_FSEEK)
endif ()

check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_WINDOWS_H)
  set(LIBCFUNK_REPLACE_FSEEKO "1" CACHE STRING "")
  check_symbol_exists("_fseeki64" "stdio.h" HAVE__FSEEKI64)
  # Reject pipes.
  include($CACHE{LIBCFUNK_MODULE_DIR}/lseek.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/fileno.cmake)
endif ()

set(LIBCFUNK_DECLARE_FSEEKO "1" CACHE STRING "")

if (NOT HAVE_FSEEKO OR LIBCFUNK_REPLACE_FSEEKO)
  # Check the structure of 'FILE *' so the error flag can be cleared.
  include($CACHE{LIBCFUNK_MODULE_DIR}/sys-types-h.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/stdio-ext-h.cmake)
  if (NOT HAVE_FSEEK AND NOT HAVE__FSEEKI64)
    message(WARNING "Using fseek as a replacement for fseeko. This may \
cause unexpected behavior on large files.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/fseeko.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-fseeko.cmake)
endif ()

