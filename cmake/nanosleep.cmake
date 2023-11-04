
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

if (HAVE_TIME_H)
  check_symbol_exists("nanosleep" "time.h" HAVE_NANOSLEEP)
endif ()

check_include_file("windows.h" HAVE_WINDOWS_H)

set(LIBCFUNK_DECLARE_NANOSLEEP "1" CACHE STRING "")

if (NOT HAVE_NANOSLEEP)
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/nanosleep.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-nanosleep.cmake)
endif ()

