
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-time-h.cmake)

if (HAVE_SYS_TIME_H)
  check_symbol_exists("gettimeofday" "sys/time.h" HAVE_GETTIMEOFDAY)
endif ()

set(LIBCFUNK_DECLARE_GETTIMEOFDAY "1" CACHE STRING "")

if (NOT HAVE_GETTIMEOFDAY OR LIBCFUNK_REPLACE_GETTIMEOFDAY)
  check_include_file("windows.h" HAVE_WINDOWS_H)
  if (NOT HAVE_WINDOWS_H)
    check_include_file("time.h" HAVE_TIME_H)
    if (HAVE_TIME_H)
      check_symbol_exists("time" "time.h" HAVE_TIME)
    endif ()
  endif ()
  if (NOT HAVE_WINDOWS_H AND NOT HAVE_GETTIMEOFDAY AND NOT HAVE_TIME)
    message(FATAL_ERROR "No implementation for 'gettimeofday' on your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/gettimeofday.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-gettimeofday.cmake)
endif ()

