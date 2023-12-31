
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/unistd-h.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_UNISTD_H)
  check_symbol_exists("sleep" "unistd.h" HAVE_SLEEP)
endif ()

set(LIBCFUNK_DECLARE_SLEEP "1" CACHE STRING "")

if (NOT HAVE_SLEEP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/sleep.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-sleep.cmake)
endif ()
