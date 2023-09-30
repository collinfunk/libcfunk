include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/time-h.cmake)

if (HAVE_TIME_H)
  check_symbol_exists("timespec_getres" "time.h" HAVE_TIMESPEC_GETRES)
else ()
  set(HAVE_TIMESPEC_GETRES "" CACHE INTERNAL "")
endif ()

set(LIBCFUNK_DECLARE_TIMESPEC_GETRES "1" CACHE INTERNAL "")

if (NOT HAVE_TIMESPEC_GETRES)
  check_symbol_exists("clock_getres" "time.h" HAVE_CLOCK_GETRES)
  # FIXME
  if (NOT HAVE_CLOCK_GETRES)
    message(FATAL_ERROR "Could not implement timespec_getres on your system.")
  endif ()
  target_sources("$CACHE{LIBCFUNK_LIBRARY_NAME}" PRIVATE
    $CACHE{LIBCFUNK_SOURCE_DIR}/timespec-getres.c
  )
endif ()

if (LIBCFUNK_ENABLE_TESTS)
endif ()
