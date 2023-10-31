
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/sys-time-h.cmake)

check_include_file("windows.h" HAVE_WINDOWS_H)

if (HAVE_SYS_TIME_H)
  check_symbol_exists("gettimeofday" "sys/time.h" HAVE_GETTIMEOFDAY)
else ()
  set(HAVE_GETTIMEOFDAY "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_GETTIMEOFDAY "1" CACHE INTERNAL "")

if (NOT HAVE_GETTIMEOFDAY)
  if (NOT HAVE_WINDOWS_H)
    message(FATAL_ERROR "No implementation for 'gettimeofday' on your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/gettimeofday.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-gettimeofday.cmake)
endif ()

