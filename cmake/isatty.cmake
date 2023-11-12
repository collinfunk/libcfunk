
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/fcntl-h.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_UNISTD_H)
  check_symbol_exists("isatty" "unistd.h" HAVE_ISATTY)
  check_symbol_exists("_isatty" "unistd.h" HAVE__ISATTY)
endif ()

set(LIBCFUNK_DECLARE_ISATTY "1" CACHE STRING "")

# Windows '_isatty' actually checks for character devices and not terminals.
# See the associated source file.
if (HAVE_WINDOWS_H)
  set(LIBCFUNK_REPLACE_ISATTY "1" CACHE STRING "")
endif ()

if (NOT HAVE_ISATTY OR LIBCFUNK_REPLACE_ISATTY)
  if (NOT HAVE__ISATTY AND NOT HAVE_WINDOWS_H)
    message(FATAL_ERROR "No implementation for isatty on your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/isatty.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-isatty.cmake)
endif ()

